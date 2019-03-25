<?php
/**
 * @file
 * ug_node_mirror.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ug_node_mirror_default_rules_configuration() {
  $items = array();
  $items['rules_sync_nodes'] = entity_import('rules_config', '{ "rules_sync_nodes" : {
      "LABEL" : "Sync nodes",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "source" : { "label" : "Source", "type" : "node" },
        "targets" : { "label" : "Targets", "type" : "list\\u003Cinteger\\u003E" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "source:nid" ], "op" : "IN", "value" : [ "targets" ] } }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "targets" ] },
            "ITEM" : { "item" : "Current list item" },
            "DO" : [
              { "entity_fetch" : {
                  "USING" : { "type" : "node", "id" : [ "item" ] },
                  "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
                }
              },
              { "data_set" : { "data" : [ "entity-fetched:body" ], "value" : [ "source:body" ] } },
              { "entity_save" : { "data" : [ "entity-fetched" ], "immediate" : "1" } }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
