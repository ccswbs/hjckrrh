<?php 

class UGUpdate7Migration extends DrupalNode7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

    	$this->arguments['update_source_body'] = 'body';
    	$this->arguments['update_map_table'] = '';
    	$this->arguments['update_insert_fields'] = NULL;
	}

	public function prepareRow($row) {
	    if (parent::prepareRow($row) === FALSE) {
	      return FALSE;
	    }

		//insert unmappable fields into body field
		if(isset($this->arguments['update_insert_fields'])){
		    $row->{$this->arguments['update_source_body']}[0] = $this->insertUnmappableFields($row->{$this->arguments['update_source_body']}[0], $this->arguments['update_insert_fields'], $row->nid);
		}

	    //fix updated items missing destination ID
	    if(!isset($row->migrate_map_destid1)){
	    	if($this->arguments['update_map_table'] != ''){
	    		$new_destid = $this->retrieveMapDestID($this->arguments['update_map_table'],$row->nid);
	    		if(is_numeric($new_destid)){
			    	$row->migrate_map_destid1 = $new_destid;
		    	}
	    	}
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


	    // update source prefix for in-line images & files
	    if(isset($this->arguments['update_prefix_inline'])) {
	    	if($this->arguments['update_prefix_inline'] == TRUE){
		    	$old_prefixes = $this->arguments['update_prefix_source'];
		    	$new_prefix = $this->arguments['update_prefix_destination'];
			    $row->{$this->arguments['update_source_body']}[0] = $this->replaceImgTags($row->{$this->arguments['update_source_body']}[0],$old_prefixes, $new_prefix);
				$row->{$this->arguments['update_source_body']}[0] = $this->replaceLinkUrls($row->{$this->arguments['update_source_body']}[0], $old_prefixes, $new_prefix);
			}
		}
	}

	public function insertUnmappableFields(&$body, &$field_inserts, &$nid){
		$new_body = $body;
		$top_section = '';
		$bottom_section = '';

		if($new_body != ''){
			$new_body = $field_inserts['before_target'] . $new_body;
			$new_body .= $field_inserts['after_target'];
		}

		//loop through field groups
		foreach($field_inserts['field_groups'] as $field_group){
			$content_count = 0;
			$field_group_insert = '';

			foreach($field_group['fields'] as $field_name => $field_info){

				//retrieve value for each field
				$field_query = Database::getConnection('default','legacy_d7')
					->select($field_info['db_table'],'f')
					->fields('f',$field_info['db_field_value'])
					->condition($field_info['db_field_entity_id'],$nid,'LIKE')
					->execute()
					->fetchObject();
				$field_value = $field_query->{$field_info['db_field_value'][0]};

				// if field value exists, add to 
				if(isset($field_value)){
					if($field_value != ''){
						$content_count++;

						if($field_info['content_before'] != ''){
							$field_group_insert .= $field_info['content_before'];
						}
						$field_group_insert .= $field_value;

						if($field_info['content_after'] != ''){
							$field_group_insert .= $field_info['content_after'];
						}
					}
				}
			}

			if($content_count > 0){

				$field_group_insert = $field_group['content_before'] . $field_group_insert;
				$field_group_insert .= $field_group['content_after'];

				if($field_group['placement'] == 'top'){
					$top_section .= $field_group_insert;
				}else{
					$bottom_section .= $field_group_insert;
				}
			}
		}

		//add top section to top of body
		if($top_section != ''){
			$new_body = $top_section . $new_body;
		}

		//add bottom section to bottom of body
		if($bottom_section != ''){
			$new_body .= $bottom_section;
		}

	  	if(isset($new_body)){
		  	return $new_body;
	  	}
	  	return $body;
	}


	public function retrieveMapDestID(&$map_table, &$nid){
	    $destID = Database::getConnection('default', 'default')
	      ->select($map_table, 'm')
	      ->fields('m', array('destid1'))
	      ->condition('sourceid1', $nid, 'LIKE')
	      ->execute()
	      ->fetchObject();

	    if (isset($destID->destid1)) {
	    	return $destID->destid1;
	    }
	}

	/******
	* @TODO: Make a more generic class that receives the search pattern as a variable
	************/
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

	/******
	* @TODO: Make a more generic class that receives the search pattern as a variable
	************/
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
			'source_page_insert_fields' => NULL,
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
			->sourceMigration('UGPage7');
		$this->arguments['update_map_table'] = 'migrate_map_ugpage7';

	    // Update body field
		$this->arguments['update_insert_fields'] = $page_arguments['source_page_insert_fields'];
		$this->arguments['update_source_body'] = $page_arguments['source_page_body'];
	    $this->addFieldMapping('field_page_body', $page_arguments['source_page_body']);
	    $this->addFieldMapping('field_page_body:summary', $page_arguments['source_page_summary']);

		// Page Body Format
		if($page_arguments['source_page_body'] == 'body'){
		    $this->addFieldMapping( 'field_page_body:format', $page_arguments['source_page_format'])
			    ->defaultValue('full_html');
		}else{
		    $this->addFieldMapping( 'field_page_body:format', $page_arguments['source_page_format'])
			    ->callbacks(array($this, 'mapFormat'))
			    ->defaultValue('full_html');
		}
    }
}


