<?php
/**
lists the pages for each of the accordion groups
includes some outer html
*/
?>
<div class="accordion-body">
<ul class="accordion-inner tertiary-nav-list">
  
    <?php foreach ($items as $delta => $item): ?>
      <li><?php print render($item); ?></li>
    <?php endforeach; ?>

</ul>
</div>