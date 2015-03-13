<?php
/**
 * @file
 * Template for a 4 column panel layout.
 *
 * This template provides a four column panel display layout, with
 * each column equal in width.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Content in the top row.
 *   - $content['first']: Content in the first column.
 *   - $content['second']: Content in the second column.
 *   - $content['third']: Content in the third column.
 *   - $content['fourth']: Content in the fourth column.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
<div class="row">
  <div class="col-md-12"><?php print $content['top']; ?></div>  
</div>
<div class="row">
  <div class="col-sm-3"><?php print $content['first']; ?></div>
  <div class="col-sm-3"><?php print $content['second']; ?></div>
  <div class="col-sm-3"><?php print $content['third']; ?></div>
  <div class="col-sm-3"><?php print $content['fourth']; ?></div>
</div>
<div class="row">
  <div class="col-md-12"><?php print $content['bottom']; ?></div>
</div>
