<?php

/** get list of most popular manifestations from ADHL
 * @param $numRecords
 * @return array|string
 */
function bibdk_adhl_get_toplist($numRecords) {
  if ($numRecords > 100){
    $numRecords = 100;
  }
  if (!$numRecords || !is_numeric($numRecords)){
    $numRecords = 20;
  }
  drupal_set_title(t('Top !numRecords', array('!numRecords' => $numRecords)));

  $result = bibdk_adhl_topTenRequest($numRecords);

  if ( empty($result) ) {
    return array();
  }

  $manifestations = bibdk_adhl_get_manifestations($result);

  return bibdk_adhl_get_link_list_view($manifestations);
}


/**
* Execute adhl TopTenRequest
* @param int $numResults
* @return array
 */
function bibdk_adhl_topTenRequest($numRecords) {

  //make param used for request with pid-list
  $param = array(
    'numRecords' => $numRecords,
    'action' => 'topTenRequest',
  );

  $client = new ting_client_class();

  $response = $client->do_request('adhl', $param);
  return bibdk_adhl_parse_response($response->topTenResponse);
}
