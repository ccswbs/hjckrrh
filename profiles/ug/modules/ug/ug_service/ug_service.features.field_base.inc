<?php
/**
 * @file
 * ug_service.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ug_service_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_service_audience'.
  $field_bases['field_service_audience'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_service_audience',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'service_audience',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_service_category'.
  $field_bases['field_service_category'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_service_category',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'service_category',
          'parent' => 0,
        ),
      ),
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_service_description'.
  $field_bases['field_service_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_service_description',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_service_icon'.
  $field_bases['field_service_icon'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_service_icon',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'asterisk' => 'asterisk',
        'plus' => 'plus',
        'euro' => 'euro',
        'minus' => 'minus',
        'cloud' => 'cloud',
        'envelope' => 'envelope',
        'pencil' => 'pencil',
        'glass' => 'glass',
        'music' => 'music',
        'search' => 'search',
        'heart' => 'heart',
        'star' => 'star',
        'star-empty' => 'star-empty',
        'user' => 'user',
        'film' => 'film',
        'th-large' => 'th-large',
        'th' => 'th',
        'th-list' => 'th-list',
        'ok' => 'ok',
        'remove' => 'remove',
        'zoom-in' => 'zoom-in',
        'zoom-out' => 'zoom-out',
        'off' => 'off',
        'signal' => 'signal',
        'cog' => 'cog',
        'trash' => 'trash',
        'home' => 'home',
        'file' => 'file',
        'time' => 'time',
        'road' => 'road',
        'download-alt' => 'download-alt',
        'download' => 'download',
        'upload' => 'upload',
        'inbox' => 'inbox',
        'play-circle' => 'play-circle',
        'repeat' => 'repeat',
        'refresh' => 'refresh',
        'list-alt' => 'list-alt',
        'lock' => 'lock',
        'flag' => 'flag',
        'headphones' => 'headphones',
        'volume-off' => 'volume-off',
        'volume-down' => 'volume-down',
        'volume-up' => 'volume-up',
        'qrcode' => 'qrcode',
        'barcode' => 'barcode',
        'tag' => 'tag',
        'tags' => 'tags',
        'book' => 'book',
        'bookmark' => 'bookmark',
        'print' => 'print',
        'camera' => 'camera',
        'font' => 'font',
        'bold' => 'bold',
        'italic' => 'italic',
        'text-height' => 'text-height',
        'text-width' => 'text-width',
        'align-left' => 'align-left',
        'align-center' => 'align-center',
        'align-right' => 'align-right',
        'align-justify' => 'align-justify',
        'list' => 'list',
        'indent-left' => 'indent-left',
        'indent-right' => 'indent-right',
        'facetime-video' => 'facetime-video',
        'picture' => 'picture',
        'map-marker' => 'map-marker',
        'adjust' => 'adjust',
        'tint' => 'tint',
        'edit' => 'edit',
        'share' => 'share',
        'check' => 'check',
        'move' => 'move',
        'step-backward' => 'step-backward',
        'fast-backward' => 'fast-backward',
        'backward' => 'backward',
        'play' => 'play',
        'pause' => 'pause',
        'stop' => 'stop',
        'forward' => 'forward',
        'fast-forward' => 'fast-forward',
        'step-forward' => 'step-forward',
        'eject' => 'eject',
        'chevron-left' => 'chevron-left',
        'chevron-right' => 'chevron-right',
        'plus-sign' => 'plus-sign',
        'minus-sign' => 'minus-sign',
        'remove-sign' => 'remove-sign',
        'ok-sign' => 'ok-sign',
        'question-sign' => 'question-sign',
        'info-sign' => 'info-sign',
        'screenshot' => 'screenshot',
        'remove-circle' => 'remove-circle',
        'ok-circle' => 'ok-circle',
        'ban-circle' => 'ban-circle',
        'arrow-left' => 'arrow-left',
        'arrow-right' => 'arrow-right',
        'arrow-up' => 'arrow-up',
        'arrow-down' => 'arrow-down',
        'share-alt' => 'share-alt',
        'resize-full' => 'resize-full',
        'resize-small' => 'resize-small',
        'exclamation-sign' => 'exclamation-sign',
        'gift' => 'gift',
        'leaf' => 'leaf',
        'fire' => 'fire',
        'eye-open' => 'eye-open',
        'eye-close' => 'eye-close',
        'warning-sign' => 'warning-sign',
        'plane' => 'plane',
        'calendar' => 'calendar',
        'random' => 'random',
        'comment' => 'comment',
        'magnet' => 'magnet',
        'chevron-up' => 'chevron-up',
        'chevron-down' => 'chevron-down',
        'retweet' => 'retweet',
        'shopping-cart' => 'shopping-cart',
        'folder-close' => 'folder-close',
        'folder-open' => 'folder-open',
        'resize-vertical' => 'resize-vertical',
        'resize-horizontal' => 'resize-horizontal',
        'hdd' => 'hdd',
        'bullhorn' => 'bullhorn',
        'bell' => 'bell',
        'certificate' => 'certificate',
        'thumbs-up' => 'thumbs-up',
        'thumbs-down' => 'thumbs-down',
        'hand-right' => 'hand-right',
        'hand-left' => 'hand-left',
        'hand-up' => 'hand-up',
        'hand-down' => 'hand-down',
        'circle-arrow-right' => 'circle-arrow-right',
        'circle-arrow-left' => 'circle-arrow-left',
        'circle-arrow-up' => 'circle-arrow-up',
        'circle-arrow-down' => 'circle-arrow-down',
        'globe' => 'globe',
        'wrench' => 'wrench',
        'tasks' => 'tasks',
        'filter' => 'filter',
        'briefcase' => 'briefcase',
        'fullscreen' => 'fullscreen',
        'dashboard' => 'dashboard',
        'paperclip' => 'paperclip',
        'heart-empty' => 'heart-empty',
        'link' => 'link',
        'phone' => 'phone',
        'pushpin' => 'pushpin',
        'usd' => 'usd',
        'gbp' => 'gbp',
        'sort' => 'sort',
        'sort-by-alphabet' => 'sort-by-alphabet',
        'sort-by-alphabet-alt' => 'sort-by-alphabet-alt',
        'sort-by-order' => 'sort-by-order',
        'sort-by-order-alt' => 'sort-by-order-alt',
        'sort-by-attributes' => 'sort-by-attributes',
        'sort-by-attributes-alt' => 'sort-by-attributes-alt',
        'unchecked' => 'unchecked',
        'expand' => 'expand',
        'collapse-down' => 'collapse-down',
        'collapse-up' => 'collapse-up',
        'log-in' => 'log-in',
        'flash' => 'flash',
        'log-out' => 'log-out',
        'new-window' => 'new-window',
        'record' => 'record',
        'save' => 'save',
        'open' => 'open',
        'saved' => 'saved',
        'import' => 'import',
        'export' => 'export',
        'send' => 'send',
        'floppy-disk' => 'floppy-disk',
        'floppy-saved' => 'floppy-saved',
        'floppy-remove' => 'floppy-remove',
        'floppy-save' => 'floppy-save',
        'floppy-open' => 'floppy-open',
        'credit-card' => 'credit-card',
        'transfer' => 'transfer',
        'cutlery' => 'cutlery',
        'header' => 'header',
        'compressed' => 'compressed',
        'earphone' => 'earphone',
        'phone-alt' => 'phone-alt',
        'tower' => 'tower',
        'stats' => 'stats',
        'sd-video' => 'sd-video',
        'hd-video' => 'hd-video',
        'subtitles' => 'subtitles',
        'sound-stereo' => 'sound-stereo',
        'sound-dolby' => 'sound-dolby',
        'sound-5-1' => 'sound-5-1',
        'sound-6-1' => 'sound-6-1',
        'sound-7-1' => 'sound-7-1',
        'copyright-mark' => 'copyright-mark',
        'registration-mark' => 'registration-mark',
        'cloud-download' => 'cloud-download',
        'cloud-upload' => 'cloud-upload',
        'tree-conifer' => 'tree-conifer',
        'tree-deciduous' => 'tree-deciduous',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_service_keywords'.
  $field_bases['field_service_keywords'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_service_keywords',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'service_keywords',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_service_price'.
  $field_bases['field_service_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_service_price',
    'field_permissions' => array(
      'type' => 2,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 100,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_service_private'.
  $field_bases['field_service_private'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_service_private',
    'field_permissions' => array(
      'type' => 2,
    ),
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_service_private_content'.
  $field_bases['field_service_private_content'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_service_private_content',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_service_private_heading'.
  $field_bases['field_service_private_heading'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_service_private_heading',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'service_private_heading',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_service_public'.
  $field_bases['field_service_public'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_service_public',
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_service_public_content'.
  $field_bases['field_service_public_content'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_service_public_content',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_service_public_heading'.
  $field_bases['field_service_public_heading'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_service_public_heading',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'service_public_heading',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_service_related'.
  $field_bases['field_service_related'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_service_related',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'service' => 'service',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
