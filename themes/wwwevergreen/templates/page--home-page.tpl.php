<?php
/**
	
The home page has both a node.tpl AND a page.tpl.
It's easier to get at the individual fields inside of node.tpl, so most of the content is in there.
The page.tpl establishes the basic difference in grid: ie the lack of side navigation.

Right now this file duplicates a lot of the header and footer content of the site, which is super not-cool.
We'll have to do something about that.

*/
?>
<div class="row box" id="sitewide-alert"><!--This is a placeholder. Keep it empty.--></div>
<header class="row" role="banner">
	<div class="header-dropdowns">
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
				<form action="/search/home" class="search" method="get" role="search">
					<label for="q">Search</label> 
					<input id="q" name="q" placeholder="Search" type="search"/><!-- -->
					<button class="search-button">
						<img alt="Search" src="<?php echo($base_path . $directory) ?>/images/search-32.png"/>
					</button> 
					<ul class="element-list search-tools">
						<li class="internal-users-alt">
							<a href="https://my.evergreen.edu">
								<img alt="User" height="10" src="<?php echo($base_path . $directory) ?>/images/user-32.png" width="10"/> my.evergreen.edu
							</a>
						</li>
						<li class="internal-users-alt">
							<a href="http://evergreen.edu/webmail">Webmail</a>
						</li>
						<li>
							<a href="http://evergreen.edu/directories.htm">Directories</a>
						</li>
					</ul>
				</form>
			</div><!-- /.header-dropdown -->
		</div><!-- /.top-search -->
	</div><!-- /.header-dropdowns -->
	<div class="page-header">
		<div class="logo">
			<a href="http://evergreen.edu">
				<img alt="The Evergreen State College&#8212;Olympia, Washington" src="<?php echo($base_path . $directory) ?>/images/logo.png" srcset="<?php echo($base_path . $directory) ?>/images/evergreen-long-tree-oly.svg 1x, <?php echo($base_path . $directory) ?>/images/evergreen-long-tree-oly.svg 2x"/>
			</a>
		</div>
		<div class="off-canvas">
			<label class="search-toggle" for="search-flag"><img alt="Search" src="<?php echo($base_path . $directory) ?>/images/search-w32.png"/></label> 	
			<label class="student-toggle" for="internal-users-flag"><img alt="Profile" src="<?php echo( $base_path . $directory) ?>/images/user-w32.png"/></label>
		</div>
	</div>
	<nav class="top-nav" role="navigation">
		<?php 
		//navigation built using the Drupal menu system.
		//global navigation, always appears.
		print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('class' => array('top-nav-list')))); 
		
		//audience navigation, only appears on the home page.
		if($is_front == TRUE) { 
			print theme('links', array('links' => menu_navigation_links('menu-audience-navigation'), 'attributes' => array('class'=> array('secondary-nav-list')) ));
		};	
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
	<?php print render($page['primary_content']); //I don't know if anything actually uses the "primary content" region, since "content" is required?! ?>
	<?php print $feed_icons; ?>
	<!-- 	</div> --><!-- /.wrapper --> <!-- end adding in margins -->
</div><!-- /.row -->




<!-- Page Footer -->
<footer class="row page-footer" role="contentinfo">
	<div class="wrapper">
		<div class="grid">
			<div class="do-not-print unit-3-7">
				<p class="footer-map">
					<a href="http://evergreen.edu/tour/home">
						<img alt="Map of Washington" src="<?php echo($base_path . $directory) ?>/images/map-land-cover.jpg"/>
					</a><br/>
					<small>© <abbr title="Washington">WA</abbr> <abbr title="Department">Dept.</abbr> of&#160;Ecology</small>
				</p>
				<ul class="element-list link-list">
					<li><a href="http://evergreen.edu/employment">Jobs at Evergreen</a></li>
					<li><a href="http://evergreen.edu/give">Give to Evergreen</a></li>
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
			</div><!-- /.unit-3-7 -->
			<div class="unit-2-7">
				<p class="v-card">
					<span class="p-name p-org">The&#160;Evergreen State&#160;College</span><br/>
					<span class="h-adr">
						<span class="p-street-address">2700 Evergreen Parkway&#160;NW</span><br/>
						<span class="location">
							<span class="p-locality">Olympia</span>,
							<span class="p-region">Washington</span>
							<span class="p-postal-code">98505</span>
						</span>
					</span><!-- /.adr --><br/>
					<span class="p-tel">360-867-6000</span><br/>
					<span>
						<a href="http://evergreen.edu/directories">Phone &amp; Email Directories</a>
					</span>
				</p><!-- /.vcard -->
			</div><!-- /.unit-2-7 -->
			<div class="unit-2-7">
				<ul class="element-list link-list">
					<li>
						<div class="copyright">© <?php echo date("Y") ?> The&#160;Evergreen State&#160;College</div>
					</li>
					<!--<li class="do-not-print"><a href="#">Privacy Policy</a></li>-->
					<li class="do-not-print">
						<a href="http://www.evergreen.edu/news/weatherdelays">Emergency Information</a>
						<small>(Includes alerts about delays and closures.)</small>
					</li>
					<li class="do-not-print">
						<a href="http://www.evergreen.edu/about/privacy.htm">Privacy Policy</a>
					</li>
				</ul>
			</div><!--/.unit-2-7-->
		</div><!--/.grid-->
	</div><!--/.wrapper-->
</footer>