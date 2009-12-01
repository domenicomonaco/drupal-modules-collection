<?php
// $Id$

/**
 * @file
 * Adminster page callbacks
 *
 */
 


function linkshack_admin_settings(){

$options = node_get_types('names');


  $nf='linkshack_extract_bulkmode';
  $form[$nf] = array(
  '#type' => 'checkboxes',
  '#title' => t('Links Extract BULK MODE'),
  '#options' => $options,
  '#default_value' => variable_get($nf, ''),
  '#description' => t('Select a content type if you want extract all $links variables'),

  );
  
  $optionst=array_keys($options);
  $nfg='linkshack_extract_singlemode';
  foreach($optionst as $ntypes){
    $form[$nfg . '_' . $ntypes]= array(
      '#type' => 'textarea',
      '#title' => t($ntypes),
      '#default_value' => variable_get($nfg . '_' . $ntypes,'' ), 
      '#size' => '90',
      '#disabled' => FALSE
      );
}

return system_settings_form($form);
}
