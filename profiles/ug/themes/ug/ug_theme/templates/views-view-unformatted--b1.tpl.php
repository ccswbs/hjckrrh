<?php

/**
 * @file
 * Default simple view template to display a slideshow.
 *
 * @ingroup views_templates
 */
?>
<div id="carousel" class="panel panel-default">
  <div class="carousel slide" data-interval="false" data-pause="false">
    <div class="carousel-inner" role="listbox">
      <?php foreach ($rows as $id => $row): ?>
        <div class="item <?php if ($id==0): print 'active'; endif; ?>">
          <?php print $row; ?>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
</div>

