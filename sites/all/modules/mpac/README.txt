
-- SUMMARY --

"Multi path autocomplete" helps anyone who creates menu items on
admin/build/menu/*/add to enter the path to nodes.
It changes the input field for the menu path to an autocomplete text field so
you can simply enter the title of the node and will get a list with all
matching values. If you select one of them its path will be placed into the
textfield.

If path.module is enabled autocomplete is working for URL aliases, too.


For a full description of the module, visit the project page:
  http://drupal.org/project/mpac

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/mpac


-- REQUIREMENTS --

None.


-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.


-- DEVELOPER NOTES --

You can alter the list of results by using hook_mpac_autocomplete_paths().
Example:
<code><?php
function MODULENAME_mpac_autocomplete_paths_alter(&$matches, $title) {
  $matches['custom/path/1'] = t('My custom autocomplete result');
}
?></code>


-- CONTACT --

Current maintainers:
* Stefan Borchert (stborchert) - http://drupal.org/user/36942
