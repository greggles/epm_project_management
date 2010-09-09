<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function epm_project_management_user_default_permissions() {
  $permissions = array();

  // Exported permission: create epm_project content
  $permissions['create epm_project content'] = array(
    'name' => 'create epm_project content',
    'roles' => array(
      '0' => 'Security team',
      '1' => 'Site builders',
    ),
  );

  // Exported permission: edit any epm_project content
  $permissions['edit any epm_project content'] = array(
    'name' => 'edit any epm_project content',
    'roles' => array(
      '0' => 'Security team',
      '1' => 'Site builders',
    ),
  );

  return $permissions;
}
