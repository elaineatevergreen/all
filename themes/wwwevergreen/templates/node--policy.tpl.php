<?php print render($content['title']);?>

<?php if (!empty($content['field_archived'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_archived']); ?>
      </div>
    </div>
<?php endif;?>

<?php if (!empty($content['field_effective_date'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_effective_date']); ?>
      </div>
    </div>
<?php endif;?>

<?php if (!empty($content['field_steward'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_steward']); ?>
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

<?php if (!empty($content['field_previous_version'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_previous_version']); ?>
      </div>
    </div>
<?php endif;?>

<?php if (!empty($content['field_categories'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_categories']); ?>
      </div>
    </div>
<?php endif;?>

<?php if (!empty($content['field_prefix'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_prefix']); ?>
      </div>
    </div>
<?php endif;?>
<?php print render($content['field_updated_version']); ?>

<?php if (!empty($content['field_external_policy'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_external_policy']); ?>
      </div>
    </div>
<?php endif;?>

<?php if (!empty($content['field_approval_date'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_approval_date']); ?>
      </div>
    </div>
<?php endif;?>



<?php if (!empty($content['field_signature_file'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_signature_file']); ?>
      </div>
    </div>
<?php endif;?>

<?php print render($content['body']); ?>

<?php if (!empty($content['field_related_policies'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_related_policies']); ?>
      </div>
    </div>
<?php endif;?>

<?php if (!empty($content['field_related_documents'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_related_documents']); ?>
      </div>
    </div>
<?php endif;?>
