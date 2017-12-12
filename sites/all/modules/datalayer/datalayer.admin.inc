<?php
/**
 * @file
 * Admin-only functionality.
 */

/**
 * Form callback for module configuration.
 */
function datalayer_settings_form($form_state) {
  $form = array();

  // Get available meta data.
  $meta_data = _datalayer_collect_meta_properties();

  $form['global'] = array(
    '#type' => 'fieldset',
    '#title' => t('Global'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['global']['datalayer_add_page_meta'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add entity meta data to pages'),
    '#default_value' => variable_get('datalayer_add_page_meta', TRUE),
  );

  $form['global']['datalayer_output_terms'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include taxonomy terms'),
    '#default_value' => variable_get('datalayer_output_terms', module_exists('taxonomy')),
    '#disabled' => !module_exists('taxonomy'),
  );

  $form['global']['datalayer_lib_helper'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include "data layer helper" library'),
    '#default_value' => variable_get('datalayer_lib_helper', FALSE),
    '#description' => t('Provides the ability to process messages passed to the dataLayer. See: !link on GitHub.',
      array(
        '!link' => l(
          t('data-layer-helper'),
          'https://github.com/google/data-layer-helper',
          array('external' => TRUE, 'attributes' => array('target' => '_blank'))
        ),
      )
    ),
  );

  $form['entity_meta'] = array(
    '#type' => 'fieldset',
    '#title' => t('Entity meta data'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('The meta data details to ouput for client-side consumption. Marking none will output everything available.'),
  );

  $form['entity_meta']['datalayer_global_entity_meta'] = array(
    '#type' => 'checkboxes',
    '#states' => array(
      'enabled' => array(
        ':input[name="datalayer_add_page_meta"]' => array('checked' => TRUE),
      ),
    ),
    '#title' => '',
    '#default_value' => variable_get('datalayer_global_entity_meta', array()),
    '#options' => drupal_map_assoc($meta_data),
  );

  $form['vocabs'] = array(
    '#type' => 'fieldset',
    '#title' => t('Taxonomy'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('The vocabularies which should be output within page meta data. Marking none will output everything available.'),
  );

  if (module_exists('taxonomy')) {
    $vocabs = taxonomy_get_vocabularies();
    $v_options = array();

    foreach ($vocabs as $v) {
      $v_options[$v->machine_name] = $v->name;
    }

    $form['vocabs']['datalayer_vocabs'] = array(
      '#type' => 'checkboxes',
      '#states' => array(
        'enabled' => array(
          ':input[name="datalayer_output_terms"]' => array('checked' => TRUE),
        ),
      ),
      '#default_value' => variable_get('datalayer_vocabs', array()),
      '#options' => $v_options,
    );
  }
  else {
    $form['vocabs']['datalayer_vocabs'] = array(
      '#type' => 'item',
      '#markup' => t('Enable the taxonomy module to expose this data to the datalayer object.'),
    );
  }

  $form['user'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Details'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('Details about the current user can be output to the dataLayer.'),
  );
  $form['user']['datalayer_expose_user_details'] = array(
    '#type' => 'textarea',
    '#title' => t('Expose user details'),
    '#default_value' => variable_get('datalayer_expose_user_details', array()),
    '#description' => t('Pages that should expose active user details to the dataLayer. Leaving empty will expose nothing.'),
  );
  $form['user']['datalayer_expose_user_details_roles'] = array(
    '#type' => 'checkboxes',
    '#options' => user_roles(TRUE),
    '#multiple' => TRUE,
    '#title' => t('Expose user roles'),
    '#default_value' => variable_get('datalayer_expose_user_details_roles', array()),
    '#description' => t('Roles that should expose active user details to the dataLayer. Leaving empty will expose to all roles.'),
  );

  return system_settings_form($form);
}
