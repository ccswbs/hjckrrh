<?php

/**
 * @file
 * Sample hooks demonstrating usage in Webform_matrix_component.
 */

/**
 * Validate hook for matrix component.
 *
 * You can define custom validation for this.
 */
function hook_webform_matrix_validate($element, $form_state) {
    
}

/**
 * Implements hook_webform_edit_matrix_alter().
 *
 * Webform_edit_matrix_alter for alter matrix edit form.
 * Like add helptext textfield.
 *
 * @see hook_webform_render_matrix_alter()
 */
function hook_webform_edit_matrix_alter(&$element, &$element_values, $element_id) {
    $helptext = $element_values['helptext'];
    $element['helptext'] = array(
        '#type' => 'textfield',
        '#title' => t('Help Text'),
        '#size' => 15,
        '#default_value' => $helptext,
        '#parents' => array('extra', 'element', $element_id, 'helptext'),
        '#weight' => 1,
    );
}

/**
 * Webform_render_matrix_alter for alter webform_render_matrix.
 *
 * @see hook_webform_edit_matrix_alter()
 */
function hook_webform_render_matrix_alter(&$component, &$value, &$element) {
    $helptext = $value['helptext'];
    if (!empty($helptext)) {
        $element['#field_suffix'] = $helptext;
    }
}
