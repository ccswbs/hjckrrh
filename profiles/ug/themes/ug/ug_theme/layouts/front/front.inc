<?php

// Plugin definition
$plugin = array(
  'title' => t('Three column (4:4:4)'),
  'category' => t('Responsive'),
  'icon' => 'front.png',
  'theme' => 'front',
  'css' => 'front.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left column'),
    'middle' => t('Middle column'),
    'right' => t('Right column'),
    'bottom' => t('Bottom')
  ),
);
