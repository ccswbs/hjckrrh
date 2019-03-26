<?php

class UGMenu7Migration extends DrupalMenu7Migration {

	/*
	*  Issue: Destination system menus merged with source system menus are deleted after roll back
	*  Solution: Make a copy of any designated system menus on the destination site. 
	*
	*  protectedMenus: array of Drupal system menus that we do not want to override. 
	*  
	*/

	protected $protectedMenus = array(
		'navigation', 
		'user-menu', 
		'devel', 
		'management',
	);

	public function setProtectedMenus($menu_override){
		$this->protectedMenus = $menu_override;
	}

	public function checkProtectedMenu($menu_name){

		$protected_menus = $this->protectedMenus;

		foreach ($protected_menus as $protected_menu_name) {
			if($menu_name == $protected_menu_name){
				return 'migrate-d7-' . $protected_menu_name;
			}
		}

		return $menu_name;
	}

	public function __construct($arguments) {
    	parent::__construct($arguments);

    	if(isset($this->arguments['protected_system_menus'])){
    		self::setProtectedMenus($this->arguments['protected_system_menus']);
    	}
	}	

	public function prepareRow($row) {

		if (parent::prepareRow($row) === FALSE) {
			return FALSE;
		}

		//Preserve main-menu during rollback
		if($row->menu_name == 'main-menu'){
			$this->rollbackAction = MigrateMap::ROLLBACK_PRESERVE;
			return FALSE;
		}

		$row->menu_name = self::checkProtectedMenu($row->menu_name);
	}
}

class UGMenuLinks7Migration extends DrupalMenuLinks7Migration {

	protected $protectedMenus = array(
		'navigation', 
		'user-menu', 
		'devel', 
		'management',
	);

	public function setProtectedMenus($menu_override){
		$this->protectedMenus = $menu_override;
	}

	public function checkProtectedMenu($menu_name){

		$protected_menus = $this->protectedMenus;

		foreach ($protected_menus as $protected_menu_name) {
			if($menu_name == $protected_menu_name){
				return 'migrate-d7-' . $protected_menu_name;
			}
		}

		return $menu_name;
	}

	public function __construct($arguments) {
    	parent::__construct($arguments);
	}	

	public function prepareRow($row) {
		if (parent::prepareRow($row) === FALSE) {
			return FALSE;
		}

		$row->menu_name = self::checkProtectedMenu($row->menu_name);
	}
}

?>