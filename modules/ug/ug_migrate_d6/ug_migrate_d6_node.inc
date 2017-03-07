<?php 

class UGDrupalNode6Migration extends DrupalNode6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

		$this->arguments['update_source_body'] = '';
    	$this->arguments['update_map_table'] = '';
    	$this->arguments['update_insert_fields'] = NULL;
    	$this->arguments['update_image_src_prefix'] = NULL;
    }

  /**
   * Implementation of Migration::prepareRow().
   */

	public function prepareRow($row) {
	    if (parent::prepareRow($row) === FALSE) {
	      return FALSE;
	    }

		//insert unmappable fields into body field
		if(isset($this->arguments['update_insert_fields'])){
		    $row->{$this->arguments['update_source_body']} = $this->insertUnmappableFields($row->{$this->arguments['update_source_body']}, $this->arguments['update_insert_fields'], $row->nid);
		}

	    // retrieve inline prefix of image (use hardlinks destination site stub as inline prefix for image
		$image_src_prefix = '';
    	if(isset($this->arguments['update_image_src_prefix']) && $this->arguments['update_image_src_prefix']!=''){
	    	$image_src_prefix = $this->arguments['update_image_src_prefix'];
    	}else if(isset($this->arguments['update_hardlinks_destination']) && $this->arguments['update_hardlinks_destination']!=''){
	    	$image_src_prefix = $this->arguments['update_hardlinks_destination'];
    	}

    	// IMAGE ATTACH - insert img attach files into body field
    	$queryImageAttach = Database::getConnection('default','legacy_d6')
    		->schema()
    		->tableExists('image_attach');

    	if($queryImageAttach == TRUE){
	    	$row->{$this->arguments['update_source_body']} = $this->replaceImgAttach($row->{$this->arguments['update_source_body']}, $image_src_prefix, $this->arguments['update_map_table'], $row->nid);
    	}else{
	    	//reset exception object -- see https://www.drupal.org/node/1706810
	    	Database::getConnection('default',$this->sourceConnection)->schema()->tableExists('node');
	    }

	    // IMAGE ASSIST - update img assist tags with html img tags
    	$queryImageAssist = Database::getConnection('default','legacy_d6')
    		->schema()
    		->tableExists('img_assist_map');

    	if($queryImageAssist == TRUE){
		    if(strpos($row->{$this->arguments['update_source_body']},'[img_assist') !== false){
		    	$row->{$this->arguments['update_source_body']} = $this->replaceImgAssist($row->{$this->arguments['update_source_body']}, $image_src_prefix);
		    }
	    }else{
	    	//reset exception object -- see https://www.drupal.org/node/1706810
	    	Database::getConnection('default',$this->sourceConnection)->schema()->tableExists('node');
	    }
	}

	// insert Image Attachments into body field
	public function replaceImgAttach(&$body, &$image_src_prefix, $source_table, $source_nid){
	  	$new_body = $body;

	    //retrieve image attach files from image_attach table
	    $image_attach_query = Database::getConnection('default','legacy_d6')
	    	->select('image_attach','ia')
	    	->fields('ia',array('iid'))
	    	->condition('ia.nid', $source_nid, '=')
	    	->orderBy('weight','ASC');

		//retrieve image id and limit to _original size files
	    $image_attach_query->innerJoin('image','i','i.nid=ia.iid');
		$image_attach_query->condition('i.image_size','_original','LIKE');

		//retrieve image filename and filepath
		$image_attach_query->innerJoin('files','f','i.fid=f.fid');
		$image_attach_query->fields('f', array('fid'));

		//retrieve image description from node table
		$image_attach_query->innerJoin('node','n','i.nid=n.nid');
		$image_attach_query->fields('n', array('title'));
	    $image_attach_results = $image_attach_query->execute()->fetchAll();

	  	foreach($image_attach_results as $ia){
			//retrieve destination file ID for image attach
			$image_query = Database::getConnection('default','default')
				->select('file_managed','f')
				->fields('f', array('fid','uri'));
			$image_query->innerJoin('migrate_map_ugfile6','mm','mm.destid1=f.fid');
			$image_query->condition('mm.sourceid1', $ia->fid ,"=");
			$image = $image_query->execute()->fetchObject();

			// Insert img attach file at top of body field
			$image_src = $image_src_prefix . "/" . conf_path() . "/files/" . file_uri_target($image->uri);
			$desc = $ia->title;

			$replacement = '<figure class="thumbnail"><img alt="' . $desc .'" class="img-responsive" src="'. $image_src .'" /></figure>';
	  		$new_body = $replacement . $new_body;

		}

	  	if($new_body){
		  	return $new_body;
	  	}
	  	return $body;

	}

	//replace Image Assist tags with regular HTML img tags
	public function replaceImgAssist(&$body, &$image_src_prefix){
	  	$pattern_desc = '/(?<=desc=)([\d\s\w\.\?\,]+?)(?=\|)/';
	  	$pattern_img = '/(?<=_)([\d\s\w\.\?\,]+?)(?=_)/';
	  	$new_body = $body;

	  	//retrieve list of img_assist_tag nids in body field
		$pattern = '/\[img_assist\|nid=(\d*).+?]/';
		preg_match_all($pattern, $new_body, $matches);
		$image_ids = array_pop($matches);
		$images = array();

		foreach($image_ids as $id){

			//retrieve source file ID for image assist
			$source_query = Database::getConnection('default','legacy_d6')
				->select('files','f')
				->fields('f', array('fid','filename','filepath'));
			$source_query->innerJoin('image','i','f.fid=i.fid');
			$source_query->condition('f.filename','_original','LIKE');
			$source_query->innerJoin('node','n','n.nid=i.nid');
			$source_query->condition('n.nid',$id,'=');
			$source_results = $source_query->execute()->fetchObject();

			//retrieve destination file ID for image assist
			$dest_query = Database::getConnection('default','default')
				->select('file_managed','f')
				->fields('f', array('fid','uri'));
			$dest_query->innerJoin('migrate_map_ugfile6','mm','mm.destid1=f.fid');
			$dest_query->condition('mm.sourceid1',$source_results->fid,"=");
			$dest_results = $dest_query->execute()->fetchObject();

			// Find img_assist tag in body field
			$pattern = '/\[img_assist\|(nid=' . $id . ')(.+?)]/';
			preg_match($pattern, $new_body, $matches);
			$m = array_shift($matches);

			// Replace img_assist tag with img tag
			if(strpos($m,'[img_assist') !== false){
				$image_src = $image_src_prefix . "/" . conf_path() . "/files/" . file_uri_target($dest_results->uri);
				preg_match($pattern_desc, $m, $desc_match);
				$desc = array_shift($desc_match);
				$replacement = '<figure class="thumbnail"><img alt="' . $desc .'" class="img-responsive" src="'. $image_src .'" /></figure>';
		  		$new_body = preg_replace($pattern, $replacement, $new_body);
		  	}

		}

	  	if($new_body){
		  	return $new_body;
	  	}
	  	return $body;
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
				$field_query = Database::getConnection('default','legacy_d6')
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

}


