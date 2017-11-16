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

<?phpprint render($content['field_prefix']);?>
<?php print render($content['field_updated_version']); ?>

<?php if (!empty($content['field_external_policy'])): ?>
    <div class="content">
      <div>
         <?php foreach($content['field_external_policy'] as $key) {
             foreach ($key as $value){
             print($value . '<br>');
             }
                } ?>
         <?php print render($content['field_external_policy']); ?>
         <?php print render(print_r($content['field_external_policy'])); ?>
      </div>
    </div>
<?php endif;?>

<?php print render($content['']); ?>


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

<?php if (!empty($content['field_signature_filed'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_signature_file']); ?>
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

<?php if (!empty($content['field_categories'])): ?>
    <div class="content">
      <div>
         <?php print render($content['field_categories']); ?>
      </div>
    </div>
<?php endif;?>

<?php print render($content['body']); ?>


