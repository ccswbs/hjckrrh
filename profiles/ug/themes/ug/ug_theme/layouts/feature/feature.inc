<?php

// Plugin definition
$plugin = array(
  'title' => t('Four column (3:3:3:3)'),
  'category' => t('Responsive'),
  'icon' => 'feature.png',
  'theme' => 'feature',
  'css' => 'feature.css',
  'regions' => array(
    'top' => t('Top'),
    'first' => t('First column'),
    'second' => t('Second column'),
    'third' => t('Third column'),
    'fourth' => t('Fourth column'),
    'bottom' => t('Bottom')
  ),
);
