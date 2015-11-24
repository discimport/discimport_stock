<?php
/**
 * @file
 * discimport_stock.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function discimport_stock_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer commerce_stock settings'.
  $permissions['administer commerce_stock settings'] = array(
    'name' => 'administer commerce_stock settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_stock',
  );

  // Exported permission: 'make rule based changes to commerce_stock'.
  $permissions['make rule based changes to commerce_stock'] = array(
    'name' => 'make rule based changes to commerce_stock',
    'roles' => array(),
    'module' => 'commerce_stock',
  );

  return $permissions;
}
