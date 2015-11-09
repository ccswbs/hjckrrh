<?php 

class UGNews6Migration extends DrupalNode6Migration {
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
			->sourceMigration('UGNewsCategory6');
		$this->addFieldMapping('field_news_tags:source_type')
			->defaultValue('tid');

		/* News Keyword */
		$this->addFieldMapping('field_tags', $this->arguments['source_news_keyword'])
			->sourceMigration('UGNewsKeyword6');
		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');
	}
}

class UGPage6Migration extends DrupalNode6Migration {
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