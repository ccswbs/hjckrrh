<?php

/**
 * @file
 * API documentation and examples for the Search and Replace Scanner module.
 */

/**
 * Allow additional arguments to be added to the 'or' query.
 *
 * @param db_or $or
 *   The 'or' argument for the main query.
 * @param string $table
 *   The table being queried.
 * @param string $field
 *   The field being queried.
 * @param string $where
 *   Something
 * @param bool $binary
 *   If this is querying a binary field, will contain the string ' BINARY'.
 */
function hook_scanner_query_where(&$or, $table, $field, $where, $binary) {
}

/**
 * Allow the full query to be adjusted.
 *
 * @param SelectQuery $query
 *   The query being executed.
 * @param array $map
 *   The map of fields.
 * @param string $table
 *   The table being queried.
 * @param string $field
 *   The field being queried.
 */
function hook_scanner_query_alter(&$query, $map, $table, $field) {
}

/**
 * Wrapper for preg_match_all() to allow customizations at the field level.
 *
 * @param array $matches
 *   Expected to be passed to preg_match_all() as the third argument.
 * @param string $regextr
 *   The regular expression being used for the query.
 * @param object $row
 *   The results row from the search process.
 *
 * @return int
 *   The number of matches found in this check.
 */
function hook_scanner_preg_match_all(&$matches, $regexstr, $row) {
}

/**
 * Wrapper for preg_replace() to allow customizations at the field level.
 *
 * @param object $node
 *   The full node object being modified. Changes are expected to be made
 *   directly to the node.
 * @param string $field
 *   The field being modified.
 * @param array $matches
 *   Expected to be passed to preg_replace() as the third argument.
 * @param string $regextr
 *   The regular expression being used for the query.
 * @param object $row
 *   The results row from the search process.
 * @param string $replace
 *   The new string being replaced into the $node based upon what is identified
 *   in $matches.
 * @param string $suffix
 *   The
 *
 * @return int
 *   The number of items replaced.
 */
function hook_scanner_preg_replace(&$node, $field, $matches, $row, $regexstr, $replace, $suffix) {
}

/**
 * Indicate which simple field types are supported.
 *
 * Only works with simple field types, complex field types, which require
 * related entities, etc may need to implement hook_scanner_fields_alter().
 *
 * @return array
 *   The list of simple text field types which are supported.
 *
 * @see hook_scanner_fields_alter().
 */
function hook_scanner_field_types() {
  return array('text');
}

/**
 * Allow the list of supported fields to be extended.
 *
 * This function will search recursively down any level of field collection
 * nesting to find all text fields. Note that if a field collection is nested
 * within itself, this function will not traverse the field collection a second
 * time (which would otherwise result in infinite recusion).
 *
 * @param array $all_field_records
 *   Array of field records curerntly being built.
 * @param string $node_bundle
 *   The name of the node type being searched. Initially passed in as NULL b/c
 *   the first time this function runs it finds all "top level" field
 *   collections, which can be across multiple node types. For each field
 *   collection instance found, however, if there are field collections inside
 *   of it we call this function recursively to find more fields. On that
 *   recursive call, we pass in the node type where the top level field
 *   collection was found so that we have the appropriate node type to add to
 *   the text field records added to $all_field_records.
 * @param string $parent_bundle
 *   The bundle in which we are currently searching for field collections.
 *   Initially passed in as NULL b/c the first time this function runs it finds
 *   all "top level" field collections, which can be across multiple node types
 *   (a.k.a. bundles). For each field collection instance found, however, if
 *   there are field collections inside of it we call this function recursively
 *   to find more fields. On that recursive call, we pass in the bundle of the
 *   current field collection being searched so that the query in the recursive
 *   call can search for fields within that bundle.
 * @param array $parents
 *   An array tracking all field collection parents for text fields we
 *   eventually find. Initially passed in as NULL b/c the first time this
 *   function runs it finds all "top level" field collections, which must each
 *   have its own instance of the $parents array. The $parents array serves
 *   two purposes. First, it is used to set the "field_collection_parents"
 *   value for all text fields found. Second, it is used to prevent infinite
 *   recursion in the case where a field collection is nested within itself.
 */
function hook_scanner_fields_alter(array &$all_field_records, $node_bundle = NULL, $parent_bundle = NULL, $parents = NULL) {
}