class UGUpdateNews7Migration extends UGUpdate7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

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
			'source_news_insert_fields' => NULL,
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
			->sourceMigration('UGNews7');
		$this->arguments['update_map_table'] = 'migrate_map_ugnews7';

	    // Update body field
    	$this->arguments['update_insert_fields'] = $news_arguments['source_news_insert_fields'];
		$this->arguments['update_source_body'] = $news_arguments['source_news_body'];
	    $this->addFieldMapping('field_news_body', $news_arguments['source_news_body']);
	    $this->addFieldMapping('field_news_body:summary', $news_arguments['source_news_summary']);

		// News Body Format
		if($news_arguments['source_news_body'] == 'body'){
		    $this->addFieldMapping( 'field_news_body:format', $news_arguments['source_news_format'])
			    ->defaultValue('full_html');
		}else{
		    $this->addFieldMapping( 'field_news_body:format', $news_arguments['source_news_format'])
			    ->callbacks(array($this, 'mapFormat'))
			    ->defaultValue('full_html');
		}
    }
}

class UGUpdateEvent7Migration extends UGUpdate7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

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
			'source_event_insert_fields' => NULL,
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
			->sourceMigration('UGEvent7');
		$this->arguments['update_map_table'] = 'migrate_map_ugevent7';

	    // Update body field
    	$this->arguments['update_insert_fields'] = $event_arguments['source_event_insert_fields'];
		$this->arguments['update_source_body'] = $event_arguments['source_event_body'];
	    $this->addFieldMapping('field_event_body', $event_arguments['source_event_body']);
	    $this->addFieldMapping('field_event_body:summary', $event_arguments['source_event_summary']);

		// Event Body Format
		if($event_arguments['source_event_body'] == 'body'){
		    $this->addFieldMapping( 'field_event_body:format', $event_arguments['source_event_format'])
			    ->defaultValue('full_html');
		}else{
		    $this->addFieldMapping( 'field_event_body:format', $event_arguments['source_event_format'])
			    ->callbacks(array($this, 'mapFormat'))
			    ->defaultValue('full_html');
		}
    }
}


class UGUpdateFAQ7Migration extends UGUpdate7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

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
			'source_faq_insert_fields' => NULL,
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
			->sourceMigration('UGFAQ7');
		$this->arguments['update_map_table'] = 'migrate_map_ugfaq7';

	    // Update field_faq_answer field
    	$this->arguments['update_insert_fields'] = $faq_arguments['source_faq_insert_fields'];
		$this->arguments['update_source_body'] = $faq_arguments['source_faq_answer'];
	    $this->addFieldMapping('field_faq_answer', $faq_arguments['source_faq_answer']);

		// FAQ Answer Format
		if($faq_arguments['source_faq_answer'] == 'body'){
		    $this->addFieldMapping( 'field_faq_answer:format', $faq_arguments['source_faq_format'])
			    ->defaultValue('full_html');
		}else{
		    $this->addFieldMapping( 'field_faq_answer:format', $faq_arguments['source_faq_format'])
			    ->callbacks(array($this, 'mapFormat'))
			    ->defaultValue('full_html');
		}
    }
}


