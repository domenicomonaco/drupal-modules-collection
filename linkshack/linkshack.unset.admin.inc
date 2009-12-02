<?php
// $Id$

/**
 * @file
 * Adminster page callbacks
 *
 */
 

function linkshack_admin_settings() {

$options = node_get_types('names');


  $nf='linkshack_unset_bulkmode';
  $form[$nf] = array(
  '#type' => 'checkboxes',
  '#title' => t('<em>UNSET</em> Bulk Mode'),
  '#options' => $options,
  '#default_value' => variable_get($nf, ''),
  '#description' => t('Unset Bulk Mode can be unsetting all of variable by selecting content type'),

  );
  
  $optionst = array_keys($options);
  $nfg='linkshack_unset_singlemode';
  foreach ($optionst as $ntypes) {
    $form[$nfg . '_' . $ntypes] = array(
      '#type' => 'textarea',
      '#title' => t($ntypes . ' <em>UNSET</em> Single varibles'),
      '#default_value' => variable_get($nfg . '_' . $ntypes, '' ), 
      '#size' => '90',
      '#disabled' => FALSE
      );
}

return system_settings_form($form);
}
