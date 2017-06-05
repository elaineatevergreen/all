<div class="header-dropdowns">
	<div>
		<input id="internal-users-flag" name="header-toggle" type="checkbox"/>
		<ul class="element-list header-dropdown internal-users">
			<li><a href="https://my.evergreen.edu"><img alt="User" height="10" src="<?php echo($imagepath) ?>user-32.png" width="10"/> my.evergreen.edu</a></li>
			<li><a href="<?php echo($siteurl) ?>/webmail">Webmail</a></li>
		</ul>
	</div>
	<div class="top-search">
		<input id="search-flag" name="header-toggle" type="checkbox"/> 
		<div class="header-dropdown">
			<form action="http://www.evergreen.edu/search" class="search" method="get" role="search">
				<label for="q">Search</label> 
				<input id="q" name="keys" placeholder="Search" type="search"/>
				<button class="search-button">
					<img alt="Search" src="<?php echo($imagepath) ?>search-32.png"/>
				</button> 
				<ul class="element-list search-tools">
					<li class="internal-users-alt"><a href="https://my.evergreen.edu">
						<img alt="Profile" height="10" src="<?php echo($imagepath) ?>user-32.png" width="10"/> my.evergreen.edu</a>
					</li>
					<li class="internal-users-alt"><a href="<?php echo($siteurl) ?>/webmail">Webmail</a></li>
					<li><a href="<?php echo($siteurl) ?>/directory">Directories</a></li>
				</ul>
			</form>
		</div>
	</div>
</div>
<div class="page-header">
	<div class="logo h-card">
		<a class="u-url" href="<?php echo($siteurl) ?>/">
			<picture>
				<source media="(min-width: 125em)" srcset="<?php echo($imagepath) ?>evergreen-wide-tree-oly.svg" type="image/svg+xml"/>
				<source srcset="<?php echo($imagepath) ?>evergreen-long-tree-oly.svg" type="image/svg+xml"/>
				<img alt="Logo of The Evergreen State College&#8212;Olympia, Washington" class="p-name p-org u-logo" src="<?php echo($imagepath) ?>logo.png" srcset="<?php echo($imagepath) ?>evergreen-long-tree-oly.svg"/>
			</picture>
		</a>
	</div>
	<div class="off-canvas">
		<label class="search-toggle" for="search-flag">
			<img alt="Search" src="<?php echo($imagepath) ?>search-w32.png"/>
		</label>
		<label class="student-toggle" for="internal-users-flag">
			<img alt="Profile" src="<?php echo( $imagepath) ?>user-w32.png"/>
		</label>
	</div>
</div>