class UGUpdateFeaturedItem7Migration extends UGUpdate7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

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
			'source_featureditem_link' => '',
			'source_featureditem_insert_fields' => NULL,
			'source_featureditem_update_hardlinks_destination' => '',
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
			->sourceMigration('UGFeaturedItem7');
		$this->arguments['update_map_table'] = 'migrate_map_ugfeatureditem7';

	    // Update body field
    	$this->arguments['update_insert_fields'] = $featureditem_arguments['source_featureditem_insert_fields'];
		$this->arguments['update_source_body'] = $featureditem_arguments['source_featureditem_body'];
	    $this->addFieldMapping('field_feature_text', $featureditem_arguments['source_featureditem_body']);
	    $this->addFieldMapping('field_feature_text:summary', $featureditem_arguments['source_featureditem_summary']);
	    $this->addFieldMapping('field_feature_link', $featureditem_arguments['source_featureditem_link']);

		// Featured Item Body Format
		if($featureditem_arguments['source_featureditem_body'] == 'body'){
		    $this->addFieldMapping( 'field_feature_text:format', $featureditem_arguments['source_featureditem_format'])
			    ->defaultValue('full_html');
		}else{
		    $this->addFieldMapping( 'field_feature_text:format', $featureditem_arguments['source_featureditem_format'])
			    ->callbacks(array($this, 'mapFormat'))
			    ->defaultValue('full_html');
		}
    }

	public function prepareRow($row) {
	    if (parent::prepareRow($row) === FALSE) {
	      return FALSE;
	    }

		/******
		* @TODO: Once a more generic class for replacing node IDs and absolute URLs (ie. one that allows
		*    you to pass the search pattern as a variable), update UGUpdateFeaturedItem so it uses 
		*    those classes instead of rewriting the same code in prepareRow
		************/

		//update Featured Item Link
	    if(isset($this->arguments['update_nodelinks'])) {
	    	if($this->arguments['update_nodelinks'] == TRUE){
			    $pattern_nodelinks = array('/node/');
			    $source_migrations = $this->arguments['dependencies'];

			    // replace linked source nids with destination nids
			    if(isset($this->arguments['update_nodelinks_urls'])){
			    	$pattern_nodelinks = $this->arguments['update_nodelinks_urls'];
			    }

				$row->{$this->arguments['source_featureditem_link']}[0] = $this->replaceFeatureLinkSourceNodes(
					$row->{$this->arguments['source_featureditem_link']}[0], 
					$this->arguments['update_nodelinks_urls'], 
					$source_migrations);


			    // replace linked source URLs with destination urls
			    if(isset($this->arguments['update_hardlinks_source']) &&
			    	isset($this->arguments['source_featureditem_update_hardlinks_destination'])) {
				    	$old_urls = $this->arguments['update_hardlinks_source'];
				    	$new_url = $this->arguments['source_featureditem_update_hardlinks_destination'];
				    	$row->{$this->arguments['source_featureditem_link']}[0] = $this->replaceFeatureLinkUrls($row->{$this->arguments['source_featureditem_link']}[0], $old_urls, $new_url);
			    }

			}
		}
    }

	public function replaceFeatureLinkSourceNodes(&$value, $pattern_nodelinks, $migrations){
	  	$new_value = $value;

	  	foreach($pattern_nodelinks as $np){
	  		// Search for links matching pattern
	  		$np = preg_quote($np,"/");
	  		$pattern_search = '/^' . $np . '(\d+)\/*?/si';
	  		$num_matches = preg_match_all($pattern_search, $new_value, $match_pattern);

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
						$new_value = str_replace($mp, $updated_mp, $new_value);
					}
		  		}
	  		}
	  	}

	  	if(isset($new_value)){
		  	return $new_value;
	  	}
	  	return $value;
	}


	public function replaceFeatureLinkUrls(&$body, &$replace_urls, &$new_url){
	  	$new_body = $body;

	  	//loop through each source site URL up for replacement
	  	foreach($replace_urls as $u){

	  		//remove trailing slash
	  		if(substr($u, -1) == '/'){
	  			$u = substr($u, 0, -1);
	  		}
	  		$new_body = str_replace($u, $new_url, $new_body);
  		}

	  	if(isset($new_body)){
		  	return $new_body;
	  	}
	  	return $body;
	}
}


class UGUpdateProfile7Migration extends UGUpdate7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

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
		  'source_profile_title' => 'field_profile_title',
		  'source_profile_name' => 'field_profile_name',
		  'source_profile_lastname' => 'field_profile_lastname',
		  'source_profile_summary' => 'field_profile_summary',
		  'source_profile_format' => 'field_profile_summary:format',
		  'source_profile_insert_fields' => NULL,
		);

		//Override default values with arguments if they exist
		foreach ($profile_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key] != ''){
			    	$profile_arguments[$key] = $this->arguments[$key];
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
			->sourceMigration('UGProfile7');
		$this->arguments['update_map_table'] = 'migrate_map_ugprofile7';

		/* Profile Title */
		$this->addFieldMapping('field_profile_title', $profile_arguments['source_profile_title']);

		/* Profile First and Last Name */
		$this->addFieldMapping('field_profile_name', $profile_arguments['source_profile_name']);
		$this->addFieldMapping('field_profile_lastname', $profile_arguments['source_profile_lastname']);

	    // Update body field
    	$this->arguments['update_insert_fields'] = $profile_arguments['source_profile_insert_fields'];
		$this->arguments['update_source_body'] = $profile_arguments['source_profile_summary'];
		$this->addFieldMapping('field_profile_summary', $profile_arguments['source_profile_summary']);

		// Profile Summary Format
		if($profile_arguments['source_profile_summary'] == 'body'){
			$this->addFieldMapping('field_profile_summary:format', $profile_arguments['source_profile_format'])
			    ->defaultValue('full_html');
		}else{
			$this->addFieldMapping('field_profile_summary:format', $profile_arguments['source_profile_format'])
			    ->callbacks(array($this, 'mapFormat'))
			    ->defaultValue('full_html');
		}
	}
}


