<?php

class crumbs_EntityPlugin_Field_NodeReference extends crumbs_EntityPlugin_Field_Abstract {

  /**
   * {@inheritdoc}
   */
  function fieldFindCandidate(array $items) {
    foreach ($items as $item) {
      if (1
        && !empty($item['nid'])
        && ($target_node = node_load($item['nid']))
        && ($uri = entity_uri('node', $target_node))
      ) {
        return $uri['path'];
      }
    }

    return NULL;
  }

}
