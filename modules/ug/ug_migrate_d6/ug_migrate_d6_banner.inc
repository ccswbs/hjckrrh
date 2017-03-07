<?php

/* BANNER classes */
class UGBanner6Migration extends UGDrupalNode6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

		$this->destination = new MigrateDestinationNode('banner');

		/* DEFAULT arguments */
		$banner_arguments = array(
		  'source_banner_node_type'                => 'banner',
		  'source_banner_headline'                 => 'field_banner_headline',
		  'source_banner_headline_format'          => 'field_banner_headline:format',
		  'source_banner_text'                     => 'field_banner_text',
		  'source_banner_text_format'              => 'field_banner_text:format',
		  'source_banner_category'                 => 'field_banner_category',
	  	  'source_banner_category_source_type'     => 'tid',
		  'source_banner_category_ignore_case'     => TRUE,
		  'source_banner_category_create_term'     => TRUE,
	 	  'source_banner_category_vocabulary'      => 'banner_category',
	 	  'source_banner_category_default_value'   => '',
		  'source_banner_link'                     => 'field_banner_link',
		  'source_banner_image'                    => 'field_banner_image',
		  'source_banner_alttext'                  => 'field_banner_alttext',
		  'source_banner_keyword'                  => 'field_tags',
		  'source_banner_keyword_source_type'      => 'tid',
		  'source_banner_keyword_ignore_case'      => TRUE,
		  'source_banner_keyword_create_term'      => TRUE,
		  'source_banner_keyword_vocabulary'       => 'tags',
	 	  'source_banner_keyword_default_value'    => '',
		  'source_banner_weight'                   => 'field_banner_weight',
		  'source_banner_image_src_prefix'         => '',
		  'source_banner_insert_fields'            => NULL,
		);

		//Override default values with arguments if they exist
		foreach ($banner_arguments as $key => $value) {
		    if(isset($this->arguments[$key])){
		    	if($this->arguments[$key] != ''){
			    	$banner_arguments[$key] = $this->arguments[$key];
			    }
		    }
		}

		/* INSERT fields into Body variables */
		$this->arguments['update_source_body'] = $banner_arguments['source_banner_text'];
		$this->arguments['update_map_table'] = 'migrate_map_ugbanner6';
    	$this->arguments['update_insert_fields'] = $banner_arguments['source_banner_insert_fields'];
		$this->arguments['update_image_src_prefix'] = $banner_arguments['source_banner_image_src_prefix'];


		// Banner Headline
		$this->addFieldMapping('field_banner_headline', $banner_arguments['source_banner_headline']);			

		// Banner Headline Format
		if($banner_arguments['source_banner_headline'] == 'body'){
			$this->addFieldMapping('field_banner_headline:format', $banner_arguments['source_banner_headline_format'])
			    ->defaultValue('full_html');
		}else{
			$this->addFieldMapping('field_banner_headline:format', $banner_arguments['source_banner_headline_format'])
			    ->callbacks(array($this, 'mapFormat'))
			    ->defaultValue('full_html');
		}

		// Banner Text
		$this->addFieldMapping('field_banner_text', $banner_arguments['source_banner_text']);
		// Banner Text Format
		if($banner_arguments['source_banner_text'] == 'body'){
			$this->addFieldMapping('field_banner_text:format', $banner_arguments['source_banner_text_format'])
			    ->defaultValue('full_html');
		}else{
			$this->addFieldMapping('field_banner_text:format', $banner_arguments['source_banner_text_format'])
			    ->callbacks(array($this, 'mapFormat'))
			    ->defaultValue('full_html');
		}

		// Banner Category
		if($banner_arguments['source_banner_category_default_value']!=''){
			$this->addFieldMapping('field_banner_category')
			     ->defaultValue($banner_arguments['source_banner_category_default_value']);
		}else{
			$this->addFieldMapping('field_banner_category', $banner_arguments['source_banner_category'])
			     ->sourceMigration('UGBannerCategory6');
		}
		$this->addFieldMapping('field_banner_category:source_type')
			->defaultValue('tid');		

		// Banner Keyword
		if($banner_arguments['source_banner_keyword_default_value']!=''){
			$this->addFieldMapping('field_tags')
			     ->defaultValue($banner_arguments['source_banner_keyword_default_value']);
		}else{
			$this->addFieldMapping('field_tags', $banner_arguments['source_banner_keyword'])
			     ->sourceMigration('UGTerm6','UGBannerKeyword6');
		}
		$this->addFieldMapping('field_tags:source_type')
			->defaultValue('tid');


		/* Banner Item Image */
		$this->addFieldMapping('field_banner_image', $banner_arguments['source_banner_image'])
			->sourceMigration('UGFile6');
		$this->addFieldMapping('field_banner_image:file_class')
		    ->defaultValue('MigrateFileFid');
		$this->addFieldMapping('field_banner_image:preserve_files')
		    ->defaultValue('TRUE');
	    $this->addFieldMapping('field_banner_image:description', $banner_arguments['source_banner_image'] . ':description')
	        ->defaultValue('');
	    $this->addFieldMapping('field_banner_image:title', $banner_arguments['source_banner_image'] . ':title')
	        ->defaultValue('');
	    $this->addFieldMapping('field_banner_image:language')
	        ->defaultValue(LANGUAGE_NONE);

		// Banner Image Alt Text
		if($banner_arguments['source_banner_alttext'] != ''){
			$this->addFieldMapping('field_banner_alttext', $banner_arguments['source_banner_alttext']);
		    $this->addFieldMapping('field_banner_image:alt', $banner_arguments['source_banner_alttext'])
		        ->defaultValue('');
		}else{
		    $this->addFieldMapping('field_banner_image:alt', $banner_arguments['source_banner_image'] . ':alt')
		        ->defaultValue('');
		}

		$this->addFieldMapping('field_banner_link', $banner_arguments['source_banner_link']);
		$this->addFieldMapping('field_banner_weight', $banner_arguments['source_banner_weight'])
			->defaultValue(0);

	}
}

class UGBannerCategory6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}

class UGBannerKeyword6Migration extends DrupalTerm6Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

	}	
}