<?php

/**

This is the node for an office entry in the directory.
It's themed for the contact block, which probably isn't quite right for individual node "pages".
Still in progress.

 */
?>

<section class="site-info">
	<!--<h2>Contact</h2>-->
	<?php if (!$page): ?>
    <p><?php print $title; ?></p>
  <?php endif; ?>
	
	<dl>
		<dt>Location</dt>
		<dd><?php print $content['field_building_alt']['#items']['0']['value'] . ' ' . $content['field_room']['#items']['0']['value']; ?></dd>
	<?php
		hide($content['field_building_alt']);
		hide($content['field_room']);
      print render($content);
    ?>
		<?php /*
		<dt>Location</dt>
		<dd><?php print render($content['field_building_alt']) ?> <?php print render($content['field_room']) ?></dd>
		<dt>Phone</dt>
		<dd><?php print render($content['field_phone']) ?></dd>
		<dt>Alternate Phone</dt>
		<dd><?php print render($content['field_alternate_phone']) ?></dd>
		<dt>Phone</dt>
		<dd><?php print render($content['field_fax']) ?></dd>
		<dt>Email</dt>
		<dd><?php print render($content['field_email']) ?></dd>
		<dt>Websites</dt>
		<dd><?php print render($content['field_websites']) ?></dd>
		
		<dd><?php print render($content['body']) ?></dd>
		<dt>Social Media Connections</dt>
		<dd>
			<ul class="tertiary-nav-list">
				<li><?php print render($content['field_facebook']) ?></li>
				<li><?php print render($content['field_twitter']) ?></li>
				<li><a href="../news/social-media.htm">More Social Media at Evergreen</a></li>
			</ul>
		</dd>
		*/ ?>
	</dl>
</section>