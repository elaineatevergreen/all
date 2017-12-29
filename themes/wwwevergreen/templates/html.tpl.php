<?php

/**
	
Right now I think the only difference from the default html.tpl.php is the inclusion of a whole bunch of favicon links.
	
	
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup themeable
 */
?><!DOCTYPE html>
<html dir="<?php print $language->dir; ?>" lang="<?php print $language->language; ?>">

<head profile="<?php print $grddl_profile; ?>">
  <?php print $head; ?>
  <title>
  	<?php print $head_title; ?>
  </title>
  <?php print $styles; ?>
  
  <meta content="width=device-width, minimum-scale=1.0" name="viewport" />
	<meta content="Evergreen" name="apple-mobile-web-app-title" />
	
	<link href="<?php print base_path() . path_to_theme() ?>/images/favicons/site-icon.png" rel="apple-touch-icon"/><!-- Homescreen icon -->
	<link color="#64933a" href="<?php print base_path() . path_to_theme() ?>/images/favicons/apple-pinned-tab.svg" rel="mask-icon"/><!-- Safari 9+ -->
	<meta content="#64933a" name="msapplication-TileColor"/><!-- Windows 8, IE10 -->
	<meta content="<?php print base_path() . path_to_theme() ?>/images/favicons/mstile-144x144.png" name="msapplication-TileImage"/><!-- Windows 8, IE10 -->
	<link href="<?php print base_path() . path_to_theme() ?>/images/favicons/favicon.ico" rel="shortcut icon" type="image/x-icon"/><!-- IE and hi-dpi favicon -->
	<!-- favicons for everybody else -->
	<link href="<?php print base_path() . path_to_theme() ?>/images/favicons/favicon-16.png" rel="icon" sizes="16x16" type="image/png"/>
	<link href="<?php print base_path() . path_to_theme() ?>/images/favicons/favicon-32.png" rel="icon" sizes="24x24" type="image/png"/>
	<link href="<?php print base_path() . path_to_theme() ?>/images/favicons/favicon-32.png" rel="icon" sizes="32x32" type="image/png"/>
	<link href="<?php print base_path() . path_to_theme() ?>/images/favicons/favicon-64.png" rel="icon" sizes="64x64" type="image/png"/>
	<link href="<?php print base_path() . path_to_theme() ?>/images/favicons/favicon.svg" rel="icon" type="image/svg+xml"/><!-- Firefox 41+ -->
	
	<link href="<?php print base_path() . path_to_theme() ?>/css/dist/print.css" media="print" rel="stylesheet" />
	
	<!-- Typekit -->
	<link rel="stylesheet" href="https://use.typekit.net/kfy7nbq.css">
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
  <?php
	  print $scripts;  // Include scripts from the theme .info file.
  ?>
  <?php 
	  // Any site-wide ad tracking scripts go here. This allows them to be turned off for service center, test, or local sites.
	  if(theme_get_setting('evergreen_ad_tracking')) { ?>
  <?php }; ?>
</body>
</html>
