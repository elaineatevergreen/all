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

  // Exported menu link: main-menu_about:node/1694.
  $menu_links['main-menu_about:node/1694'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1694',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'identifier' => 'main-menu_about:node/1694',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_directory:node/1693.
  $menu_links['main-menu_directory:node/1693'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1693',
    'router_path' => 'node/%',
    'link_title' => 'Directory',
    'options' => array(
      'identifier' => 'main-menu_directory:node/1693',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_home:<front>.
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_institutes:node/1692.
  $menu_links['main-menu_institutes:node/1692'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1692',
    'router_path' => 'node/%',
    'link_title' => 'Institutes',
    'options' => array(
      'identifier' => 'main-menu_institutes:node/1692',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_resources:node/1695.
  $menu_links['main-menu_resources:node/1695'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1695',
    'router_path' => 'node/%',
    'link_title' => 'Resources',
    'options' => array(
      'identifier' => 'main-menu_resources:node/1695',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-directory-navigation_institution-listing:directory/institutions.
  $menu_links['menu-directory-navigation_institution-listing:directory/institutions'] = array(
    'menu_name' => 'menu-directory-navigation',
    'link_path' => 'directory/institutions',
    'router_path' => 'directory/institutions',
    'link_title' => 'Institution Listing',
    'options' => array(
      'identifier' => 'menu-directory-navigation_institution-listing:directory/institutions',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-directory-navigation_program-search:directory/programs.
  $menu_links['menu-directory-navigation_program-search:directory/programs'] = array(
    'menu_name' => 'menu-directory-navigation',
    'link_path' => 'directory/programs',
    'router_path' => 'directory/programs',
    'link_title' => 'Program Search',
    'options' => array(
      'identifier' => 'menu-directory-navigation_program-search:directory/programs',
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
  t('About');
  t('Directory');
  t('Home');
  t('Institutes');
  t('Institution Listing');
  t('Program Search');
  t('Resources');

  return $menu_links;
}
