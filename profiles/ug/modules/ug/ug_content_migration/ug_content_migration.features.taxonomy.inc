<?php

/**
 * @file
 * ug_content_migration.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ug_content_migration_taxonomy_default_vocabularies() {
  return array(
    'content_subject_expert_team' => array(
      'name' => 'Content Subject Expert Team',
      'machine_name' => 'content_subject_expert_team',
      'description' => 'List of teams in department responsible for content on the website',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
