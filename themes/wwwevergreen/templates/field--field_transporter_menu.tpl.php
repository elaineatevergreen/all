<?php
/**

	Transporter menus are created on fields on content types, or at least that's how it works now on the home page.
	This is the ul that contains all the items themed in bean--transformer.

*/
?>

<ul class="element-list grid transporter">
	<?php foreach ($items as $delta => $item): ?>
      <?php print render($item); ?>
    <?php endforeach; ?>
</ul>