class UGFeaturedItem6Migration extends UGDrupalNode6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
	    $this->destination = new MigrateDestinationNode('feature');

		/* DEFAULT arguments */
		$featureditem_arguments = array(
			'source_featureditem_body'                   => 'body',
			'source_featureditem_summary'                => 'body:summary',
			'source_featureditem_format'                 => 'body:format',
			'source_featureditem_link'                   => '',
			'source_featureditem_image'                  => 'fid',
			'source_featureditem_category' 	             => '',
			'source_featureditem_category_default_value' => '',
			'source_featureditem_keyword'                => '',
			'source_featureditem_keyword_default_value'  => '',
			'source_featureditem_image_src_prefix'       => '',
			'source_featureditem_insert_fields'	         => NULL,
		);

		//Override default values with arguments if they exist
		foreach ($featureditem_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key] != ''){
			    	$featureditem_arguments[$key] = $this->arguments[$key];
			    }
		    }
		}

		/* INSERT fields into Body variables */
		$this->arguments['update_source_body'] = $featureditem_arguments['source_featureditem_body'];
    	$this->arguments['update_image_src_prefix'] = $featureditem_arguments['source_featureditem_image_src_prefix'];
    	$this->arguments['update_insert_fields'] = $featureditem_arguments['source_featureditem_insert_fields'];
		$this->arguments['update_map_table'] = 'migrate_map_ugfeatureditem6';

	    /* Featured Item Body */
	    $this->addFieldMapping('field_feature_text', $featureditem_arguments['source_featureditem_body']);
	    $this->addFieldMapping('field_feature_text:summary', $featureditem_arguments['source_featureditem_summary']);

		// Featured Item Body Format
		if($featureditem_arguments['source_featureditem_body'] == 'body'){
		    $this->addFieldMapping( 'field_feature_text:format', $featureditem_arguments['source_featureditem_format'])
			    ->defaultValue('full_html');
		}else{
		    $this->addFieldMapping( 'field_feature_text:format', $featureditem_arguments['source_featureditem_format'])
			    ->callbacks(array($this, 'mapFormat'))
			    ->defaultValue('full_html');
		}

		/* Featured Item Category */
		if($featureditem_arguments['source_featureditem_category_default_value'] != ''){
			$this->addFieldMapping('field_feature_category')
				->defaultValue($featureditem_arguments['source_featureditem_category_default_value']);
		}else{
			$this->addFieldMapping('field_feature_category', $featureditem_arguments['source_featureditem_category'])
				->sourceMigration('UGFeaturedItemCategory6');
		}
		$this->addFieldMapping('field_feature_category:source_type')
			->defaultValue('tid');

		/* Featured Item Keyword */
		if($featureditem_arguments['source_featureditem_keyword_default_value'] != ''){
			$this->addFieldMapping('field_tags')
				->defaultValue($featureditem_arguments['source_featureditem_keyword_default_value']);
		}else{
			$this->addFieldMapping('field_tags', $featureditem_arguments['source_featureditem_keyword'])
				->sourceMigration('UGTerm6','UGFeaturedItemKeyword6');			
		}
		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');

		/* Featured Item Image */
	    $this->addFieldMapping('field_feature_image', $featureditem_arguments['source_featureditem_image']);
		$this->addFieldMapping('field_feature_image:file_class')
		    ->defaultValue('MigrateFileFid');
		$this->addFieldMapping('field_feature_image:preserve_files')
		    ->defaultValue('TRUE');
	    $this->addFieldMapping('field_feature_image:alt', $featureditem_arguments['source_featureditem_image'] . ':alt')
	        ->defaultValue('');
	    $this->addFieldMapping('field_feature_image:title', $featureditem_arguments['source_featureditem_image'] . ':title')
	        ->defaultValue('');
	    $this->addFieldMapping('field_feature_image:language')
	        ->defaultValue(LANGUAGE_NONE);

		/* Featured Item Link */
	    $this->addFieldMapping('field_feature_link', $featureditem_arguments['source_featureditem_link']);
	}
}


