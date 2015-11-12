<?php 

class UGEvent7Migration extends DrupalNode7Migration {
	public function __construct($arguments) {

    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('event');

	    /* Event Body */
	    $this->addFieldMapping('field_event_body', $this->arguments['source_event_body']);
	    $this->addFieldMapping( 'field_event_body:format', $this->arguments['source_event_format'])
		    ->defaultValue('full_html');

		/* Event Category */
		$this->addFieldMapping('field_event_category', $this->arguments['source_event_category'])
			->sourceMigration('UGEventCategory7');
		$this->addFieldMapping('field_event_category:source_type')
			->defaultValue('tid');

		/* Event Keyword */
		$this->addFieldMapping('field_tags', $this->arguments['source_event_keyword'])
			->sourceMigration('UGTerm7');
		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');

		/* Event Fields */
		$this->addFieldMapping('field_event_date', $this->arguments['source_event_date']);
		$this->addFieldMapping('field_event_location', $this->arguments['source_event_location']);
		$this->addFieldMapping('field_event_image', $this->arguments['source_event_image']);
		$this->addFieldMapping('field_event_multipart', $this->arguments['source_event_multipart']);
		$this->addFieldMapping('field_event_caption', $this->arguments['source_event_caption']);
		$this->addFieldMapping('field_event_attachments', $this->arguments['source_event_attachments']);
		$this->addFieldMapping('field_event_link', $this->arguments['source_event_link']);
	}
}

class UGEventMultifield7Migration extends DrupalMigration {
	public function __construct($arguments) {
		parent::__construct($arguments);

		$query = $this->arguments['source_event_multipart_query'];
		$this->source = new MigrateSourceSQL($query, $this->arguments['source_event_mulitpart_sourcefields'], NULL);

		$this->map = new MigrateSQLMap($this->machineName, 
			$this->arguments['source_event_multipart_mapping'],
	      	MigrateDestinationFieldCollection::getKeySchema()
	    );

	    $this->destination = new MigrateDestinationFieldCollection(
			'field_event_multipart',
			array('host_entity_type' => 'node')
	    );

		$this->addFieldMapping('item_id', $this->arguments['source_event_multipart_field_collection_ID']);

	    $this->addFieldMapping('host_entity_id', 'entity_id')
	    	->sourceMigration('UGEvent7');

    	$this->addFieldMapping('field_event_heading', $this->arguments['source_event_multipart_field_collection_heading_termID'])
	    	->sourceMigration('UGEventHeading7');
		$this->addFieldMapping('field_event_heading:source_type')
			->defaultValue('tid');

		$this->addFieldMapping('field_event_content', $this->arguments['source_event_multipart_field_collection_content']);
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

	    /* News Body */
	    $this->addFieldMapping('field_news_body', $this->arguments['source_news_body']);
	    $this->addFieldMapping( 'field_news_body:format', $this->arguments['source_news_format'])
		    ->defaultValue('full_html');

		/* News Category */
		$this->addFieldMapping('field_news_tags', $this->arguments['source_news_category'])
			->sourceMigration('UGNewsCategory7');
		$this->addFieldMapping('field_news_tags:source_type')
			->defaultValue('tid');

		/* News Keyword */
		$this->addFieldMapping('field_tags', $this->arguments['source_news_keyword'])
			->sourceMigration('UGTerm7');
		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');

		/* News Fields */
	    $this->addFieldMapping('field_news_writer', $this->arguments['source_news_writer']);
	    $this->addFieldMapping('field_news_link', $this->arguments['source_news_link']);
	    $this->addFieldMapping('field_news_image', $this->arguments['source_news_image']);
	    $this->addFieldMapping('field_news_caption', $this->arguments['source_news_caption']);
	    $this->addFieldMapping('field_news_attachment', $this->arguments['source_news_attachment']);

	}
}


class UGPage7Migration extends DrupalNode7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('page');

	    /* Page Body */
	    $this->addFieldMapping('field_page_body', $this->arguments['source_page_body']);
	    $this->addFieldMapping('field_page_body:summary', $this->arguments['source_page_summary']);
	    $this->addFieldMapping( 'field_page_body:format', $this->arguments['source_page_format'])
		    ->callbacks(array($this, 'mapFormat'))
		    ->defaultValue('full_html');

		/* Page Category */
		$this->addFieldMapping('field_page_category', $this->arguments['source_page_category'])
			->sourceMigration('UGPageCategory7');
		$this->addFieldMapping('field_page_category:source_type')
			->defaultValue('tid');
		$this->addFieldMapping('field_page_category:ignore_case')
			->defaultValue(TRUE);
		$this->addFieldMapping('field_page_category:create_term')
		    ->defaultValue(TRUE);

		/* Page Keyword */
		$this->addFieldMapping('field_tags', $this->arguments['source_page_keyword'])
			->sourceMigration('UGTerm7');
		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');

		/* Page File Attachments */
	    $this->addFieldMapping('field_page_attachments', $this->arguments['source_page_attachments']);

		/* Settings: Is New / Revisions */
		/*$this->addFieldMapping('is_new', NULL, FALSE)
			->defaultValue(TRUE);
	    $this->addFieldMapping('revision', NULL, FALSE)
	    	->defaultValue(TRUE);*/

	}
}


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