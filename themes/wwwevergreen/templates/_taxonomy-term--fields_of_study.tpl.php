 <?php

/**
 * @file

Note (emn): this manages the inner content of a taxonomy term.

 *
 * Available variables:
 * - $name: (deprecated) The unsanitized name of the term. Use $term_name
 *   instead.
 * - $content: An array of items for the content of the term (fields and
 *   description). Use render($content) to print them all, or print a subset
 *   such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $term_url: Direct URL of the current term.
 * - $term_name: Name of the current term.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - taxonomy-term: The current template type, i.e., "theming hook".
 *   - vocabulary-[vocabulary-name]: The vocabulary to which the term belongs to.
 *     For example, if the term is a "Tag" it would result in "vocabulary-tag".
 *
 * Other variables:
 * - $term: Full term object. Contains data that may not be safe.
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $page: Flag for the full page state.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the term. Increments each time it's output.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_taxonomy_term()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
	    <div id="primary-content-wrapper" class="primary-content-wrapper unit-4-7">
		      
				<article class="main-content">
		      
				<?php 
					/* and now, all the main column content coming out of Drupal... */	
					
					print $messages; 
					if ($page['highlighted']): 
				?>
	        	<div id="highlighted"><?php print render($page['highlighted']); ?></div>
				<?php endif; ?>
	        <a id="main-content"></a>
	        	
						<h1 class="title" id="page-title"><?php print $term_name; ?></h1>
				<?php 
					print render($title_suffix); 
					if ($tabs): 
				?>
						<div class="tabs"><?php print render($tabs); ?></div>
				<?php 
					endif; 
					
					print render($page['help']); 
					
					if ($action_links): 
				?>
						<ul class="action-links"><?php print render($action_links); ?></ul>
				<?php 
					endif; 
					
					print render($content['description']); 
					

					
				?>
	      	
	      </article>
	    </div> <!-- /.main-content, /#content-wrapper -->
	      
			<div id="sidebar-wrapper" class="sidebar-wrapper unit-2-7">
				<section class="sidebar">
					<?php  ?>
				</section><!-- /.sidebar -->
			</div>


<?php
	/*
<div id="primary-content-wrapper" class="primary-content-wrapper unit-4-7">
		      
				<article class="main-content">
<div id="taxonomy-term-<?php print $term->tid; ?>" class="<?php print $classes; ?>">
  <?php if (!$page): ?>
    <h2><a href="<?php print $term_url; ?>"><?php print $term_name; ?></a></h2>
  <?php endif; ?>

  <div class="content">
    <?php print render($content); ?>
  </div>

</div>
</article>
	    </div> <!-- /.main-content, /#content-wrapper -->
	      
			<div id="sidebar-wrapper" class="sidebar-wrapper unit-2-7">
				<section class="sidebar">
					<?php print render($page['secondary_content']); ?>
				</section><!-- /.sidebar -->
			</div>
*/