class UGEvent6Migration extends UGDrupalNode6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('event');

		/* DEFAULT arguments */
		$event_arguments = array(
			'source_event_body'                   => 'body',
			'source_event_summary'                => 'body:summary',
			'source_event_format'                 => 'body:format',
			'source_event_category'	              => '',
			'source_event_category_default_value' => '',
			'source_event_keyword'                => '',
			'source_event_keyword_default_value'  => '',
			'source_event_date'                   => '',
			'source_event_location'               => '',
			'source_event_multipart'              => '',
			'source_event_image'                  => 'fid',
			'source_event_caption'                => '',
			'source_event_attachments'            => '',
			'source_event_link'                   => '',
			'source_event_image_src_prefix'       => '',
			'source_event_insert_fields'          => NULL,
		);

		//Override default values with arguments if they exist
		foreach ($event_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key]!=''){
			    	$event_arguments[$key] = $this->arguments[$key];
		    	}
		    }
		}

		/* INSERT fields into Body variables */
		$this->arguments['update_source_body'] = $event_arguments['source_event_body'];
		$this->arguments['update_image_src_prefix'] = $event_arguments['source_event_image_src_prefix'];
    	$this->arguments['update_insert_fields'] = $event_arguments['source_event_insert_fields'];
		$this->arguments['update_map_table'] = 'migrate_map_ugevent6';

	    /* Event Body */
	    $this->addFieldMapping('field_event_body', $event_arguments['source_event_body']);
	    $this->addFieldMapping( 'field_event_body:summary', $event_arguments['source_event_summary']);

		// Event Body Format
		if($event_arguments['source_event_body'] == 'body'){
		    $this->addFieldMapping( 'field_event_body:format', $event_arguments['source_event_format'])
			    ->defaultValue('full_html');
		}else{
		    $this->addFieldMapping( 'field_event_body:format', $event_arguments['source_event_format'])
			    ->callbacks(array($this, 'mapFormat'))
			    ->defaultValue('full_html');
		}

		/* Event Category */
		if($event_arguments['source_event_category_default_value'] != ''){
			$this->addFieldMapping('field_event_category')
				->defaultValue($event_arguments['source_event_category_default_value']);
		}else{
			$this->addFieldMapping('field_event_category', $event_arguments['source_event_category'])
				->sourceMigration('UGEventCategory6');
		}
		$this->addFieldMapping('field_event_category:source_type')
			->defaultValue('tid');

		/* Event Keyword */
		if($event_arguments['source_event_keyword_default_value'] != ''){
			$this->addFieldMapping('field_tags')
				->defaultValue($event_arguments['source_event_keyword_default_value']);
		}else{
			$this->addFieldMapping('field_tags', $event_arguments['source_event_keyword'])
				->sourceMigration('UGTerm6','UGEventKeyword6');
		}
		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');

		/* Event Fields */
		$this->addFieldMapping('field_event_date', $event_arguments['source_event_date']);
		$this->addFieldMapping('field_event_location', $event_arguments['source_event_location']);
		$this->addFieldMapping('field_event_multipart', $event_arguments['source_event_multipart']);
		$this->addFieldMapping('field_event_caption', $event_arguments['source_event_caption']);
		$this->addFieldMapping('field_event_link', $event_arguments['source_event_link']);

		/* Event File Attachments */
		$this->addFieldMapping('field_event_attachments', $event_arguments['source_event_attachments'])
		    ->sourceMigration('UGFile6');
		$this->addFieldMapping('field_event_attachments:file_class')
		    ->defaultValue('MigrateFileFid');
		$this->addFieldMapping('field_event_attachments:preserve_files')
		    ->defaultValue('TRUE');
	    $this->addFieldMapping('field_event_attachments:description', $event_arguments['source_event_attachments'] . ':description')
	        ->defaultValue('');
	    $this->addFieldMapping('field_event_attachments:language')
	        ->defaultValue(LANGUAGE_NONE);

		/* Event Featured Image */
	    $this->addFieldMapping('field_event_image', $event_arguments['source_event_image']);
		$this->addFieldMapping('field_event_image:file_class')
		    ->defaultValue('MigrateFileFid');
		$this->addFieldMapping('field_event_image:preserve_files')
		    ->defaultValue('TRUE');
	    $this->addFieldMapping('field_event_image:alt', $event_arguments['source_event_image'] . ':alt')
	        ->defaultValue('');
	    $this->addFieldMapping('field_event_image:title', $event_arguments['source_event_image'] . ':title')
	        ->defaultValue('');
	    $this->addFieldMapping('field_event_image:language')
	        ->defaultValue(LANGUAGE_NONE);
	}
}


