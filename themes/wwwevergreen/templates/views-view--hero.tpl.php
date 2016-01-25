<?php
/*
	
	This just removes (or should remove!) all of the wrappers from the background image that's created as part of a View.
	
*/	
?>


  <?php if ($rows): ?>

      <?php print $rows; ?>

  <?php elseif ($empty): ?>

      <?php print $empty; ?>

  <?php endif; ?>
