<?php

/**
 * Implements hook_field_info().
 */
function bibdk_adhl_field_info() {
  return array(
    'bibdk_adhl_info' => array(
      'label' => t('ADHL'),
      'description' => t('Displays ADHL information'),
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
    $items[$id][] = $id;
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
  foreach ($items as $delta => $item) {
    $isbn = $entity->getISBN();
    $list = bibdk_adhl_work_field_render($isbn, $item);
    $element[$delta]['#markup'] = drupal_render($list);
  }
  return $element;
}

function bibdk_adhl_button_form_element($form, &$form_state, $path) {
  $form = array();
  $form['link'] = array(
    '#type' => 'textfield',
    '#default_value' => $path,
    //'#disabled' => true,
  );
  return $form;
}

function bibdk_adhl_work_field_render($isbn, $id){
  if (!isset($isbn))
    return null;
  $items['description'] = array(
    '#type' => 'markup',
    '#markup' => '<p>'.t('about_adhl').'</p>',
  );
  $items['recommendations'] = array(
    '#type' => 'fieldset',
    '#attributes' => array(
      'class' => array('recommendation-load'),
      'data-isbn' => $isbn,
      'data-pid' => $id,
    ),
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'bibdk_adhl') . '/js/bibdk_adhl.js'),
    ),
  );
  $items[$id]['more'] = array(
    '#type' => 'link',
    '#title' => t('see_more_adhl'),
    '#href' => 'overlay/adhl/'.$isbn,
    '#attributes' => array(
      'class' => array('recommendation-more', 'bibdk-popup-link', 'text-small', 'text-lightgrey', 'visuallyhidden'),
      'rel' => 'holdings',
      'data-pid' => $id,
    )
  );
  return $items;
}
