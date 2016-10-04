<?php

/**
Formatting for individual items in the news-o-matic view, as seen on the home page.
 */
?>
<article class="news-article">
<header>
	<h3 class="lead"><?php print $fields['title']->content ?></h3>
</header>
<div class="news-body">
<p>
	<q><?php print $fields['field_description_plain']->content ?></q>
</p>
</div>
<footer>
	<p>
		<cite><?php print $fields['field_article_link']->content ?></cite>
	</p>
	<p class="source">
		(<i class="source"><?php print $fields['field_publication_title']->content ?></i>,
		<?php print $fields['field_article_date']->content ?>)
	</p>
</footer>
</article>