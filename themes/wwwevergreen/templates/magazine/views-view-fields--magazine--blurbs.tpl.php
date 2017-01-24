<?php

/**
 * @file
 * All the stuff inside of each li for the magazine blurb listing.
 */
?>

	<div class="media-img"><a href="<?php print $fields['path']->content ?>"><?php print $fields['field_thumbnail']->content ?></a></div>

	<div class="media-body">
	<h3><?php print $fields['title']->content ?></h3>

	<p class="byline">by <?php print $fields['field_byline']->content ?></p>

	<p><?php print $fields['field_blurb']->content ?></p>
	</div>

