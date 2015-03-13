<?php

// Plugin definition
$plugin = array(
  'title' => t('Two column (8:4)'),
  'category' => t('Responsive'),
  'icon' => 'aside.png',
  'theme' => 'aside',
  'css' => 'aside.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left side'),
    'right' => t('Right side'),
    'bottom' => t('Bottom')
  ),
);
