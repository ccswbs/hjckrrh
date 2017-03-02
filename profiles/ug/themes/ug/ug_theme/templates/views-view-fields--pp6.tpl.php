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
<article class="media">
	<div class="row">
		<?php if (isset($large_image)): ?>
		  <div class="col-md-4">
		    <div class="media-thumbnail">
		      <?php print $large_image; ?>
		    </div>
		  </div>
		<?php endif; ?>
		<?php if(isset($small_image)): ?>
			<div class="col-md-2">
				<div class="media-thumbnail">
					<?php print $small_image; ?>
				</div>
			</div>
		<?php endif; ?>
		<div class="<?php print($content_width); if($content_offset != '') print(' '.$content_offset); ?>">
		  <div class="media-header">
		    <h2 class="media-heading">
		      <?php print $fullname; ?>
		    </h2>
		  </div>
		  <div class="media-summary">
		    <?php if ($phone): ?>
		      <p>
		        <?php print t("<strong>@label:</strong>", array('@label' => 'Phone')); ?>
		        <?php print $phone; ?>
		      </p>
		    <?php endif; ?>
		    <?php if ($email): ?>
		      <p>
		        <?php print t("<strong>@label:</strong>", array('@label' => 'Email')); ?>
		        <?php print $email; ?>
		      </p>
		    <?php endif; ?>
		    <?php if ($office): ?>
		      <p>
		        <?php print t("<strong>@label:</strong>", array('@label' => 'Office')); ?>
		        <?php print $office; ?>
		      </p>
		    <?php endif; ?>
		  </div>
		</div>
	</div>
</article>