class UGEventMultifield6Migration extends DrupalMigration {
	public function __construct($arguments) {
		parent::__construct($arguments);

		/* PSEUDO D6 QUERY - used when site config file fails to define an override query */
		$pseudo_query = Database::getConnection('default', 'legacy_d6')
		    ->select('node', 'n');
		$pseudo_query->fields('n',array('nid'));
		$pseudo_query->range(0, 1);
		$skip_count = TRUE;

		/* PSEUDO D6 MAPPING - used to ensure map messages table is constructed */
	    $pseudo_mapping = array('nid' => array(
		      'type' => 'int',
		      'not signed' => true,
		      'not null' => true,
		      'description' => t('Define query in site configuration file'),
		      'alias' => 'n',
		    )
	    );

		/* DEFAULT arguments */
		$event_multipart_arguments = array(
			'source_event_multipart_query' => $pseudo_query,
			'source_event_multipart_sourcefields' => array(),
			'source_event_multipart_mapping' => $pseudo_mapping,
			'source_event_multipart_field_collection_ID'=>'',
			'source_event_multipart_field_collection_heading_termID'=>'',
			'source_event_multipart_field_collection_content' => '',
		);

		//Override default values with arguments if they exist
		foreach ($event_multipart_arguments as $key => $value) {
		    if(isset($this->arguments[$key])) {
		    	$event_multipart_arguments[$key] = $this->arguments[$key];
		    }
		}

		if(isset($this->arguments['source_event_multipart_query'])) {
			$skip_count = FALSE;
		}

		$this->source = new MigrateSourceSQL(
			$event_multipart_arguments['source_event_multipart_query'],
			$event_multipart_arguments['source_event_multipart_sourcefields'],
			NULL, array('map_joinable' => FALSE, 'skip_count' => $skip_count));

		$this->map = new MigrateSQLMap($this->machineName, 
			$event_multipart_arguments['source_event_multipart_mapping'],
	      	MigrateDestinationFieldCollection::getKeySchema()
	    );

	    $this->destination = new MigrateDestinationFieldCollection(
			'field_event_multipart',
			array('host_entity_type' => 'node')
	    );

		$this->addFieldMapping('item_id', $event_multipart_arguments['source_event_multipart_field_collection_ID']);

	    $this->addFieldMapping('host_entity_id', 'entity_id')
	    	->sourceMigration('UGEvent6');

    	$this->addFieldMapping('field_event_heading', $event_multipart_arguments['source_event_multipart_field_collection_heading_termID'])
	    	->sourceMigration('UGEventHeading6');
		$this->addFieldMapping('field_event_heading:source_type')
			->defaultValue('tid');

		$this->addFieldMapping('field_event_content', $event_multipart_arguments['source_event_multipart_field_collection_content']);
	}

