 <?php

/**
 * @file

Note (emn): this manages the inner content of a taxonomy term.
Also, the secondary content is all set via Views+Context.
 */
?>


<?php print render($content['description']); ?>

<?php if(isset($content['field_sample_program_description'])) { ?>
<h2>Sample Program</h2>
<?php print render($content['field_sample_program_description']); ?>
<?php }; ?>


<!--<h2>Offerings</h2>
<p><em>This will be something else. Soon. I swear.</em></p>-->

<?php if(isset($content['field_after_graduation'])) { ?>
<h2>After Graduation</h2>
<?php print render($content['field_after_graduation']); ?>
<?php }; ?>

<?php if(isset($content['field_facilities_resources'])) { ?>
<h2>Facilities and Resources</h2>
<?php print render($content['field_facilities_resources']); ?>
<?php }; ?>
