
<?phpprint render($content['title']);?>


<?php if (!empty($content['field_archived'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_archived']); ?>
      </div>
    </div>
<?php endif;?>


<?phpprint render($content['field_prefix']);?>






<?php print render($content['field_updated_version']); ?>
<?php print render($content['field_external_policy']); ?>

<?php print render($content['group_related']); ?>
<?php print render($content['field_related_documents']); ?>
<?php print render($content['field_related_policies']); ?>
<?php print render($content['field_previous_version']); ?>
<?php print render($content['field_stub']); ?>
<?php print render($content['path']); ?>

<?php if (!empty($content['field_approval_date'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_approval_date']); ?>
      </div>
    </div>
<?php endif;?>

<?php if (!empty($content['field_approval_authority'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_approval_authority']); ?>
      </div>
    </div>
<?php endif;?>

<?php print render($content['field_signature_file']); ?>
<?php print render($content['field_steward']); ?>

<?php print render($content['field_categories']); ?>
<?php print render($content['body']); ?>


