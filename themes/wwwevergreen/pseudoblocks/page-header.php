<div class="header-dropdowns">
	<div>
		<input id="internal-users-flag" name="header-toggle" type="checkbox"/>
		<ul class="element-list header-dropdown internal-users">
			<li>
				<a href="https://my.evergreen.edu">
					<img alt="Profile" src="<?php echo($imagepath) ?>icons/header/user.svg"/> my.evergreen.edu
				</a>
			</li>
			<li>
				<a href="/webmail"><img alt="Email" src="<?php echo($imagepath) ?>icons/header/webmail.svg"/> Webmail</a>
			</li>
		</ul>
	</div>
	<div class="top-search">
		<input id="search-flag" name="header-toggle" type="checkbox"/> 
		<div class="header-dropdown">
			<form action="https://www.evergreen.edu/search" class="search" method="get" role="search">
				<label for="q">Search</label> 
				<input id="q" name="search" placeholder="Search" type="search"/>
				<button class="search-button">
					<img alt="Search" src="<?php echo($imagepath) ?>search-32.png"/>
				</button> 
				<ul class="element-list search-tools">
					<li class="internal-users-alt">
						<a href="https://my.evergreen.edu">
							<img alt="Profile" src="<?php echo($imagepath) ?>icons/header/user.svg"/> my.evergreen.edu
						</a>
					</li>
					<li class="internal-users-alt">
						<a href="/webmail">
							<img alt="Email" src="<?php echo($imagepath) ?>icons/header/webmail.svg"/> Webmail
						</a>
					</li>
					<li>
						<a href="/directory">
							<img alt="Address Book" src="<?php echo($imagepath) ?>icons/header/address-book.svg"/> Directories
						</a>
					</li>
				</ul>
			</form>
		</div>
	</div>
</div>
<div class="page-header">
	<div class="logo h-card">
		<a class="u-url" href="/">
			<picture>
				<source media="(min-width: 125em)" srcset="<?php echo($imagepath) ?>evergreen-logo-primary.svg" type="image/svg+xml"/>
				<img alt="The Evergreen State College&#8212;Olympia, Washington" class="p-name p-org u-logo" src="<?php echo($imagepath) ?>logo.png" srcset="<?php echo($imagepath) ?>evergreen-logo-secondary.svg"/>
			</picture>
		</a>
	</div>
	<div class="off-canvas">
		<label class="search-toggle" for="search-flag">
			<img alt="Search" src="<?php echo($imagepath) ?>icons/header/search-alt.svg"/>
		</label>
		<label class="student-toggle" for="internal-users-flag">
			<img alt="Profile" src="<?php echo($imagepath) ?>icons/header/user-alt.svg"/>
		</label>
	</div>
</div>
