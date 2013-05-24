<?php

/**
 * Implements hook_worktabs_items().
 *
 * @param $tabs
 * @param bibdkWork $entity
 */
function bibdk_adhl_worktabs_items($tabs, $entity) {
  $tabs['more-about']['adhl'] = array(
    'title' => t('adhls', array(), array('context' => 'bibdk_adhl')),
    'btn_txt_closed' => t('view_more', array(), array('context' => 'bibdk_adhl')),
    'rendered' => bibdk_adhl_get_worktab_content($entity),
    'weight' => 0,
  );
  return $tabs;
}

/**
 * @param bibdkWork $entity
 * @return array $list
 */
function bibdk_adhl_get_worktab_content($entity){
  $list = bibdk_adhl_work_tabs_render($entity->getId());
  return drupal_render($list);
}

/**
 * @param $id
 * @return array $items
 */
function bibdk_adhl_work_tabs_render($id){

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
    '#href' => 'overlay/adhl/'.$id,
    '#attributes' => array(
      'class' => array('recommendation-more', 'bibdk-popup-link', 'text-small', 'text-lightgrey', 'visuallyhidden'),
      'rel' => 'holdings',
      'data-pid' => $id,
    )
  );
  return $items;
}
