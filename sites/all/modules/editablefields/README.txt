
-- DESCRIPTION --

This is the Drupal 7 port of the Editable Fields module. It is still a work in
progress, but the current version is seriously streamlined.

The Editable Fields module allows node fields to be edited on a node's display
(e.g. at node/123), not just on the node edit pages (e.g. node/123/edit).
It also works within views allowing you to edit multiple nodes on a single page.
Anywhere a formatter can be selected, you can select "Editable".


-- CONFIGURATION --

The module does not have its own configuration page or permissions. People
without edit permission for a particular node, will just see the default
display.

* To make one or more fields of a content type editable,
  go to "Structure >Content types", and click "manage display" for that
  content type. For a field to be editable, choose "Editable" from the
  format drop-down select box. This will make the field editable anywhere the
  node is displayed (also in views displaying teasers or full content).

* To make a view with editable fields, you don't need to do the previous step.
  Create a view and add some fields to it. On the settings page for each field,
  choose "Editable" from the "Formatter" select box.

NOTE: The title of a node is not a field in Drupal. However, with the Title
module (http://drupal.org/project/title) you can turn it into one, and thus make
it editable too.

-- KNOWN PROBLEMS --

* the 'feature' in the drupal 5 version of this module that allowed a form to be
  added to the bottom of a view no longer exists - that should be covered by
  other modules, not this one.

* This is a development version which may still have several bugs. See
  the issue queue for updated information
