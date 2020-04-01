<?php
/**
 * @file
 * Drupal site-specific configuration file.
 */

/**
 * Access control for update.php script.
 *
 * If you are updating your Drupal installation using the update.php script but
 * are not logged in using either an account with the "Administer software
 * updates" permission or the site maintenance account (the account that was
 * created during installation), you will need to modify the access check
 * statement below. Change the FALSE to a TRUE to disable the access check.
 * After finishing the upgrade, be sure to open this file again and change the
 * TRUE back to a FALSE!
 */
 $update_free_access = FALSE;

/**
 * Some distributions of Linux (most notably Debian) ship their PHP
 * installations with garbage collection (gc) disabled. Since Drupal depends on
 * PHP's garbage collection for clearing sessions, ensure that garbage
 * collection occurs by using the most common settings.
 */
ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);

/**
 * Set session lifetime (in seconds), i.e. the time from the user's last visit
 * to the active session may be deleted by the session garbage collector. When
 * a session is deleted, authenticated users are logged out, and the contents
 * of the user's $_SESSION variable is discarded.
 */
ini_set('session.gc_maxlifetime', 200000);

/**
 * Set session cookie lifetime (in seconds), i.e. the time from the session is
 * created to the cookie expires, i.e. when the browser is expected to discard
 * the cookie. The value 0 means "until the browser is closed".
 */
ini_set('session.cookie_lifetime', 2000000);

/**
 * Fast 404 pages:
 *
 * Drupal can generate fully themed 404 pages. However, some of these responses
 * are for images or other resource files that are not displayed to the user.
 * This can waste bandwidth, and also generate server load.
 *
 * The options below return a simple, fast 404 page for URLs matching a
 * specific pattern:
 * - 404_fast_paths_exclude: A regular expression to match paths to exclude,
 *   such as images generated by image styles, or dynamically-resized images.
 *   The default pattern provided below also excludes the private file system.
 *   If you need to add more paths, you can add '|path' to the expression.
 * - 404_fast_paths: A regular expression to match paths that should return a
 *   simple 404 page, rather than the fully themed 404 page. If you don't have
 *   any aliases ending in htm or html you can add '|s?html?' to the expression.
 * - 404_fast_html: The html to return for simple 404 pages.
 *
 * Add leading hash signs if you would like to disable this functionality.
 */
$conf['404_fast_paths_exclude'] = '/\/(?:styles)|(?:system\/files)\/|(?:sitemap.txt)|(?:robots.txt)/';
$conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['404_fast_html'] = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd"><html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';

/**
 * Specify every reverse proxy IP address in your environment.
 */
$conf['reverse_proxy_addresses'] = array(
  '131.104.92.23',
  '131.104.16.8',
  '131.104.16.9',
  '131.104.16.10',
  '131.104.16.11',
  '131.104.16.42',
);

/**
 * By default the page request process will return a fast 404 page for missing
 * files if they match the regular expression set in '404_fast_paths' and not
 * '404_fast_paths_exclude' above. 404 errors will simultaneously be logged in
 * the Drupal system log.
 *
 * You can choose to return a fast 404 page earlier for missing pages (as soon
 * as settings.php is loaded) by uncommenting the line below. This speeds up
 * server response time when loading 404 error pages and prevents the 404 error
 * from being logged in the Drupal system log. In order to prevent valid pages
 * such as image styles and other generated content that may match the
 * '404_fast_paths' regular expression from returning 404 errors, it is
 * necessary to add them to the '404_fast_paths_exclude' regular expression
 * above. Make sure that you understand the effects of this feature before
 * uncommenting the line below.
 */
drupal_fast_404();

/**
 * Pantheon configuration
 */
