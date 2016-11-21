<?php
/**
 * @file
 * All the extra markup around site alerts
 */
?>

<div class="alert box" id="sitewide-alert">
<div class="wrapper">
    <div class="media">
        <div class="media-img media-img-alt">
            <img alt="Alert" class="media-img-icon" src="<?php echo(base_path() . $directory) ?>/images/icons/red/warning.png"/>
        </div>
		<div class="media-body">
            <p class="alert-title"><strong><?php print $title; ?></strong></p>
            <div class="alert-message">
<?php
 // We hide the comments and links now so that we can render them later.
hide($content['comments']);
hide($content['links']);
print render($content);
?>
            </div>
        </div>
    </div>
</div>
</div>

