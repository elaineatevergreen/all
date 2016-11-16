<?php

/**
 * @file field.tpl.php
 * Makes a little table out of all the facilities!
 * Each item is rendered as a tr in node--directory_office--contact_row
 */
?>

<table>
	<caption>Facilities</caption>
	<tr>
		<th>Name</th>
		<th>Email</th>
		<th>Location</th>
		<th>Mailstop</th>
		<th>Phone</th>
	</tr>
    <?php foreach ($items as $delta => $item): ?>
      <?php print render($item); ?>
    <?php endforeach; ?>
</table>
