<div class="header-dropdowns">
<div>
					<input id="internal-users-flag" name="header-toggle" type="checkbox"/> 
					<ul class="element-list header-dropdown internal-users">
						<li><a href="https://my.evergreen.edu"><img alt="User" height="10" src="<?php echo($imagepath) ?>user-32.png" width="10"/> my.evergreen.edu</a></li>
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
								<img alt="Search" src="<?php echo($imagepath) ?>search-32.png"/>
							</button> 
							<ul class="element-list search-tools">
								<li class="internal-users-alt"><a href="https://my.evergreen.edu">
									<img alt="User" height="10" src="<?php echo($imagepath) ?>user-32.png" width="10"/> my.evergreen.edu</a>
								</li>
								<li class="internal-users-alt"><a href="http://evergreen.edu/webmail">Webmail</a></li>
								<li><a href="http://evergreen.edu/directories.htm">Directories</a></li>
							</ul>
						</form>
					</div>
				</div>
</div>
				
				
				
				<div class="page-header">
			<div class="logo">
				<a href="http://evergreen.edu">
			      <img alt="The Evergreen State College&#8212;Olympia, Washington" src="<?php echo($imagepath) ?>logo.png" srcset="<?php echo($imagepath) ?>evergreen-long-tree-oly.svg 1x, <?php echo($imagepath) ?>evergreen-long-tree-oly.svg 2x"/>
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