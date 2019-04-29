CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Requirements
 * Similar modules
 * Known conflicts
 * Installation
 * Configuration
 * Maintainers


INTRODUCTION
------------

This module allows you to restrict access of menu items per roles.


REQUIREMENTS
------------

There is no special requirement for this module.


SIMILAR MODULES
---------------

 * Menu Admin per Menu (https://www.drupal.org/project/menu_admin_per_menu):
   By default, Drupal allows only users with "administrer menu permission" to
   add, modify or delete menu items. In case you want for instance to let
   certain users manage primary links or secondary links but not navigation
   menu, this module provides this functionality.
 * Menu item visibility (https://www.drupal.org/project/menu_item_visibility):
   Does the same thing as Menu per role.


KNOWN CONFLICTS
---------------

 * Menu token (https://www.drupal.org/project/menu_token): Menu token erase the
   access result of Menu per role, see https://www.drupal.org/node/2044963


INSTALLATION
------------

Once enabled, go to the global settings of the module to configure the module.


CONFIGURATION
-------------

Global settings: /admin/config/system/menu_per_role

Just activate the Menu per Role module and edit a menu item as usual. There will
be one or two fieldsets, depending on the configuration of the module, that
allows you to restrict access by role.

If you don't check any roles the default access permissions will be kept.
Otherwise the module will additionally restrict access to the chosen user roles.


MAINTAINERS
-----------

Current maintainers:
 * Daniel Wehner (dawehner) - https://www.drupal.org/user/99340
 * Florent Torregrosa (Grimreaper) - https://www.drupal.org/user/2388214

Previous maintainers:
 * Wolfgang Ziegler (fago) - https://www.drupal.org/user/16747
 * AlexisWilke (AlexisWilke) - https://www.drupal.org/user/356197

This project has been sponsored by:
 * Made to Order Software Corporation - https://www.m2osw.com
