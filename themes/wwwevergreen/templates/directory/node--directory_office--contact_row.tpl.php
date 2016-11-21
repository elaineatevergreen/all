<?php

/**
shows suboffices, etc as rows in a table.
 */
?>


    <tr>
        <td><strong><?php print $title; ?></strong></td>
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
    </tr>