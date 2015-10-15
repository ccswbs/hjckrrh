<?php


class crumbs_Container_ContainerUtil {

  /**
   * Initializes all lazy properties from the container and returns the array.
   *
   * Use this only for debugging!
   *
   * @param object $container
   *
   * @return mixed[]
   */
  static function getAllProperties($container) {
    $reflClass = new ReflectionClass($container);
    $data = array();
    foreach (self::extractProperties($reflClass->getDocComment()) as $propertyName) {
      $data[$propertyName] = $container->$propertyName;
    }
    return $data;
  }

  /**
   * @param string $classDocComment
   *
   * @return array
   */
  private static function extractProperties($classDocComment) {
    $identifier = '[a-zA-Z_][a-zA-Z0-9_]*';
    $namespaceFragment = '\\\\' . $identifier;
    $type = "$identifier($namespaceFragment)*";
    $type = "($type|\\\\$type)";
    $propertyNames = array();
    foreach (explode("\n", $classDocComment) as $docLine) {
      if (preg_match("#@property +$type +(\\\$|)($identifier) *$#", $docLine, $m)) {
        $propertyNames[] = $m[5];
      }
    }
    return $propertyNames;
  }
} 
