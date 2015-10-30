<?php 



class UGPageMigration extends DrupalNode7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

    	$dest_prefix = 'field_page_body';
    	$source_prefix = 'body';

	    $this->destination = new MigrateDestinationNode('page');
	    $this->addFieldMapping( $dest_prefix, $source_prefix);
	    $this->addFieldMapping( $dest_prefix . ':format', $source_prefix . ':format')
		    ->defaultValue('full_html');
	}
}

class UGTermMigration extends DrupalTerm7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}