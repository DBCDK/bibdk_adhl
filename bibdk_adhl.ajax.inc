<?php

/**
 * Return json object from ajax call
 */
function bibdk_adhl_ajax_get_recommendations(){

  if ( empty($_REQUEST['pid']) ) {

    $data['error'] = t('bibdk_adhl_unknown_error', array(), array('context' => 'bibdk_adhl'));
    $data['toggle_text'] = t('bibdk_adhl_toggle_text_error');
    watchdog('bibdk_adhl', 'Empty PID in AJAX call', WATCHDOG_ERROR);

  }
  else {

    $data['pid'] = $_REQUEST['pid'];
    $result = bibdk_adhl_get_adhl($data['pid'], 10);

    if ( empty($result) ) {
      $data['error'] = t('bibdk_adhl_no_recommendations');
      $data['toggle_text'] = t('bibdk_adhl_toggle_text_empty');
    }
    else {
      $data['list'] = drupal_render(bibdk_adhl_get_link_list_view($result));
    }

  }

  drupal_json_output($data);

}
