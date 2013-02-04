<?php

/**
 * Return json object from ajax call
 */
function bibdk_adhl_ajax_get_recommendations(){
  if (!$_REQUEST['pid'])
    die('pid has to be set');

  $data['pid'] = $pid = $_REQUEST['pid'];

  $result = bibdk_adhl_request($pid);
  if (!$result){
    $data['error'] = t('no_recommendations');
  }
  else {
    $data['list'] = bibdk_adhl_get_list($result);
    $more = array(
      '#type' => 'link',
      '#path' => 'overlay/adhl/'.$pid,
      '#options' => array(
        '#attributes' => array(
          'class' => array('more-recommendations'),
          'target' => '_blank',
        )
      ),
    );
    $data['more'] = drupal_render($more);
  }
  print json_encode($data);
}
