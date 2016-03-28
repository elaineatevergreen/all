<?php
/**
 * @file
 * learning_community_directory.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function learning_community_directory_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_add-content:node/add.
  $menu_links['navigation_add-content:node/add'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add content',
    'options' => array(
      'identifier' => 'navigation_add-content:node/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_basic-page:node/add/basic-page.
  $menu_links['navigation_basic-page:node/add/basic-page'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/basic-page',
    'router_path' => 'node/add/basic-page',
    'link_title' => 'Basic Page',
    'options' => array(
      'attributes' => array(
        'title' => 'A <em>basic page</em> is used to post general information about the Directory.',
      ),
      'identifier' => 'navigation_basic-page:node/add/basic-page',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_institution-listing:institution-listing.
  $menu_links['navigation_institution-listing:institution-listing'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'institution-listing',
    'router_path' => 'institution-listing',
    'link_title' => 'Institution Listing',
    'options' => array(
      'identifier' => 'navigation_institution-listing:institution-listing',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_institution:node/add/institution.
  $menu_links['navigation_institution:node/add/institution'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/institution',
    'router_path' => 'node/add/institution',
    'link_title' => 'Institution',
    'options' => array(
      'attributes' => array(
        'title' => 'An <em>institution</em> is a college, university, or similar. An institution may host one or more learning community programs.',
      ),
      'identifier' => 'navigation_institution:node/add/institution',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_learning-community-program:node/add/learning-community-program.
  $menu_links['navigation_learning-community-program:node/add/learning-community-program'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/learning-community-program',
    'router_path' => 'node/add/learning-community-program',
    'link_title' => 'Learning Community Program',
    'options' => array(
      'attributes' => array(
        'title' => 'A <em>Learning Community Program</em> is a specific project connected with an institution.',
      ),
      'identifier' => 'navigation_learning-community-program:node/add/learning-community-program',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_program-search:program-search.
  $menu_links['navigation_program-search:program-search'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'program-search',
    'router_path' => 'program-search',
    'link_title' => 'Program Search',
    'options' => array(
      'identifier' => 'navigation_program-search:program-search',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add content');
  t('Basic Page');
  t('Institution');
  t('Institution Listing');
  t('Learning Community Program');
  t('Program Search');

  return $menu_links;
}
