<?php 

class UGUpdate7Migration extends DrupalNode7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

    	$this->arguments['update_source_body'] = 'body';
	}

	public function prepareRow($row) {
	    if (parent::prepareRow($row) === FALSE) {
	      return FALSE;
	    }

	    // update node links
	    if(isset($this->arguments['update_nodelinks'])) {
	    	if($this->arguments['update_nodelinks'] == TRUE){
			    $pattern_nodelinks = array('/node/');
			    $source_migrations = $this->arguments['dependencies'];

			    // replace linked source nids with destination nids
			    if(isset($this->arguments['update_nodelinks_urls'])){
			    	$pattern_nodelinks = $this->arguments['update_nodelinks_urls'];
			    }

				$row->{$this->arguments['update_source_body']}[0] = $this->replaceSourceNodes($row->{$this->arguments['update_source_body']}[0], $pattern_nodelinks, $source_migrations);

			    // replace linked source URLs with destination urls
			    if(isset($this->arguments['update_hardlinks_source']) &&
			    	isset($this->arguments['update_hardlinks_destination'])) {
				    	$old_urls = $this->arguments['update_hardlinks_source'];
				    	$new_url = $this->arguments['update_hardlinks_destination'];
				    	$row->{$this->arguments['update_source_body']}[0] = $this->replaceLinkUrls($row->{$this->arguments['update_source_body']}[0], $old_urls, $new_url);
			    }
		    }
		}


	    // update source prefix for in-line images
	    if(isset($this->arguments['update_prefix_images'])) {
	    	if($this->arguments['update_prefix_images'] == TRUE){
		    	$old_prefixes = $this->arguments['update_prefix_source'];
		    	$new_prefix = $this->arguments['update_prefix_destination'];
			    $row->{$this->arguments['update_source_body']}[0] = $this->replaceImgTags($row->{$this->arguments['update_source_body']}[0],$old_prefixes, $new_prefix);
			}
		}
	}

	public function replaceLinkUrls(&$body, &$replace_urls, &$new_url){
	  	$new_body = $body;

	  	//loop through each source site URL up for replacement
	  	foreach($replace_urls as $u){

	  		//remove trailing slash
	  		if(substr($u, -1) == '/'){
	  			$u = substr($u, 0, -1);
	  		}

	  		//find matches for source site URL
		  	$escaped_source = preg_quote($u, "/");
		  	$pattern_search = '/<a\s[^>]*?href=[\"|\'](' . $escaped_source . ')[\/*?|\'|\"][^>]*?>.*?<\/a>/si';
		  	$num_matches = preg_match_all($pattern_search, $new_body, $matches);

		  	if($num_matches > 0){
		  		//update link and replace in body field
		  		foreach($matches[0] as $key => $m){
					$search_val = $matches[1][$key];
					$replace_val = $new_url;
					$updated_m = str_replace($search_val, $replace_val, $m);
					$new_body = str_replace($m, $updated_m, $new_body);
		  		}
		  	}
  		}

	  	if(isset($new_body)){
		  	return $new_body;
	  	}
	  	return $body;

	}

	public function replaceImgTags(&$body, &$old_prefixes, &$new_prefix){
	  	$new_body = $body;

	  	foreach($old_prefixes as $op){

		  	$prefix_escaped = preg_quote($op, "/");
	  		$pattern_search = '/<img\s[^>]*?src=[\"|\'](' . $prefix_escaped . ')\/*?[^\"\']*?[\"|\'][^>]*?>/si';
	  		$num_matches = preg_match_all($pattern_search, $new_body, $matches);

	  		if($num_matches > 0){
		  		//update image prefix and replace in body field
		  		foreach($matches[0] as $key => $m){
					$search_val = $matches[1][$key];
					$replace_val = $new_prefix;
					$updated_m = str_replace($search_val, $replace_val, $m);
					$new_body = str_replace($m, $updated_m, $new_body);
		  		}

	  		}
	  	}

	  	if(isset($new_body)){
		  	return $new_body;
	  	}
	  	return $body;
	}

	public function replaceSourceNodes(&$body, &$pattern_nodelinks, &$migrations){
	  	$new_body = $body;

	  	foreach($pattern_nodelinks as $np){
	  		// Search for links matching pattern
	  		$np = preg_quote($np,"/");
	  		$pattern_search = '/<a\s[^>]*?href=[\"|\']' . $np . '(\d+)\/*?[^\"\']*?[\"|\'][^>]*?>.*?<\/a>/si';
	  		$num_matches = preg_match_all($pattern_search, $new_body, $match_pattern);

	  		if($num_matches > 0){
		  		foreach($match_pattern[0] as $key => $mp){
		  			//retrieve source node ID in the pattern
		  			$search_nid = strval($match_pattern[1][$key]);
		  			$source_migrations = $migrations; 

		  			// get source migrations instances
		  			$source_migrations = (array)$source_migrations;
		  			$source_key = array(array($search_nid));
		  			foreach ($source_migrations as $key => $source_migration) {
					    $source_migrations[$key] = Migration::getInstance($source_migration);
					}

					// look up destination ID using source migrations
					foreach ($source_migrations as $source_migration) {
						// Break out of the loop as soon as a destination ID is found.
						if ($replace_nid = $source_migration->getMap()->lookupDestinationID($source_key)) {
							if (!empty($replace_nid['destid1'])) {
								break;
							}
						}
					}

					if(!empty($replace_nid['destid1'])){
						$search_val = "node/" . $search_nid;
						$replace_val = "node/" . $replace_nid['destid1'];
						$updated_mp = str_replace($search_val, $replace_val, $mp);
						$new_body = str_replace($mp, $updated_mp, $new_body);
					}
		  		}
	  		}
	  	}

	  	if(isset($new_body)){
		  	return $new_body;
	  	}
	  	return $body;
	}
}

