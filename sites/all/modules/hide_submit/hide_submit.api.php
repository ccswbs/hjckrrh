<?php

/**
 * Allows modules to alter the behavior of the hide_submit settings.
 *
 * This example sets Hide Submit to only be active on the module and module
 * confirmation forms.
 */
function hook_hide_submit_alter(&$hide_submit_settings) {
  $current_path = current_path();
  if (!($current_path === 'admin/modules') && !($current_path === 'admin/modules/list/confirm')) {
    $hide_submit_settings['hide_submit']['hide_submit_status'] = FALSE;
  }
}
