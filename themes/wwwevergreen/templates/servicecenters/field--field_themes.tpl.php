<?php

/**
 * @file field.tpl.php
 * Bare field contents are comma-separated.
 *
 */
?>
    <?php foreach ($items as $delta => $item): 
	    $render[] = render($item); 
     endforeach; 
     
     print implode(", ", $render);
     
     ?>