if (isset($_ENV['PANTHEON_ENVIRONMENT']) && (php_sapi_name() != "cli"))
{
  // Set local variables from environment
  $site  = $_ENV['PANTHEON_SITE_NAME'];
  $env   = $_ENV['PANTHEON_ENVIRONMENT'];

  // Redirect to HTTPS
  if ($_SERVER['HTTPS'] === 'OFF') {
    // Send redirect
    header('HTTP/1.0 301 Moved Permanently');
    header('Location: https://'. $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);
    // Name transaction "redirect" in New Relic for improved reporting (optional).
    if (extension_loaded('newrelic')) {
      newrelic_name_transaction("redirect");
    }
    exit();
  }

  // Reverse proxy configuration
  if (isset($_SERVER['REMOTE_ADDR']) && (in_array($_SERVER['REMOTE_ADDR'], $conf['reverse_proxy_addresses'], TRUE))) {
    // Domain masking:
    // Some sites on Pantheon share a common domain name (e.g. www.uoguelph.ca). Pantheon
    // refers to this as 'domain masking' and it is not officially supported. These sites
    // are forwarded through an Apache reverse proxy server. The original domain name of
    // the site is translated to the Pantheon platform URL. On the Pantheon side, Drupal
    // must be tricked into thinking it is running under the primary domain name from a
    // subdirectory. The general case is to rewrite the request URL to:
    // www.uoguelph.ca/{sitename}, but there are exceptions.
    // Every site on Pantheon has a "platform domain" derived from the site name and 
    // environment, ending in pantheonsite.io.
    $platform_domain = $env . '-' . $site . '.pantheonsite.io';

    // Site specific reverse proxy configuration. If a reverse proxy site does not
    // follow the https://www.uoguelph.ca/sitename pattern, override the reverse proxy
    // domain and path here.
    $proxy_conf = array(
      'a11yportal' => array('domain' => 'wellness.uoguelph.ca', 'path' => '/accessibility/portal'),
      'accessibilityweb' => array('path' => '/accessibility/web'),
      'ahl1' => array('path' => '/ahl'),
      'alliance1' => array('path' => '/alliance'),
      'arts1' => array('path' => '/arts'),
      'bioinformatics1' => array('path' => '/bioinformatics'),
      'business2' => array('path' => '/lang'),
      'cbspurchasing' => array('path' => '/cbs/purchasing'),
      'ccs1' => array('path' => '/ccs'),
      'ccsforms' => array('path' => '/ccs/forms'),
      'cecs' => array('domain' => 'www.recruitguelph.ca'),
      'cio1' => array('path' => '/cio'),
      'cip1' => array('path' => '/cip'),
      'counselling' => array('domain' => 'wellness.uoguelph.ca'),
      'cps1' => array('path' => '/cps'),
      'dhr1' => array('path' => '/diversity-human-rights'),
      'dunfield' => array('path' => '/crc/dunfield'),
      'engineering1' => array('path' => '/engineering'),
      'finance1' => array('path' => '/finance'),
      'fire1' => array('path' => '/fire'),
      'fsadmin' => array('path' => '/foodscience/fsadmin'),
      'fys' => array('path' => '/vpacademic/fys'),
      'graduatestudies' => array('domain' => 'graduatestudies.uoguelph.ca'),
      'graduatestudiesforms' => array('path' => '/graduatestudies/forms2'),
      'gsa1' => array('path' => '/gsa'),
      'hr1' => array('path' => '/hr'),
      'ib2' => array('path' => '/ib'),
      'international1' => array('path' => '/international'),
      'iqap' => array('path' => '/vpacademic/iqap'),
      'lvpo' => array('path' => '/finance/departments-services/purchasing-services/lvpo-forms'),
      'management1' => array('path' => '/management'),
      'mcs1' => array('path' => '/mcs'),
      'oac1' => array('path' => '/oac'),
      'police1' => array('path' => '/police'),
      'ppp1' => array('path' => '/vpacademic/ppp'),
      'psa1' => array('path' => '/psa'),
      'psychology1' => array('path' => '/psychology'),
      'realestate1' => array('path' => '/realestate'),
      'researchinnovation' => array('path' => '/research/innovation'),
      'sas1' => array('domain' => 'wellness.uoguelph.ca', 'path' => '/accessibility'),
      'ses1' => array('path' => '/ses'),
      'sws1' => array('domain' => 'wellness.uoguelph.ca'),
      'studentaffairs1' => array('path' => '/studentaffairs'),
      'sustainability1' => array('path' => '/sustainability'),
      'tutoring1' => array('path' => '/tutoring'),
    );

    // Domain masking is only required if the request comes from the proxy server and
    // the HTTP host matches the Pantheon platform URL.
    if ($_SERVER["HTTP_HOST"] === $platform_domain) {

      // Set default proxy domain and path
      if (!isset($proxy_conf[$site])) {
        $proxy_conf[$site] = array('domain' => 'www.uoguelph.ca', 'path' => '/' . $site);
      }

      // Use default proxy domain if none specified
      if (!isset($proxy_conf[$site]['domain'])) {
        $proxy_conf[$site]['domain'] = 'www.uoguelph.ca';
      }
      
      // Use default proxy path if none specified
      if (!isset($proxy_conf[$site]['path'])) {
        $proxy_conf[$site]['path'] = '/' . $site;
      }

      // Rewrite request URI.
      $_SERVER['REQUEST_URI'] = $proxy_conf[$site]['path'] . $_SERVER['REQUEST_URI'];

      // Set cookie domain.
      $cookie_domain = '.' . $proxy_conf[$site]['domain'];
      $cookie_path = $proxy_conf[$site]['path'];

      // Set Drupal base URL.
      $base_url = 'https://' . $proxy_conf[$site]['domain'] . $proxy_conf[$site]['path'];
    }

    // Single sign-on:
    // Oracle access manager sets the ca-uoguelph-user HTTP header with the user 
    // name of the currently logged in user. The Drupal LDAP SSO module expects
    // to find this value in the REMOTE_USER environment variable.
    if (isset($_SERVER['HTTP_CA_UOGUELPH_USER'])) {
      $_SERVER['REMOTE_USER'] = $_SERVER['HTTP_CA_UOGUELPH_USER'];
    }

    // Enable Drupal's reverse proxy features
    $conf['reverse_proxy'] = TRUE;

    // end of reverse proxy configuration
  } 

  // The reroute email module prevents emails from being sent from development and
  // test environments, and can optionally redirect all emails to a specific address.
  // Disable mail rerouting in live environments, enable it otherwise.
  $conf['reroute_email_enable'] = ($env === 'live' ? 0 : 1);

  // end of pantheon configuration
}

/**
 * Include a local settings file if it exists.
 *
 * Pantheon requires that settings.php be committed to version control.
 * If you are running a site locally using this upstream,
 * move your site configuration to `local.settings.php` and it will be included here.
 * Note that this only applies to the default site, multi-site settings are not affected.
 */
$local_settings = dirname(__FILE__) . '/local.settings.php';
if (file_exists($local_settings)) {
  include $local_settings;
}
