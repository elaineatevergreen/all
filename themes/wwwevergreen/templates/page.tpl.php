<?php

/**
	
This theme file includes the header and footer that are displayed across the entire site.
Because it still uses so much of the basic page.tpl materials, I've left the usual documentation intact.	
	

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
		
		
		<div class="header-dropdowns">
			<?php if ($evergreen_blocks == 1): ?>
				<div>
					<input id="internal-users-flag" name="header-toggle" type="checkbox"/> 
					<ul class="element-list header-dropdown internal-users">
						<li><a href="https://my.evergreen.edu"><img alt="User" height="10" src="<?php echo($base_path . $directory) ?>/images/user-32.png" width="10"/> my.evergreen.edu</a></li>
						<li><a href="http://evergreen.edu/webmail">Webmail</a></li>
					</ul>
				</div>
				<div class="top-search">
					<input id="search-flag" name="header-toggle" type="checkbox"/> 
					<div class="header-dropdown">
						<form action="http://evergreen.edu/search/home" class="search" method="get" role="search">
							<label for="q">Search</label> 
							<input id="q" name="q" placeholder="Search" type="search"/><!-- -->
							<button class="search-button">
								<img alt="Search" src="<?php echo($base_path . $directory) ?>/images/search-32.png"/>
							</button> 
							<ul class="element-list search-tools">
								<li class="internal-users-alt"><a href="https://my.evergreen.edu">
									<img alt="User" height="10" src="<?php echo($base_path . $directory) ?>/images/user-32.png" width="10"/> my.evergreen.edu</a>
								</li>
								<li class="internal-users-alt"><a href="http://evergreen.edu/webmail">Webmail</a></li>
								<li><a href="http://evergreen.edu/directories.htm">Directories</a></li>
							</ul>
						</form>
					</div>
				</div>
			<?php 
			//if this isn't using our search field and tabs, then render block in region as set in Structure > Blocks
			else: 
			?>
				<div class="header-dropdown">
					<?php print render($page['header_dropdowns']);  ?>
				</div>
			<?php 
			endif; //end check for whether it's using our stuff
			?>
		</div>
		
		<div class="page-header">
			<div class="logo">
			
			
			
				<?php
					/* I'm attempting some generalization here so as to be able to use public service center logos. */
					
					 if ($evergreen_blocks != 1 and $logo): ?>
		      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
		        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
		      </a>
		      
				<?php else: ?>
		      <a href="http://evergreen.edu">
			      <img alt="The Evergreen State College&#8212;Olympia, Washington" src="<?php echo($base_path . $directory) ?>/images/logo.png" srcset="<?php echo($base_path . $directory) ?>/images/evergreen-long-tree-oly.svg 1x, <?php echo($base_path . $directory) ?>/images/evergreen-long-tree-oly.svg 2x"/>
			     </a>
		      
		    <?php endif; //end logo check ?>
				
			</div>
			
			<?php if ($evergreen_blocks == 1): ?>
				<div class="off-canvas">
					<label class="search-toggle" for="search-flag">
						<img alt="Search" src="<?php echo($base_path . $directory) ?>/images/search-w32.png"/>
					</label>
					<label class="student-toggle" for="internal-users-flag">
						<img alt="Profile" src="<?php echo( $base_path . $directory) ?>/images/user-w32.png"/>
					</label>
				</div>
			<?php endif; //end off-canvas tabs check ?>
		</div>


	<nav class="top-nav" role="navigation">
		<?php 
		
		//navigation build using the Drupal menu system.
		//global navigation, always appears.
		print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('class' => array('top-nav-list')))); 
		
		//audience navigation, only appears on the home page.
		if($is_front == TRUE) { 
			print theme('links', array('links' => menu_navigation_links('menu-audience-navigation'), 'attributes' => array('class'=> array('secondary-nav-list')) ));
		};	
		?>            
	</nav>
</header><!-- /.row -->


<section class="site-content">
	
	<!-- this would be the right one per the new CSS, but since I'm not getting the class on the img tag it doesn't work. -->
	<!-- I think this works now. —jkm -->
	<div class="main-background2">
		<?php print render($page['background_image']); ?>
	</div>
	

	<header class="row">
		<div class="grid grid-alt wrapper">
			<div class="site-name unit-5-7"><?php print render($page['section_title']); ?></div>
		</div>
	</header>

	<main id="main-row" class="main-row row wrapper" role="main">
		<div class="grid main-row-grid">
		
			<div class="tertiary-nav-wrapper unit-1-7">
				<?php 
					
					/* 
					
						Drupal things get SUPER WEIRD in here. 
					
					*/
					
					print render($page['section_nav']); 
				?>
				<?php 
					
					/* 
					
						This is for stuff outside of the <nav> element 
					
					*/
					
					print render($page['filters']); 
				?>
			</div>
	
	    <div id="primary-content-wrapper" class="primary-content-wrapper unit-4-7">
		      
				<article class="main-content">
		      
					<?php 
						/* lots of content in here for Drupaling */	
					?>
					<?php print $messages; ?>
	        <?php if ($page['highlighted']): ?>
	        	<div id="highlighted"><?php print render($page['highlighted']); ?></div>
	        <?php endif; ?>
	        <a id="main-content"></a>
	        <?php print render($title_prefix); ?>
	        <?php if ($title and $title!='Home'): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
	        <?php print render($title_suffix); ?>
	        <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
	        <?php print render($page['help']); ?>
	        <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
	        <?php print render($page['content']); ?>
	        <?php print render($page['primary_content']); //I don't know if anything actually uses the "primary content" region, since "content" is required?! ?>
	        <?php print $feed_icons; ?>
	      	
	      </article>
	    </div> <!-- /.main-content, /#content-wrapper -->
	      
			<div id="sidebar-wrapper" class="sidebar-wrapper unit-2-7">
				<section class="sidebar">
					<?php print render($page['secondary_content']); ?>
							
					<?php
							
						/* because Drupal sites often have sidebar regions, let's just let them show up if they exist. */
						/* except that it throws an error. sadness. :(
								
					?>		
					<?php if ($page['sidebar_first']): print render($page['sidebar_first']); endif; ?>
					<?php if ($page['sidebar_second']):  print render($page['sidebar_second']); endif;  */ ?>
							
				</section><!-- /.sidebar -->
			</div>
		
		</div> <!-- end .main-row-grid -->
	</main>

	<!-- this is the old style of showing the background image, but it works. -->
	<!-- Commenting this out, because I believe I got main-background2 working correctly. —jkm -->
	<!--<div class="main-background"><?php /*print render($page['background_image']);*/ ?></div>-->

