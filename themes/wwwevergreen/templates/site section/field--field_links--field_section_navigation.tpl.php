<?php
/**

	This theme file produces the markup for each list of links in the navigation accordion.

*/
?>
<div class="accordion-body">
<ul class="accordion-inner tertiary-nav-list">
  
    <?php foreach ($items as $delta => $item): ?>
      <li><?php print render($item); ?></li>
    <?php endforeach; ?>

</ul>
</div>