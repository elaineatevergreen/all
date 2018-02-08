<?php

/**
Just give us a normal name (because, remember, the node's title is their CAS name!)
This one also has a link to the node
 */

	
?>
<a class="u-email" href="<?php print $node_url; ?>"><?php print render($content['field_first_name']) . ' ' . render($content['field_last_name']); ?></a>