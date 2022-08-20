<?php

/**
 * Form builder function for settings form
 */
function quiz_question_import_settings_form($form, &$form_state) {
  $form['qq_import_multichoice'] = array(
    '#type' => 'fieldset',
    '#title' => t('Quiz questions - Multichoice import settings'),
    '#description' => t('Set the various default values to be used while importing a multichoice question'),
    '#collapsible' => TRUE,
  );
  $form['qq_import_multichoice']['qq_import_choice_multi'] = array(
    '#type' => 'checkbox',
    '#title' => t('Multiple answers'),
    '#description' => t('Allow any number of answers(checkboxes are used). If this box is not checked, one, and only one answer is allowed(radiobuttons are used).'),
    '#default_value' => variable_get('qq_import_choice_multi', 0),
    '#parents' => array('choice_multi'),
  );
  $form['qq_import_multichoice']['qq_import_choice_random'] = array(
    '#type' => 'checkbox',
    '#title' => t('Random order'),
    '#description' => t('Present alternatives in random order when quiz is being taken.'),
    '#default_value' => variable_get('qq_import_choice_random', 1),
    '#parents' => array('choice_random'),
  );
  $form['qq_import_multichoice']['qq_import_choice_boolean'] = array(
    '#type' => 'checkbox',
    '#title' => t('Simple scoring'),
    '#description' => t('Give max score if everything is correct. Zero points otherwise.'),
    '#default_value' => variable_get('qq_import_choice_boolean', 0),
    '#parents' => array('choice_boolean'),
  );
  $form['qq_import_multichoice']['qq_import_score_correct'] = array(
    '#type' => 'textfield',
    '#title' => t('Score for correct answer'),
    '#default_value' => variable_get('qq_import_score_correct', 1),
    '#size' => 40,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#description' => t('Ideally 1 or above'),
  );
  $form['qq_import_multichoice']['qq_import_score_incorrect'] = array(
    '#type' => 'textfield',
    '#title' => t('Score for incorrect answer'),
    '#default_value' => variable_get('qq_import_score_incorrect', 0),
    '#size' => 40,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#description' => t('Ideally 0 or less'),
  );
  $form['qq_import_multichoice']['qq_import_multichoice_text_format'] = array(
    '#type' => 'select',
    '#title' => t('Default text format'),
    '#default_value' => variable_get('qq_import_multichoice_text_format', filter_default_format()),
    '#options' => _qq_import_get_all_text_formats(),
    '#required' => TRUE,
    '#description' => t('Enter the default text format to be used in multichoice feedback'),
  );
  return system_settings_form($form);
}

function _qq_import_get_all_text_formats() {
  $formats = array();
  foreach (filter_formats() as $name => $format) {
    $formats[$name] = $format->name;
  }
  return $formats;
}
