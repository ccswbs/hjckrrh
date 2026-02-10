<?php

/**
 * @file
 * Hooks provided by Rabbit Hole.
 */

 /**
  * Integrate an entity type with Rabbit Hole.
  *
  * This will automatically add permissions, columns to the entity table, alter
  * the "View" tab (if possible) and add pseudo fields. The only thing that
  * should be left in order to add full integration is to alter the relevant
  * bundle and entity form, and to execute Rabbit Hole when an entity is viewed.
  *
  * Have a look at how the Rabbit Hole nodes module has been built in order to
  * get a deeper understanding of the integration.
  *
  * @return array
  *   You should return an array where the outer key is the name of the module,
  *   and the inner keys consist of:
  *   - entity type
  *   - base table
  *   - view path
  */
 function hook_rabbit_hole() {
   return array(
     'rh_node' => array(
       'entity type' => 'node',
       'base table' => 'node',
       'view path' => 'node/%/view',
     ),
   );
 }

/**
 * Alters the action before it is performed.
 *
 * @param $action
 *   The action that will be performed. The following constants and values are
 *   recognized:
 *   - RABBIT_HOLE_ACCESS_DENIED: Return 403.
 *   - RABBIT_HOLE_PAGE_NOT_FOUND:
 *   - RABBIT_HOLE_PAGE_REDIRECT
 *   - NULL or FALSE to skip the action.
 * @param $context
 *   An associative array containing:
 *   - entity_type: The type of $entity; for example, 'node' or 'user'.
 *   - entity: The entity that is being viewed.
 */
function hook_rabbit_hole_execute_alter(&$action, $context) {
  if ($context['entity_type'] === 'user' && isset($_GET['token'])) {
    $user = $context['entity'];
    if (drupal_valid_token($_GET['token'], "override_rh:user:$user->uid")) {
      $action = FALSE;
    }
  }
}
