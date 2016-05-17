<?php 

class UGUpdate7Migration extends DrupalNode7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

    	$this->arguments['update_source_body'] = 'body';
    	$this->arguments['update_map_table'] = '';
	}

	public function prepareRow($row) {
	    if (parent::prepareRow($row) === FALSE) {
	      return FALSE;
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

		$this->arguments['update_map_table'] = 'migrate_map_ugpage7';

	    // Update body field
		$this->arguments['update_source_body'] = $page_arguments['source_page_body'];
	    $this->addFieldMapping('field_page_body', $page_arguments['source_page_body']);
	    $this->addFieldMapping('field_page_body:summary', $page_arguments['source_page_summary']);
	    $this->addFieldMapping( 'field_page_body:format', $page_arguments['source_page_format'])
		    ->defaultValue('full_html');
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
		$this->arguments['update_map_table'] = 'migrate_map_ugnews7';

	    // Update body field
		$this->arguments['update_source_body'] = $news_arguments['source_news_body'];
	    $this->addFieldMapping('field_news_body', $news_arguments['source_news_body']);
	    $this->addFieldMapping('field_news_body:summary', $news_arguments['source_news_summary']);
	    $this->addFieldMapping( 'field_news_body:format', $news_arguments['source_news_format'])
		    ->defaultValue('full_html');
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
		$this->arguments['update_map_table'] = 'migrate_map_ugevent7';

	    // Update body field
		$this->arguments['update_source_body'] = $event_arguments['source_event_body'];
	    $this->addFieldMapping('field_event_body', $event_arguments['source_event_body']);
	    $this->addFieldMapping('field_event_body:summary', $event_arguments['source_event_summary']);
	    $this->addFieldMapping( 'field_event_body:format', $event_arguments['source_event_format'])
		    ->defaultValue('full_html');
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
		$this->arguments['update_map_table'] = 'migrate_map_ugfaq7';

	    // Update field_faq_answer field
		$this->arguments['update_source_body'] = $faq_arguments['source_faq_answer'];
	    $this->addFieldMapping('field_faq_answer', $faq_arguments['source_faq_answer']);
	    $this->addFieldMapping( 'field_faq_answer:format', $faq_arguments['source_faq_format'])
		    ->callbacks(array($this, 'mapFormat'))
		    ->defaultValue('full_html');
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
		$this->arguments['update_map_table'] = 'migrate_map_ugfeatureditem7';

	    // Update body field
		$this->arguments['update_source_body'] = $featureditem_arguments['source_featureditem_body'];
	    $this->addFieldMapping('field_feature_text', $featureditem_arguments['source_featureditem_body']);
	    $this->addFieldMapping('field_feature_text:summary', $featureditem_arguments['source_featureditem_summary']);
	    $this->addFieldMapping( 'field_feature_text:format', $featureditem_arguments['source_featureditem_format'])
		    ->defaultValue('full_html');
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
		  'source_profile_title'     => 'field_profile_title',
		  'source_profile_name'      => 'field_profile_name',
		  'source_profile_lastname'  => 'field_profile_lastname',
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
		$this->arguments['update_map_table'] = 'migrate_map_ugprofile7';

		/* Profile Title */
		$this->addFieldMapping('field_profile_title', $profile_arguments['source_profile_title']);

		/* Profile First and Last Name */
		$this->addFieldMapping('field_profile_name', $profile_arguments['source_profile_name']);
		$this->addFieldMapping('field_profile_lastname', $profile_arguments['source_profile_lastname']);

	    // Update body field
		$this->arguments['update_source_body'] = $profile_arguments['source_profile_summary'];
		$this->addFieldMapping('field_profile_summary', $profile_arguments['source_profile_summary']);
		$this->addFieldMapping('field_profile_summary:format', $profile_arguments['source_profile_format']);
	}
}


?>