<?php

/**
 * @file field.tpl.php
 * Similar to the facilities field, this puts all of the people in an office into a table
 */
?>

<table>
	<caption>People in this Office</caption>
	<tr>
		<th>Name and Title</th>
		<th>Email</th>
		<th>Location</th>
		<th>Mailstop</th>
		<th>Phone</th>
	</tr>
    <?php foreach ($items as $delta => $item): ?>
      <?php print render($item); ?>
    <?php endforeach; ?>
</table>
