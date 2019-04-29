<?php

/**
 * @file
 * Administration form for menu per role.
 */

/**
 * Settings form.
 */
function menu_per_role_settings_form($form, $form_state) {
  $form['menu_per_role_uid1_see_all'] = array(
    '#type' => 'checkbox',
    '#title' => t('The administrator (UID=1) sees everything'),
    '#description' => t('When selected, the administrator will not be affected by Menu per Role. (i.e. All the menus are visible to him.)'),
    '#default_value' => variable_get('menu_per_role_uid1_see_all', 1),
  );

  $admin_roles = user_roles(FALSE, 'administer menu_per_role');
  $form['menu_per_role_admin_see_all'] = array(
    '#type' => 'checkbox',
    '#title' => t('The menu per role administrators see everything'),
    '#description' => t('When selected, all the menu per role administrators see all the menus, whether they were marked as hidden or not.') . ' ' . t('!check assigned the "administer menu_per_role" permission.',
          array(
            '!check' => l(t('Check the roles'), 'admin/user/permissions', array(
              'fragment' => 'module-menu_per_role',
            )
            ),
          )) . (empty($admin_roles) ? '<br /><span style="color: red;">' . t('IMPORTANT NOTE: No roles were marked with the "administer menu_per_role" permission.') . '</span>' : ''),
    '#default_value' => variable_get('menu_per_role_admin_see_all', 0),
  );

  $form['menu_per_role_hide_show'] = array(
    '#type' => 'radios',
    '#title' => t('Select what is shown when editing menu items'),
    '#options' => array(
      0 => t('Hide and Show check boxes'),
      1 => t('Only Hide check boxes'),
      2 => t('Only Show check boxes'),
    ),
    '#description' => t('By default, both list of check boxes are shown when editing a menu item (in the menu administration area or while editing a node.) This option let you choose to only show the "Show menu item only to selected roles" or "Hide menu item from selected roles". WARNING: changing this option does not change the existing selection. This means some selection will become invisible when you hide one of the set of check boxes...'),
    '#default_value' => variable_get('menu_per_role_hide_show', 0),
  );

  return system_settings_form($form);
}
