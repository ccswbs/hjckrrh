<?php
/**
 * @file
 * ug_news.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ug_news_user_default_roles() {
  $roles = array();

  // Exported role: news editor.
  $roles['news editor'] = array(
    'name' => 'news editor',
    'weight' => 2,
  );

  return $roles;
}
