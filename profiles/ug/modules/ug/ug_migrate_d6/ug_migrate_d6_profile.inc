<?php

/* PROFILE classes */
class UGProfile6Migration extends UGDrupalNode6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

		$this->destination = new MigrateDestinationNode('profile');

		/* DEFAULT arguments */
		$profile_arguments = array(
		  'source_profile_node_type'                => 'profile',
		  'source_profile_name'                     => 'field_profile_name',
		  'source_profile_lastname'                 => 'field_profile_lastname',
		  'source_profile_role'                     => 'field_profile_role',
		  'source_profile_role_source_type'         => 'tid',
		  'source_profile_role_ignore_case'         => TRUE,
		  'source_profile_role_create_term'         => TRUE,
		  'source_profile_role_vocabulary'     	    => 'profile_role',
	 	  'source_profile_role_default_value'       => '',
		  'source_profile_unit'                     => 'field_profile_unit',
	  	  'source_profile_unit_source_type'         => 'tid',
		  'source_profile_unit_ignore_case'         => TRUE,
		  'source_profile_unit_create_term'         => TRUE,
		  'source_profile_unit_vocabulary'          => 'profile_unit',
	 	  'source_profile_unit_default_value'       => '',
		  'source_profile_summary'                  => 'field_profile_summary',
		  'source_profile_format'                   => 'field_profile_summary:format',
		  'source_profile_category'                 => 'field_profile_category',
	  	  'source_profile_category_source_type'     => 'tid',
		  'source_profile_category_ignore_case'     => TRUE,
		  'source_profile_category_create_term'     => TRUE,
	 	  'source_profile_category_vocabulary'      => 'profile_category',
	 	  'source_profile_category_default_value'   => '',
		  'source_profile_title'                    => 'field_profile_title',
		  'source_profile_subunit'                  => 'field_profile_subunit',
	  	  'source_profile_subunit_source_type'      => 'tid',
		  'source_profile_subunit_ignore_case'      => TRUE,
		  'source_profile_subunit_create_term'      => TRUE,
		  'source_profile_subunit_vocabulary'       => 'profile_term_subunit',
	 	  'source_profile_subunit_default_value'    => '',
		  'source_profile_research'                 => 'field_profile_research',
	  	  'source_profile_research_source_type'     => 'tid',
		  'source_profile_research_ignore_case'     => TRUE,
		  'source_profile_research_create_term'     => TRUE,
		  'source_profile_research_vocabulary'      => 'profile_research',
	 	  'source_profile_research_default_value'   => '',
		  'source_profile_attachments'              => 'field_profile_attachments',
		  'source_profile_image'                    => 'field_profile_image',
		  'source_profile_caption'                  => 'field_profile_caption',
		  'source_profile_address'                  => 'field_profile_address',
		  'source_profile_email'                    => 'field_profile_email',
		  'source_profile_telephonenumber'          => 'field_profile_telephonenumber',
		  'source_profile_faxnumber'                => 'field_profile_faxnumber',
		  'source_profile_office'                   => 'field_profile_office',
		  'source_profile_lab'                      => 'field_profile_lab',
		  'source_profile_website'                  => 'field_profile_website',
		  'source_tags'                             => 'field_tags',
		  'source_tags_source_type'                 => 'tid',
		  'source_tags_ignore_case'                 => TRUE,
		  'source_tags_create_term'                 => TRUE,
		  'source_tags_vocabulary'                  => 'tags',
	 	  'source_tags_default_value'               => '',
		  'source_profile_image_src_prefix'         => '',
		  'source_profile_insert_fields'            => NULL,
		);

		//Override default values with arguments if they exist
		foreach ($profile_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key] != ''){
			    	$profile_arguments[$key] = $this->arguments[$key];
			    }
		    }
		}

		/* INSERT fields into Body variables */
		$this->arguments['update_source_body'] = $profile_arguments['source_profile_summary'];
		$this->arguments['update_map_table'] = 'migrate_map_ugprofile6';
    	$this->arguments['update_insert_fields'] = $profile_arguments['source_profile_insert_fields'];
		$this->arguments['update_image_src_prefix'] = $profile_arguments['source_profile_image_src_prefix'];

		/* Profile First and Last Name */
		$this->addFieldMapping('field_profile_name', $profile_arguments['source_profile_name']);
		$this->addFieldMapping('field_profile_lastname', $profile_arguments['source_profile_lastname']);

		/* Profile Role */
		if($profile_arguments['source_profile_role_default_value']!=''){
			$this->addFieldMapping('field_profile_role')
			     ->defaultValue($profile_arguments['source_profile_role_default_value']);
		}else{
			$this->addFieldMapping('field_profile_role', $profile_arguments['source_profile_role'])
			     ->sourceMigration('UGProfileRole6');
		}

		$this->addFieldMapping('field_profile_role:source_type')
		     ->defaultValue($profile_arguments['source_profile_role_source_type']);
		$this->addFieldMapping('field_profile_role:ignore_case')
		     ->defaultValue($profile_arguments['source_profile_role_ignore_case']);
		$this->addFieldMapping('field_profile_role:create_term')
		     ->defaultValue($profile_arguments['source_profile_role_create_term']);
		      
		/* Profile Unit */
		if($profile_arguments['source_profile_unit_default_value']!=''){
			$this->addFieldMapping('field_profile_unit')
			     ->defaultValue($profile_arguments['source_profile_unit_default_value']);
		}else{
			$this->addFieldMapping('field_profile_unit', $profile_arguments['source_profile_unit'])
			     ->sourceMigration('UGProfileUnit6');
		}

		$this->addFieldMapping('field_profile_unit:source_type')
		     ->defaultValue($profile_arguments['source_profile_unit_source_type']);
		$this->addFieldMapping('field_profile_unit:ignore_case')
		     ->defaultValue($profile_arguments['source_profile_unit_ignore_case']);
		$this->addFieldMapping('field_profile_unit:create_term')
		     ->defaultValue($profile_arguments['source_profile_unit_create_term']);
		
		/* Profile Summary */
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

		/* Profile Category */
		if($profile_arguments['source_profile_category_default_value']!=''){
			$this->addFieldMapping('field_profile_category')
			     ->defaultValue($profile_arguments['source_profile_category_default_value']);
		}else{
			$this->addFieldMapping('field_profile_category', $profile_arguments['source_profile_category'])
			     ->sourceMigration('UGProfileCategory6');
		}
		$this->addFieldMapping('field_profile_category:source_type')
		     ->defaultValue($profile_arguments['source_profile_category_source_type']);
		$this->addFieldMapping('field_profile_category:ignore_case')
		     ->defaultValue($profile_arguments['source_profile_category_ignore_case']);
		$this->addFieldMapping('field_profile_category:create_term')
		     ->defaultValue($profile_arguments['source_profile_category_create_term']);


		/* Profile Title */
		$this->addFieldMapping('field_profile_title', $profile_arguments['source_profile_title']);
		
		/* Profile Subunit */
		if($profile_arguments['source_profile_subunit_default_value']!=''){
			$this->addFieldMapping('field_profile_subunit')
			     ->defaultValue($profile_arguments['source_profile_subunit_default_value']);
		}else{
			$this->addFieldMapping('field_profile_subunit', $profile_arguments['source_profile_subunit'])
			     ->sourceMigration('UGProfileSubunit6');
		}

		$this->addFieldMapping('field_profile_subunit:source_type')
		     ->defaultValue($profile_arguments['source_profile_subunit_source_type']);
		$this->addFieldMapping('field_profile_subunit:ignore_case')
		     ->defaultValue($profile_arguments['source_profile_subunit_ignore_case']);
		$this->addFieldMapping('field_profile_subunit:create_term')
		     ->defaultValue($profile_arguments['source_profile_subunit_create_term']);
		
		/* Profile Research */
		if($profile_arguments['source_profile_research_default_value']!=''){
			$this->addFieldMapping('field_profile_research')
			     ->defaultValue($profile_arguments['source_profile_research_default_value']);
		}else{
			$this->addFieldMapping('field_profile_research', $profile_arguments['source_profile_research'])
			     ->sourceMigration('UGProfileResearch6');
		}

		$this->addFieldMapping('field_profile_research:source_type')
		     ->defaultValue($profile_arguments['source_profile_research_source_type']);
		$this->addFieldMapping('field_profile_research:ignore_case')
		     ->defaultValue($profile_arguments['source_profile_research_ignore_case']);
		$this->addFieldMapping('field_profile_research:create_term')
		     ->defaultValue($profile_arguments['source_profile_research_create_term']);
		     

	    /* Profile Image */
		$this->addFieldMapping('field_profile_image', $profile_arguments['source_profile_image'])
	         ->sourceMigration('UGFile6');
	    $this->addFieldMapping('field_profile_image:file_class')
	         ->defaultValue('MigrateFileFid');
	    $this->addFieldMapping('field_profile_image:preserve_files')
	         ->defaultValue('TRUE');
	    $this->addFieldMapping('field_profile_image:alt', $profile_arguments['source_profile_image'] . ':alt')
	         ->defaultValue('');
	    $this->addFieldMapping('field_profile_image:title', $profile_arguments['source_profile_image'] . ':title')
	         ->defaultValue('');
	    $this->addFieldMapping('field_profile_image:language')
	         ->defaultValue(LANGUAGE_NONE);

	    /* Profile Attachments */
	    $this->addFieldMapping('field_profile_attachments', $profile_arguments['source_profile_attachments'])
	    	->sourceMigration('UGFile6');
        $this->addFieldMapping('field_profile_attachments:file_class')
            ->defaultValue('MigrateFileFid');
        $this->addFieldMapping('field_profile_attachments:preserve_files')
            ->defaultValue('TRUE');
        $this->addFieldMapping('field_profile_attachments:description', $profile_arguments['source_profile_attachments'] . ':description')
            ->defaultValue('');
        $this->addFieldMapping('field_profile_attachments:language')
            ->defaultValue(LANGUAGE_NONE);

	    /* Other Profile Fields */
	    $this->addFieldMapping('field_profile_caption', $profile_arguments['source_profile_caption']);
	    $this->addFieldMapping('field_profile_address', $profile_arguments['source_profile_address']);
	    $this->addFieldMapping('field_profile_email', $profile_arguments['source_profile_email']);
	    $this->addFieldMapping('field_profile_telephonenumber', $profile_arguments['source_profile_telephonenumber']);
	    $this->addFieldMapping('field_profile_faxnumber', $profile_arguments['source_profile_faxnumber']);
	    $this->addFieldMapping('field_profile_office', $profile_arguments['source_profile_office']);
	    $this->addFieldMapping('field_profile_lab', $profile_arguments['source_profile_lab']);
	    $this->addFieldMapping('field_profile_website', $profile_arguments['source_profile_website']);

	    /* Profile Tags */
		if($profile_arguments['source_tags_default_value']!=''){
			$this->addFieldMapping('field_tags')
			     ->defaultValue($profile_arguments['source_tags_default_value']);
		}else{
		    $this->addFieldMapping('field_tags', $profile_arguments['source_tags'])
		         ->sourceMigration(array('UGTerm6','UGProfileKeyword6'));
		}

	    $this->addFieldMapping('field_tags:source_type')
	         ->defaultValue('tid');
         
	}
}

class UGProfileCategory6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGProfileKeyword6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}


class UGProfileRole6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGProfileUnit6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGProfileSubunit6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGProfileResearch6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}