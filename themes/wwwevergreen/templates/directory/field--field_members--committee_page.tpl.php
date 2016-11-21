<?php

/**
 * @file field.tpl.php
 * Similar to the facilities field, this puts all of the people in an office into a table
 */
?>
<h2><?php print $label ?></h2>
<ul>
	<?php foreach ($items as $delta => $item): ?>
      <li><?php print render($item); ?></li>
    <?php endforeach; ?>
</ul>