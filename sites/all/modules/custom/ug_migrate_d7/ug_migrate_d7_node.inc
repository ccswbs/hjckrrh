<?php 

class UGEvents7Migration extends DrupalNode7Migration {
	public function __construct($arguments) {

    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('event');

		/**
		*
		* @TODO: 
		*
		*  - Add backup plan for when $arguments do not include field mappings variables
		*  - add File and URL Redirect
		**/

	    /* Events Body */
	    $this->addFieldMapping('field_events_body', $this->arguments['source_events_body']);
	    $this->addFieldMapping( 'field_events_body:format', $this->arguments['source_events_format'])
		    ->defaultValue('full_html');

		/* Events Category */
		$this->addFieldMapping('field_event_category', $this->arguments['source_events_category'])
			->sourceMigration('UGEventsCategory7');
		$this->addFieldMapping('field_event_category:source_type')
			->defaultValue('tid');

		/* Events Keyword */
		$this->addFieldMapping('field_tags', $this->arguments['source_events_keyword'])
			->sourceMigration('UGTerm7');
		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');
	}
}


class UGNews7Migration extends DrupalNode7Migration {
	public function __construct($arguments) {

    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('news');

		/**
		*
		* @TODO: 
		*
		*  - Add backup plan for when $arguments do not include field mappings variables
		*  - add File and URL Redirect
		**/

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
	}
}


class UGPage7Migration extends DrupalNode7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('page');

		/**
		*
		* @TODO: 
		*
		*  - Add backup plan for when $arguments do not include field mapping variables
		*  - add File and URL Redirect
		**/

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

		/* Settings: Is New / Revisions */
		$this->addFieldMapping('is_new', NULL, FALSE)
			->defaultValue(TRUE);
	    $this->addFieldMapping('revision', NULL, FALSE)
	    	->defaultValue(TRUE);
	}
}

class UGEventsCategory7Migration extends DrupalTerm7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGNewsCategory7Migration extends DrupalTerm7Migration {
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