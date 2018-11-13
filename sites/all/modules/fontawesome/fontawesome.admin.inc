<?php

/**
 * @file
 * Administrative pages for the Font Awesome module.
 */

/**
 * Settings form for administering module.
 */
function fontawesome_admin_settings_form() {
  // Load the library.
  $library = libraries_load(FONTAWESOME_LIBRARY);

  $form['fontawesome_method'] = array(
    '#type' => 'select',
    '#title' => t('Font Awesome Method'),
    '#options' => array(
      'svg' => t('SVG with JS'),
      'webfonts' => t('Web Fonts with CSS'),
    ),
    '#default_value' => variable_get('fontawesome_method', 'svg'),
    '#description' => t('This setting controls the way Font Awesome works. SVG with JS is the modern, easy, and powerful version with the most backwards compatibility. Web Fonts with CSS is the classic Font Awesome icon method that you have seen in earlier versions of Font Awesome. We recommend SVG with JS. Please note that the Webfonts with CSS version does not allow backwards compatibility with Font Awesome 4. That means you will need to check your code base to be certain that the icons are all updated to work with version 5. See !gettingStartedLink for more information.', array(
      '!gettingStartedLink' => l(t('the Font Awesome guide'), 'https://fontawesome.com/get-started'),
    )),
  );

  $form['fontawesome_allow_pseudo_elements'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow CSS pseudo-elements?'),
    '#description' => t('If you do not want to add icons directly in code, you can add them through CSS pseudo-elements. Font Awesome has leveraged the ::before pseudo-element to add icons to a page since the very beginning. For more information on how to use pseudo-elements, see the !pseudoElementsLink. Note that this feature is always available with the Webfonts version of Font Awesome. If you turn this feature on for SVG with JS, it will slow your site down noticeably.', array(
      '!pseudoElementsLink' => l(t('Font Awesome guide to pseudo-elements'), 'https://fontawesome.com/how-to-use/web-fonts-with-css#pseudo-elements'),
    )),
    '#default_value' => variable_get('fontawesome_allow_pseudo_elements', FALSE),
  );

  $defaults = variable_get('fontawesome_external', array(
    'use_cdn' => TRUE,
    'external_location' => '',
  ));
  $form['fontawesome_external'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
    '#title' => t('External File Configuration'),
    '#description' => t('These settings control the method by which the Font Awesome library is loaded. You can choose to use an external (full URL) or local (relative path) library by selecting a URL / path below, or you can use a local version of the file by leaving the box unchecked and downloading the library <a href="!remoteurl">!remoteurl</a> and installing locally at %installpath. See the README for more information.', array(
      '!remoteurl' => $library['download url'],
      '%installpath' => '/sites/all/libraries',
    )),
    'use_cdn' => array(
      '#type' => 'checkbox',
      '#title' => t('Use external file (CDN) / local file?'),
      '#description' => t('Checking this box will cause the Font Awesome library to be loaded from the given source rather than from the local library file.'),
      '#default_value' => $defaults['use_cdn'],
    ),
    'external_location' => array(
      '#type' => 'textfield',
      '#title' => t('External File Location'),
      '#default_value' => $defaults['external_location'],
      '#size' => 80,
      '#description' => t('Enter a source URL for the external Font Awesome library file you wish to use. Note that this is designed for use with the <strong>SVG with JS</strong> method. Use for the Webfonts method at your own risk. This URL should point to the Font Awesome JS svg file when using <strong>SVG with JS</strong> or it should point to the Font Awesome CSS file when using <strong>Web Fonts with CSS</strong>. Leave blank to use the default Font Awesome CDN.'),
      '#states' => array(
        'disabled' => array(
          ':input[name="fontawesome_external[use_cdn]"]' => array('checked' => FALSE),
        ),
        'visible' => array(
          ':input[name="fontawesome_external[use_cdn]"]' => array('checked' => TRUE),
        ),
      ),
    ),
  );

  $defaults = variable_get('fontawesome_shim', array(
    'use_shim' => FALSE,
    'external_location' => '',
  ));
  $form['fontawesome_shim'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
    '#title' => t('Version 4 Backwards Compatibility'),
    '#description' => t('Version 5 of Font Awesome has some changes which require modifications to the way you declare many of your icons. The settings below are designed to ease that transition. See !upgradingLink for more information.', array(
      '!upgradingLink' => l(t('the Font Awesome guide to upgrading version 4 to version 5'), 'https://fontawesome.com/how-to-use/upgrading-from-4'),
    )),
    // Webfonts with CSS does not support shims.
    '#states' => array(
      'visible' => array(
        ':input[name="fontawesome_method"]' => array('value' => 'svg'),
      ),
    ),
    'use_shim' => array(
      '#type' => 'checkbox',
      '#title' => t('Use version 4 shim file?'),
      '#description' => t('Rather than editing all of your Font Awesome declarations to use the new Font Awesome syntax, you can choose to include a shim file above. This file will allow you to use Font Awesome version 5 with Font Awesome version 4 syntax. This prevents you from needing to modify your existing code and syntax.'),
      '#default_value' => $defaults['use_shim'],
    ),
    'external_location' => array(
      '#type' => 'textfield',
      '#title' => t('External / local Library Location'),
      '#default_value' => $defaults['external_location'],
      '#size' => 80,
      '#description' => t('Enter a source URL for the external / local (relative path) Font Awesome v4 shim file you wish to use. This URL should point to the Font Awesome JS shim file. Leave blank to use the default Font Awesome CDN.'),
      '#states' => array(
        'disabled' => array(
          ':input[name="fontawesome_external[use_cdn]"]' => array('checked' => FALSE),
          ':input[name="fontawesome_shim[use_shim]"]' => array('checked' => FALSE),
        ),
        'visible' => array(
          ':input[name="fontawesome_external[use_cdn]"]' => array('checked' => TRUE),
          ':input[name="fontawesome_shim[use_shim]"]' => array('checked' => TRUE),
        ),
      ),
    ),
  );

  $form['fontawesome_no_shim'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
    '#title' => t('Version 4 Backwards Compatibility'),
    '#description' => t('<strong>The Webfonts with CSS version of Font Awesome does not support backwards compatibility with Font Awesome 4.0.</strong> If you are using Webfonts, please make certain that the icons in your code base are updated to work with the 5.0 version of Font Awesome. See !upgradingLink and !webfontsLink for more information.', array(
      '!upgradingLink' => l(t('the Font Awesome guide to upgrading version 4 to version 5'), 'https://fontawesome.com/how-to-use/upgrading-from-4'),
      '!webfontsLink' => l(t('the Font Awesome Webfonts guide'), 'https://fontawesome.com/get-started/web-fonts-with-css'),
    )),
    '#states' => array(
      'visible' => array(
        ':input[name="fontawesome_method"]' => array('value' => 'webfonts'),
      ),
    ),
  );

  // Set a submit handler manually because the default submit handler
  // gets overridden by the system_settings_form() submit handler.
  $form['#submit'][] = 'fontawesome_admin_settings_form_submit';

  return system_settings_form($form);
}

/**
 * Implements hook_form_submit().
 */
function fontawesome_admin_settings_form_submit($form, &$form_state) {
  // Load the library.
  $library = libraries_load(FONTAWESOME_LIBRARY . '_' . $form_state['values']['fontawesome_method']);

  // Use default values if CDN is checked and the locations are blank.
  if ($form_state['values']['fontawesome_external']['use_cdn']) {
    if (empty($form_state['values']['fontawesome_external']['external_location']) ||
      $form_state['values']['fontawesome_external']['external_location'] == $library['cdn url']['webfonts'] ||
      $form_state['values']['fontawesome_external']['external_location'] == $library['cdn url']['svg']
    ) {
      // Choose the default depending on method.
      if ($form_state['values']['fontawesome_method'] == 'webfonts') {
        $form_state['values']['fontawesome_external']['external_location'] = $library['cdn url']['webfonts'];
      }
      else {
        $form_state['values']['fontawesome_external']['external_location'] = $library['cdn url']['svg'];
      }
    }
    if ($form_state['values']['fontawesome_shim']['use_shim'] && empty($form_state['values']['fontawesome_shim']['external_location'])) {
      $form_state['values']['fontawesome_shim']['external_location'] = $library['cdn url']['shim'];
    }
  }
}
