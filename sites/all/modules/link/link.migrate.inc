<?php

/**
 * @file
 * Support for migrate module.
 *
 * With Migrate 2.4 or later, you can use the subfield syntax to set the title
 * and attributes:
 *
 * @code
 * $this->addFieldMapping('field_my_link', 'source_url');
 * $this->addFieldMapping('field_my_link:title', 'source_title');
 * $this->addFieldMapping('field_my_link:attributes', 'source_attributes');
 *
 * # With earlier versions of Migrate, you must pass an arguments array:
 *
 * $link_args = array(
 *   'title' => array('source_field' => 'source_title'),
 *   'attributes' => array('source_field' => 'source_attributes'),
 * );
 * $this->addFieldMapping('field_my_link', 'source_url')
 *      ->arguments($link_args);
 * @endcode
 */

if (!class_exists('MigrateFieldHandler')) {
  return;
}

/**
 * Implements hook_migrate_api().
 */
function link_migrate_api() {
  return array(
    'api' => 2,
    'field handlers' => array('MigrateLinkFieldHandler'),
  );
}

// @codingStandardsIgnoreLine
class MigrateLinkFieldHandler extends MigrateFieldHandler {

  /**
   * Construct.
   */
  public function __construct() {
    $this->registerTypes(array('link_field'));
  }

  /**
   * Arguments.
   */
  public static function arguments($title = NULL, $attributes = NULL, $language = NULL) {
    $arguments = array();
    if (!is_null($title)) {
      $arguments['title'] = $title;
    }
    if (!is_null($attributes)) {
      $arguments['attributes'] = $attributes;
    }
    if (!is_null($language)) {
      $arguments['language'] = $language;
    }
    return $arguments;
  }

  /**
   * Implementation of MigrateFieldHandler::fields().
   *
   * @param array $type
   *   The field type.
   * @param array $instance
   *   Instance info for the field.
   * @param Migration $migration
   *   The migration context for the parent field. We can look at the mappings
   *   and determine which subfields are relevant.
   *
   * @return array
   *   Array with values.
   *
   * @codingStandardsIgnoreStart
   */
  public function fields($type, $instance, $migration = NULL) {
    // @codingStandardsIgnoreEnd
    return array(
      'title' => t('Subfield: The link title attribute'),
      'attributes' => t('Subfield: The attributes for this link'),
      'language' => t('Subfield: The language for the field'),
    );
  }

  /**
   * Prepare.
   */
  public function prepare($entity, array $field_info, array $instance, array $values) {
    if (isset($values['arguments'])) {
      $arguments = $values['arguments'];
      unset($values['arguments']);
    }
    else {
      $arguments = array();
    }

    $language = $this->getFieldLanguage($entity, $field_info, $arguments);

    // URLs are numeric array elements, keyed by delta. As those elements don't
    // exist for empty URLs they are allowed and it's up to the developer what
    // data to migrate, add elements for those URLs up to the maximum delta
    // found.
    //
    // First of all, determine the maximum delta from non-empty URLs.
    $max_delta = max(array_merge(array(0), array_map('intval', array_keys($values))));

    // Next, determine the max delta from arguments.
    foreach ($arguments as $key => $value) {
      if (is_array($value)) {
        $max_delta = max($max_delta, max(array_map('intval', array_keys($value))));
      }
    }

    // Finally, add missing elements for empty URLs.
    for ($delta = 0; $delta <= $max_delta; $delta++) {
      if (!isset($values[$delta])) {
        $values[$delta] = '';
      }
    }

    foreach ($values as $delta => $value) {
      $item = array();
      if (isset($arguments['title'])) {
        if (!is_array($arguments['title'])) {
          $item['title'] = $arguments['title'];
        }
        elseif (isset($arguments['title'][$delta])) {
          $item['title'] = $arguments['title'][$delta];
        }
      }
      if (isset($arguments['attributes'])) {
        if (is_array($arguments['attributes']) && isset($arguments['attributes'][$delta])) {
          $item['attributes'] = $arguments['attributes'][$delta];
        }
        else {
          $item['attributes'] = $arguments['attributes'];
        }
      }
      $item['url'] = $value;

      if (is_array($language)) {
        $current_language = $language[$delta];
      }
      else {
        $current_language = $language;
      }
      $return[$current_language][$delta] = $item;
    }

    return isset($return) ? $return : NULL;
  }

}
