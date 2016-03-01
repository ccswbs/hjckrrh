<?php 

/* NODE classes */

class UGEvent7Migration extends DrupalNode7Migration {
	public function __construct($arguments) {

    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('event');

		/* DEFAULT arguments */
		$event_arguments = array(
			'source_event_body' => 'body',
			'source_event_summary' => 'body:summary',
			'source_event_format' => 'body:format',
			'source_event_category' => '',
			'source_event_keyword' => '',
			'source_event_date' => '',
			'source_event_date_timezone' => 'America/New_York',
			'source_event_location' => '',
			'source_event_multipart' => '',
			'source_event_image' => '',
			'source_event_caption' => '',
			'source_event_attachments' => '',
			'source_event_link' => '',
		);

		//Override default values with arguments if they exist
		foreach ($event_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key] != ''){
			    	$event_arguments[$key] = $this->arguments[$key];
		    	}
		    }
		}

	    /* Event Body */
	    $this->addFieldMapping('field_event_body', $event_arguments['source_event_body']);
	    $this->addFieldMapping('field_event_body:summary', $event_arguments['source_event_summary']);
	    $this->addFieldMapping( 'field_event_body:format', $event_arguments['source_event_format'])
		    ->defaultValue('full_html');

		/* Event Category */
		$this->addFieldMapping('field_event_category', $event_arguments['source_event_category'])
			->sourceMigration('UGEventCategory7');
		$this->addFieldMapping('field_event_category:source_type')
			->defaultValue('tid');

		/* Event Keyword */
		$this->addFieldMapping('field_tags', $event_arguments['source_event_keyword'])
			->sourceMigration('UGTerm7');
		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');

		/* Event Featured Image */
	    $this->addFieldMapping('field_event_image', $event_arguments['source_event_image'])
	    	->sourceMigration('UGFile7');
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

		/* Event File Attachments */
	    $this->addFieldMapping('field_event_attachments', $event_arguments['source_event_attachments'])
		    ->sourceMigration('UGFile7');
		$this->addFieldMapping('field_event_attachments:file_class')
		    ->defaultValue('MigrateFileFid');
		$this->addFieldMapping('field_event_attachments:preserve_files')
		    ->defaultValue('TRUE');
	    $this->addFieldMapping('field_event_attachments:description', $event_arguments['source_event_attachments'] . ':description')
	        ->defaultValue('');
	    $this->addFieldMapping('field_event_attachments:language')
	        ->defaultValue(LANGUAGE_NONE);

		/* Event Date */
		$this->addFieldMapping('field_event_date', $event_arguments['source_event_date']);
		$this->addFieldMapping('field_event_date:to', $event_arguments['source_event_date'].":value2");
		$this->addFieldMapping('field_event_date:timezone')
			->defaultValue($event_arguments['source_event_date_timezone']);

		/* Event Location, Multipart Fields, Caption, Link */
		$this->addFieldMapping('field_event_location', $event_arguments['source_event_location']);
		$this->addFieldMapping('field_event_multipart', $event_arguments['source_event_multipart']);
		$this->addFieldMapping('field_event_caption', $event_arguments['source_event_caption']);
		$this->addFieldMapping('field_event_link', $event_arguments['source_event_link']);
	}



/* Troubleshooting Function -- Uncomment to print out contents of every row */

	/*public function prepareRow($row){
		if(parent::prepareRow($row)===FALSE){
			return FALSE;
		}
		echo("<<<<<<<");
		drush_print_r($row);
		echo(">>>>>>>");
	}*/

	

}

