<?php

/**
 * Page callback: Admin page to configure Exec-ed Featured Programs
 */
function gsb_feature_ee_program_display_config_featured_programs() {

  $featured_programs = variable_get('gsb_feature_ee_program_display_config_featured_programs', array());

  $form['fieldset_featured_programs'] = array(
    '#type' => 'fieldset',
    '#title' => t('Featured Programs'),
    '#collapsible' => FALSE,
    '#collapsed' => TRUE,
    '#description' => '<p>' . t('') . '</p>'
  );
  
  $form['fieldset_featured_programs']['featured_program_one'] = array(
    '#type' => 'entityreference',
    '#title' => 'Program 1',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('program'),
    '#era_cardinality' => 1,
    '#default_value' => empty($featured_programs) ? '' : $featured_programs[0],
    '#process' => array('ajax_process_form', 'entityreference_autocomplete_process_entityreference'),    
  );

  $form['fieldset_featured_programs']['featured_program_two'] = array(
    '#type' => 'entityreference',
    '#title' => 'Program 2',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('program'),
    '#era_cardinality' => 1,
    '#default_value' => empty($featured_programs) ? '' : $featured_programs[1],
    '#process' => array('ajax_process_form', 'entityreference_autocomplete_process_entityreference'),
  );

  $form['fieldset_featured_programs']['featured_program_three'] = array(
    '#type' => 'entityreference',
    '#title' => 'Program 3',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('program'),
    '#era_cardinality' => 1,
    '#default_value' => empty($featured_programs) ? '' : $featured_programs[2],
    '#process' => array('ajax_process_form', 'entityreference_autocomplete_process_entityreference'),
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['#validate'][] = 'gsb_feature_ee_program_display_config_featured_programs_validate';
  $form['#submit'][]   = 'gsb_feature_ee_program_display_config_featured_programs_submit';

  return $form;

}

/**
 * Custom validate callback for the admin config of featured programs
 */
function gsb_feature_ee_program_display_config_featured_programs_validate(&$form, &$form_state) {

    $featured_programs = array();

    $featured_programs[0] = $form_state['values']['featured_program_one']['entity_id'];
    $featured_programs[1] = $form_state['values']['featured_program_two']['entity_id'];
    $featured_programs[2] = $form_state['values']['featured_program_three']['entity_id'];

    $error_msg = t("Please configure 3 featured programs." );
    if (!$featured_programs[0]) {
        form_error($form['fieldset_featured_programs']['featured_program_one'], $error_msg);
    }
    else if (!$featured_programs[1]) {
        form_error($form['fieldset_featured_programs']['featured_program_two'], $error_msg);
    }
    else if (!$featured_programs[2]) {
        form_error($form['fieldset_featured_programs']['featured_program_three'], $error_msg);
    }
}

/**
 * Custom submit callback for the admin config of featured programs
 */
function gsb_feature_ee_program_display_config_featured_programs_submit(&$form, &$form_state) {

  $featured_programs = array();

  $featured_programs[0] = $form_state['values']['featured_program_one']['entity_id'];
  $featured_programs[1] = $form_state['values']['featured_program_two']['entity_id'];
  $featured_programs[2] = $form_state['values']['featured_program_three']['entity_id'];

  variable_set('gsb_feature_ee_program_display_config_featured_programs', $featured_programs);

  drupal_set_message(t('Your configuration of featured programs have been successfully saved.'), 'status', FALSE);
  
}

