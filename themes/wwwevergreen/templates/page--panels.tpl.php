<?php

/**
	this template file applies to pages created via Page Manager/Panels.
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
			</div>
			
		<!-- 
			
			for Panel pages, the wrapping divs are classed in the Page Manager interface. 
			this doesn't seem to have quite the right markup; let's see what we can do. -emn
			
			/* 
			Primary column has the class "primary-content-wrapper unit-4-7 
			Region in that column is "main-content" 
			Secondary column has the class "sidebar-wrapper unit-2-7" 
			Region in that column is "sidebar"
			*/
		
		-->
		
		
	
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
			<p class="footer-map"><a href="http://evergreen.edu/tour/home"><img alt="Map of Washington" src="<?php echo($base_path . $directory) ?>/images/map-land-cover.jpg"/></a><br/>
			<small>&#169; <abbr title="Washington">WA</abbr> <abbr title="Department">Dept.</abbr> of&#160;Ecology</small></p>
			<ul class="element-list link-list">
				<li><a href="http://evergreen.edu/employment">Jobs at Evergreen</a></li>
				<li><a href="http://evergreen.edu/give">Give to Evergreen</a></li>
				<li>
					<p>Stay connected:</p>
					<ul class="element-list lineup">
						<li><a href="http://facebook.com/TheEvergreenStateCollege" title="Facebook"><img alt="Facebook" class="lineup-icon" src="<?php echo($base_path . $directory) ?>/images/icons/external/facebook32x32.png"/></a></li>
						<li><a href="http://twitter.com/EvergreenStCol" title="Twitter"><img alt="Twitter" class="lineup-icon" src="<?php echo($base_path . $directory) ?>/images/icons/external/twitter32x32.png"/></a></li>
						<li><a href="http://youtube.com/user/evergreen" title="YouTube"><img alt="YouTube" class="lineup-icon" src="<?php echo($base_path . $directory) ?>/images/icons/external/youtube32x32.png"/></a></li>
						<li><a href="http://instagram.com/TheEvergreenStateCollege" title="Instagram"><img alt="Instagram" class="lineup-icon" src="<?php echo($base_path . $directory) ?>/images/icons/external/instagram32x32.png"/></a></li>
						<li><a href="http://www.linkedin.com/edu/school?id=19655" title="LinkedIn"><img alt="LinkedIn" class="lineup-icon" src="<?php echo($base_path . $directory) ?>/images/icons/external/linkedin32x32.png"/></a></li>
					</ul>
				</li>
			</ul>
		</div>
		<!-- /.unit-3-7 -->
		<div class="unit-2-7">
			<div class="base vcard">
			<div class="fn org">The&#160;Evergreen State&#160;College</div>
			<div class="adr">
			<div class="street-address">2700 Evergreen Parkway&#160;NW</div>
			<div class="location"><span class="locality">Olympia</span>, <span class="region">Washington</span> <span class="postal-code">98505</span></div>
		</div>
		<!-- /.adr -->
		<div class="tel">360-867-6000</div>
		<div><a href="http://evergreen.edu/directories">Phone &amp; Email Directories</a></div>
		</div>
		<!-- /.vcard --></div>
		<!-- /.unit-2-7 -->
		<div class="unit-2-7">
		<ul class="element-list link-list">
		<li>
		<div class="copyright">&#169; <?php echo date("Y") ?> The&#160;Evergreen State&#160;College</div>
		</li>
		<!--<li class="do-not-print"><a href="#">Privacy Policy</a></li>-->
		<li class="do-not-print"><a href="http://www.evergreen.edu/news/weatherdelays">Emergency Information</a> <small>(Includes alerts about delays and closures.)</small></li>
		<li class="do-not-print"><a href="http://www.evergreen.edu/about/privacy.htm">Privacy Policy</a></li>
		</ul>
		</div><!--/.unit-2-7-->
		</div><!--/.grid-->
		<?php else: 
			print render($page['footer']); 
		endif; ?>
	</div><!--/.wrapper-->
</footer>