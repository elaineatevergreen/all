<?php

/**
 * @file
 * Native cases navigation on View/Panel pages
 * Just wraps the plain menu content in a box
 */
?>
<nav id="tertiary-nav" class="box">
	<?php if ($block->subject): ?>
  <h4<?php print $title_attributes; ?>><?php print $block->subject ?></h4>
<?php endif;?>
	<?php print $content ?>
</nav>

