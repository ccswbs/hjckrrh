<?php

/**
 * @file
 * API documentation for Facebook Pixel.
 */

/**
 * Alters the final array of data items to be pushed.
 *
 * Modules can implement hook_facebook_pixel_data_ACTION_alter() to modify
 * data sent to Facebook Pixel for a specific action.
 *
 * Possible actions:
 *  - Purchase
 *  - AddToCart
 *  - InitiateCheckout
 *  - CompleteRegistration
 *  - ViewContent
 * 
 * @param array &$$data
 *   By reference. An array of all encoded data elements.
 * 
 * @param int $entity_id
 *   Associated entity id.
 */
function hook_facebook_pixel_data_ACTION_alter(&$data, $order_id) {
  // Example for 'Purchase' action: Add product ids to the purchase data.
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order_id);

  $product_ids = array();
  foreach ($order_wrapper->commerce_line_items as $line_item_wrapper) {
    if (in_array($line_item_wrapper->getBundle(), commerce_product_line_item_types())) {
      $product_ids[] = $line_item_wrapper->commerce_product->product_id->value();
    }
  }

  $data += array(
    'content_ids' => $product_ids,
    'content_type' => 'product',
  );
}
