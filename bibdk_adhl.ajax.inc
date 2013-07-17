<?php

/**
 * Return json object from ajax call
 */
function bibdk_adhl_ajax_get_recommendations(){
  $data['pid'] = $_REQUEST['pid'];

  if (empty($_REQUEST['pid'])){
    $data['error'] = t('bibdk_adhl_unknown_error');
  }
  else{
    $result = bibdk_adhl_get_adhl($data['pid'], 10);
  }

  if (empty($result)){
    $data['error'] = t('bibdk_adhl_no_recommendations');
  }
  else {
    $data['list'] = bibdk_adhl_get_link_list_view($result);
  }
  drupal_json_output($data);
}
