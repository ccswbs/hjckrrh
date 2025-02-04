<?php

/**
 * Defines the module settings entity.
 */
class GTMSettings {

  /**
   * Singleton instance of this class.
   *
   * @var GTMSettings
   */
  private static $instance;

  /**
   * The machine name for the configuration entity.
   *
   * @var string
   */
  public $name;

  /**
   * The human-readable name of the configuration entity.
   *
   * @var string
   */
  public $label;

  /**
   * XXX
   *
   * @var string
   */
  public $status;

  /**
   * Snippet parent URI.
   *
   * @var string
   */
  public $uri;

  /**
   * Whether to compact the JavaScript snippet.
   *
   * @var bool
   */
  public $compact_snippet;

  /**
   * Whether to include the snippet as a file.
   *
   * @var bool
   */
  public $include_file;

  /**
   * Whether to recreate snippets on cache rebuild.
   *
   * @var bool
   */
  public $rebuild_snippets;

  /**
   * Whether to flush snippet directory on cache rebuild.
   *
   * @var bool
   */
  public $flush_snippets;

  /**
   * Whether to show debug output.
   *
   * @var bool
   */
  public $debug_output;

  /**
   * The name of the data layer.
   *
   * @var string
   */
  public $data_layer;

  /**
   * Whether to add the listed classes to the data layer.
   *
   * @var bool
   */
  public $include_classes;

  /**
   * The white-listed classes.
   *
   * @var string
   */
  public $whitelist_classes;

  /**
   * The black-listed classes.
   *
   * @var string
   */
  public $blacklist_classes;

  /**
   * Whether to include the environment items in the applicable snippets.
   *
   * @var bool
   */
  public $include_environment;

  /**
   * Teh environment ID.
   *
   * @var string
   */
  public $environment_id;

  /**
   * The environment token.
   *
   * @var string
   */
  public $environment_token;

  /**
   * Whether to include or exclude the listed paths.
   *
   * @var string
   */
  public $path_toggle;

  /**
   * The listed paths.
   *
   * @var array
   */
  public $path_list;

  /**
   * Whether to include or exclude the listed roles.
   *
   * @var string
   */
  public $role_toggle;

  /**
   * The listed roles.
   *
   * @var array
   */
  public $role_list;

  /**
   * Whether to include or exclude the listed statuses.
   *
   * @var string
   */
  public $status_toggle;

  /**
   * The listed statuses.
   *
   * @var array
   */
  public $status_list;

  /**
   * Constructs a module settings object.
   */
  public function __construct() {
    // On load the values include ctools items: table, type, export_type.
    // $values = (array) ctools_export_crud_load('gtag_config', 'google_tag.settings');
    $values = (array) gtag_export_crud_load('gtag_config', 'google_tag.settings');
    foreach ($values as $key => $value) {
      if (property_exists($this, $key)) {
        $this->$key = $value;
      }
    }
  }

  /**
   * Returns singleton instance of this class.
   *
   * @return GTMSettings
   *   The instance.
   */
  public static function getInstance() {
    if (!self::$instance) {
      self::$instance = new GTMSettings();
    }
    return self::$instance;
  }

  /**
   * Returns a property.
   *
   * @param string $property
   *   The property name.
   *
   * @return string
   *   The property.
   */
  public function get($property) {
    return isset($this->$property) ? $this->$property : NULL;
  }

  /**
   * Saves settings to database.
   *
   * @return bool
   *   Whether the save was successful.
   */
  public function save() {
    // On load the properties include ctools items: table, type, export_type.
    $export_type = isset($this->export_type) ? $this->export_type : NULL;
    $data = (array) $this;
    unset($data['table'], $data['type'], $data['export_type']);

    $settings['name'] = 'google_tag.settings';
    $settings['data'] = $data;
    $settings['type'] = 'Normal';
    $settings['export_type'] = $export_type;
    $settings = (object) $settings;
    $result = ctools_export_crud_save('gtag_config', $settings);
    return $result;
  }

}