class UGUpdateBanner7Migration extends UGUpdate7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('banner');

	    // DEFAULT arguments
		$update_arguments = array(
			'update_nodelinks' => FALSE,
			'update_nodelinks_urls' => '/node/',
			'update_hardlinks_source' => '',
			'update_hardlinks_destination' => '',
		);

		$banner_arguments = array(
		  'source_banner_text'                     => 'field_banner_text',
		  'source_banner_text_format'              => 'field_banner_text:format',
		  'source_banner_image_src_prefix'         => '',
		  'source_banner_insert_fields'            => NULL,
		);

		//Override default values with arguments if they exist
		foreach ($banner_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key] != ''){
			    	$banner_arguments[$key] = $this->arguments[$key];
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
			->sourceMigration('UGBanner7');
		$this->arguments['update_map_table'] = 'migrate_map_ugbanner7';
    	$this->arguments['update_insert_fields'] = $banner_arguments['source_banner_insert_fields'];
    	$this->arguments['update_image_src_prefix'] = $banner_arguments['source_banner_image_src_prefix'];

	    // Update Banner Text field
		$this->arguments['update_source_body'] = $banner_arguments['source_banner_text'];
	    $this->addFieldMapping('field_banner_text', $banner_arguments['source_banner_text']);

		// Banner Text Format
		if($banner_arguments['source_banner_text'] == 'body'){
			$this->addFieldMapping('field_banner_text:format', $banner_arguments['source_banner_text_format'])
			    ->defaultValue('full_html');
		}else{
			$this->addFieldMapping('field_banner_text:format', $banner_arguments['source_banner_text_format'])
			    ->callbacks(array($this, 'mapFormat'))
			    ->defaultValue('full_html');
		}

    }
}



class UGUpdateCourseOutline7Migration extends UGUpdate7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

		$this->destination = new MigrateDestinationNode('course_outline');

	    /* DEFAULT arguments */
		$update_arguments = array(
			'update_nodelinks' => FALSE,
			'update_nodelinks_urls' => '/node/',
			'update_hardlinks_source' => '',
			'update_hardlinks_destination' => '',
		);

		/* DEFAULT arguments */
		$course_arguments = array(
		    'source_course_title'           => 'field_course_title',
		    'source_course_name'            => 'field_course_name',
		    'source_course_code'            => 'field_course_code',
		    'source_course_section'         => 'field_course_section',
		    'source_course_body'            => 'field_course_body',
		    'source_course_summary'         => 'field_course_body:summary',
		    'source_course_format'          => 'field_course_body:format',
			'source_course_insert_fields'   => NULL,
		);

		//Override default values with arguments if they exist
		foreach ($course_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key] != ''){
			    	$course_arguments[$key] = $this->arguments[$key];
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
			->sourceMigration('UGCourseOutline7');
		$this->arguments['update_map_table'] = 'migrate_map_ugcourseoutline7';

		// Course Outline Title 
		$this->addFieldMapping('field_course_title', $course_arguments['source_course_title']);

		// Course Outline Name, Course, and Section
		$this->addFieldMapping('field_course_name', $course_arguments['source_course_name']);
		$this->addFieldMapping('field_course_code', $course_arguments['source_course_code']);
		$this->addFieldMapping('field_course_section', $course_arguments['source_course_section']);

	    // Update body field
    	$this->arguments['update_insert_fields'] = $course_arguments['source_course_insert_fields'];
		$this->arguments['update_source_body'] = $course_arguments['source_course_body'];
	    $this->addFieldMapping('field_course_body', $course_arguments['source_course_body']);
	    $this->addFieldMapping('field_course_body:summary', $course_arguments['source_course_summary']);

		// Course Outline Body Format
		if($course_arguments['source_course_body'] == 'body'){
		    $this->addFieldMapping( 'field_course_body:format', $course_arguments['source_course_format'])
			    ->defaultValue('full_html');
		}else{
		    $this->addFieldMapping( 'field_course_body:format', $course_arguments['source_course_format'])
			    ->callbacks(array($this, 'mapFormat'))
			    ->defaultValue('full_html');
		}
	}
}


?>