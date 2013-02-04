<?php

/**
 * Implements hook_field_info().
 */
function bibdk_adhl_field_info() {
  return array(
    'bibdk_adhl' => array(
      'label' => t('ADHL'),
      'description' => t('Linkme formatted permalink.'),
      'default_widget' => 'hidden',
      'default_formatter' => 'bibdk_linkme_permalink_default',
      'no_ui' => TRUE,
    ),
  );
}

/**
 * Implements hook_field_load().
 */
function bibdk_adhl_field_load($entity_type, $entities, $field, $instances, $langcode, &$items, $age) {
  foreach ($entities as $id => $entity) {
    $items[$id][] = array(
      'link' => bibdk_adhl_get_adhl_info($id),
    );
  }
}


/**
 * Implements hook_field_formatter_info().
 */
function bibdk_adhl_field_formatter_info() {
  return array(
    'bibdk_linkme_permalink_default' => array(
      'label' => t('Default'),
      'field types' => array(
        'bibdk_linkme_permalink',
      ),
    )
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function bibdk_adhl_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
}

function bibdk_adhl_button_form_element($form, &$form_state, $path){
  $form = array();
  $form['link'] = array(
    '#type' => 'textfield',
    '#default_value' => $path,
    //'#disabled' => true,
  );


  return $form;
}
