<?php
/**
 * @file
 * ug_user.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ug_user_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ldap_authentication_conf';
  $strongarm->value = array(
    'sids' => array(
      'ug' => 'ug',
    ),
    'authenticationMode' => 2,
    'loginConflictResolve' => 2,
    'acctCreation' => 4,
    'loginUIUsernameTxt' => 'Please enter your U of G central login ID.',
    'loginUIPasswordTxt' => 'Please enter your U of G central login password.',
    'ldapUserHelpLinkUrl' => 'http://www.uoguelph.ca/ccs/service/central-login-id-and-password',
    'ldapUserHelpLinkText' => 'Central Login ID Help',
    'emailOption' => 3,
    'emailUpdate' => 1,
    'allowOnlyIfTextInDn' => array(),
    'excludeIfTextInDn' => array(),
    'allowTestPhp' => '',
    'excludeIfNoAuthorizations' => NULL,
    'ssoRemoteUserStripDomainName' => NULL,
    'seamlessLogin' => NULL,
    'ldapImplementation' => NULL,
    'cookieExpire' => NULL,
  );
  $export['ldap_authentication_conf'] = $strongarm;

  return $export;
}