	protected function query() {
	}

	//Source: https://www.drupal.org/node/2487618
	public function prepare($entity, $row) {
	    //parent::prepare($entity, $row);

	    // The field collection migration code will have loaded an old revision of
	    // the host entity; when it saves the host entity, old field values will
	    // overwrite the current ones. Set the most recent revision as the host
	    // entity instead.
	    if ($hosts = entity_load($entity->hostEntityType(), array($entity->hostEntityId()))) {
	      $host = reset($hosts);
	      $entity->updateHostEntity($host);
	    }
	  }
}


class UGNews6Migration extends UGDrupalNode6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('news');

		/* DEFAULT arguments */
		$news_arguments = array(
			'source_news_body'                   => 'body',
			'source_news_summary'                => 'body:summary',
			'source_news_format'                 => 'body:format',
			'source_news_category'               => '',
			'source_news_category_default_value' => '',
			'source_news_keyword'                => '',
			'source_news_keyword_default_value'  => '',
			'source_news_writer'                 => '',
			'source_news_link'                   => '',
			'source_news_image'                  => 'fid',
			'source_news_caption'                => '',
			'source_news_attachment'             => '',
			'source_news_image_src_prefix'       => '',
			'source_news_insert_fields'          => NULL,
		);

		//Override default values with arguments if they exist
		foreach ($news_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key]!=''){
			    	$news_arguments[$key] = $this->arguments[$key];
			    }
		    }
		}

		/* INSERT fields into Body variables */
		$this->arguments['update_source_body'] = $news_arguments['source_news_body'];
		$this->arguments['update_image_src_prefix'] = $news_arguments['source_news_image_src_prefix'];
    	$this->arguments['update_insert_fields'] = $news_arguments['source_news_insert_fields'];
		$this->arguments['update_map_table'] = 'migrate_map_ugnews6';

	    /* News Body */
	    $this->addFieldMapping('field_news_body', $news_arguments['source_news_body']);
	    $this->addFieldMapping( 'field_news_body:summary', $news_arguments['source_news_summary']);

		// News Body Format
		if($news_arguments['source_news_body'] == 'body'){
		    $this->addFieldMapping( 'field_news_body:format', $news_arguments['source_news_format'])
			    ->defaultValue('full_html');
		}else{
		    $this->addFieldMapping( 'field_news_body:format', $news_arguments['source_news_format'])
			    ->callbacks(array($this, 'mapFormat'))
			    ->defaultValue('full_html');
		}

		/* News Category */
		if($news_arguments['source_news_category_default_value'] != ''){
			$this->addFieldMapping('field_news_tags')
				->defaultValue($news_arguments['source_news_category_default_value']);
		}else{
			$this->addFieldMapping('field_news_tags', $news_arguments['source_news_category'])
				->sourceMigration('UGNewsCategory6');
		}

		$this->addFieldMapping('field_news_tags:source_type')
			->defaultValue('tid');

		/* News Keyword */
		if($news_arguments['source_news_keyword_default_value'] != ''){
			$this->addFieldMapping('field_tags')
				->defaultValue($news_arguments['source_news_keyword_default_value']);
		}else{
			$this->addFieldMapping('field_tags', $news_arguments['source_news_keyword'])
				->sourceMigration('UGTerm6','UGNewsKeyword6');
		}

		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');

		/* News Fields */
	    $this->addFieldMapping('field_news_writer', $news_arguments['source_news_writer']);
	    $this->addFieldMapping('field_news_link', $news_arguments['source_news_link']);
	    $this->addFieldMapping('field_news_caption', $news_arguments['source_news_caption']);

		/* News File Attachments */
	    $this->addFieldMapping('field_news_attachment', $news_arguments['source_news_attachment'])
		    ->sourceMigration('UGFile6');
		$this->addFieldMapping('field_news_attachment:file_class')
		    ->defaultValue('MigrateFileFid');
		$this->addFieldMapping('field_news_attachment:preserve_files')
		    ->defaultValue('TRUE');
	    $this->addFieldMapping('field_news_attachment:description', $news_arguments['source_news_attachment'] . ':description')
	        ->defaultValue('');
	    $this->addFieldMapping('field_news_attachment:language')
	        ->defaultValue(LANGUAGE_NONE);

		/* News Featured Image */
	    $this->addFieldMapping('field_news_image', $news_arguments['source_news_image']);
		$this->addFieldMapping('field_news_image:file_class')
		    ->defaultValue('MigrateFileFid');
		$this->addFieldMapping('field_news_image:preserve_files')
		    ->defaultValue('TRUE');
	    $this->addFieldMapping('field_news_image:alt', $news_arguments['source_news_image'] . ':alt')
	        ->defaultValue('');
	    $this->addFieldMapping('field_news_image:title', $news_arguments['source_news_image'] . ':title')
	        ->defaultValue('');
	    $this->addFieldMapping('field_news_image:language')
	        ->defaultValue(LANGUAGE_NONE);

	}

}


