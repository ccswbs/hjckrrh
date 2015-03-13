<?php

// Plugin definition
$plugin = array(
  'title' => t('Two column (4:8)'),
  'category' => t('Responsive'),
  'icon' => 'news.png',
  'theme' => 'news',
  'css' => 'news.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left side'),
    'right' => t('Right side'),
    'bottom' => t('Bottom')
  ),
);
