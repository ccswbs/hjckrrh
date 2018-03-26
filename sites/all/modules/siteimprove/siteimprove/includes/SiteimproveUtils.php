<?php

/**
 * @file
 * Utils for Siteimprove Plugin.
 */

/**
 * Class SiteimproveUtils.
 */
class SiteimproveUtils {

  const TOKEN_REQUEST_URL = 'https://my2.siteimprove.com/auth/token';
  const JS_LIBRARY_URL = 'https://cdn.siteimprove.net/cms/overlay.js';

  /**
   * Return Siteimprove token.
   */
  static public function requestToken() {

    // Request new token.
    $headers = array('Accept' => 'application/json');
    $result = drupal_http_request(self::TOKEN_REQUEST_URL, array('headers' => $headers));

    // If success, set token field with the new token.
    if ($result->code == 200) {
      $json = json_decode($result->data);
      if (!empty($json->token)) {
        return $json->token;
      }
    }

    watchdog('siteimprove', 'There was an error requesting a new token.', array(), WATCHDOG_ERROR);
    return FALSE;
  }

  /**
   * Include all Siteimprove js scripts.
   *
   * @param string $url
   *   Url.
   * @param string $type
   *   Action: recheck|input|recrawl|domain.
   * @param bool $auto
   *   Automatic calling to the defined method.
   */
  static public function includeJs($url, $type, $auto = TRUE) {
    // Add Siteimprove JS.
    drupal_add_js(self::JS_LIBRARY_URL, 'external');
    // Add url and token to the JS settings.
    drupal_add_js(array(
      'siteimprove' => array(
        $type => array(
          'auto' => $auto,
          'url' => $url,
        ),
        'token' => variable_get('siteimprove_token'),
      ),
    ), 'setting');
    // Include custom JS.
    drupal_add_js(drupal_get_path('module', 'siteimprove') . '/js/siteimprove.js');
  }

  /**
   * Save URL in session.
   *
   * @param object $object
   *   Node or taxonomy term entity object.
   * @param string $id
   *   Name of identifier field:
   *     - nid: Node id.
   *     - tid: Taxonomy term id.
   * @param string $path
   *   Internal path of entity:
   *     - node/: Node path.
   *     - taxonomy/term/: Taxonomy term path.
   */
  static public function setSessionUrl($object, $id, $path) {
    // Check if user has access.
    if (user_access(SITEIMPROVE_PERMISSION_USE)) {
      // Get friendly url of node and save in SESSION.
      $url = url($path . $object->{$id}, array('absolute' => TRUE));
      $_SESSION['siteimprove_url'][] = $url;
    }
  }

}
