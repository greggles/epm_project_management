<?php

/**
 * Implementation of hook_flag_default_flags().
 */
function epm_project_management_flag_default_flags() {
$flags = array();
// Exported flag: "Approved for security".
$flags[] = array (
  'content_type' => 'node',
  'name' => 'epm_approved_security',
  'title' => 'Approved for security',
  'global' => '1',
  'types' => 
  array (
    0 => 'epm_project',
  ),
  'flag_short' => 'Mark as reviewed for security',
  'flag_long' => 'Mark this project as reviewed for security.',
  'flag_message' => 'Thanks for performing a security review',
  'unflag_short' => 'Mark as not reviewed for security',
  'unflag_long' => 'Mark this project as no longer approved by security',
  'unflag_message' => 'Thanks for performing a security review',
  'unflag_denied_text' => '',
  'link_type' => 'toggle',
  'roles' => 
  array (
    'flag' => 
    array (
      0 => 3,
    ),
    'unflag' => 
    array (
      0 => 3,
    ),
  ),
  'show_on_page' => 1,
  'show_on_teaser' => 1,
  'show_on_form' => 1,
  'access_author' => '',
  'i18n' => 0,
  'module' => 'epm_project_management',
  'locked' => 
  array (
    0 => 'name',
  ),
  'api_version' => 2,
);
// Exported flag: "Project in use".
$flags[] = array (
  'content_type' => 'node',
  'name' => 'epm_in_use',
  'title' => 'Project in use',
  'global' => '1',
  'types' => 
  array (
    0 => 'epm_project',
  ),
  'flag_short' => 'Mark as in use',
  'flag_long' => 'Mark project as in use',
  'flag_message' => 'Thanks for marking the project as being in use',
  'unflag_short' => 'Mark as not in use',
  'unflag_long' => 'Mark project as no longer in use',
  'unflag_message' => 'Thanks for marking the project as no longer in use',
  'unflag_denied_text' => '',
  'link_type' => 'toggle',
  'roles' => 
  array (
    'flag' => 
    array (
      0 => 4,
    ),
    'unflag' => 
    array (
      0 => 4,
    ),
  ),
  'show_on_page' => 1,
  'show_on_teaser' => 1,
  'show_on_form' => 1,
  'access_author' => '',
  'i18n' => 0,
  'module' => 'epm_project_management',
  'locked' => 
  array (
    0 => 'name',
  ),
  'api_version' => 2,
);
return $flags;
}

/**
 * Implementation of hook_node_info().
 */
function epm_project_management_node_info() {
  $items = array(
    'epm_project' => array(
      'name' => t('Project'),
      'module' => 'features',
      'description' => t('The Project content type keeps track of "Projects" on drupal.org like modules and themes. Create a Project node including the name and shortname. Enter internal information about the project like whether it is a suggested, approved, or explicitly rejected tool to use in a specific environment. It will then be added to a list on your site of Projects. Other users on your site can update it to keep the information accurate. This site will automatically download information about the project from drupal.org to help you know about the quality of the module.'),
      'has_title' => '1',
      'title_label' => t('Project name'),
      'has_body' => '1',
      'body_label' => t('Usage notes'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function epm_project_management_views_api() {
  return array(
    'api' => '2',
  );
}
