<?php

/**
 * Implements hook_field_info().
 */
function bibdk_adhl_field_info() {
  return array(
    'bibdk_adhl_info' => array(
      'label' => t('ADHL'),
      'description' => t('ADHL'),
      'default_widget' => 'hidden',
      'default_formatter' => 'bibdk_adhl_default',
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
      '#type' => 'fieldset',
      '#title' => $id,
      '#attributes' => array(
        'class' => array('recommendation-load'),
        'data-pid' => $id,
      ),
      '#attached' => array(
        'js' => array(drupal_get_path('module', 'bibdk_adhl') . '/js/bibdk_adhl.js'),
      ),
    );
  }
}


/**
 * Implements hook_field_formatter_info().
 */
function bibdk_adhl_field_formatter_info() {
  return array(
    'bibdk_adhl_default' => array(
      'label' => t('Default'),
      'field types' => array(
        'bibdk_adhl_info',
      ),
    )
  );
}


/**
 * Implements hook_field_formatter_view().
 */
function bibdk_adhl_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  foreach($items as $delta => $item){
    $element[$delta]['#markup'] = drupal_render($item);
  }
  return $element;
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
