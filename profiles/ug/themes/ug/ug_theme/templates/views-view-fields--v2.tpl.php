
<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
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
 * @ingroup views_templates
 */
?>

<div class="row">
	<?php if (!empty($transcript)): ?>
	<div class="col-md-8">
	<?php endif; ?>
		<video data-able-player playsinline data-hide-controls data-speed-icons="arrows" <?php if (!empty($transcript)) echo "data-transcript-div='transcript-container{$nid}'" ?> data-youtube-id="<?php print $video ?>" id="video<?php print $nid ?>" preload="auto">
		<?php if (!empty($transcript)): ?>
		        <track kind="captions" src="<?php print $transcript ?>" srclang="en" />
		<?php endif; ?>
		<?php if (!empty($description)): ?>
			<track kind="descriptions" src="<?php print $description ?>" srclang="en" />
		<?php endif; ?>
		</video>
	<?php if (!empty($transcript)): ?>
	</div>
	<div class="col-md-4">
        	<div id="transcript-container<?php print $nid ?>"></div>
	</div>
	<?php endif; ?>
</div>
