<?php
/**
 * @file
 * discimport_stock.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function discimport_stock_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'commerce_stock_override'.
  $field_bases['commerce_stock_override'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_product',
    ),
    'field_name' => 'commerce_stock_override',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 0,
        1 => 1,
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
