<?php 

class UGEvent7Migration extends DrupalNode7Migration {
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
		$this->addFieldMapping('field_event_category', $this->arguments['source_event_category'])
			->sourceMigration('UGEventCategory7');
		$this->addFieldMapping('field_event_category:source_type')
			->defaultValue('tid');

		/* Event Keyword */
		$this->addFieldMapping('field_tags', $this->arguments['source_event_keyword'])
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
		* @TODO: add File and URL Redirect
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

		/* News Writer */
	    $this->addFieldMapping('field_news_writer', $this->arguments['source_news_writer']);

		/* News Link (External) */
	    $this->addFieldMapping('field_news_link', $this->arguments['source_news_link']);

		/* News Image */
	    $this->addFieldMapping('field_news_image', $this->arguments['source_news_image']);

		/* News Image Caption */
	    $this->addFieldMapping('field_news_caption', $this->arguments['source_news_caption']);

		/* News File Attachment */
	    $this->addFieldMapping('field_news_attachment', $this->arguments['source_news_attachment']);

	}
}


class UGPage7Migration extends DrupalNode7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	    $this->destination = new MigrateDestinationNode('page');

		/**
		* @TODO: add File and URL Redirect
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

		/* Page File Attachments */
	    $this->addFieldMapping('field_page_attachments', $this->arguments['source_page_attachments']);

		/* Settings: Is New / Revisions */
		/*$this->addFieldMapping('is_new', NULL, FALSE)
			->defaultValue(TRUE);
	    $this->addFieldMapping('revision', NULL, FALSE)
	    	->defaultValue(TRUE);*/

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