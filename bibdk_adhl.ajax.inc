<?php

/**
 * Return json object from ajax call
 */
function bibdk_adhl_ajax_get_recommendations(){
  $data['pid'] = $pid = $_REQUEST['pid'];
  if (empty($_REQUEST['isbn'])){
    $data['error'] = t('no_recommendations');
  }
  else{
    $result = bibdk_adhl_request($_REQUEST['isbn']);
  }

  if (!$result){
    $data['error'] = t('no_recommendations');
  }
  else {
    $data['list'] = bibdk_adhl_get_list($result);
  }
  drupal_json_output($data);
}
