<?php
/**
 * @file
 * learning_community_directory.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function learning_community_directory_default_rules_configuration() {
  $items = array();
  $items['rules_add_institution_to_user_profile'] = entity_import('rules_config', '{ "rules_add_institution_to_user_profile" : {
      "LABEL" : "Add Institution to User Profile",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--institution" : { "bundle" : "institution" } },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1", "3" : "3", "4" : "4" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:author:field-institution" ], "value" : [ "node" ] } }
      ]
    }
  }');
  return $items;
}
