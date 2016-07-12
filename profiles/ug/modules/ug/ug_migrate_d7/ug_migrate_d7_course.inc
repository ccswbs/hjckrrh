<?php

	class UGCourseOutline7Migration extends UGDrupalNode7Migration {
		public function __construct($arguments) {
	    	parent::__construct($arguments);

		    $this->destination = new MigrateDestinationNode('course_outline');

		    /* DEFAULT arguments */
			$course_arguments = array(
			    'source_course_title'                        => 'field_course_title',
			    'source_course_name'                         => 'field_course_name',
			    'source_course_code'                         => 'field_course_code',
			    'source_course_section'                      => 'field_course_section',
			    'source_course_category'                     => 'field_course_category',
			    'source_course_category_vocabulary'          => 'course_outline_category',
			    'source_course_category_default_value'       => '',
			    'source_course_category_source_type'         => 'tid',
			    'source_course_category_ignore_case'         => TRUE,
			    'source_course_category_create_term'         => TRUE,
			    'source_course_semester'                     => 'field_course_term',
			    'source_course_semester_vocabulary'          => 'course_outline_term',
			    'source_course_semester_default_value'       => '',
			    'source_course_semester_source_type'         => 'tid',
			    'source_course_semester_ignore_case'         => TRUE,
			    'source_course_semester_create_term'         => TRUE,
			    'source_course_level'                        => 'field_course_level',
			    'source_course_level_vocabulary'             => 'course_outline_level',
			    'source_course_level_default_value'          => '',
			    'source_course_level_source_type'            => 'tid',
			    'source_course_level_ignore_case'            => TRUE,
			    'source_course_level_create_term'            => TRUE,
			    'source_course_academic_level'               => 'field_course_acad_level', 
			    'source_course_academic_level_vocabulary'    => 'course_outline_academic_level',
			    'source_course_academic_level_default_value' => '',
			    'source_course_academic_level_source_type'   => 'tid',
			    'source_course_academic_level_ignore_case'   => TRUE,
			    'source_course_academic_level_create_term'   => TRUE,
			    'source_course_subject'                      => 'field_course_subject',
			    'source_course_subject_vocabulary'           => 'course_outline_subject',
			    'source_course_subject_default_value'        => '',
			    'source_course_subject_source_type'          => 'tid',
			    'source_course_subject_ignore_case'          => TRUE,
			    'source_course_subject_create_term'          => TRUE,
			    'source_course_department'                   => 'field_course_department',
			    'source_course_department_vocabulary'        => 'course_outline_department',
			    'source_course_department_default_value'     => '',
			    'source_course_department_source_type'       => 'tid',
			    'source_course_department_ignore_case'       => TRUE,
			    'source_course_department_create_term'       => TRUE,
			    'source_course_instructor'                   => 'field_course_instructor', 
			    'source_course_instructor_url'               => 'field_course_instructor_url',
			    'source_course_body'                         => 'field_course_body',
			    'source_course_summary'                      => 'field_course_body:summary',
			    'source_course_format'                       => 'field_course_body:format',
			    'source_course_website'                      => 'field_course_website',
			    'source_course_attachments'                  => 'field_course_attachments',
			    'source_course_keyword'                      => 'field_tags',
			    'source_course_keyword_vocabulary'           => 'tags',
			    'source_course_keyword_default_value'        => '',
			    'source_course_keyword_source_type'          => 'tid',
			    'source_course_keyword_ignore_case'          => TRUE,
			    'source_course_keyword_create_term'          => TRUE,
				'source_course_insert_fields'	             => NULL,
			);

			//Override default values with arguments if they exist
			foreach ($course_arguments as $key => $value) {
			    if(isset($this->arguments[$key])){
			    	if($this->arguments[$key] != ''){
				    	$course_arguments[$key] = $this->arguments[$key];
				    }
			    }
			}

			/* INSERT fields into Body variables */
			$this->arguments['update_source_body'] = $course_arguments['source_course_body'];
	    	$this->arguments['update_insert_fields'] = $course_arguments['source_course_insert_fields'];

		    /* Course Outline Body */
		    $this->addFieldMapping('field_course_body', $course_arguments['source_course_body']);
		    $this->addFieldMapping('field_course_body:summary', $course_arguments['source_course_summary']);

			// Course Outline Body Format
			if($course_arguments['source_course_body'] == 'body'){
			    $this->addFieldMapping( 'field_course_body:format', $course_arguments['source_course_format'])
				    ->defaultValue('full_html');
			}else{
			    $this->addFieldMapping( 'field_course_body:format', $course_arguments['source_course_format'])
				    ->callbacks(array($this, 'mapFormat'))
				    ->defaultValue('full_html');
			}

			// Course Outline CATEGORY 
			if($course_arguments['source_course_category_default_value'] != ''){
				$this->addFieldMapping('field_course_category')
					->defaultValue($course_arguments['source_course_category_default_value']);
			}else{
				$this->addFieldMapping('field_course_category', $course_arguments['source_course_category'])
					->sourceMigration('UGCourseOutlineCategory7');
			}
			$this->addFieldMapping('field_course_category:source_type')
			     ->defaultValue($course_arguments['source_course_category_source_type']);
			$this->addFieldMapping('field_course_category:ignore_case')
			     ->defaultValue($course_arguments['source_course_category_ignore_case']);
			$this->addFieldMapping('field_course_category:create_term')
			     ->defaultValue($course_arguments['source_course_category_create_term']);

			// Course Outline KEYWORD
			if($course_arguments['source_course_keyword_default_value'] != ''){
				$this->addFieldMapping('field_tags')
					->defaultValue($course_arguments['source_course_keyword_default_value']);
			}else{
				$this->addFieldMapping('field_tags', $course_arguments['source_course_keyword'])
					->sourceMigration(array('UGTerm7','UGCourseOutlineKeyword7'));
			}
			$this->addFieldMapping('field_tags:source_type')
			     ->defaultValue($course_arguments['source_course_keyword_source_type']);
			$this->addFieldMapping('field_tags:ignore_case')
			     ->defaultValue($course_arguments['source_course_keyword_ignore_case']);
			$this->addFieldMapping('field_tags:create_term')
			     ->defaultValue($course_arguments['source_course_keyword_create_term']);

			// Course Outline LEVEL
			if($course_arguments['source_course_level_default_value'] != ''){
				$this->addFieldMapping('field_course_level')
					->defaultValue($course_arguments['source_course_level_default_value']);
			}else{
				$this->addFieldMapping('field_course_level', $course_arguments['source_course_level'])
					->sourceMigration('UGCourseOutlineLevel7');
			}
			$this->addFieldMapping('field_course_level:source_type')
			     ->defaultValue($course_arguments['source_course_level_source_type']);
			$this->addFieldMapping('field_course_level:ignore_case')
			     ->defaultValue($course_arguments['source_course_level_ignore_case']);
			$this->addFieldMapping('field_course_level:create_term')
			     ->defaultValue($course_arguments['source_course_level_create_term']);


			// Course Outline ACADEMIC LEVEL
			if($course_arguments['source_course_academic_level_default_value'] != ''){
				$this->addFieldMapping('field_course_acad_level')
					->defaultValue($course_arguments['source_course_academic_level_default_value']);
			}else{
				$this->addFieldMapping('field_course_acad_level', $course_arguments['source_course_academic_level'])
					->sourceMigration('UGCourseOutlineAcademicLevel7');
			}
			$this->addFieldMapping('field_course_acad_level:source_type')
			     ->defaultValue($course_arguments['source_course_academic_level_source_type']);
			$this->addFieldMapping('field_course_acad_level:ignore_case')
			     ->defaultValue($course_arguments['source_course_academic_level_ignore_case']);
			$this->addFieldMapping('field_course_acad_level:create_term')
			     ->defaultValue($course_arguments['source_course_academic_level_create_term']);

			// Course Outline TERM (SEMESTER)
			if($course_arguments['source_course_semester_default_value'] != ''){
				$this->addFieldMapping('field_course_term')
					->defaultValue($course_arguments['source_course_semester_default_value']);
			}else{
				$this->addFieldMapping('field_course_term', $course_arguments['source_course_semester'])
					->sourceMigration('UGCourseOutlineSemester7');
			}
			$this->addFieldMapping('field_course_term:source_type')
			     ->defaultValue($course_arguments['source_course_semester_source_type']);
			$this->addFieldMapping('field_course_term:ignore_case')
			     ->defaultValue($course_arguments['source_course_semester_ignore_case']);
			$this->addFieldMapping('field_course_term:create_term')
			     ->defaultValue($course_arguments['source_course_semester_create_term']);

			// Course Outline TERM (SEMESTER)
			if($course_arguments['source_course_subject_default_value'] != ''){
				$this->addFieldMapping('field_course_subject')
					->defaultValue($course_arguments['source_course_subject_default_value']);
			}else{
				$this->addFieldMapping('field_course_subject', $course_arguments['source_course_subject'])
					->sourceMigration('UGCourseOutlineSubject7');
			}
			$this->addFieldMapping('field_course_subject:source_type')
			     ->defaultValue($course_arguments['source_course_subject_source_type']);
			$this->addFieldMapping('field_course_subject:ignore_case')
			     ->defaultValue($course_arguments['source_course_subject_ignore_case']);
			$this->addFieldMapping('field_course_subject:create_term')
			     ->defaultValue($course_arguments['source_course_subject_create_term']);

			// Course Outline DEPARTMENT
			if($course_arguments['source_course_department_default_value'] != ''){
				$this->addFieldMapping('field_course_department')
					->defaultValue($course_arguments['source_course_department_default_value']);
			}else{
				$this->addFieldMapping('field_course_department', $course_arguments['source_course_department'])
					->sourceMigration('UGCourseOutlineDepartment7');
			}
			$this->addFieldMapping('field_course_department:source_type')
			     ->defaultValue($course_arguments['source_course_department_source_type']);
			$this->addFieldMapping('field_course_department:ignore_case')
			     ->defaultValue($course_arguments['source_course_department_ignore_case']);
			$this->addFieldMapping('field_course_department:create_term')
			     ->defaultValue($course_arguments['source_course_department_create_term']);

			/* Course Outline File Attachments */
		    $this->addFieldMapping('field_course_attachments', $course_arguments['source_course_attachments'])
			    ->sourceMigration('UGFile7');
			$this->addFieldMapping('field_course_attachments:file_class')
			    ->defaultValue('MigrateFileFid');
			$this->addFieldMapping('field_course_attachments:preserve_files')
			    ->defaultValue('TRUE');
		    $this->addFieldMapping('field_course_attachments:description', $course_arguments['source_course_attachments'] . ':description')
		        ->defaultValue('');
		    $this->addFieldMapping('field_course_attachments:language')
		        ->defaultValue(LANGUAGE_NONE);
				
			/* Other Course Outline fields */
			$this->addFieldMapping('field_course_title', $course_arguments['source_field_course_title']);
			$this->addFieldMapping('field_course_name',	$course_arguments['source_course_name']);
			$this->addFieldMapping('field_course_code', $course_arguments['source_course_code']);
			$this->addFieldMapping('field_course_section', $course_arguments['source_course_section']);
			$this->addFieldMapping('field_course_instructor', $course_arguments['source_course_instructor']);
			$this->addFieldMapping('field_course_instructor_url', $course_arguments['source_course_instructor_url']);
			$this->addFieldMapping('field_course_website', $course_arguments['source_course_website']);

		}
	}

	class UGCourseOutlineCategory7Migration extends DrupalTerm7Migration {
		public function __construct($arguments) {
	    	parent::__construct($arguments);

		}	
	}

	class UGCourseOutlineKeyword7Migration extends DrupalTerm7Migration {
		public function __construct($arguments) {
	    	parent::__construct($arguments);

		}	
	}

	class UGCourseOutlineSemester7Migration extends DrupalTerm7Migration {
		public function __construct($arguments) {
	    	parent::__construct($arguments);

		}	
	}

	class UGCourseOutlineLevel7Migration extends DrupalTerm7Migration {
		public function __construct($arguments) {
	    	parent::__construct($arguments);

		}	
	}

	class UGCourseOutlineAcademicLevel7Migration extends DrupalTerm7Migration {
		public function __construct($arguments) {
	    	parent::__construct($arguments);

		}	
	}

	class UGCourseOutlineSubject7Migration extends DrupalTerm7Migration {
		public function __construct($arguments) {
	    	parent::__construct($arguments);

		}	
	}

	class UGCourseOutlineDepartment7Migration extends DrupalTerm7Migration {
		public function __construct($arguments) {
	    	parent::__construct($arguments);

		}	
	}

?>
