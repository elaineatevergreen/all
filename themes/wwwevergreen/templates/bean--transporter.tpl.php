<?php
/*
	
	This theme provides markup for individual icons in a "transporter" menu.
	Transporter menus are seen on the home page and the campus life page.
	They always appear as a list.
	
*/	
?>


<li class="unit-1-6-alt">
<a href="<?php print render($content['field_transport_link']); ?>">
	<div class="transporter-icon"><?php print render($content['field_icon']); ?></div>
	<div><?php print $title; ?></div>
</a>
</li>