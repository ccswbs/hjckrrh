# Image Resize

## CONTENTS OF THIS FILE

  * Introduction
  * Requirements
  * Installation
  * Configuration
  * Author

## INTRODUCTION

Before downloading and using this module please read the next lines carefully.
This module has a very specific use case. You should not use it to resize images
that are managed by Drupal. If your content type or taxonomy vocabulary has an
image field, then images you upload to the nodes or terms of this type are most
likely managed by Drupal.

Use this module if your images are not managed by Drupal. Lets say that for some
reason you are loading images directly in templates, based on some file path
pattern, then these images "live" outside of Drupal. This usually happens when
you migrate from some other system and your images have a specific names, so you
can load them directly in template. "Image resize" will only resize images in a
specified folder, and it won't modify any table in your database.

## REQUIREMENTS

Minimum PHP 5.5.0

## INSTALLATION

1. Install module as usual via Drupal UI or Drush.
2. Go to "Modules" and enable the "Image Resize" module.

## CONFIGURATION

1. Go to the module settings '/admin/config/media/image-resize/settings' page
and set options for resizing you images.
2. Go to the '/admin/config/media/image-resize' page and start resizing images.

### AUTHOR

Goran Nikolovski  
Website: http://gorannikolovski.com  
Drupal: https://www.drupal.org/u/gnikolovski  
Email: nikolovski84@gmail.com  

Company: Studio Present, Subotica, Serbia  
Website: http://www.studiopresent.com  
Drupal: https://www.drupal.org/studio-present  
Email: info@studiopresent.com  
