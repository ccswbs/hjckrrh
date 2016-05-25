<?php

	class UGCourseOutline7Migration extends DrupalNode7Migration {
		public function __construct($arguments) {
	    	parent::__construct($arguments);

		    $this->destination = new MigrateDestinationNode('course_outline');

		    /* DEFAULT arguments */
			$courseoutline_arguments = array(
				'source_course_title' => 'field_course_title',
				'source_course_name' => 'field_course_name',
				'source_course_code' => 'field_course_code',
				'source_course_section' => 'field_course_section',
				'source_course_semester' => 'field_course_semester',
				'source_course_year' => 'field_course_year',
				'source_course_instructor' => 'field_course_instructor', 
				'source_course_instructor_url' => 'field_course_instructor_url',
				'source_course_body' => 'body',
				'source_course_summary' => 'body:summary',
				'source_course_format' => 'body:format',			
				'source_course_website' => 'field_course_website',			
				'source_course_attachments' => 'field_course_attachments',
				'source_course_level' => 'field_course_level', 
				'source_course_type' => 'field_course_type', 
				'source_course_subject' => 'field_course_subject',
				'source_course_department' => 'field_course_department', 		
				'source_course_category' => 'field_course_category',			
				'source_course_keyword' => 'field_tags',
			);

			//Override default values with arguments if they exist
			foreach ($courseoutline_arguments as $key => $value) {
			    if(isset($this->arguments[$key])){
			    	$courseoutline_arguments[$key] = $this->arguments[$key];
			    }
			}

		    /* Course Outline Body */
		    $this->addFieldMapping('field_course_body', $courseoutline_arguments['source_course_body']);
		    $this->addFieldMapping('field_course_body:summary', $courseoutline_arguments['source_course_summary']);
		    $this->addFieldMapping( 'field_course_body:format', $courseoutline_arguments['source_course_format'])
			    ->callbacks(array($this, 'mapFormat'))
			    ->defaultValue('full_html');

			/* Course Outline Category */
			$this->addFieldMapping('field_course_category', $courseoutline_arguments['source_course_category'])
				->sourceMigration('UGCourseOutlineCategory7');
			$this->addFieldMapping('field_course_category:source_type')
				->defaultValue('tid');
			$this->addFieldMapping('field_course_category:ignore_case')
				->defaultValue(TRUE);
			$this->addFieldMapping('field_course_category:create_term')
			    ->defaultValue(TRUE);

			/* Course Outline Keyword */
			$this->addFieldMapping('field_tags', $courseoutline_arguments['source_course_keyword'])
				->sourceMigration(array('UGTerm7','UGCourseOutlineKeyword7'));
			$this->addFieldMapping('field_tags:source_type')
				->defaultValue('tid');

			/* Course Outline File Attachments */
		    $this->addFieldMapping('field_course_attachments', $courseoutline_arguments['source_course_attachments'])
			    ->sourceMigration('UGFile7');
			$this->addFieldMapping('field_course_attachments:file_class')
			    ->defaultValue('MigrateFileFid');
			$this->addFieldMapping('field_course_attachments:preserve_files')
			    ->defaultValue('TRUE');
		    $this->addFieldMapping('field_course_attachments:description', $courseoutline_arguments['source_course_attachments'] . ':description')
		        ->defaultValue('');
		    $this->addFieldMapping('field_course_attachments:language')
		        ->defaultValue(LANGUAGE_NONE);
				
			/* Course Outline Date 
			$this->addFieldMapping('field_course_year', $courseoutline_arguments['source_course_year']);
			$this->addFieldMapping('field_course_year:to', $courseoutline_arguments['source_course_year'].":value2");
			$this->addFieldMapping('field_course_year:timezone')
				->defaultValue($courseoutline_arguments['source_course_year_timezone']);*/
				
			/* Other Course Outline fields */
			$this->addFieldMapping('field_course_title', $courseoutline_arguments['source_field_course_title']);
			$this->addFieldMapping('field_course_name',	$courseoutline_arguments['source_course_name']);
			$this->addFieldMapping('field_course_code', $courseoutline_arguments['source_course_code']);
			$this->addFieldMapping('field_course_section', $courseoutline_arguments['source_course_section']);
			$this->addFieldMapping('field_course_semester', $courseoutline_arguments['source_course_semester']);
			$this->addFieldMapping('field_course_year', $courseoutline_arguments['source_course_year']);
			$this->addFieldMapping('field_course_instructor', $courseoutline_arguments['source_course_instructor']);
			$this->addFieldMapping('field_course_instructor_url', $courseoutline_arguments['source_course_instructor_url']);
			$this->addFieldMapping('field_course_website', $courseoutline_arguments['source_course_website']);
			$this->addFieldMapping('field_course_level', $courseoutline_arguments['source_course_level']);
			$this->addFieldMapping('field_course_type', $courseoutline_arguments['source_course_type']);
			$this->addFieldMapping('field_course_subject', $courseoutline_arguments['source_course_subject']);
			$this->addFieldMapping('field_course_department', $courseoutline_arguments['source_course_department']);

		}
	}

	class UGCourseOutlineKeyword7Migration extends DrupalTerm7Migration {
		public function __construct($arguments) {
	    	parent::__construct($arguments);

		}	
	}

	class UGCourseOutlineCategory7Migration extends DrupalTerm7Migration {
		public function __construct($arguments) {
	    	parent::__construct($arguments);

		}	
	}
?>
