<?php

/**
 * @file
 * The Node export serialize format handler.
 *
 * Adds serialize format to Node export.
 */

/**
 * Export callback.
 */
function node_export_serialize_export($nodes, $format) {
  return 'node_export_serialize::' . urlencode(serialize($nodes));
}

/**
 * Import callback.
 */
function node_export_serialize_import($code_string) {
  // Check for 'node_export_serialize::' at the start.
  if (substr(ltrim($code_string), 0, 23) == 'node_export_serialize::') {
    if (variable_get('node_export_allow_unsafe_unserialize', FALSE) ||
      version_compare(PHP_VERSION, '7', '<')) {
      return unserialize(urldecode(str_replace('node_export_serialize::', '', $code_string)));
    }
    else {
      $options = array('allowed_classes' => FALSE);
      return unserialize(urldecode(str_replace('node_export_serialize::', '', $code_string)), $options);
    }
  }
}

/**
 * Callback for actions.
 */
function node_export_serialize_action_form($context, &$form_state) {
  return node_export_action_form($context, $form_state, 'serialize');
}
