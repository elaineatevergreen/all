<?php
/**
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
  <meta charset="utf-8" />
  <!-- Google Analytics Experiments -->
  <?php
		if ($node = menu_get_object()) {
			$nid = $node->nid;
		}
		if (isset($nid)) {
			if ($nid == 19197) {  // /admissions/visit
	?>
				<!-- Experiment: CTA Buttons vs Links -->
				<script>function utmx_section(){}function utmx(){}(function(){var
				k='734515-20',d=document,l=d.location,c=d.cookie;
				if(l.search.indexOf('utm_expid='+k)>0)return;
				function f(n){if(c){var i=c.indexOf(n+'=');if(i>-1){var j=c.
				indexOf(';',i);return escape(c.substring(i+n.length+1,j<0?c.
				length:j))}}}var x=f('__utmx'),xx=f('__utmxx'),h=l.hash;d.write(
				'<sc'+'ript src="'+'http'+(l.protocol=='https:'?'s://ssl':
				'://www')+'.google-analytics.com/ga_exp.js?'+'utmxkey='+k+
				'&utmx='+(x?x:'')+'&utmxx='+(xx?xx:'')+'&utmxtime='+new Date().
				valueOf()+(h?'&utmxhash='+escape(h.substr(1)):'')+
				'" type="text/javascript" charset="utf-8"><\/sc'+'ript>')})();
				</script><script>utmx('url','A/B');</script>
	<?php
			} elseif ($nid == 83161){  // /admitted
	?>
				<!-- Experiment: CTA .action-call vs .spotlight > .button.prime -->
				<script>function utmx_section(){}function utmx(){}(function(){var
				k='734515-21',d=document,l=d.location,c=d.cookie;
				if(l.search.indexOf('utm_expid='+k)>0)return;
				function f(n){if(c){var i=c.indexOf(n+'=');if(i>-1){var j=c.
				indexOf(';',i);return escape(c.substring(i+n.length+1,j<0?c.
				length:j))}}}var x=f('__utmx'),xx=f('__utmxx'),h=l.hash;d.write(
				'<sc'+'ript src="'+'http'+(l.protocol=='https:'?'s://ssl':
				'://www')+'.google-analytics.com/ga_exp.js?'+'utmxkey='+k+
				'&utmx='+(x?x:'')+'&utmxx='+(xx?xx:'')+'&utmxtime='+new Date().
				valueOf()+(h?'&utmxhash='+escape(h.substr(1)):'')+
				'" type="text/javascript" charset="utf-8"><\/sc'+'ript>')})();
				</script><script>utmx('url','A/B');</script>
	<?php
			}
		}
	?>
	<!-- End of Google Analytics Content Experiment code -->
  <?php print $head; ?>
  <title>
  	<?php print $head_title; ?>
  </title>
  <?php print $styles; ?>
  
  <meta content="width=device-width, minimum-scale=1.0" name="viewport" />
  <meta content="Evergreen" name="application-name" />
	<meta content="Evergreen" name="apple-mobile-web-app-title" />
	
	<!-- SVG -->
	<link href="<?php print base_path() . path_to_theme() ?>/images/favicons/favicon.svg?cache=1" rel="icon" type="image/svg+xml"/><!-- Firefox -->
	<link color="#64933a" href="<?php print base_path() . path_to_theme() ?>/images/favicons/apple-pinned-tab.svg?cache=1" rel="mask-icon"/><!-- Safari 9+ -->
	<!-- Config -->
	<meta content="<?php print base_path() . path_to_theme() ?>/images/favicons/browserconfig.xml" name="msapplication-config"/><!-- Windows, Edge -->
	<link rel="manifest" href="<?php print base_path() . path_to_theme() ?>/images/favicons/site.webmanifest?cache=1" type="application/manifest+json"/><!-- Android Chrome -->
	<!-- PNG -->
	<link href="<?php print base_path() . path_to_theme() ?>/images/favicons/site-icon.png?cache=1" rel="apple-touch-icon" sizes="276x276"/><!-- Homescreen icon, iOS, Android -->
	<!-- Favicons for everybody else -->
	<link href="<?php print base_path() . path_to_theme() ?>/images/favicons/favicon-16.png?cache=1" rel="icon" sizes="16x16" type="image/png"/>
	<link href="<?php print base_path() . path_to_theme() ?>/images/favicons/favicon-32.png?cache=1" rel="icon" sizes="24x24" type="image/png"/>
	<link href="<?php print base_path() . path_to_theme() ?>/images/favicons/favicon-32.png?cache=1" rel="icon" sizes="32x32" type="image/png"/>
	<link href="<?php print base_path() . path_to_theme() ?>/images/favicons/favicon-64.png?cache=1" rel="icon" sizes="64x64" type="image/png"/>
	<!-- ICO -->
	<link href="<?php print base_path() . path_to_theme() ?>/images/favicons/favicon.ico" rel="shortcut icon" type="image/x-icon"/><!-- Legacy -->
	
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