class UGPage6Migration extends UGDrupalNode6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('page');

	    /* DEFAULT arguments */
		$page_arguments = array(
			'source_page_body'                   => 'body',
			'source_page_summary'                => 'body:summary',
			'source_page_format'                 => 'body:format',
			'source_page_category'               => '',
			'source_page_category_default_value' => '',
			'source_page_keyword'                => '',
			'source_page_keyword_default_value'  => '',
			'source_page_attachments'            => '',
			'source_page_image_src_prefix'       => '',
			'source_page_insert_fields'          => NULL,
		);

		//Override default values with arguments if they exist
		foreach ($page_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key]!=''){
			    	$page_arguments[$key] = $this->arguments[$key];
			    }
		    }
		}

		/* INSERT fields into Body variables */
		$this->arguments['update_source_body'] = $page_arguments['source_page_body'];
		$this->arguments['update_image_src_prefix'] = $page_arguments['source_page_image_src_prefix'];
    	$this->arguments['update_insert_fields'] = $page_arguments['source_page_insert_fields'];
		$this->arguments['update_map_table'] = 'migrate_map_ugpage6';

	    /* Page Body */
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

		/* Page Category */
		if($page_arguments['source_page_category_default_value'] != ''){
			$this->addFieldMapping('field_page_category')
				->defaultValue($page_arguments['source_page_category_default_value']);
		}else{
			$this->addFieldMapping('field_page_category', $page_arguments['source_page_category'])
				->sourceMigration('UGPageCategory6');
		}
		$this->addFieldMapping('field_page_category:source_type')
			->defaultValue('tid');

		/* Page Keyword */
		if($page_arguments['source_page_keyword_default_value'] != ''){
			$this->addFieldMapping('field_tags')
				->defaultValue($page_arguments['source_page_keyword_default_value']);
		}else{
			$this->addFieldMapping('field_tags', $page_arguments['source_page_keyword'])
				->sourceMigration('UGTerm6','UGPageKeyword6');
		}
		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');

		/* Page File Attachments */
	    $this->addFieldMapping('field_page_attachments', $page_arguments['source_page_attachments'])
		    ->sourceMigration('UGFile6');
		$this->addFieldMapping('field_page_attachments:file_class')
		    ->defaultValue('MigrateFileFid');
		$this->addFieldMapping('field_page_attachments:preserve_files')
		    ->defaultValue('TRUE');
	    $this->addFieldMapping('field_page_attachments:description', $page_arguments['source_page_attachments'] . ':description')
	        ->defaultValue('');
	    $this->addFieldMapping('field_page_attachments:language')
	        ->defaultValue(LANGUAGE_NONE);
	}
}

