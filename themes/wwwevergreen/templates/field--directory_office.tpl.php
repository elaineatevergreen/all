<?php

/**

Directory office information appears in a dl.
This template puts each field into a dt/dd pair.

 */
?>


  <?php if (!$label_hidden): ?>
    <dt class="field-label"<?php print $title_attributes; ?>><?php print $label ?>&nbsp;</dt>
  <?php endif; ?>
    <?php foreach ($items as $delta => $item): ?>
      <dd class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></dd>
    <?php endforeach; ?>

