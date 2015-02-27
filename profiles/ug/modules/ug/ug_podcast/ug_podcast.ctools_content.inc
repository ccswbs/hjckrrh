<?php
/**
 * @file
 * ug_podcast.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function ug_podcast_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'podcast';
  $content->admin_title = 'Podcast';
  $content->admin_description = '';
  $content->category = 'UG';
  $content->settings = array(
    'admin_title' => '',
    'title' => 'Podcast',
    'body' => '<iframe title="soundcloud" class="embed-responsive-item" src="https://w.soundcloud.com/player/?url=https%3A//api.soundcloud.com/tracks/181654772&amp;color=ff5500&amp;auto_play=false&amp;hide_related=false&amp;show_comments=true&amp;show_user=true&amp;show_reposts=false"></iframe>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $export['podcast'] = $content;

  return $export;
}
