<?php

/**
	
This theme file includes the header and footer that are displayed across the entire site.
Because it still uses so much of the basic page.tpl materials, I've left the usual documentation intact.

If you're looking for the page header or footer (basic identity elements), check the files in the "pseudoblocks" folder.
The staticblocks function is used to include those sections as needed for easier editing.	
	

 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>

<?php
$evergreen_blocks = theme_get_setting('evergreen_blocks');
?>

<div class="row box" id="sitewide-alert"><!--This is a placeholder. Keep it empty.--></div>
	<header class="row" role="banner">
		
		
		<?php 
			/* one of the locations where we can switch between standard Evergreen site elements
				and customizations for public service centers.
				*/
			
			//main site
			if($evergreen_blocks == 1):
				staticblocks('page-header');
			
			// markup & regions for service center sites
			else:
		?>
			<div class="header-dropdowns">
				<div class="header-dropdown">
					<?php print render($page['header_dropdowns']);  ?>
				</div>
			</div>
			
			<div class="page-header">
				<div class="logo">
					<?php
					 if ($logo): 
					 ?>
		      <a href="<?php print $front_page; ?>" rel="home" id="logo">
		        <img src="<?php print $logo; ?>" alt="<?php print $site_name; ?>" />
		      </a>
		      	<?php else:
			      	//what should happen if the logo doesn't exist?
			      	?>
			      	<a href="<?php print $front_page; ?>" rel="home" id="logo"><?php print $site_name; ?></a>
		      <?php
			      	endif; //end check for logo
			    ?>
				</div>
			</div>
		
		<?php
			
			endif; //end check for public service center
		?>
		
		

	<nav class="top-nav" role="navigation">
		<?php 
		
		//navigation build using the Drupal menu system.
		//global navigation, always appears.
		print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('class' => array('top-nav-list')))); 
		
		?>            
	</nav>
</header><!-- /.row -->


<section class="site-content">
	
	<div class="main-background2">
		<?php print render($page['background_image']); ?>
	</div>
	

	<header class="row">
		<div class="grid grid-alt wrapper">
			<div class="site-name unit-5-7"><?php print render($page['section_title']); ?></div>
		</div>
	</header>

	<main id="main-row" class="main-row row wrapper">
		<div class="grid main-row-grid">
		
			<div class="tertiary-nav-wrapper unit-1-7">
				<?php 
					/* render anything that's in the section navigation. see region--section_nav.tpl.php for that markup. */
					print render($page['section_nav']); 
					
					/* then any 1st column content outside of the nav. usually search filters? */
					print render($page['filters']); 
				?>
			</div>
	
	    <div id="primary-content-wrapper" class="primary-content-wrapper unit-4-7">
		      
				<article class="main-content">
		      
				<?php 
					/* and now, all the main column content coming out of Drupal... */	
					
					print $messages; 
					if ($page['highlighted']): 
				?>
	        	<div id="highlighted"><?php print render($page['highlighted']); ?></div>
				<?php endif; ?>
	        <a id="main-content"></a>
	        	<?php 
		        	print render($title_prefix); 
		        	
			        if ($title and substr($title,-4)!='Home'): 
				?>
						<h1 class="title" id="page-title"><?php print $title; ?></h1>
				<?php 
					endif; 
					print render($title_suffix); 
					if ($tabs): 
				?>
						<div class="tabs"><?php print render($tabs); ?></div>
				<?php 
					endif; 
					
					print render($page['help']); 
					
					if ($action_links): 
				?>
						<ul class="action-links"><?php print render($action_links); ?></ul>
				<?php 
					endif; 
					
					print render($page['content']); 
					
					//really? this is an odd default Drupalism.
					//print $feed_icons; 
					
				?>
	      	
	      </article> <!-- /.main-content -->
	    </div> <!-- /#content-wrapper -->
	      
			<div id="sidebar-wrapper" class="sidebar-wrapper unit-2-7">
				<section class="sidebar">
					<?php print render($page['secondary_content']); ?>
				</section><!-- /.sidebar -->
			</div>
		
		</div> <!-- end .main-row-grid -->
	</main>

</section>

<!-- Page Footer -->
<footer class="row page-footer" role="contentinfo">
	<div class="wrapper">
		<div class="grid">
			<?php 
				/* 
					another place where we switch between the standard Evergreen footer 
					and possible service center footers.
				*/
				if ($evergreen_blocks == 1): 
					staticblocks('page-footer');
				else: 
					print render($page['footer']); 
				endif; 
			?>
		</div><!--/.grid-->
	</div><!--/.wrapper-->
</footer>