class UGUpdatePage7Migration extends UGUpdate7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

    	//set systemOfRecord to destination to preserve migrated nodes
	    $this->systemOfRecord = Migration::DESTINATION;
	    $this->destination = new MigrateDestinationNode('page');

	    /* DEFAULT arguments */
		$update_arguments = array(
			'update_nodelinks' => FALSE,
			'update_nodelinks_urls' => '/node/',
			'update_hardlinks_source' => '',
			'update_hardlinks_destination' => '',
		);

	    /* DEFAULT arguments */
		$page_arguments = array(
			'source_page_body' => 'body',
			'source_page_summary' => 'body:summary',
			'source_page_format' => 'body:format',
		);

		//Override default values with arguments if they exist
		foreach ($update_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key]!=''){
			    	$update_arguments[$key] = $this->arguments[$key];
			    }
		    }
		}

		//Override default values with arguments if they exist
		foreach ($page_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key]!=''){
			    	$page_arguments[$key] = $this->arguments[$key];
			    }
		    }
		}

	    $this->addFieldMapping('nid', 'nid')
			->sourceMigration($this->arguments['dependencies']);

	    // Update body field
		$this->arguments['update_source_body'] = $page_arguments['source_page_body'];
	    $this->addFieldMapping('field_page_body', $page_arguments['source_page_body']);
	    $this->addFieldMapping('field_page_body:summary', $page_arguments['source_page_summary']);
	    $this->addFieldMapping( 'field_page_body:format', $page_arguments['source_page_format'])
		    ->defaultValue('full_html');

	    // Unmapped fields
	    $suppress_warnings = FALSE;
	    $issues_group = NULL;
		$this->addUnmigratedDestinations(array(
			'body:language',
			'changed',
			'comment',
			'created',
			'field_page_attachments',
			'field_page_attachments:description',
			'field_page_attachments:file_class',
			'field_page_attachments:language',
			'field_page_attachments:preserve_files',
			'field_page_category',
			'field_page_category:source_type',
			'field_tags',
			'field_tags:source_type',
			'language',
			'promote',
			'status',
			'sticky',
			'title',
			'tnid',
			'translate',
			'uid',
			'is_new',
			'revision',
			'revision_uid',
			), $issues_group, $suppress_warnings);

	    if (module_exists('statistics')) {
	      $this->addUnmigratedDestinations(
	        array('totalcount', 'daycount', 'timestamp'));
	    }

	    if (module_exists('statistics')) {
	      $this->addUnmigratedDestinations(
	      	array('pathauto'));
		}
    }
}


