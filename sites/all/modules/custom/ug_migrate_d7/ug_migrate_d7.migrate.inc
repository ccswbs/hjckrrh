<?php

/*
* Implements hook_migrate_api()
*/

function ug_migrate_d7_migrate_api() {

  // Specify the DB connection and the source Drupal version.
  $common_arguments = array(
    'source_connection' => 'legacy',
    'source_version' => 7,
    'group_name' => 'ug_d7_migrate',
  );

  $node_arguments = $common_arguments + array(
    'user_migration' => 'UGUserMigration',
    'default_uid' => 1,
  );

  $api = array(
    //set API level to 2 to work with 7.x-2.x Migrate branch
    'api' => 2,

    /**** GROUP ****/
    'groups' => array(
      'ug_d7_migrate' => array(
        'title' => t('UG Drupal 7 to Drupal 7 migration'),
      )
    ),

    'migrations' => array(

      /**** ROLE MIGRATION ****/
      'UGRole' => $common_arguments + array(
        'description' => t('Migration of user roles from Drupal 7'),
        'class_name' => 'UGRoleMigration',
        'role_mappings' => array(
          'source-editor' => 'editor',
        ),
      ),

      /**** USER MIGRATION ****/
      'UGUser' => $common_arguments + array(
        'description' => t('Migration of users from Drupal 7'),
        'class_name' => 'UGUserMigration',
        'role_migration' => 'UGRole',
      ),

      /**** PAGE MIGRATION ****/
      'UGPage' => $node_arguments + array(
        'description' => t('Migration of basic pages from Drupal 7'),
        'class_name' => 'UGPageMigration',
      ),
    ),
  );

  return $api;
}