class UGFAQ6Migration extends UGDrupalNode6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('faq');
		
		/* DEFAULT arguments */
		$faq_arguments = array(
			'source_faq_answer'                 => 'body',
			'source_faq_format'                 => 'body:format',
			'source_faq_category'               => '',
			'source_faq_category_default_value' => '',
			'source_faq_keyword'                => '',
			'source_faq_keyword_default_value'  => '',
			'source_faq_image_src_prefix'       => '',
			'source_faq_insert_fields'          => NULL,
		);

		//Override default values with arguments if they exist
		foreach ($faq_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key] != ''){
			    	$faq_arguments[$key] = $this->arguments[$key];
		    	}
		    }
		}

		/* INSERT fields into Body variables */
		$this->arguments['update_source_body'] = $faq_arguments['source_faq_answer'];
		$this->arguments['update_image_src_prefix'] = $faq_arguments['source_faq_image_src_prefix'];
    	$this->arguments['update_insert_fields'] = $faq_arguments['source_faq_insert_fields'];
		$this->arguments['update_map_table'] = 'migrate_map_ugfaq6';

	    /* FAQ Answer */
	    $this->addFieldMapping('field_faq_answer', $faq_arguments['source_faq_answer']);

		// FAQ Answer Format
		if($faq_arguments['source_faq_answer'] == 'body'){
			$this->addFieldMapping('field_faq_answer:format', $faq_arguments['source_faq_format'])
			    ->defaultValue('full_html');
		}else{
		    $this->addFieldMapping( 'field_faq_answer:format', $faq_arguments['source_faq_format'])
			    ->callbacks(array($this, 'mapFormat'))
			    ->defaultValue('full_html');
		}

		/* FAQ Category */
		if($faq_arguments['source_faq_category_default_value'] != ''){
			$this->addFieldMapping('field_faq_category')
				->defaultValue($faq_arguments['source_faq_category_default_value']);
		}else{
			$this->addFieldMapping('field_faq_category', $faq_arguments['source_faq_category'])
				->sourceMigration('UGFAQCategory6');
		}
		$this->addFieldMapping('field_faq_category:source_type')
			->defaultValue('tid');

		/* FAQ Keyword */
		if($faq_arguments['source_faq_keyword_default_value'] != ''){
			$this->addFieldMapping('field_tags')
				->defaultValue($faq_arguments['source_faq_keyword_default_value']);
		}else{
			$this->addFieldMapping('field_tags', $faq_arguments['source_faq_keyword'])
				->sourceMigration('UGTerm6','UGFAQKeyword6');
		}

		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');
	}
}


class UGFeaturedItemCategory6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGFeaturedItemKeyword6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGEventHeading6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGEventCategory6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGEventKeyword6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGNewsCategory6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}
}

class UGNewsKeyword6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}
}

class UGPageCategory6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}
}

class UGPageKeyword6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}
}

class UGFAQCategory6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
	}	
}
class UGFAQKeyword6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
	}	
}

class UGTerm6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}
}

/* FILE classes */
class UGFile6Migration extends DrupalFile6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
	}

	public function prepareRow($row) {
		if (parent::prepareRow($row) === FALSE) {
		    return FALSE;
		}
	    
	    //drush_print_r($row);
	}
}