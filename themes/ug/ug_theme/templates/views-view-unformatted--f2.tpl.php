<?php

/**
 * @file
 * F2 - FAQ detail
 *
 * @ingroup views_templates
 */
?>
<h2><?php print t('Answers'); ?></h2>
<dl>
  <?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
  <?php endforeach; ?>
</dl>
