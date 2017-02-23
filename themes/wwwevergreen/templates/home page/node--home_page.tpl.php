<?php
	/**
		
	The home page has both a node.tpl AND a page.tpl.
	It's easier to get at the individual fields inside of node.tpl, so most of the content is in here.
	The page.tpl establishes the basic difference in grid: ie the lack of side navigation.
	
	This theme file contains all the fields and wrapping markup.
	As much as possible, use this file instead of creating individual field.tpl files.
	
	*/
?>

<!--Include SVG Icons-->

<!--<?php echo(file_get_contents($directory . '/images/icons/svg-icons-homepage/transporter-defs.svg'))?>
<?php echo(file_get_contents($directory . '/images/icons/svg-icons-homepage/fact-defs.svg'))?>-->

<!--HOMEPAGE HERO SECTION-->
<?php 
	/* 
		This is added via a View in this location. (or rather, just above this file). - emn
	*/
?>

<div class="row">
	<div class="wrapper">
		<div class="grid">
			<div class="standalone-unit unit-1-1">
				<!-- Location Transporter -->
				<p class="location-transporter">
					Olympia / <a href="/tacoma">Tacoma Program</a> / <a href="/tribal">Reservation-based Program</a>
				</p>
			</div><!-- /.standalone-unit.unit-1-1 -->
		</div><!-- /.grid -->
		
		<!-- Site Transporter -->
		<ul class="element-list grid transporter">
			<li class="unit-1-7 icon-scale">
				<a href="/about">
					<div class="transporter-icon">
						<img class="icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/green/info.png"/>
					</div>
					<div class="transporter-text">About Evergreen</div>
				</a>
			</li>
			<li class="unit-1-7 icon-scale">
				<a href="/studies">
					<div class="transporter-icon">
						<img class="icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/green/programs.png"/>
					</div>
					<div class="transporter-text">Fields of Study</div>
				</a>
			</li>
			<li class="unit-1-7 icon-scale">
				<a href="/admissions/visit">
					<div class="transporter-icon">
						<img class="icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/green/visit.png"/>
					</div>
					<div class="transporter-text">See Campus</div>
				</a>
			</li>
			<li class="unit-1-7 icon-scale transporter-call">
				<a href="/admissions/apply">
					<div class="transporter-icon">
						<img class="icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/apply.png"/>
					</div>
					<div class="transporter-text">Apply Now</div>
				</a>
			</li>
			<li class="unit-1-7 icon-scale">
				<a href="/catalog">
					<div class="transporter-icon">
						<img class="icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/green/catalog.png"/>
					</div>
					<div class="transporter-text">Catalog</div>
				</a>
			</li>
			<li class="unit-1-7 icon-scale">
				<a href="/admissions/apply">
					<div class="transporter-icon">
						<img class="icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/green/moon.png"/>
					</div>
					<div class="transporter-text">Evening and Weekend</div>
				</a>
			</li>
			<li class="unit-1-7 icon-scale">
				<a href="/admissions/apply">
					<div class="transporter-icon">
						<img class="icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/green/graduation.png"/>
					</div>
					<div class="transporter-text">Graduate Degrees</div>
				</a>
			</li>
			<!--<li class="unit-1-6-alt icon-scale">
				<a href="http://youvis.it/kcrkJP">
					<div class="transporter-icon">
						<img class="icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/tour.png"/>
					</div>
					<div class="transporter-text">Virtual Tour</div>
				</a>
			</li>-->
		</ul><!-- /.element-list.grid.transporter -->
	</div><!-- /.wrapper -->
</div><!-- /.row -->

