<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function epm_project_management_taxonomy_default_vocabularies() {
  return array(
    'epm_project_purpose' => array(
      'name' => 'Project purpose',
      'description' => 'Use these tags to identify projects that have a similar purpose. Like tagging themes with "base theme" or image related modules with "image"',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '0',
      'tags' => '1',
      'module' => 'features_epm_project_purpose',
      'weight' => '0',
      'nodes' => array(
        'epm_project' => 'epm_project',
      ),
    ),
  );
}
