<?php

/**
themes each person as a row to go in a table.
 */
?>


    <tr>
        <td><strong><?php print render($content['field_first_name']) . ' ' . render($content['field_last_name']) ?></strong>, <?php print render($content['field_job_title']) ?></td>
<?php 
	//for right now, hide contact information from off-campus users
	if(user_is_logged_in()) {
?>
		<td><?php print render($content['field_email']) ?></td>
        <td><?php print render($content['field_building_alt']) ?> <?php print render($content['field_room']) ?></td>
        <td><?php print render($content['field_mailstop']) ?></td>
        <td>
	         <?php if (isset($content['field_phone'])) {
	        ?><span class="p-tel"><?php print render($content['field_phone']) ?> </span><?php
        }; ?>
        <?php if (isset($content['field_fax'])) {
	        ?><br><i>Fax:</i> <?php print render($content['field_fax']) ?><?php
        }; ?>
        <?php if (isset($content['field_alternate_phone'])) {
	        ?><br><i>Alt:</i> <?php print render($content['field_alternate_phone']) ?><?php
        }; ?>
        </td>
<?php } else { ?>
		<td colspan="4">Currently contact information is only available to logged in members of the campus community.</td>
	
<?php }; ?>
         
    </tr>