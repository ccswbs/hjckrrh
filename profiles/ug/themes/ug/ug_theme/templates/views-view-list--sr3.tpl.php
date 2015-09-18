<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>
<?php print $wrapper_prefix; ?>
<?php if (!empty($title)) : ?>
	<h3><?php print $title; ?></h3>
<?php endif; ?>

<?php

	$index = array();

	foreach($rows as $id => $row){
		$letter = ucfirst(substr(trim($view->result[$id]->node_title),0,1));

		if(!empty($letter)){
			
			/* If row contains new index letter */
			 if(end($index) != $letter){

			 	/* Close existing list */
			 	if(!empty($index)){
			 		print $list_type_suffix; 
			 		print ('</div>');
			 	}

			 	//add letter to index
			 	$index[] = $letter;

			 	/* Start New List */
			 	print ('<div class="letter family">');
			 	print('<h3 class="letter-header">' . $letter . '</h3>');
			 	print $list_type_prefix;
			 }

		 print ('<li class="'. $classes_array[$id] .'">' . $row . '</li>');
		}
	}

	print $list_type_suffix;
	print ('</div>');
	print $wrapper_suffix;
?>