class UGUpdateNews7Migration extends UGUpdate7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

    	//set systemOfRecord to destination to preserve migrated nodes
	    $this->systemOfRecord = Migration::DESTINATION;
	    $this->destination = new MigrateDestinationNode('news');

	    /* DEFAULT arguments */
		$update_arguments = array(
			'update_nodelinks' => FALSE,
			'update_nodelinks_urls' => '/node/',
			'update_hardlinks_source' => '',
			'update_hardlinks_destination' => '',
		);


		/* DEFAULT arguments */
		$news_arguments = array(
			'source_news_body' => 'body',
			'source_news_summary' => 'body:summary',
			'source_news_format' => 'body:format',
		);

		//Override default values with arguments if they exist
		foreach ($news_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key]!=''){
			    	$news_arguments[$key] = $this->arguments[$key];
			    }
		    }
		}

		//Override default values with arguments if they exist
		foreach ($update_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key]!=''){
			    	$update_arguments[$key] = $this->arguments[$key];
			    }
		    }
		}

	    $this->addFieldMapping('nid', 'nid')
			->sourceMigration($this->arguments['dependencies']);

	    // Update body field
		$this->arguments['update_source_body'] = $news_arguments['source_news_body'];
	    $this->addFieldMapping('field_news_body', $news_arguments['source_news_body']);
	    $this->addFieldMapping('field_news_body:summary', $news_arguments['source_news_summary']);
	    $this->addFieldMapping( 'field_news_body:format', $news_arguments['source_news_format'])
		    ->defaultValue('full_html');

	    // Unmapped fields
	    $suppress_warnings = FALSE;
	    $issues_group = NULL;
		$this->addUnmigratedDestinations(array(
			'body:language',
			'changed',
			'comment',
			'created',
			'field_news_attachment',
			'field_news_attachment:description',
			'field_news_attachment:file_class',
			'field_news_attachment:language',
			'field_news_attachment:preserve_files',
			'field_news_caption',
			'field_news_image',
			'field_news_image:alt',
			'field_news_image:file_class',
			'field_news_image:language',
			'field_news_image:preserve_files',
			'field_news_image:title',
			'field_news_link',
			'field_news_tags',
			'field_news_tags:source_type',
			'field_news_writer',
			'field_tags',
			'field_tags:source_type',
			'language',
			'promote',
			'status',
			'sticky',
			'title',
			'tnid',
			'translate',
			'uid',
			'is_new',
			'revision',
			'revision_uid',
			), $issues_group, $suppress_warnings);

	    if (module_exists('statistics')) {
	      $this->addUnmigratedDestinations(
	        array('totalcount', 'daycount', 'timestamp'));
	    }

	    if (module_exists('statistics')) {
	      $this->addUnmigratedDestinations(
	      	array('pathauto'));
		}
    }
}

class UGUpdateEvent7Migration extends UGUpdate7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

    	//set systemOfRecord to destination to preserve migrated nodes
	    $this->systemOfRecord = Migration::DESTINATION;
	    $this->destination = new MigrateDestinationNode('event');

	    /* DEFAULT arguments */
		$update_arguments = array(
			'update_nodelinks' => FALSE,
			'update_nodelinks_urls' => '/node/',
			'update_hardlinks_source' => '',
			'update_hardlinks_destination' => '',
		);

		$event_arguments = array(
			'source_event_body' => 'body',
			'source_event_summary' => 'body:summary',
			'source_event_format' => 'body:format',
		);

		//Override default values with arguments if they exist
		foreach ($event_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key]!=''){
			    	$event_arguments[$key] = $this->arguments[$key];
		    	}
		    }
		}

		//Override default values with arguments if they exist
		foreach ($update_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key]!=''){
			    	$update_arguments[$key] = $this->arguments[$key];
			    }
		    }
		}

	    $this->addFieldMapping('nid', 'nid')
			->sourceMigration($this->arguments['dependencies']);

	    // Update body field
		$this->arguments['update_source_body'] = $event_arguments['source_event_body'];
	    $this->addFieldMapping('field_event_body', $event_arguments['source_event_body']);
	    $this->addFieldMapping('field_event_body:summary', $event_arguments['source_event_summary']);
	    $this->addFieldMapping( 'field_event_body:format', $event_arguments['source_event_format'])
		    ->defaultValue('full_html');

	    // Unmapped fields
	    $suppress_warnings = FALSE;
	    $issues_group = NULL;
		$this->addUnmigratedDestinations(array(
			'body:language',
			'changed',
			'comment',
			'created',
			'field_event_attachments',
			'field_event_attachments:description',
			'field_event_attachments:file_class',
			'field_event_attachments:language',
			'field_event_attachments:preserve_files',
			'field_event_caption',
			'field_event_category',
			'field_event_date',
			'field_event_link',
			'field_event_location',
			'field_event_multipart',
			'field_event_category:source_type',
			'field_event_image',
			'field_event_image:alt',
			'field_event_image:file_class',
			'field_event_image:language',
			'field_event_image:preserve_files',
			'field_event_image:title',
			'field_tags',
			'field_tags:source_type',
			'language',
			'promote',
			'status',
			'sticky',
			'title',
			'tnid',
			'translate',
			'uid',
			'is_new',
			'revision',
			'revision_uid',
			), $issues_group, $suppress_warnings);

	    if (module_exists('statistics')) {
	      $this->addUnmigratedDestinations(
	        array('totalcount', 'daycount', 'timestamp'));
	    }

	    if (module_exists('statistics')) {
	      $this->addUnmigratedDestinations(
	      	array('pathauto'));
		}
    }
}


