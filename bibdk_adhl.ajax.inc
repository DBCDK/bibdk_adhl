<?php

/**
 * Return json object from ajax call
 */
function bibdk_adhl_ajax_get_recommendations(){
  dpm($_REQUEST);
  if (!$_REQUEST['pid'])
    die('pid has to be set');

  $data['pid'] = $pid = $_REQUEST['pid'];

  $result = bibdk_adhl_request($pid);
  if (!$result){
    $data['error'] = t('no_recommendations');
  }
  else {
    $data['list'] = bibdk_adhl_get_list($result);
  }
  if ($_REQUEST['more']){
    $more = array(

    );
  $data['more'] = drupal_render($more);
  }
  print json_encode($data);
}
