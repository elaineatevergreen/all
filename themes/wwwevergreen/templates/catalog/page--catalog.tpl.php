<?php

/**

 * @file
 * Wide page for catalog index.

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

	<main id="main-row" class="main-row row wrapper" role="main">
		<div class="grid main-row-grid">
		
			<div class="tertiary-nav-wrapper unit-1-7">
				<?php 
					/* render anything that's in the section navigation. see region--section_nav.tpl.php for that markup. */
					print render($page['section_nav']); 
					
					/* then any 1st column content outside of the nav. usually search filters? */
					print render($page['filters']); 
				?>
			</div>
	
	    <div id="index-wrapper" class="index-wrapper unit-6-7">
		      
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
		        	
			        if ($title and $title!='Home'): 
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
	      	<?php print render($page['secondary_content']); ?>
	      </article>
	    </div> <!-- /.main-content, /#content-wrapper -->
	      

		
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