<?php


class crumbs_PluginSystem_PluginMethodIterator implements Iterator {

  /**
   * @var crumbs_PluginInterface[]
   */
  private $plugins;

  /**
   * @var string[]
   */
  private $pluginKeys = array();

  /**
   * The plugin key at the current iterator position.
   *
   * @var string|null
   */
  private $pluginKey;

  /**
   * The plugin method at the current iterator position.
   *
   * @var string
   */
  private $pluginMethod;

  /**
   * @var crumbs_PluginSystem_PluginMethodIteratorPosition|null
   */
  private $iteratorPosition;

  /**
   * @param true[] $pluginMethods
   *   Format: $[$plugin_key] = true
   * @param crumbs_PluginInterface[] $plugins
   * @param string $method
   *   One of 'findParent' and 'findTitle'.
   *
   * @throws Exception
   */
  function __construct($pluginMethods, $plugins, $method) {
    $this->plugins = $plugins;
    $this->pluginKeys = array_keys($pluginMethods);
    if ($method !== 'findParent' && $method !== 'findTitle') {
      throw new \Exception("Invalid plugin method '$method'.");
    }
    $this->pluginMethod = $method;

    // Set iterator start position.
    $this->setFirstValidIteratorPosition(reset($this->pluginKeys));
  }

  /**
   * @return $this
   * @throws Exception
   */
  function current() {
    return $this->iteratorPosition;
  }

  /**
   * (PHP 5 &gt;= 5.0.0)<br/>
   * Return the key of the current element
   * @link http://php.net/manual/en/iterator.key.php
   *
   * @return string|null
   */
  public function key() {
    return $this->pluginKey;
  }

  /**
   * (PHP 5 &gt;= 5.0.0)<br/>
   * Checks if current position is valid
   * @link http://php.net/manual/en/iterator.valid.php
   *
   * @return boolean
   *   TRUE, if the current position is valid.
   */
  public function valid() {
    // @todo Is this sufficient?
    return NULl !== $this->pluginKey;
  }

  /**
   * (PHP 5 &gt;= 5.0.0)<br/>
   * Move forward to next element
   * @link http://php.net/manual/en/iterator.next.php
   */
  public function next() {
    $this->setFirstValidIteratorPosition(next($this->pluginKeys));
  }

  /**
   * Skips through the array of plugins, until a valid position is found,
   * starting from the $pluginKey given as an argument.
   *
   * @param string|false $pluginKey
   *   The key returned from either next($this->pluginkeys) or from
   *   reset($this->pluginKeys). This means the value can be a key or false.
   */
  private function setFirstValidIteratorPosition($pluginKey) {
    while (TRUE) {
      if ($pluginKey === FALSE) {
        // When next($array) returns false, Iterator::key() should return NULL.
        $this->pluginKey = NULL;
        return;
      }
      if (isset($this->plugins[$pluginKey])) {
        $plugin = $this->plugins[$pluginKey];
        if (method_exists($plugin, $this->pluginMethod)) {
          $this->pluginKey = $pluginKey;
          $this->iteratorPosition = new crumbs_PluginSystem_PluginMethodIteratorPosition(
            $pluginKey,
            $this->pluginMethod,
            $plugin);
          return;
        }
      }
      $pluginKey = next($this->pluginKeys);
    }
  }

  /**
   * (PHP 5 &gt;= 5.0.0)<br/>
   * Rewind the Iterator to the first element
   * @link http://php.net/manual/en/iterator.rewind.php
   */
  public function rewind() {
    $this->pluginKey = reset($this->pluginKeys);
  }
}
