<?php 

class UGEvent6Migration extends DrupalNode6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('event');

		/**
		* @TODO: add File and URL Redirect
		**/

	    /* Event Body */
	    $this->addFieldMapping('field_event_body', $this->arguments['source_event_body']);
	    $this->addFieldMapping( 'field_event_body:format', $this->arguments['source_event_format'])
		    ->defaultValue('full_html');

		/* Event Category */
		$this->addFieldMapping('field_event_tags', $this->arguments['source_event_category'])
			->sourceMigration('UGEventCategory6');
		$this->addFieldMapping('field_event_tags:source_type')
			->defaultValue('tid');

		/* Event Keyword */
		$this->addFieldMapping('field_tags', $this->arguments['source_event_keyword'])
			->sourceMigration('UGEventKeyword6');
		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');
	}
}

class UGNews6Migration extends DrupalNode6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('news');

		/**
		* @TODO: add File and URL Redirect
		**/

	    /* News Body */
	    $this->addFieldMapping('field_news_body', $this->arguments['source_news_body']);
	    $this->addFieldMapping( 'field_news_body:format', $this->arguments['source_news_format'])
		    ->defaultValue('full_html');

		/* News Category */
		$this->addFieldMapping('field_news_tags', $this->arguments['source_news_category'])
			->sourceMigration('UGNewsCategory6');
		$this->addFieldMapping('field_news_tags:source_type')
			->defaultValue('tid');

		/* News Keyword */
		$this->addFieldMapping('field_tags', $this->arguments['source_news_keyword'])
			->sourceMigration('UGNewsKeyword6');
		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');

		/* News Writer */
	    $this->addFieldMapping('field_news_writer', $this->arguments['source_news_writer']);

		/* News Link (External) */
	    $this->addFieldMapping('field_news_link', $this->arguments['source_news_link']);

		/* News Image */
	    $this->addFieldMapping('field_news_image', $this->arguments['source_news_image']);

		/* News Image Caption */
	    $this->addFieldMapping('field_news_caption', $this->arguments['source_news_caption']);
			
	}
}

class UGPage6Migration extends DrupalNode6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);


	    $this->destination = new MigrateDestinationNode('page');

		/**
		* @TODO: add File and URL Redirect
		**/

	    /* Page Body */
	    $this->addFieldMapping('field_page_body', $this->arguments['source_page_body']);
	    $this->addFieldMapping( 'field_page_body:format', $this->arguments['source_page_format'])
		    ->defaultValue('full_html');

		/* Page Category */
		$this->addFieldMapping('field_page_category', $this->arguments['source_page_category'])
			->sourceMigration('UGPageCategory6');
		$this->addFieldMapping('field_page_category:source_type')
			->defaultValue('tid');

		/* Page Keyword */
		$this->addFieldMapping('field_tags', $this->arguments['source_page_keyword'])
			->sourceMigration('UGTerm6');
		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');
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

class UGTerm6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}