class UGEventMultifield7Migration extends DrupalMigration {
	public function __construct($arguments) {
		parent::__construct($arguments);

		/* PSEUDO D7 QUERY - used when site config file fails to define an override query */
		$pseudo_query = Database::getConnection('default', 'legacy_d7')
		    ->select('node', 'n');
		$pseudo_query->fields('n',array('nid'));
		$pseudo_query->range(0, 1);
		$skip_count = TRUE;

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
		    if(isset($this->arguments[$key])){
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
	    	->sourceMigration('UGEvent7');

    	$this->addFieldMapping('field_event_heading', $event_multipart_arguments['source_event_multipart_field_collection_heading_termID'])
	    	->sourceMigration('UGEventHeading7');
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


class UGNews7Migration extends DrupalNode7Migration {
	public function __construct($arguments) {

    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('news');

		/* DEFAULT arguments */
		$news_arguments = array(
			'source_news_body' => 'body',
			'source_news_summary' => 'body:summary',
			'source_news_format' => 'body:format',
			'source_news_category' => '',
			'source_news_keyword' => '',
			'source_news_writer' => '',
			'source_news_link' => '',
			'source_news_image' => '',
			'source_news_caption' => '',
			'source_news_attachment' => '',
		);


		//Override default values with arguments if they exist
		foreach ($news_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	$news_arguments[$key] = $this->arguments[$key];
		    }
		}

	    /* News Body */
	    $this->addFieldMapping('field_news_body', $news_arguments['source_news_body']);
	    $this->addFieldMapping('field_news_body:summary', $news_arguments['source_news_summary']);
	    $this->addFieldMapping( 'field_news_body:format', $news_arguments['source_news_format'])
		    ->defaultValue('full_html');

		/* News Category */
		$this->addFieldMapping('field_news_tags', $news_arguments['source_news_category'])
			->sourceMigration('UGNewsCategory7');
		$this->addFieldMapping('field_news_tags:source_type')
			->defaultValue('tid');

		/* News Keyword */
		$this->addFieldMapping('field_tags', $news_arguments['source_news_keyword'])
			->sourceMigration('UGTerm7');
		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');

		/* News Featured Image */
	    $this->addFieldMapping('field_news_image', $news_arguments['source_news_image'])
	    	->sourceMigration('UGFile7');
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


		/* News File Attachments */
	    $this->addFieldMapping('field_news_attachment', $news_arguments['source_news_attachment'])
		    ->sourceMigration('UGFile7');
		$this->addFieldMapping('field_news_attachment:file_class')
		    ->defaultValue('MigrateFileFid');
		$this->addFieldMapping('field_news_attachment:preserve_files')
		    ->defaultValue('TRUE');
	    $this->addFieldMapping('field_news_attachment:description', $news_arguments['source_news_attachment'] . ':description')
	        ->defaultValue('');
	    $this->addFieldMapping('field_news_attachment:language')
	        ->defaultValue(LANGUAGE_NONE);

		/* News Writer, Link, Caption */
	    $this->addFieldMapping('field_news_writer', $news_arguments['source_news_writer']);
	    $this->addFieldMapping('field_news_link', $news_arguments['source_news_link']);
	    $this->addFieldMapping('field_news_caption', $news_arguments['source_news_caption']);

	}
}


class UGPage7Migration extends DrupalNode7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('page');

	    /* DEFAULT arguments */
		$page_arguments = array(
			'source_page_body' => 'body',
			'source_page_summary' => 'body:summary',
			'source_page_format' => 'body:format',
			'source_page_category' => '',
			'source_page_keyword' => '',
			'source_page_attachments' => '',
		);

		//Override default values with arguments if they exist
		foreach ($page_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	$page_arguments[$key] = $this->arguments[$key];
		    }
		}

	    /* Page Body */
	    $this->addFieldMapping('field_page_body', $page_arguments['source_page_body']);
	    $this->addFieldMapping('field_page_body:summary', $page_arguments['source_page_summary']);
	    $this->addFieldMapping( 'field_page_body:format', $page_arguments['source_page_format'])
		    ->callbacks(array($this, 'mapFormat'))
		    ->defaultValue('full_html');

		/* Page Category */
		$this->addFieldMapping('field_page_category', $page_arguments['source_page_category'])
			->sourceMigration('UGPageCategory7');
		$this->addFieldMapping('field_page_category:source_type')
			->defaultValue('tid');
		$this->addFieldMapping('field_page_category:ignore_case')
			->defaultValue(TRUE);
		$this->addFieldMapping('field_page_category:create_term')
		    ->defaultValue(TRUE);

		/* Page Keyword */
		$this->addFieldMapping('field_tags', $page_arguments['source_page_keyword'])
			->sourceMigration('UGTerm7');
		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');

		/* Page File Attachments */
	    $this->addFieldMapping('field_page_attachments', $page_arguments['source_page_attachments'])
		    ->sourceMigration('UGFile7');
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

/* TERM classes */

class UGEventHeading7Migration extends DrupalTerm7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGEventCategory7Migration extends DrupalTerm7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGEventKeyword7Migration extends DrupalTerm7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGNewsCategory7Migration extends DrupalTerm7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGNewsKeyword7Migration extends DrupalTerm7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGPageCategory7Migration extends DrupalTerm7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGTerm7Migration extends DrupalTerm7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

/* FILE classes */
class UGFile7Migration extends DrupalFile7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
	}
}