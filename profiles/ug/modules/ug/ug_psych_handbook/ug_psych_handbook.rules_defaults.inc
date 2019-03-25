<?php
/**
 * @file
 * ug_psych_handbook.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ug_psych_handbook_default_rules_configuration() {
  $items = array();
  $items['rules_sync_content'] = entity_import('rules_config', '{ "rules_sync_content" : {
      "LABEL" : "Sync content",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--book" : { "bundle" : "book" } },
      "DO" : [
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1031", "1176", "1125", "1161" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1032", "1178", "1120", "1202" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1221", "1187", "1121", "1204" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1034", "1181", "1124", "1208" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1036", "1182", "1119", "1210" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1040", "1183", "1126", "1211" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1041", "1184", "1127", "1211" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1042", "1185", "1128", "1213" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1019", "1104", "1085", "1069" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1020", "1105", "1087", "1070" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1021", "1106", "1090", "1071" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1023", "1108", "1092", "1072" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1024", "1110", "1094", "1073" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1026", "1113", "1097", "1075" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1025", "1112", "1096", "1074" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1027", "1114", "1101", "1077" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1028", "1115", "1099", "1076" ] }
          }
        },
        { "component_rules_sync_nodes" : {
            "source" : [ "node" ],
            "targets" : { "value" : [ "1222", "1189", "1122", "1206" ] }
          }
        }
      ]
    }
  }');
  return $items;
}