</section>

<!-- Page Footer -->
<footer class="row page-footer" role="contentinfo">
	<div class="wrapper">
		<div class="grid">
			<?php if ($evergreen_blocks == 1): ?>
				<div class="do-not-print unit-3-7">
					<p class="footer-map">
						<a href="http://evergreen.edu/tour/home">
							<img alt="Map of Washington" src="<?php echo($base_path . $directory) ?>/images/map-land-cover.jpg"/>
						</a><br/>
						<small>&#169;
							<abbr title="Washington">WA</abbr> <abbr title="Department">Dept.</abbr> of&nbsp;Ecology
						</small>
					</p>
					<ul class="element-list text-list-alt">
						<li>
							<a href="http://evergreen.edu/employment">Jobs at Evergreen</a>
						</li>
						<!--<li>
							<a href="http://evergreen.edu/give">Give to Evergreen</a>
						</li>-->
						<li>
							<a href="http://evergreen.edu/tour/home">Tours and Maps</a>
						</li>
						<li>
							<p>Stay connected:</p>
							<ul class="element-list lineup">
								<li>
									<a href="http://facebook.com/TheEvergreenStateCollege" title="Facebook">
										<img alt="Facebook" class="lineup-icon" src="<?php echo($base_path . $directory) ?>/images/icons/external/facebook.svg"/>
									</a>
								</li>
								<li>
									<a href="http://twitter.com/EvergreenStCol" title="Twitter">
										<img alt="Twitter" class="lineup-icon" src="<?php echo($base_path . $directory) ?>/images/icons/external/twitter.svg"/>
									</a>
								</li>
								<li>
									<a href="http://youtube.com/user/evergreen" title="YouTube">
										<img alt="YouTube" class="lineup-icon" src="<?php echo($base_path . $directory) ?>/images/icons/external/youtube.svg"/>
									</a>
								</li>
								<li>
									<a href="http://instagram.com/TheEvergreenStateCollege" title="Instagram">
										<img alt="Instagram" class="lineup-icon" src="<?php echo($base_path . $directory) ?>/images/icons/external/instagram.png"/>
									</a>
								</li>
								<li>
									<a href="http://www.linkedin.com/edu/school?id=19655" title="LinkedIn">
										<img alt="LinkedIn" class="lineup-icon" src="<?php echo($base_path . $directory) ?>/images/icons/external/linkedin.svg"/>
									</a>
								</li>
							</ul>
						</li>
					</ul>
				</div><!-- /.do-not-print.unit-3-7 -->
				<div class="unit-2-7">
					<div class="base vcard">
						<div class="fn org">The&nbsp;Evergreen State&nbsp;College</div>
						<div class="adr">
							<div class="street-address">2700 Evergreen Parkway&nbsp;NW</div>
							<div class="location">
								<span class="locality">Olympia</span>,
								<span class="region">Washington</span>
								<span class="postal-code">98505</span>
							</div>
						</div><!-- /.adr -->
						<div class="tel">(360)&nbsp;867-6000</div>
						<div>
							<a href="http://evergreen.edu/directories">Phone &amp; Email Directories</a>
						</div>
					</div><!-- /.vcard -->
				</div><!-- /.unit-2-7 -->
				<div class="unit-2-7">
					<ul class="element-list text-list-alt">
						<li>
							<div class="copyright">©
								<?php echo date("Y") ?> The&nbsp;Evergreen State&nbsp;College
							</div>
						</li>
						<li class="do-not-print">
							<a href="http://www.evergreen.edu/news/weatherdelays">Emergency Information</a>
							<small>(Includes alerts about delays and closures.)</small>
						</li>
						<li class="do-not-print">
							<a href="http://www.evergreen.edu/about/privacy.htm">Privacy Policy</a>
						</li>
					</ul>
				</div><!--/.unit-2-7-->
			<?php else: 
				print render($page['footer']); 
			endif; ?>
		</div><!--/.grid-->
	</div><!--/.wrapper-->
</footer>