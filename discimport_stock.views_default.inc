<?php
/**
 * @file
 * discimport_stock.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function discimport_stock_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'out_of_stock';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_product';
  $view->human_name = 'Out of stock';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Out of stock';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    1 => '1',
    2 => '2',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Content: Referenced products */
  $handler->display->display_options['relationships']['field_product_product_id']['id'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['table'] = 'field_data_field_product';
  $handler->display->display_options['relationships']['field_product_product_id']['field'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['label'] = 'Produkt';
  /* Relationship: Commerce Product: Referencing Node */
  $handler->display->display_options['relationships']['field_product']['id'] = 'field_product';
  $handler->display->display_options['relationships']['field_product']['table'] = 'commerce_product';
  $handler->display->display_options['relationships']['field_product']['field'] = 'field_product';
  $handler->display->display_options['relationships']['field_product']['label'] = 'Indholdselement henviser til produkter fra field_product';
  /* Field: Commerce Product: Product ID */
  $handler->display->display_options['fields']['product_id']['id'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['product_id']['field'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['label'] = 'Produkt-ID';
  $handler->display->display_options['fields']['product_id']['link_to_product'] = 1;
  /* Field: Commerce Product: SKU */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['link_to_product'] = 1;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'field_product';
  $handler->display->display_options['fields']['title_field']['label'] = 'Titel';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Commerce Product: Delete link */
  $handler->display->display_options['fields']['delete_product']['id'] = 'delete_product';
  $handler->display->display_options['fields']['delete_product']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['delete_product']['field'] = 'delete_product';
  $handler->display->display_options['fields']['delete_product']['label'] = 'Slet-link';
  /* Field: Commerce Product: Stock */
  $handler->display->display_options['fields']['commerce_stock']['id'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['field'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['label'] = 'Lager';
  $handler->display->display_options['fields']['commerce_stock']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Filter criterion: Commerce Product: Stock (commerce_stock) */
  $handler->display->display_options['filters']['commerce_stock_value']['id'] = 'commerce_stock_value';
  $handler->display->display_options['filters']['commerce_stock_value']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['filters']['commerce_stock_value']['field'] = 'commerce_stock_value';
  $handler->display->display_options['filters']['commerce_stock_value']['value']['value'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/commerce/products/out-of-stock';

  /* Display: Side */
  $handler = $view->new_display('page', 'Side', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'No pictures';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Product: Images (field_images:fid) */
  $handler->display->display_options['filters']['field_images_fid']['id'] = 'field_images_fid';
  $handler->display->display_options['filters']['field_images_fid']['table'] = 'field_data_field_images';
  $handler->display->display_options['filters']['field_images_fid']['field'] = 'field_images_fid';
  $handler->display->display_options['filters']['field_images_fid']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_images_fid']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/commerce/no-pictures';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Reorder';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Commerce Product: Stock (commerce_stock) */
  $handler->display->display_options['sorts']['commerce_stock_value']['id'] = 'commerce_stock_value';
  $handler->display->display_options['sorts']['commerce_stock_value']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['sorts']['commerce_stock_value']['field'] = 'commerce_stock_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Product: Stock (commerce_stock) */
  $handler->display->display_options['filters']['commerce_stock_value']['id'] = 'commerce_stock_value';
  $handler->display->display_options['filters']['commerce_stock_value']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['filters']['commerce_stock_value']['field'] = 'commerce_stock_value';
  $handler->display->display_options['filters']['commerce_stock_value']['operator'] = '<=';
  $handler->display->display_options['filters']['commerce_stock_value']['value']['value'] = '5';
  $handler->display->display_options['filters']['commerce_stock_value']['group'] = 1;
  /* Filter criterion: Commerce Product: Stock (commerce_stock) */
  $handler->display->display_options['filters']['commerce_stock_value_1']['id'] = 'commerce_stock_value_1';
  $handler->display->display_options['filters']['commerce_stock_value_1']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['filters']['commerce_stock_value_1']['field'] = 'commerce_stock_value';
  $handler->display->display_options['filters']['commerce_stock_value_1']['operator'] = '>';
  $handler->display->display_options['filters']['commerce_stock_value_1']['value']['value'] = '0';
  $handler->display->display_options['filters']['commerce_stock_value_1']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/commerce/products/reorder';
  $translatables['out_of_stock'] = array(
    t('Master'),
    t('Out of stock'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Antal elementer'),
    t('- Alle -'),
    t('Forskydning'),
    t('« første'),
    t('‹ forrige'),
    t('næste ›'),
    t('sidste »'),
    t('Produkt'),
    t('Indholdselement henviser til produkter fra field_product'),
    t('Produkt-ID'),
    t('SKU'),
    t('Titel'),
    t('Slet-link'),
    t('Lager'),
    t('Page'),
    t('Side'),
    t('No pictures'),
    t('Reorder'),
  );
  $export['out_of_stock'] = $view;

  $view = new view();
  $view->name = 'product_stock_editor';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Product Stock Editor';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Product Stock Editor';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit any commerce_product entity';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'editableviews_table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_plastic' => 'field_plastic',
    'field_weight' => 'field_weight',
    'field_color' => 'field_color',
    'commerce_stock_editable' => 'commerce_stock_editable',
    'delete_product' => 'delete_product',
  );
  $handler->display->display_options['style_options']['default'] = 'field_plastic';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_plastic' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_weight' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_color' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'commerce_stock_editable' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_product' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Referenced products */
  $handler->display->display_options['relationships']['field_product_product_id']['id'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['table'] = 'field_data_field_product';
  $handler->display->display_options['relationships']['field_product_product_id']['field'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Commerce Product: Plastic */
  $handler->display->display_options['fields']['field_plastic']['id'] = 'field_plastic';
  $handler->display->display_options['fields']['field_plastic']['table'] = 'field_data_field_plastic';
  $handler->display->display_options['fields']['field_plastic']['field'] = 'field_plastic';
  $handler->display->display_options['fields']['field_plastic']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_plastic']['element_type'] = '0';
  $handler->display->display_options['fields']['field_plastic']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_plastic']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_plastic']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_plastic']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_plastic']['field_api_classes'] = TRUE;
  /* Field: Commerce Product: Weight */
  $handler->display->display_options['fields']['field_weight']['id'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['table'] = 'field_data_field_weight';
  $handler->display->display_options['fields']['field_weight']['field'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_weight']['element_type'] = '0';
  $handler->display->display_options['fields']['field_weight']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_weight']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_weight']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_weight']['field_api_classes'] = TRUE;
  /* Field: Commerce Product: Color */
  $handler->display->display_options['fields']['field_color']['id'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['table'] = 'field_data_field_color';
  $handler->display->display_options['fields']['field_color']['field'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_color']['element_type'] = '0';
  $handler->display->display_options['fields']['field_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_color']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_color']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_color']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_color']['field_api_classes'] = TRUE;
  /* Field: Commerce Product: Stock (editable) */
  $handler->display->display_options['fields']['commerce_stock_editable']['id'] = 'commerce_stock_editable';
  $handler->display->display_options['fields']['commerce_stock_editable']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['fields']['commerce_stock_editable']['field'] = 'commerce_stock_editable';
  $handler->display->display_options['fields']['commerce_stock_editable']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['commerce_stock_editable']['label'] = '';
  $handler->display->display_options['fields']['commerce_stock_editable']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_stock_editable']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_stock_editable']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_stock_editable']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_stock_editable']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['commerce_stock_editable']['field_api_classes'] = TRUE;
  $handler->display->display_options['fields']['commerce_stock_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['commerce_stock_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['commerce_stock_editable']['suppress_description'] = 0;
  /* Field: Commerce Product: Delete link */
  $handler->display->display_options['fields']['delete_product']['id'] = 'delete_product';
  $handler->display->display_options['fields']['delete_product']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['delete_product']['field'] = 'delete_product';
  $handler->display->display_options['fields']['delete_product']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['delete_product']['label'] = '';
  $handler->display->display_options['fields']['delete_product']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/stock';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Stock';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['product_stock_editor'] = array(
    t('Master'),
    t('Product Stock Editor'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Products referenced by field_product'),
    t('Title'),
    t('Plastic'),
    t('Weight'),
    t('Color'),
    t('Alle'),
    t('Page'),
  );
  $export['product_stock_editor'] = $view;

  return $export;
}
