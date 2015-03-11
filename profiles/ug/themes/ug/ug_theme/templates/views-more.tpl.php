<?php

/**
 * @file
 * Theme the more link.
 *
 * - $view: The view object.
 * - $more_url: the url for the more link.
 * - $link_text: the text for the more link.
 *
 * @ingroup views_templates
 */
?>

<p class="more-link">
  <a href="<?php print $more_url ?>" class="btn btn-default">
    <?php print $link_text; ?>
  </a>
</p>
