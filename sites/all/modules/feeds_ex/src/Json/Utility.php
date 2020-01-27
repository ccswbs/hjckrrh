<?php

/**
 * @file
 * Contains FeedsExJsonUtility.
 */

/**
 * Various helpers for handling JSON.
 */
class FeedsExJsonUtility {

  /**
   * Translates an error message.
   *
   * @param int $error
   *   The JSON error.
   *
   * @return string
   *   The JSON parsing error message.
   */
  public static function translateError($error) {
    // This shouldn't get called for PHP < 5.3.0.
    if (version_compare(PHP_VERSION, '5.3.0', '<')) {
      return 'Unknown error';
    }

    if (version_compare(PHP_VERSION, '5.3.3', '>=')) {
      switch ($error) {
        case JSON_ERROR_UTF8:
          return 'Malformed UTF-8 characters, possibly incorrectly encoded';
      }
    }

    if (version_compare(PHP_VERSION, '5.5.0', '>=')) {
      switch ($error) {
        case JSON_ERROR_RECURSION:
          return 'One or more recursive references in the value to be encoded';

        case JSON_ERROR_INF_OR_NAN:
          return 'One or more NAN or INF values in the value to be encoded';

        case JSON_ERROR_UNSUPPORTED_TYPE:
          return 'A value of a type that cannot be encoded was given';
      }
    }

    switch ($error) {
      case JSON_ERROR_NONE:
        return 'No error has occurred';

      case JSON_ERROR_DEPTH:
        return 'The maximum stack depth has been exceeded';

      case JSON_ERROR_STATE_MISMATCH:
        return 'Invalid or malformed JSON';

      case JSON_ERROR_CTRL_CHAR:
        return 'Control character error, possibly incorrectly encoded';

      case JSON_ERROR_SYNTAX:
        return 'Syntax error';

      default:
        return 'Unknown error';
    }
  }

  /**
   * Decodes a JSON string into an array.
   *
   * @param string $json
   *   A JSON string.
   *
   * @return array
   *   A PHP array.
   *
   * @throws RuntimeException
   *   Thrown if the encoded JSON does not result in an array.
   */
  public static function decodeJsonArray($json) {
    $parsed = drupal_json_decode($json);

    if (!is_array($parsed)) {
      throw new RuntimeException(t('The JSON is invalid.'));
    }

    return $parsed;
  }

  /**
   * Decodes a JSON string into an object or array.
   *
   * @param string $json
   *   A JSON string.
   *
   * @return object|array
   *   A PHP object or array.
   *
   * @throws RuntimeException
   *   Thrown if the encoded JSON does not result in an array or object.
   */
  public static function decodeJsonObject($json) {
    $parsed = json_decode($json);

    if (!is_array($parsed) && !is_object($parsed)) {
      throw new RuntimeException(t('The JSON is invalid.'));
    }

    return $parsed;
  }

  /**
   * Returns the path of the JSONPath library.
   *
   * @return string|false|array
   *   The root-relative path to the JSONPath include(s), or false on failure.
   */
  public static function jsonPathLibraryPath() {
    $libraries_path = module_exists('libraries') ? libraries_get_path('jsonpath') : FALSE;
    if ($libraries_path && is_dir($libraries_path)) {
      $path = $libraries_path;
    }
    elseif (is_dir(DRUPAL_ROOT . '/sites/all/libraries/jsonpath')) {
      $path = 'sites/all/libraries/jsonpath';
    }

    if (!isset($path)) {
      if (is_file(DRUPAL_ROOT . '/vendor/autoload.php')) {
        // This can exist when running tests on drupal.org.
        return 'vendor/autoload.php';
      }
      return FALSE;
    }

    // Newer forks of JSONPath are all modern and fancy with their autoloaders.
    if (is_file($path . '/vendor/autoload.php')) {
      return $path . '/vendor/autoload.php';
    }
    if (is_file($path . '/src/Peekmo/JsonPath/JsonStore.php')) {
      return array(
        $path . '/src/Peekmo/JsonPath/JsonStore.php',
        $path . '/src/Peekmo/JsonPath/JsonPath.php',
      );
    }
    // Old school. Look for multiple versions.
    $files = glob($path . '/jsonpath*.php');

    return $files ? reset($files) : FALSE;
  }

  /**
   * Determines if a JSONPath parser is installed.
   *
   * @return bool
   *   True if a parser is installed, false if not.
   */
  public static function jsonPathParserInstalled() {
    if (class_exists('Flow\JSONPath\JSONPath') || class_exists('Peekmo\JsonPath\JsonStore') || function_exists('jsonPath')) {
      return TRUE;
    }

    $path = self::jsonPathLibraryPath();
    if (!$path) {
      return FALSE;
    }

    if (is_array($path)) {
      foreach ($path as $subpath) {
        require_once DRUPAL_ROOT . '/' . $subpath;
      }
    }
    else {
      require_once DRUPAL_ROOT . '/' . $path;
    }

    return class_exists('Flow\JSONPath\JSONPath') || class_exists('Peekmo\JsonPath\JsonStore') || function_exists('jsonPath');
  }

  /**
   * Determines if a JMESPath parser is installed.
   *
   * @return bool
   *   True if a parser is installed, false if not.
   */
  public static function jmesPathParserInstalled() {
    if (class_exists('JmesPath\AstRuntime') || class_exists('JmesPath\Runtime\AstRuntime')) {
      return TRUE;
    }

    $path = feeds_ex_library_path('jmespath.php', 'vendor/autoload.php');
    if (!$path && is_file(DRUPAL_ROOT . '/vendor/autoload.php')) {
      // This can exist when running tests on drupal.org.
      $path = 'vendor/autoload.php';
    }
    if (!$path) {
      return FALSE;
    }

    require_once DRUPAL_ROOT . '/' . $path;

    return class_exists('JmesPath\AstRuntime') || class_exists('JmesPath\Runtime\AstRuntime');
  }

}
