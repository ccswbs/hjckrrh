<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="col-md-6">
<?php if (!empty($title)): ?>
  <h2><?php print $title; ?></h2>
<?php endif; ?>
  <ul class="nav nav-pills nav-stacked">
    <?php foreach ($rows as $id => $row): ?>
      <?php print $row; ?>
    <?php endforeach; ?>
  </ul>
</div>
