<?php
print render($content['field_prefix']);
print render($content['title']);
print render($content['field_categories']);
?>


<?php if (!empty($content['field_effective_date'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_effective_date']); ?>
      </div>
    </div>
<?php endif;?>


<?php if (!empty($content['field_archived'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_archived']); ?>
      </div>
    </div>
<?php endif;?>

<?php
print render($content['field_updated_version']);
print render($content['field_external_policy']);
print render($content['body']);
print render($content['group_related']);
print render($content['field_related_documents']);
print render($content['field_related_policies']);
print render($content['field_previous_version']);
print render($content['field_stub']);
print render($content['path']); ?>

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

<?php
print render($content['field_signature_file']);
print render($content['field_steward']);
?>


