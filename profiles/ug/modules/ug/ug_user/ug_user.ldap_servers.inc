<?php
/**
 * @file
 * ug_user.ldap_servers.inc
 */

/**
 * Implements hook_default_ldap_servers().
 */
function ug_user_default_ldap_servers() {
  $export = array();

  $ldap_servers_conf = new stdClass();
  $ldap_servers_conf->disabled = FALSE; /* Edit this to true to make a default ldap_servers_conf disabled initially */
  $ldap_servers_conf->api_version = 1;
  $ldap_servers_conf->sid = 'ug';
  $ldap_servers_conf->name = 'UG Central Directory';
  $ldap_servers_conf->status = TRUE;
  $ldap_servers_conf->ldap_type = 'default';
  $ldap_servers_conf->address = 'directory.uoguelph.ca';
  $ldap_servers_conf->port = 389;
  $ldap_servers_conf->tls = TRUE;
  $ldap_servers_conf->followrefs = FALSE;
  $ldap_servers_conf->bind_method = 1;
  $ldap_servers_conf->binddn = 'uid=drupalpx,ou=people,o=uoguelph.ca';
  $ldap_servers_conf->bindpw = '';
  $ldap_servers_conf->basedn = array(
    0 => 'ou=People,o=uoguelph.ca',
  );
  $ldap_servers_conf->user_attr = 'uid';
  $ldap_servers_conf->account_name_attr = '';
  $ldap_servers_conf->mail_attr = 'mail';
  $ldap_servers_conf->mail_template = '';
  $ldap_servers_conf->picture_attr = '';
  $ldap_servers_conf->unique_persistent_attr = '';
  $ldap_servers_conf->unique_persistent_attr_binary = FALSE;
  $ldap_servers_conf->user_dn_expression = '';
  $ldap_servers_conf->ldap_to_drupal_user = '';
  $ldap_servers_conf->testing_drupal_username = '';
  $ldap_servers_conf->testing_drupal_user_dn = '';
  $ldap_servers_conf->grp_unused = FALSE;
  $ldap_servers_conf->grp_object_cat = '';
  $ldap_servers_conf->grp_nested = FALSE;
  $ldap_servers_conf->grp_user_memb_attr_exists = TRUE;
  $ldap_servers_conf->grp_user_memb_attr = 'edupersonaffiliation';
  $ldap_servers_conf->grp_memb_attr = '';
  $ldap_servers_conf->grp_memb_attr_match_user_attr = '';
  $ldap_servers_conf->grp_derive_from_dn = FALSE;
  $ldap_servers_conf->grp_derive_from_dn_attr = '';
  $ldap_servers_conf->grp_test_grp_dn = '';
  $ldap_servers_conf->grp_test_grp_dn_writeable = '';
  $ldap_servers_conf->search_pagination = FALSE;
  $ldap_servers_conf->search_page_size = 1000;
  $ldap_servers_conf->weight = 0;
  $export['ug'] = $ldap_servers_conf;

  return $export;
}
