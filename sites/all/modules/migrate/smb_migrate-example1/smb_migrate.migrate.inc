<?php

/**
 * Implements hook_migrate_api().
 */
function smb_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'content_migration' => array(
        'title' => t('SMB Drupal 6 to Drupal 7 migration example.'),
      ),
    ),
  );

  // Specify the DB connection and the source Drupal version.
  $common_arguments = array(
    'source_connection' => 'legacy',
    'source_version' => 6,
    'group_name' => 'content_migration',
  );

  /**
   * Register the user migration.
   * We just use the migrate_d2d D6 migration class as-is.
   */
  $api['migrations']['User'] = $common_arguments + array(
    'description' => t('Migration of users from Drupal 6'),
    'class_name' => 'DrupalUser6Migration',
  );

  return $api;
}
