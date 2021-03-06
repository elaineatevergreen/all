<?php

/**
	this template file applies to pages created via Page Manager/Panels.
	
	Panel pages get their grid classes from the Panels interface.
			
	Go to [siteurl]/admin/structure/pages and click "Edit" for the page you want
	Go to Content
	Click "Show layout designer"
			
	* Canvas > Canvas settings
	* Column > Column settings
	
	
 */
?>

<?php
	$evergreen_blocks = theme_get_setting('evergreen_blocks');
?>

<header class="row" role="banner">
		
	<?php 
		/**
		 * one of the locations where we can switch between standard Evergreen site elements
		 * and customizations for public service centers.
		 */
		
		// main site
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
		
		//audience navigation, only appears on the home page.
		//leaving this here for now even though it doesn't actually fire on www site
		if($is_front == TRUE) { 
			print theme('links', array('links' => menu_navigation_links('menu-audience-navigation'), 'attributes' => array('class'=> array('secondary-nav-list')) ));
		};	
		?>            
	</nav>
</header><!-- /.row -->


<section class="site-content">
	<?php
		// I don’t think we need tabs in panels pages.
	?>
	<!--<?php if ($tabs): ?>
		<div class="tabs">
			<?php print render($tabs); ?>
		</div>
	<?php endif; ?>-->

	<div class="main-background2">
		<?php print render($page['background_image']); ?>
	</div>
	
	<?php 
		/* only show the header region if this is NOT the front page */
		if($is_front == FALSE) { ?>
		<header class="row">
			<div class="grid grid-alt wrapper">
				<div class="site-name unit-5-7"><?php print render($page['section_title']); ?></div>
			</div>
		</header>
	<?php }; ?>
	
	<div id="main-content"></div>
	<?php /* for Panels pages, there are no wrapping grid divs. */ ?>
	<?php print $messages; ?>
	<?php if ($page['highlighted']): ?>
		<div id="highlighted">
			<?php print render($page['highlighted']); ?>
		</div>
	<?php endif; ?>
	<?php print render($title_prefix); ?>
	<?php if ($title and $title!='Home'): ?>
		<h1 class="title" id="page-title">
			<?php print $title; ?>
		</h1>
	<?php endif; ?>
	<?php print render($title_suffix); ?>	<?php print render($page['help']); ?>
	<?php if ($action_links): ?>
		<ul class="action-links">
			<?php print render($action_links); ?>
		</ul>
	<?php endif; ?>
	<?php print render($page['content']); ?>
	<?php print $feed_icons; ?>
</section>

<!-- Page Footer -->
<?php 
	/*
		Choose either the standard Evergreen footer or a custom footers
		(e.g. for service centers).
	*/
	if ($evergreen_blocks == 1): 
		staticblocks('page-footer');
	else: 
		print render($page['footer']); 
	endif; 
?>