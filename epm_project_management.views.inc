<?php

/**
 * Implementation of hook_views_data().
 */
function epm_project_management_views_data() {
  $data = array();

  $data['epm_project_management_data']['table']['group']  = t('EPM Project data');

  $data['epm_project_management_data']['table']['join'] = array(
    'node' => array(
      'type' => 'LEFT',
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  // TODO: we may not need this at all. It came from pid.
  $data['epm_project_management_data']['nid'] = array(
    'title' => t('Node'),
    'help' => t('The node a record is tied to.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
    // Information for accepting a pid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
      'name field' => 'title',
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),
    // Information for accepting a pid as a filter
    // TODO: we could do this...
//    'filter' => array(
//      'handler' => 'project_issue_handler_filter_issue_project',
//    ),
    'relationship' => array(
      'base' => 'node',
      'handler' => 'views_handler_relationship',
      'label' => t('EPM Project node'),
    ),
  );

  $data['epm_project_management_data']['last_update'] = array(
    'title' => t('Update'),
    'help' => t("The date the data was laste updated"),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );

  $data['epm_project_management_data']['open_bug_count'] = array(
    'title' => t('Open bug count'),
    'help' => t("Open bugs for the project"),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    
  );  
  
  $data['epm_project_management_data']['closed_bug_count'] = array(
    'title' => t('Closed bug count'),
    'help' => t("Closed bugs for the project"),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  
  $data['epm_project_management_data']['last_stable_release'] = array(
    'title' => t('Stable, supported release date'),
    'help' => t("The date of the last stable, supported release"),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );
  
  $data['epm_project_management_data']['active_maintainer_count'] = array(
    'title' => t('Maintainers'),
    'help' => t("Recently cctive maintainers for the project"),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  
  $data['epm_project_management_data']['major_version_usage'] = array(
    'title' => t('Usage'),
    'help' => t("Usage of the relevant major version for the project"),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
   
  return $data;
}
