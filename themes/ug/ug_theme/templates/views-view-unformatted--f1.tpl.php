<?php

/**
 * @file
 * F1 - FAQ listing
 *
 * @ingroup views_templates
 */
?>
<h2><?php print t('Questions'); ?></h2>
<ul>
  <?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
  <?php endforeach; ?>
</ul>
