<?php 



class UGUserMigration extends DrupalUser7Migration {
	public function __construct($arguments) {
    	parent::__construct($arguments);

		/*$this->addFieldMapping('roles', 'roles')
		  ->defaultValue(1)
	      ->sourceMigration('UGRole');*/

	}
}

class UGRoleMigration extends DrupalRole7Migration {
  public function __construct($arguments) {
	    parent::__construct($arguments);
	}
}

abstract class UGMigration extends Migration {
	public function __construct($arguments) {
		parent::__construct($arguments);
		// With migrate_ui enabled, migration pages will indicate people involved in
		// the particular migration, with their role and contact info. We default the
		// list in the shared class; it can be overridden for specific migrations.
	    $this->team = array(
	      new MigrateTeamMember('Name of Team Member', 'test@uoguelph.ca', t('Team Member'))
	    );

	    // Individual mappings in a migration can be linked to a ticket or issue
	    // in an external tracking system. Define the URL pattern here in the shared
	    // class with ':id:' representing the position of the issue number, then add
	    // ->issueNumber(1234) to a mapping.
	    $this->issuePattern = 'https://github.com/ccswbs/hjckrrh/issues/:id:';
	}
}