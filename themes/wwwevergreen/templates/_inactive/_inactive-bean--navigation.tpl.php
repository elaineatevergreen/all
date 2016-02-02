<?php
//this is the "outer ring" of the navigation
//the "Bean" contains the input that controls the whole collapso-expando thing
//plus also the outer ul for the navigation
//in theory one might even put the nav element itself here, but I'm not for now.

//$content consists of...
//one or more field collections (sets of pages)
//optionally one "related links" fields
?>
<input checked="checked" id="collapse-all" name="accordion-group" type="radio"/>
<ul class="element-list">
<?php print render($content); ?>
</ul>