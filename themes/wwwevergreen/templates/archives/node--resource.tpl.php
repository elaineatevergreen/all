<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $user_picture; ?>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
    <div class="submitted">
      <?php print $submitted; ?>
    </div>
  <?php endif; ?>


  <div class="content"<?php print $content_attributes; ?>>

    <!--Overview of the Collection-->
    <?php if(isset($content['group_overview_of_the_collection']['field_resource_summary'][0])) { ?>
      <p class="intro"><?php print render($content['group_overview_of_the_collection']['field_resource_summary'][0]) ?> </p>
    <?php }; ?>

    <?php if(isset($content['group_overview_of_the_collection']['#title'])) { ?>
      <h2><?php print render($content['group_overview_of_the_collection']['#title']) ?></h2>
    <?php }; ?>

    <?php if(isset($content['group_overview_of_the_collection']['field_resource_creator']['#title'])) { ?>
      <p><strong><?php print render($content['group_overview_of_the_collection']['field_resource_creator']['#title']); ?>: </strong> <?php print render($content['group_overview_of_the_collection']['field_resource_creator'][0]) ?><br/> 
    <?php }; ?>

    <?php if(isset($content['group_overview_of_the_collection']['field_resource_dates']['#title'])) { ?>
      <strong><?php print render($content['group_overview_of_the_collection']['field_resource_dates']['#title']) ?>: </strong><?php print render($content['group_overview_of_the_collection']['field_resource_dates'][0]) ?><br/>
    <?php }; ?>

    <?php if(isset($content['group_overview_of_the_collection']['field_resource_quantity']['#title'])) { ?>
      <strong><?php print render($content['group_overview_of_the_collection']['field_resource_quantity']['#title']) ?>: </strong><?php print render($content['group_overview_of_the_collection']['field_resource_quantity'][0]) ?><br/>
    <?php }; ?>

    <?php if(isset($content['group_overview_of_the_collection']['field_resource_collection_number']['#title'])) { ?>
      <strong><?php print render($content['group_overview_of_the_collection']['field_resource_collection_number']['#title']) ?>: </strong><span class="machine-text"><?php print render($content['group_overview_of_the_collection']['field_resource_collection_number'][0]) ?></span><br/>
    <?php }; ?>

    <?php if(isset($content['group_overview_of_the_collection']['field_res_access_restrictions']['#title'])) { ?>
      <strong><?php print render($content['group_overview_of_the_collection']['field_res_access_restrictions']['#title']) ?>: </strong><?php print render($content['group_overview_of_the_collection']['field_res_access_restrictions'][0]) ?><br/>
    <?php }; ?>

    <?php if(isset($content['group_overview_of_the_collection']['field_languages']['#title'])) { ?>
      <strong><?php print render($content['group_overview_of_the_collection']['field_languages']['#title']) ?>: </strong><?php print render($content['group_overview_of_the_collection']['field_languages'][0]) ?><br/>
    <?php }; ?>

    <!--Find Related Materials-->
    <?php if(isset($content['group_find_related_collections']['#title'])) { ?>
      <hr/>
      <h2><?php print render($content['group_find_related_collections']['#title']) ?></h2>
    <?php }; ?>

    <?php if(isset($content['group_find_related_collections']['field_res_related_accessions']['#title'])) { ?>
      <h3><?php print render($content['group_find_related_collections']['field_res_related_accessions']['#title']) ?></h3>
      <!--print accessions-->
      <ul>
      <?php for ($x=0; $x<count($content['group_find_related_collections']['field_res_related_accessions']['#items']); $x++): ?>
        <li><?php print render($content['group_find_related_collections']['field_res_related_accessions'][$x]); ?></li>
      <?php endfor; ?>
      </ul>
    <?php }; ?>

    <?php if(isset($content['group_find_related_collections']['field_res_related_names']['#title'])) { ?>
      <h3><?php print render($content['group_find_related_collections']['field_res_related_names']['#title']) ?></h3>
      <!--print names-->
      <ul>
      <?php for ($x=0; $x<count($content['group_find_related_collections']['field_res_related_names']['#items']); $x++): ?>
        <li><?php print render($content['group_find_related_collections']['field_res_related_names'][$x]); ?></li>
      <?php endfor; ?>
      </ul>
    <?php }; ?>

    <?php if(isset($content['group_find_related_collections']['field_res_related_subjects']['#title'])) { ?>
      <h3><?php print render($content['group_find_related_collections']['field_res_related_subjects']['#title']) ?></h3>
      <!--print subjects-->
      <ul>
      <?php for ($x=0; $x<count($content['group_find_related_collections']['field_res_related_subjects']['#items']); $x++): ?>
        <li><?php print render($content['group_find_related_collections']['field_res_related_subjects'][$x]); ?></li>
      <?php endfor; ?>
    </ul>
    <?php }; ?>


    <!--Historical Note-->
    <?php if(isset($content['group_historical_note']['#title'])) { ?>
      <h2><?php print render($content['group_historical_note']['#title']) ?></h2>
      <p><?php print render($content['group_historical_note']['field_historical_note'][0]) ?></p>
    <?php }; ?>

    <!--Content Description-->
    <?php if(isset($content['group_content_description']['#title'])) { ?>
      <h2><?php print render($content['group_content_description']['field_content_description']['#title']) ?></h2>
      <p><?php print render($content['group_content_description']['field_content_description'][0]) ?></p>
    <?php }; ?>


    <!--Collection Use-->
    <?php if(isset($content['group_collection_use']['#title'])) { ?>
      <h2><?php print render($content['group_collection_use']['#title']) ?></h2>
      <?php if(isset($content['group_collection_use']['field_restrictions_on_use']['#title'])) { ?>
        <p><?php print render($content['group_collection_use']['field_restrictions_on_use'][0]) ?></p>
      <?php }; ?>

      <?php if(isset($content['group_collection_use']['field_preferred_citation']['#title'])) { ?>
        <p><?php print render($content['group_collection_use']['field_preferred_citation'][0]) ?></p>
      <?php }; ?>
    <?php }; ?>


    <!--Administrative Information-->
    <?php if(isset($content['group_admin_information']['#title'])) { ?>
      <h2><?php print render($content['group_admin_information']['#title']) ?></h2>

      <?php if(isset($content['group_admin_information']['field_accruals']['#title'])) { ?> 
        <p><strong><?php print render($content['group_admin_information']['field_accruals']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_accruals'][0]) ?></p>
      <?php }; ?>
      <?php if(isset($content['group_admin_information']['field_arrangement']['#title'])) { ?> 
        <p><strong><?php print render($content['group_admin_information']['field_arrangement']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_arrangement'][0]) ?></p>
      <?php }; ?>
      <?php if(isset($content['group_admin_information']['field_custodial_history']['#title'])) { ?> 
        <p><strong><?php print render($content['group_admin_information']['field_custodial_history']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_custodial_history'][0]) ?></p>
      <?php }; ?>
      <?php if(isset($content['group_admin_information']['field_dimensions']['#title'])) { ?> 
        <p><strong><?php print render($content['group_admin_information']['field_dimensions']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_dimensions'][0]) ?></p>
      <?php }; ?>
      <?php if(isset($content['group_admin_information']['field_existence_of_originals']['#title'])) { ?> 
        <p><strong><?php print render($content['group_admin_information']['field_existence_of_originals']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_existence_of_originals'][0]) ?></p>
      <?php }; ?>
      <?php if(isset($content['group_admin_information']['field_file_plan']['#title'])) { ?> 
        <p><strong><?php print render($content['group_admin_information']['field_file_plan']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_file_plan'][0]) ?></p>
      <?php }; ?>

      <?php if (isset($content['group_admin_information']['field_general']['#title'])) { ?>
        <p><strong><?php print render($content['group_admin_information']['field_general']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_general'][0]) ?></p>
      <?php }; ?>

      <?php if (isset($content['group_admin_information']['field_language_of_materials']['#title'])) { ?>
        <p><strong><?php print render($content['group_admin_information']['field_language_of_materials']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_language_of_materials'][0]) ?></p>
      <?php }; ?>

      <?php if (isset($content['group_admin_information']['field_location_of_collection']['#title'])) { ?>
        <p><strong><?php print render($content['group_admin_information']['field_location_of_collection']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_location_of_collection'][0]) ?></p>
      <?php }; ?>

      <?php if (isset($content['group_admin_information']['field_material_specific_details']['#title'])) { ?>
        <p><strong><?php print render($content['group_admin_information']['field_material_specific_details']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_material_specific_details'][0]) ?></p>
      <?php }; ?>

      <?php if (isset($content['group_admin_information']['field_other_copies']['#title'])) { ?>
        <p><strong><?php print render($content['group_admin_information']['field_other_copies']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_other_copies'][0]) ?></p>
      <?php }; ?>

      <?php if (isset($content['group_admin_information']['field_other_finding_aids']['#title'])) { ?>
        <p><strong><?php print render($content['group_admin_information']['field_other_finding_aids']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_other_finding_aids'][0]) ?></p>
      <?php }; ?>

      <?php if (isset($content['group_admin_information']['field_field_tech_requirements']['#title'])) { ?>
        <p><strong><?php print render($content['group_admin_information']['field_field_tech_requirements']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_field_tech_requirements'][0]) ?></p>
      <?php }; ?>

      <?php if (isset($content['group_admin_information']['field_physical_description']['#title'])) { ?>
        <p><strong><?php print render($content['group_admin_information']['field_physical_description']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_physical_description'][0]) ?></p>
      <?php }; ?>

      <?php if (isset($content['group_admin_information']['field_processing_information']['#title'])) { ?>
        <p><strong><?php print render($content['group_admin_information']['field_processing_information']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_processing_information'][0]) ?></p>
      <?php }; ?>

      <?php if (isset($content['group_admin_information']['field_related_archival_materials']['#title'])) { ?>
        <p><strong><?php print render($content['group_admin_information']['field_related_archival_materials']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_related_archival_materials'][0]) ?></p>
      <?php }; ?>

      <?php if (isset($content['group_admin_information']['field_source_of_acquisition']['#title'])) { ?>
        <p><strong><?php print render($content['group_admin_information']['field_source_of_acquisition']['#title']) ?>: </strong><?php print render($content['group_admin_information']['field_source_of_acquisition'][0]) ?></p>
      <?php }; ?>

    <?php }; ?>

    <!--Detailed Description-->
    <?php if(isset($content['group_detailed_description']['field_detailed_description'][0])) { ?>
      <h2><?php print render($content['group_detailed_description']['#title']) ?></h2>
      <?php if(isset($content['group_detailed_description']['field_detailed_description'][0])) { ?>
        <?php print render($content['group_detailed_description']['field_detailed_description'][0]) ?>
      <?php }; ?>
    <?php }; ?>

  </div>
</div>



