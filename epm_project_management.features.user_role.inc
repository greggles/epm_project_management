<?php

/**
 * Implementation of hook_user_default_roles().
 */
function epm_project_management_user_default_roles() {
  $roles = array();

  // Exported role: Security team
  $roles['Security team'] = array(
    'name' => 'Security team',
  );

  // Exported role: Site builders
  $roles['Site builders'] = array(
    'name' => 'Site builders',
  );

  return $roles;
}