<section class="site-content">
	<main class="main-row row wrapper" id="main-row" role="main">
		<div class="grid main-row-grid">
			<div class="tertiary-nav-wrapper unit-1-7">
				<!-- nothing to see here. -->
			</div>
			<div class="index-wrapper unit-6-7" id="index-wrapper">
				<!-- Main Content -->
				<article class="main-content">
						<!--Tertiary Navigation-->
						<nav class="box tertiary-nav-homepage" id="tertiary-nav">
							<?php print render($content['field_section_navigation']); ?>
						</nav>
						
						<!--This is the placeholder for the blob content. I commented it out
						because we're currently not using any Blobby content :P-->
	 					<!--<div class="grid">
							<p>This is NOT A PLACEHOLDER! Actually it is.</p>
							<?php print render($content['body']); ?>
						</div> -->
						
						<!-- Pullquote -->
	 					<!--<div class="grid">
							<figure class="unit-1-1">
								<div class="box pull-box pull-box-alt">
									<p class="pull-quote"><q>Pullquote to go here.</q></p>
									<figcaption>
										<p>—Person's name and identity</p>
									</figcaption>
								</div>
							</figure>
						</div> -->
						
						
						<!--Intro Sentence-->
						<p class="intro intro-alt"><?php print render($content['field_intro']); ?> <a href="about/">Learn more.</a></p>
						
						<div class="grid"><!--<div class="unit-1-1"><a href="/graduation/home"><img alt="See photos and more from graduation day" class="image-full" src="/graduation/images/grad-homepage-banner.jpg" /></a></div>-->
							<figure class="unit-1-1">
								<div class="box pull-box pull-box-alt">
									<p class="pull-quote">
										<q>Evergreen had an impact on me that I still feel. The skills I learned at Evergreen in communication, setting goals, leadership and personal ethics are with me every day. Evergreen was the perfect place for me.</q>
									</p>
									<figcaption>
										<p>—Chere Weiss, Community Outreach Coordinator, St. Johns Medical Center, Longview, Washington</p>
									</figcaption>
								</div>
							</figure>



							<!-- Incredible Experiences -->
							<div class="unit-1-1">
								<h2>Incredible Experiences</h2>
								<p>You&#8217;ll have many opportunities to explore your interests and discover new ones.</p>
							</div>
							<div class="unit-1-1">
								<ul class="element-list grid">
									<li class="unit-1-2">
										<a class="lazy-load" href="https://www.youtube.com/watch?v=a3hHMKwLvcc">
											<img alt="Imagine Yourself at Evergreen" src="<?php print base_path() . path_to_theme() ?>/images/homepage/beauty.jpg" />
										</a>
										<p>Imagine yourself at Evergreen. See a slice of what you&#8217;ll be a part of during your time here as a Greener.</p>
										<p><a href="/about/students">Explore profiles of current students</a> to see how Evergreen changes people&#8217;s lives.</p>
									</li>
									<li class="unit-1-2">
										<a class="lazy-load" href="https://www.youtube.com/watch?v=lQb5YUqSV9Y">
											<img alt="Chico Herbison" src="<?php print base_path() . path_to_theme() ?>/images/homepage/herbison.jpg" />
										</a>
										<p>Faculty member Chico Herbison talks about what makes learning at Evergreen so different from other colleges.</p>
										<p><a href="/academics">Learn about Evergreen&#8217;s unique academics.</a></p>
									</li>
								</ul>
							</div>
						</div>
	
						
						<!-- Magazine Features -->
	
						<div class="grid">
							<div class="unit-1-1">
								<h2>Professional Success</h2>
								<p>Evergreen alumni have gone on to become successful in every field they&#8217;ve entered, from art, business, and education to health care, media, and science.</p>
							</div>
							<div class="unit-1-1">
								<ul class="element-list grid">
									<li class="unit-1-2">
										<figure class="box caption-box">
											<a class ="profile-img-link" href="/magazine/2016spring-summer/calling-to-conserve">
												<img alt="Amanda Sargent ’10" class="image-full profile-img" src="<?php print base_path() . path_to_theme() ?>/images/homepage/profiles/amanda-sargent.jpg" />
											</a>
											<figcaption>
												<p>
													<a href="/magazine/2016spring-summer/calling-to-conserve">
														<strong>Amanda Sargent ’10</strong>
													</a> felt a calling to conserve.
												</p>
											</figcaption>
										</figure>
									</li>
									<li class="unit-1-2">
										<figure class="box caption-box">
											<a class="profile-img-link" href="/magazine/2016spring-summer/positioning-the-pnw-to-lead-in-sustainability">
												<img alt="Rhys Roth ’87, MES ’90" class="image-full profile-img" src="<?php print base_path() . path_to_theme() ?>/images/homepage/profiles/rhys-roth.jpg" />
											</a>
											<figcaption>
												<p>
													<a href="/magazine/2016spring-summer/positioning-the-pnw-to-lead-in-sustainability">
														<strong>Rhys Roth ’87, MES ’90</strong>
													</a> is positioning the Pacific Northwest to lead in sustainability.
												</p>
											</figcaption>
										</figure>
									</li>
								</ul>
							</div>
							<div class="unit-1-1">
								<p><a href="/about/graduates">Read more Evergreen alumni success stories.</a></p>
								<p>Read <a href="/magazine/home"><em>Evergreen Magazine</em></a> and catch up on the latest accomplishments of our alumni.</p>
							</div>
						</div>
						
						<!-- Fun Facts, heyyy! -->
						<!-- [ ] We may want to make this dynamic. I don’t know. -->
						<div class="row">
							<h2>Go Beyond</h2>
							<ul class="element-list grid">
								<li class="unit-1-3-alt">
									<div class="compound">
										<div class="compound-img">
											<!-- <img alt="Testing svgs" src="<?php //echo($base_path . $directory) ?>/images/icons/svg-icons-homepage/academic-resources.svg" /> -->
											<img alt="Academic resources icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/green/academic-resources.png">
											<!--<svg width="75">
												<use xlink:href="#icon-brain"></use>
											</svg>-->
										</div>
										<div class="compound-body">
											<p>
												You’ll be
												<a href="/academics">better equipped for the workforce</a> after graduation because our unique academics more accurately reflect the real world.
											</p>
										</div>
									</div>
								</li>
								<li class="unit-1-3-alt">
									<div class="compound">
										<div class="compound-img">
											<img alt="Value icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/green/value.png">
											<!--<svg width="75">
												<use xlink:href="#icon-coins"></use>
											</svg>-->
										</div>
										<div class="compound-body">
											<p>
												You’ll have
												<a href="/costs">less financial worry</a>. Evergreen has one of the lowest tuition costs and fastest time to degree of any Washington four-year school.
												<a href="about/praise">Fiske Guide calls it a 2015 “Best Buy.”</a>
											</p>
										</div>
									</div>
								</li>
								<li class="unit-1-3-alt">
									<div class="compound">
										<div class="compound-img">
											<img alt="Sun icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/green/sun.png">
											<!--<svg width="75">
												<use xlink:href="#icon-sun2"></use>
											</svg>-->
										</div>
										<div class="compound-body">
											<p>
												<a href="/about/graduates">97 percent of our graduates are working,</a> in graduate or professional schools, or otherwise doing something personally meaningful one year after graduation.
											</p>
										</div>
									</div>
								</li>
								<li class="unit-1-3-alt">
									<div class="compound">
										<div class="compound-img">
											<img alt="Tools icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/green/tools.png">
											<!--<svg width="75">
												<use xlink:href="#icon-tools"></use>
											</svg>-->
										</div>
										<div class="compound-body">
											<p>
												You’ll get hands-on experience right away because we give you
												<a href="/academics/resources">access to an impressive range of tools and technologies</a> from our scanning electron microscope to a wealth of media equipment.
											</p>
										</div>
									</div>
								</li>
								<li class="unit-1-3-alt">
									<div class="compound">
										<div class="compound-img">
											<img alt="Scene icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/green/scene.png">
											<!--<svg width="75">
												<use xlink:href="#icon-guitar"></use>
											</svg>-->
										</div>
										<div class="compound-body">
											<p src="<?php print base_path() . path_to_theme() ?>/images/icons/green/scene.png">
												<a href="/about/explorethearea">As one of the Pacific Northwest’s cultural centers, Olympia</a> offers a vibrant independent music and art scene, theater, restaurants, bars, parks, and a full slate of events and activities to enrich your free time.
											</p>
										</div>
									</div>
								</li>
								<li class="unit-1-3-alt">
									<div class="compound">
										<div class="compound-img">
											<img alt="Mascot icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/green/speedy.png">
											<!--<svg width="75">
												<use xlink:href="#icon-speedy"></use>
											</svg>-->
										</div>
										<div class="compound-body">
											<p>
												Speedy,
												<a href="geoduck">our humble and beloved mascot,</a> happens to be a geoduck—a large clam—that inevitably tops weirdest mascot lists year after year.
											</p>
										</div>
									</div>
								</li>
							</ul>
							<p class="row">
								<em>Want to know more?</em> Check out our
								<a href="about/facts">Fact Page.</a>
							</p>
						</div><!-- /.row, end Fun Facts -->
					</article><!-- /.main-content -->
				</div><!-- /#index-wrapper.index-wrapper.unit-6-7 -->
						
				<?php
					/*
						Events and News are added after this file as Views via Blocks. - emn
						
						are these end tags in the right place after all the moving around?
					*/
				?>
			</section><!--/row-->
		</div><!-- /.grid.main-row-grid -->
	</main>
</section>
