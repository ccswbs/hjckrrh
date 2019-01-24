<?php
/**
 * @file
 * Logic for system_status output
 */

/**
 * Return JSON formatted module information.
 */
function system_status_status_page() {
  $system_modules = system_list('module_enabled');
  $system_themes = list_themes(TRUE);

  // Needless initialisation, but hey.
  $res = array(
    "core" => array(),
    "contrib" => array(),
    "profile" => array(),
    "theme" => array()
  );

  // Go over Themes
  foreach($system_themes as $theme) {
    if(isset($theme->info['package']) && $theme->info['package'] == 'Core')
      continue;

    if(isset($theme->info['version'])) {
      //In next updates we will move themes from contrib to theme so we can GUI them differently
      $res['contrib'][$theme->name] = array("version" => $theme->info['version']);
      $res['theme'][$theme->name] = array("version" => $theme->info['version']);
    }
  }

  // Go over Modules
  foreach ($system_modules as $module => $module_info) {

    // Match for core modules.
    if (strtolower($module_info->info['package']) == "core") {
      if(isset($module_info->info['project'])) {
        $res['core'][$module_info->info['project']] = array("version" => $module_info->info['version']);
      } else {
        $res['core'][$module] = array("version" => $module_info->info['version']);
      }

      continue;
    }

    // Match for installation profiles
    if (strpos($module_info->filename,'.profile') !== false) {
      if(isset($module_info->info['project'])) {
        $res['profile'][$module_info->info['project']] = array("version" => $module_info->info['version']);
      } else {
        $res['profile'][$module] = array("version" => $module_info->info['version']);
      }

      continue;
    }

    // What now remains must be modules
    if(isset($module_info->info['project'])) {
      $res['contrib'][$module_info->info['project']] = array("version" => $module_info->info['version']);
    } else {
      $res['contrib'][$module] = array("version" => $module_info->info['version']);
    }
  }

  // doublecheck if drupal version is reported, if not add bootstrap define
  if(!isset($res['core']['drupal'])) {
    $res['core']['drupal'] = array("version" => VERSION);
  }

  if (extension_loaded('mcrypt')) {
    $res = SystemStatusEncryption::encrypt(drupal_json_encode(array("system_status" => $res)));
    drupal_json_output(array("system_status" => "encrypted", "data" => $res, "drupal_version" => "7", "engine_version" => "DRUPAL7"));
  }
  else {
    drupal_json_output(array("system_status" => $res, "drupal_version" => "7", "engine_version" => "DRUPAL7"));
  }
}
