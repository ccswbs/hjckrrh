<?php

/**
 * @file 
 * University of Guelph specific site settings file.
 */

define('UG_DEFAULT_PRIMARY_DOMAIN', 'www.uoguelph.ca');

/**
 * Pantheon specific settings
 */
if (isset($_ENV['PANTHEON_ENVIRONMENT']) && php_sapi_name() != 'cli') {
  /**
   * Site specific overrides
   * 
   * Configuration that applies to a specific Pantheon sites may be
   * placed in a file named ug.SITE.settings.php will be merged here.
   * */
  $ug_site_settings = 'ug.' . $_ENV['PANTHEON_SITE_NAME'] . '.settings.php';
  if (file_exists(__DIR__ . DIRECTORY_SEPARATOR . $ug_site_settings)) {
    require_once __DIR__ . DIRECTORY_SEPARATOR . $ug_site_settings;
  }
  /**
   * Domain masking
   * 
   * Domain masking refers to hosting mutiple sites at the same domain name,
   * under different sub-directories or sub-paths. Although not officially 
   * supported by Pantheon, domain masking is required to maintain some
   * legacy U of G site URLs.
   * 
   * To enable domain masking, create a site override file (see above) that
   * sets at least the $ug_base_path variable. If set, this file will rewrite
   * the server request URI, cookie path, etc. to enable the site to be served
   * from a subdirectory path.
   * 
   * The default domain for domain masked sites is www.uoguelph.ca
   * (e.g. https://www.uoguelph.ca/example/) To specify a different domain name,
   * also set the $ug_primary_domain variable in your site overrides file.
   */
  if (isset($ug_base_path)) {
      // Use default domain name if not specified.
      if (!isset($ug_primary_domain)) {
          $ug_primary_domain = UG_DEFAULT_PRIMARY_DOMAIN;
      }
      // Rewrite request URI.
      $_SERVER['REQUEST_URI'] = $ug_base_path . $_SERVER['REQUEST_URI'];
      // Set cookie domain.
      $cookie_domain = '.' . $ug_primary_domain;
      $cookie_path = $ug_base_path;
      // Set Drupal base URL.
      $base_url = 'https://' . $ug_primary_domain . $ug_base_path;
  }
}
