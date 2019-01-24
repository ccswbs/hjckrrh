<?php

class crumbs_EntityPlugin_Field_UserReference extends crumbs_EntityPlugin_Field_Abstract {

  /**
   * {@inheritdoc}
   */
  function fieldFindCandidate(array $items) {
    foreach ($items as $item) {
      if (1
        && !empty($item['uid'])
        && ($target_user = user_load($item['uid']))
        && ($uri = entity_uri('user', $target_user))
      ) {
        return $uri['path'];
      }
    }

    return NULL;
  }

}
