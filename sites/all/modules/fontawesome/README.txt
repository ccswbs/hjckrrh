
CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation
 * Credits


INTRODUCTION 7.x-3.x version
------------
Font Awesome (http://fontawesome.com) is the web's most popular icon set and
toolkit. This release of the Font Awesome Icons module supports Font Awesome
versions higher than 5.0. For older versions of Font Awesome, you should
download and install Font Awesome Icons 7.x-2.x. See the Font Awesome Icons
page on Drupal.org for more information.

"fontawesome" provides integration of "Font Awesome" with Drupal. Once enabled
"Font Awesome" icon fonts could be used as:

1. Directly inside of any HTML (node/block/view/panel). Inside HTML you can
   place Font Awesome icons just about anywhere with an <i> tag.

   Example for an info icon: <i class="fas fa-camera-retro"></i>

   See more examples of using "Font Awesome" within HTML at:
   https://fontawesome.com/how-to-use/svg-with-js


INSTALLATION
------------

1. Using Drush 8 (http://docs.drush.org/en/8.x/install/#drupal-compatibility)

    $ drush en fontawesome

    Upon enabling, this will also attempt to download and install the library
    in "sites/all/libraries/fontawesome". If, for whatever reason, this process
    fails, you can re-run the library install manually by first clearing Drush
    caches:

    $ drush cc drush

    and then using another drush command:-

    $ drush fa-download

2. Manually

    a. Install the "Font Awesome" library following one of these 2 options:
       - run "drush fa-download" (recommended, it will download the right
         package and extract it at the right place for you.)
       - manual install: Download & extract "Font Awesome"
         (http://fontawesome.com) and place inside
         "sites/all/libraries/fontawesome" directory. The JS file should
         be at sites/all/libraries/fontawesome/js/all.js
         Direct link for downloading latest version (current is v5.4.1) is:
         https://use.fontawesome.com/releases/v5.4.1/fontawesome-free-5.4.1-web.zip
    b. Enable the module at Administer >> Modules.


USAGE
_____
Font Awesome can be used in many ways - you can manually insert Font Awesome
tags wherever you see fit after enabling the module, but there are other ways
as well. See
  https://fontawesome.com/how-to-use/on-the-web/setup/getting-started?using=svg-with-js
for information on basic usage.

CSS Pseudo-elements - if you are using the older version of Font Awesome, CSS
with webfonts, you can use CSS Pseudo-elements for inserting your icons rather
than the default method. See
  https://fontawesome.com/how-to-use/on-the-web/advanced/css-pseudo-elements
for more information on how to add the icons through CSS.


CREDITS
-------
* Rob Loach (RobLoach) http://robloach.net
* Inder Singh (inders) http://indersingh.com | https://www.drupal.org/u/inders
* Mark Carver https://www.drupal.org/u/mark-carver
* Brian Gilbert https://drupal.org/u/realityloop
* Daniel Moberly https://drupal.org/u/danielmoberly
* Truls S. Yggeseth https://drupal.org/u/truls1502
