<?php
/**
 * @file
 * Template to display one row of the user profile listing.
 *
 * Available variables:
 * - $image: the profile picture.
 * - $name: the person's first name.
 * - $lastname: the person's last name.
 * - $uid: the user id.
 * - $title: the person's title.
 * - $unit: the person's unit.
 * - $phone: the person's telephone number.
 * - $email: the person's email address. 
 * - $user_url: URL of the user's full profile.
 *
 * Other variables:
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 */
?>

<div class="row">
  <?php if ($image): ?>
    <div class="col-md-4">
      <img class="img-responsive" src="<?php print $image; ?>"/>
    </div>
  <?php endif; ?>
  <div class="col-md-<?php print $image ? 8 : 4; ?>">
    <?php print $fullname; ?><br/>
    <?php print $title; if ($unit): print ', '.$unit; endif; ?><br/>
    <?php if ($phone): ?>
      <?php print t("<span class='text-muted'>@label: </span>", array('@label' => 'Phone')); ?>
      <?php print $phone; ?><br/>
    <?php endif; ?>
    <?php if ($email): ?>
      <?php print t("<span class='text-muted'>@label: </span>", array('@label' => 'Email')); ?>
      <?php print $email; ?><br/>
    <?php endif; ?>
  </div>
</div> 
<hr/>

