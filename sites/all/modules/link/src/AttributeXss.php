<?php

/**
 * Defines a class for attribute XSS filtering.
 */
class AttributeXss {

  /**
   * Filters attributes.
   *
   * @param string $attributes
   *   Rendered attribute string, e.g. 'class="foo bar"'.
   */
  private static function attributes($attributes) {
    $attributes_array = array();
    $mode = 0;
    $attribute_name = '';
    $skip = FALSE;
    $skip_protocol_filtering = FALSE;

    while (strlen($attributes) != 0) {
      // Was the last operation successful?
      $working = 0;

      switch ($mode) {
        case 0:
          // Attribute name, href for instance.
          if (preg_match('/^([-a-zA-Z][-a-zA-Z0-9]*)/', $attributes, $match)) {
            $attribute_name = strtolower($match[1]);
            $skip = (
              $attribute_name == 'style' ||
              strncmp($attribute_name, 'on', 2) === 0 ||
              strncmp($attribute_name, '-', 1) === 0 ||
              // Ignore long attributes to avoid unnecessary processing
              // overhead.
              strlen($attribute_name) > 96
            );

            // Values for attributes of type URI should be filtered for
            // potentially malicious protocols (for example, an href-attribute
            // starting with "javascript:"). However, for some non-URI
            // attributes performing this filtering causes valid and safe data
            // to be mangled. We prevent this by skipping protocol filtering on
            // such attributes.
            // @see drupal_strip_dangerous_protocols()
            // @see http://www.w3.org/TR/html4/index/attributes.html
            $skip_protocol_filtering = (strpos($attribute_name, 'data-') === 0) || in_array($attribute_name, array(
              'title',
              'alt',
              'rel',
              'property',
              'class',
              'datetime',
            ));

            $working = $mode = 1;
            $attributes = preg_replace('/^[-a-zA-Z][-a-zA-Z0-9]*/', '', $attributes);
          }
          break;

        case 1:
          // Equals sign or valueless ("selected").
          if (preg_match('/^\s*=\s*/', $attributes)) {
            $working = 1;
            $mode = 2;
            $attributes = preg_replace('/^\s*=\s*/', '', $attributes);
            break;
          }

          if (preg_match('/^\s+/', $attributes)) {
            $working = 1;
            $mode = 0;
            if (!$skip) {
              $attributes_array[$attribute_name] = $attribute_name;
            }
            $attributes = preg_replace('/^\s+/', '', $attributes);
          }
          break;

        case 2:
          // Once we've finished processing the attribute value continue to look
          // for attributes.
          $mode = 0;
          $working = 1;
          // Attribute value, a URL after href= for instance.
          if (preg_match('/^"([^"]*)"(\s+|$)/', $attributes, $match)) {
            $value = $skip_protocol_filtering ? $match[1] : drupal_strip_dangerous_protocols($match[1]);

            if (!$skip) {
              $attributes_array[$attribute_name] = $value;
            }
            $attributes = preg_replace('/^"[^"]*"(\s+|$)/', '', $attributes);
            break;
          }

          if (preg_match("/^'([^']*)'(\s+|$)/", $attributes, $match)) {
            $value = $skip_protocol_filtering ? $match[1] : drupal_strip_dangerous_protocols($match[1]);

            if (!$skip) {
              $attributes_array[$attribute_name] = $value;
            }
            $attributes = preg_replace("/^'[^']*'(\s+|$)/", '', $attributes);
            break;
          }

          if (preg_match("%^([^\s\"']+)(\s+|$)%", $attributes, $match)) {
            $value = $skip_protocol_filtering ? $match[1] : drupal_strip_dangerous_protocols($match[1]);

            if (!$skip) {
              $attributes_array[$attribute_name] = $value;
            }
            $attributes = preg_replace("%^[^\s\"']+(\s+|$)%", '', $attributes);
          }
          break;
      }

      if ($working == 0) {
        // Not well-formed; remove and try again.
        $attributes = preg_replace('/
          ^
          (
          "[^"]*("|$)     # - a string that starts with a double quote, up until the next double quote or the end of the string
          |               # or
          \'[^\']*(\'|$)| # - a string that starts with a quote, up until the next quote or the end of the string
          |               # or
          \S              # - a non-whitespace character
          )*              # any number of the above three
          \s*             # any number of whitespaces
          /x', '', $attributes);
        $mode = 0;
      }
    }

    // The attribute list ends with a valueless attribute like "selected".
    if ($mode == 1 && !$skip) {
      $attributes_array[$attribute_name] = $attribute_name;
    }
    return $attributes_array;
  }

  /**
   * Sanitizes attributes.
   *
   * @param array $attributes
   *   Attribute values as key => value format. Value may be a string or in the
   *   case of the 'class' attribute, an array.
   *
   * @return array
   *   Sanitized attributes.
   */
  public static function sanitizeAttributes(array $attributes) {
    $new_attributes = array();
    foreach ($attributes as $name => $value) {
      $safe = AttributeXss::attributes($name . '="' . $value . '"');
      if (count($safe) > 0 && array_key_exists($name, $safe)) {
        $new_attributes[$name] = $safe[$name];
      }
    }

    return $new_attributes;
  }

}
