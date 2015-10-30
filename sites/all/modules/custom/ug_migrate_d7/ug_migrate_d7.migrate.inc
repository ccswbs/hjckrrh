<?php

/*
* Implements hook_migrate_api()
*/

function ug_migrate_d7_migrate_api() {

  /***************************************************
  ** SITE CONFIGURATION
  ** -  see if we can add these to the site settings file
  **/

  $role_mappings = array(
    'source-editor' => 'editor',
  );

  $term_destination = 'tags';
  //$term_destination = 'page_category';

  /************************************************/

  //General variables
  $common_arguments = array(
    'source_connection' => 'legacy',
    'source_version' => 7,
    'group_name' => 'ug_d7_migrate',
  );

  //Node variables
  $node_arguments = $common_arguments + array(
    'user_migration' => 'UGUser',
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

      /**** ROLE migration ****/
      'UGRole' => $common_arguments + array(
        'description' => t('Migration of user roles from Drupal 7'),
        'class_name' => 'UGRoleMigration',
        'role_mappings' => $role_mappings,
      ),

      /**** USER migration ****/
      'UGUser' => $common_arguments + array(
        'description' => t('Migration of users from Drupal 7'),
        'class_name' => 'UGUserMigration',
        'role_migration' => 'UGRole',
      ),

      /**** TERM migration ****/
      'UGTerm' => $common_arguments + array(
        'description' => t('Migration of terms from Drupal 7'),
        'class_name' => 'UGTermMigration',
        'source_vocabulary' => 'tags', 
        'destination_vocabulary' => $term_destination,
      ),

      /**** PAGE migration ****/
      'UGPage' => $node_arguments + array(
        'description' => t('Migration of basic pages from Drupal 7'),
        'class_name' => 'UGPageMigration',
        'source_type' => 'page', 
        'destination_type' => 'page',
      ),
    ),
  );

  return $api;
}
