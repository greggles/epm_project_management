<?php

/**
 * Implementation of hook_content_default_fields().
 */
function epm_project_management_content_default_fields() {
  $fields = array();

  // Exported field: field_epm_project_shortname
  $fields['epm_project-field_epm_project_shortname'] = array(
    'field_name' => 'field_epm_project_shortname',
    'type_name' => 'epm_project',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_epm_project_shortname][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Short name',
      'weight' => '-4',
      'description' => 'The "short name" of a project is what shows up in the urls on drupal.org. For http://drupal.org/project/views enter "views."',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Short name');

  return $fields;
}