class UGUpdateFAQ7Migration extends UGUpdate7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

    	//set systemOfRecord to destination to preserve migrated nodes
	    $this->systemOfRecord = Migration::DESTINATION;
	    $this->destination = new MigrateDestinationNode('faq');

	    // DEFAULT arguments
		$update_arguments = array(
			'update_nodelinks' => FALSE,
			'update_nodelinks_urls' => '/node/',
			'update_hardlinks_source' => '',
			'update_hardlinks_destination' => '',
		);

		$faq_arguments = array(
			'source_faq_answer' => 'body',
			'source_faq_format' => 'body:format',
		);

		//Override default values with arguments if they exist
		foreach ($faq_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key] != ''){
			    	$faq_arguments[$key] = $this->arguments[$key];
		    	}
		    }
		}

		//Override default values with arguments if they exist
		foreach ($update_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key]!=''){
			    	$update_arguments[$key] = $this->arguments[$key];
			    }
		    }
		}

	    $this->addFieldMapping('nid', 'nid')
			->sourceMigration($this->arguments['dependencies']);

	    // Update field_faq_answer field
		$this->arguments['update_source_body'] = $faq_arguments['source_faq_answer'];
	    $this->addFieldMapping('field_faq_answer', $faq_arguments['source_faq_answer']);
	    $this->addFieldMapping( 'field_faq_answer:format', $faq_arguments['source_faq_format'])
		    ->callbacks(array($this, 'mapFormat'))
		    ->defaultValue('full_html');

	    // Unmapped fields
	    $suppress_warnings = FALSE;
	    $issues_group = NULL;
		$this->addUnmigratedDestinations(array(
			'body:language',
			'changed',
			'comment',
			'created',
			'field_faq_category',
			'field_faq_category:source_type',
			'field_tags',
			'field_tags:source_type',
			'language',
			'promote',
			'status',
			'sticky',
			'title',
			'tnid',
			'translate',
			'uid',
			'is_new',
			'revision',
			'revision_uid',
			), $issues_group, $suppress_warnings);

	    if (module_exists('statistics')) {
	      $this->addUnmigratedDestinations(
	        array('totalcount', 'daycount', 'timestamp'));
	    }

	    if (module_exists('statistics')) {
	      $this->addUnmigratedDestinations(
	      	array('pathauto'));
		}
    }
}


class UGUpdateFeaturedItem7Migration extends UGUpdate7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

    	//set systemOfRecord to destination to preserve migrated nodes
	    $this->systemOfRecord = Migration::DESTINATION;
	    $this->destination = new MigrateDestinationNode('feature');

	    /* DEFAULT arguments */
		$update_arguments = array(
			'update_nodelinks' => FALSE,
			'update_nodelinks_urls' => '/node/',
			'update_hardlinks_source' => '',
			'update_hardlinks_destination' => '',
		);

		/* DEFAULT arguments */
		$featureditem_arguments = array(
			'source_featureditem_body' => 'body',
			'source_featureditem_summary' => 'body:summary',
			'source_featureditem_format' => 'body:format',
		);

		//Override default values with arguments if they exist
		foreach ($featureditem_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key] != ''){
			    	$featureditem_arguments[$key] = $this->arguments[$key];
			    }
		    }
		}

		//Override default values with arguments if they exist
		foreach ($update_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key]!=''){
			    	$update_arguments[$key] = $this->arguments[$key];
			    }
		    }
		}

	    $this->addFieldMapping('nid', 'nid')
			->sourceMigration($this->arguments['dependencies']);

	    // Update body field
		$this->arguments['update_source_body'] = $featureditem_arguments['source_featureditem_body'];
	    $this->addFieldMapping('field_feature_text', $featureditem_arguments['source_featureditem_body']);
	    $this->addFieldMapping('field_feature_text:summary', $featureditem_arguments['source_featureditem_summary']);
	    $this->addFieldMapping( 'field_feature_text:format', $featureditem_arguments['source_featureditem_format'])
		    ->defaultValue('full_html');

	    // Unmapped fields
	    $suppress_warnings = FALSE;
	    $issues_group = NULL;
		$this->addUnmigratedDestinations(array(
			'body:language',
			'changed',
			'comment',
			'created',
			'field_feature_category',
			'field_feature_category:source_type',
			'field_feature_image',
			'field_feature_image:alt',
			'field_feature_image:file_class',
			'field_feature_image:language',
			'field_feature_image:preserve_files',
			'field_feature_image:title',
			'field_feature_link',
			'field_tags',
			'field_tags:source_type',
			'language',
			'promote',
			'status',
			'sticky',
			'title',
			'tnid',
			'translate',
			'uid',
			'is_new',
			'revision',
			'revision_uid',
			), $issues_group, $suppress_warnings);

	    if (module_exists('statistics')) {
	      $this->addUnmigratedDestinations(
	        array('totalcount', 'daycount', 'timestamp'));
	    }

	    if (module_exists('statistics')) {
	      $this->addUnmigratedDestinations(
	      	array('pathauto'));
		}
    }

}


