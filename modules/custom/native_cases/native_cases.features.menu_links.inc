<?php
/**
 * @file
 * native_cases.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function native_cases_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_about:node/290.
  $menu_links['main-menu_about:node/290'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/290',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'identifier' => 'main-menu_about:node/290',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_assessment:node/292.
  $menu_links['main-menu_assessment:node/292'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/292',
    'router_path' => 'node/%',
    'link_title' => 'Assessment',
    'options' => array(
      'identifier' => 'main-menu_assessment:node/292',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_home:node/289.
  $menu_links['main-menu_home:node/289'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/289',
    'router_path' => 'node/%',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:node/289',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_resources:node/293.
  $menu_links['main-menu_resources:node/293'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/293',
    'router_path' => 'node/%',
    'link_title' => 'Resources',
    'options' => array(
      'identifier' => 'main-menu_resources:node/293',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_teaching-with-cases:node/291.
  $menu_links['main-menu_teaching-with-cases:node/291'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/291',
    'router_path' => 'node/%',
    'link_title' => 'Teaching with Cases',
    'options' => array(
      'identifier' => 'main-menu_teaching-with-cases:node/291',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-case-facets_all-cases-a-z:collection/a-z.
  $menu_links['menu-case-facets_all-cases-a-z:collection/a-z'] = array(
    'menu_name' => 'menu-case-facets',
    'link_path' => 'collection/a-z',
    'router_path' => 'collection/a-z',
    'link_title' => 'All Cases, A-Z',
    'options' => array(
      'identifier' => 'menu-case-facets_all-cases-a-z:collection/a-z',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-case-facets_by-academic-discipline:collection/discipline.
  $menu_links['menu-case-facets_by-academic-discipline:collection/discipline'] = array(
    'menu_name' => 'menu-case-facets',
    'link_path' => 'collection/discipline',
    'router_path' => 'collection',
    'link_title' => 'By Academic Discipline',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-case-facets_by-academic-discipline:collection/discipline',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-case-facets_by-theme:collection/theme.
  $menu_links['menu-case-facets_by-theme:collection/theme'] = array(
    'menu_name' => 'menu-case-facets',
    'link_path' => 'collection/theme',
    'router_path' => 'collection',
    'link_title' => 'By Theme',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-case-facets_by-theme:collection/theme',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-case-facets_by-tribe-featured:collection/tribe.
  $menu_links['menu-case-facets_by-tribe-featured:collection/tribe'] = array(
    'menu_name' => 'menu-case-facets',
    'link_path' => 'collection/tribe',
    'router_path' => 'collection',
    'link_title' => 'By Tribe Featured',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-case-facets_by-tribe-featured:collection/tribe',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-case-facets_case-study-series:node/295.
  $menu_links['menu-case-facets_case-study-series:node/295'] = array(
    'menu_name' => 'menu-case-facets',
    'link_path' => 'node/295',
    'router_path' => 'node/%',
    'link_title' => 'Case Study Series',
    'options' => array(
      'identifier' => 'menu-case-facets_case-study-series:node/295',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-case-facets_submit-a-case-study:node/296.
  $menu_links['menu-case-facets_submit-a-case-study:node/296'] = array(
    'menu_name' => 'menu-case-facets',
    'link_path' => 'node/296',
    'router_path' => 'node/%',
    'link_title' => 'Submit a Case Study',
    'options' => array(
      'identifier' => 'menu-case-facets_submit-a-case-study:node/296',
    ),
    'module' => 'menu',
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
  t('All Cases, A-Z');
  t('Assessment');
  t('By Academic Discipline');
  t('By Theme');
  t('By Tribe Featured');
  t('Case Study Series');
  t('Home');
  t('Resources');
  t('Submit a Case Study');
  t('Teaching with Cases');

  return $menu_links;
}
