<?php
/**
 * @file
 * E2 - Template to display one event.
 *
 * Available variables:
 * - $title: title of event
 * - $body: event body
 * - $email: contact email
 * - $contact: contact information
 * - $cost: cost of event
 * - $date: date of event
 * - $image: feature image
 * - $caption: image caption
 * - $attachments: file attachments
 * - $location: location of the event
 * - $link: more information url
 * - $address: street address
 * - $city: city part of event location
 * - $category: event category
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
<dl>
  <dt>
    <span class="fa fa-calendar"></span>
    <?php print t('Date and time'); ?>
  <dd>
    <?php print $date; ?>

  <dt>
    <span class="fa fa-map-marker"></span>
    <?php print t('Location'); ?>
  <dd>
    <?php print $location; ?>
    <?php if (!empty($address)): ?>
      <br><?php print $address; ?>
    <?php endif; ?>
    <?php if (!empty($city)): ?>
      <br><?php print $city; ?>
    <?php endif; ?>
</dl>

<div class="thumbnail">
  <?php print $image; ?>
  <div class="caption">
    <?php print $caption; ?>
  </div>
</div>

<?php print $body; ?>

<dl>

  <?php if (!empty($cost)): ?>
    <dt>
      <span class="fa fa-usd"></span>
      <?php print t('Cost'); ?>
    <dd>
      <?php print $cost; ?>
  <?php endif; ?>

  <?php if (!empty($link)): ?>
    <dt>
      <span class="fa fa-link"></span>
      <?php print t('Event website'); ?>
    <dd>
      <?php print t('Visit !link for more information.',
                   array('!link' => $link)); ?>
  <?php endif; ?>

  <?php if (!empty($attachments)): ?>
    <dt>
      <span class="fa fa-file"></span>
      <?php print t('File attachments'); ?>
    <dd>
      <?php print $attachments; ?>
  <?php endif; ?>

  <?php if (!empty($contact)): ?>
    <dt>
      <span class="fa fa-user"></span>
      <?php print t('Contact information'); ?>
    <dd>
      <?php print $contact; ?>
  <?php endif; ?>

</dl>

