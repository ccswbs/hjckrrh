<?php

/**
 * Implements hook_crumbs_plugins().
 *
 * @param crumbs_InjectedAPI_hookCrumbsPlugins $api
 */
function user_reference_crumbs_plugins($api) {
  foreach (field_info_fields() as $field_name => $field_info) {
    if (1
      && 'user_reference' === $field_info['type']
      && '1' === '' . $field_info['cardinality']
    ) {
      $plugin = new crumbs_EntityPlugin_Field_UserReference($field_name, $field_info['bundles']);
      $api->entityParentPlugin($field_name, $plugin, array_keys($field_info['bundles']));
    }
  }
  $api->disabledByDefault('*');
}
