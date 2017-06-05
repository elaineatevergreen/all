<?php
/**
	
The home page has both a node.tpl AND a page.tpl.
It's easier to get at the individual fields inside of node.tpl, so most of the content is in there.
The page.tpl establishes the basic difference in grid: ie the lack of side navigation.

Right now this file duplicates a lot of the header and footer content of the site, which is super not-cool.
We'll have to do something about that.

*/
?>
<?php
$evergreen_blocks = theme_get_setting('evergreen_blocks');
?>

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
		//navigation built using the Drupal menu system.
		//global navigation, always appears.
		print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('class' => array('top-nav-list')))); 
		
		//audience navigation, only appears on the home page.
		print theme('links', array('links' => menu_navigation_links('menu-audience-navigation'), 'attributes' => array('class'=> array('secondary-nav-list')) ));	
		?>
	</nav>
</header><!-- /.row -->




<div class="row">
	<!--<div class="wrapper"> --> <!-- this adds in the margins for everything, which we don't want -->
	<!--<h1>OH HAI ARE U THE HOME PAGE?</h1>-->
	<?php print $messages; ?>
	<?php if ($page['highlighted']): ?>
		<div id="highlighted">
			<?php print render($page['highlighted']); ?>
		</div>
	<?php endif; ?>
	<a id="main-content"></a>
	<?php if ($tabs): ?>
		<div class="tabs">
			<?php print render($tabs); ?>
		</div>
	<?php endif; ?>
	<?php print render($page['help']); ?>
	<?php if ($action_links): ?>
		<ul class="action-links">
			<?php print render($action_links); ?>
		</ul>
	<?php endif; ?>
	<?php print render($page['content']); ?>
	<?php print $feed_icons; ?>
	<!-- 	</div> --><!-- /.wrapper --> <!-- end adding in margins -->
</div><!-- /.row -->




<!-- Page Footer -->
<footer class="row page-footer" role="contentinfo">
	<div class="wrapper">
		<div class="grid">
			<?php 
				/* 
					another place where we switch between the standard Evergreen footer 
					and possible service center footers.
				*/
				if (!empty($evergreen_blocks)):
					staticblocks('page-footer');
				else: 
					print render($page['footer']); 
				endif; 
			?>
		</div><!--/.grid-->
	</div><!--/.wrapper-->
</footer>