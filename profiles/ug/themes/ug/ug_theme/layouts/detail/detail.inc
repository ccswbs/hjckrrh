<?php

// Plugin definition
$plugin = array(
  'title' => t('Three column (3:6:3)'),
  'category' => t('Responsive'),
  'icon' => 'detail.png',
  'theme' => 'detail',
  'css' => 'detail.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left column'),
    'centre' => t('Middle column'),
    'right' => t('Right column'),
    'bottom' => t('Bottom')
  ),
);
