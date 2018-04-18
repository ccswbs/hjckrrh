<?php
/**
 * @file
 * ug_profile_workbench_moderation.features.workbench_email.inc
 */

/**
 * Implements hook_workbench_email_export().
 */
function ug_profile_workbench_moderation_workbench_email_export() {
  $items = array(
    'draft:needs_review:original author' => array(
      'from_name' => 'draft',
      'to_name' => 'needs_review',
      'author' => 1,
      'automatic' => 1,
      'subject' => 'Web content edits sent for review',
      'message' => 'Recent updates to your web content requires review. The website content publishers have been notified.',
      'role' => 'original author',
    ),
    'draft:needs_review:publisher' => array(
      'from_name' => 'draft',
      'to_name' => 'needs_review',
      'author' => 0,
      'automatic' => 1,
      'subject' => 'Web content edit: review required',
      'message' => 'Web content review required.
The following content author has requested a review of recent changes:

User: [current-user:name]
Author email: [current-user:mail]',
      'role' => 'publisher',
    ),
    'needs_review:published:original author' => array(
      'from_name' => 'needs_review',
      'to_name' => 'published',
      'author' => 1,
      'automatic' => 1,
      'subject' => 'Web content published',
      'message' => 'Your updates to the web content have been approved by [current-user:name].
The content moderators have published your content.',
      'role' => 'original author',
    ),
  );
  return $items;
}
