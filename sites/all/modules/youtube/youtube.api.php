<?php

/**
 * @file
 * Hooks provided by the YouTube Field module.
 */

/**
 * Alter the link types in the YouTube Thumbnail formatter's display settings.
 *
 * Useful when linking a YouTube Thumbnail to something other than the content
 * or YouTube video, such as opening the video in a modal window.
 *
 * @param array $link_types
 *   An array of options to link a thumbnail to. The array items' keys are the
 *   machine names and values are the readable names.
 */
function hook_youtube_thumbnail_link_types_alter(&$link_types) {
  // See youtube_colorbox_youtube_thumbnail_link_types_alter() within the
  // YouTube Colorbox module for example usage.
}

/**
 * Alter the field display settings for the YouTube Thumbnail formatter.
 *
 * Useful to add settings to a custom link type added with
 * hook_youtube_thumbnail_link_types_alter().
 *
 * @param array $element
 *   The field formatter form to add settings to.
 * @param array $instance
 *   The instance of the field being formatted.
 * @param array $settings
 *   Existing form settings.
 * @param string $field_name
 *   The machine name of the field.
 */
function hook_youtube_thumbnail_field_formatter_settings_alter(&$element, $instance, $settings, $field_name) {
  // See youtube_colorbox_youtube_thumbnail_field_formatter_settings_alter()
  // within the YouTube Colorbox module for example usage.
}

/**
 * Alter a linked thumbnail's uri.
 *
 * Useful to define what a thumbnail should link to for a link type added with
 * hook_youtube_thumbnail_link_types_alter().
 *
 * @param array $uri
 *   The current uri array. Contains the keys:
 *   - 'path': The link path, as eventually passed to l().
 *   - 'options': The link options, as eventually passed to l().
 * @param array $settings
 *   The field item's display settings.
 * @param array $item
 *   The field item to provide the link for.
 */
function hook_youtube_thumbnail_link_uri_alter(&$uri, &$settings, $item) {
  // See youtube_colorbox_youtube_thumbnail_link_uri_alter() within the
  // YouTube Colorbox module for example usage.
}