class UGUpdateProfile7Migration extends UGUpdate7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

    	//set systemOfRecord to destination to preserve migrated nodes
	    $this->systemOfRecord = Migration::DESTINATION;
		$this->destination = new MigrateDestinationNode('profile');

	    /* DEFAULT arguments */
		$update_arguments = array(
			'update_nodelinks' => FALSE,
			'update_nodelinks_urls' => '/node/',
			'update_hardlinks_source' => '',
			'update_hardlinks_destination' => '',
		);

		/* DEFAULT arguments */
		$profile_arguments = array(
		  'source_profile_summary'   => 'field_profile_summary',
		  'source_profile_format'    => 'field_profile_summary:format',
		);

		//Override default values with arguments if they exist
		foreach ($profile_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key] != ''){
			    	$profile_arguments[$key] = $this->arguments[$key];
			    }
		    }
		}

	    $this->addFieldMapping('nid', 'nid')
			->sourceMigration($this->arguments['dependencies']);

	    // Update body field
		$this->arguments['update_source_body'] = $profile_arguments['source_profile_summary'];
		$this->addFieldMapping('field_profile_summary', $profile_arguments['source_profile_summary']);
		$this->addFieldMapping('field_profile_summary:format', $profile_arguments['source_profile_format']);

	    // Unmapped fields
	    $suppress_warnings = FALSE;
	    $issues_group = NULL;
		$this->addUnmigratedDestinations(array(
			'body:language',
			'changed',
			'comment',
			'created',
			'field_profile_address',
			'field_profile_attachments',
			'field_profile_caption',
			'field_profile_category',
			'field_profile_category:create_term',
			'field_profile_category:ignore_case',
			'field_profile_category:source_type',
			'field_profile_email',
			'field_profile_faxnumber',
			'field_profile_image',
			'field_profile_image:alt',
			'field_profile_image:file_class',
			'field_profile_image:language',
			'field_profile_image:preserve_files',
			'field_profile_image:title',
			'field_profile_lab',
			'field_profile_lastname',
			'field_profile_name',
			'field_profile_office',
			'field_profile_research',
			'field_profile_research:create_term',
			'field_profile_research:ignore_case',
			'field_profile_research:source_type',
			'field_profile_role',
			'field_profile_role:create_term',
			'field_profile_role:ignore_case',
			'field_profile_role:source_type',
			'field_profile_subunit',
			'field_profile_subunit:create_term',
			'field_profile_subunit:ignore_case',
			'field_profile_subunit:source_type',
			'field_profile_telephonenumber',
			'field_profile_title',
			'field_profile_unit',
			'field_profile_unit:create_term',
			'field_profile_unit:ignore_case',
			'field_profile_unit:source_type',
			'field_profile_website',
			'field_tags',
			'field_tags:source_type',
			'language',
			'promote',
			'status',
			'sticky',
			'title',
			'tnid',
			'translate',
			'uid',
			'is_new',
			'revision',
			'revision_uid',
			), $issues_group, $suppress_warnings);

	    if (module_exists('statistics')) {
	      $this->addUnmigratedDestinations(
	        array('totalcount', 'daycount', 'timestamp'));
	    }

	    if (module_exists('statistics')) {
	      $this->addUnmigratedDestinations(
	      	array('pathauto'));
		}
	}
}


?>