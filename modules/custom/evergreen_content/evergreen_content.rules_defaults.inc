<?php
/**
 * @file
 * evergreen_content.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function evergreen_content_default_rules_configuration() {
  $items = array();
  $items['rules_generate_section_home_page'] = entity_import('rules_config', '{ "rules_generate_section_home_page" : {
      "LABEL" : "Generate Section Home Page",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "Site Creation" ],
      "REQUIRES" : [ "rules", "taxonomy" ],
      "ON" : { "taxonomy_term_insert--site_sections" : { "bundle" : "site_sections" } },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "basic_page",
              "param_title" : "[term:field-long-name]",
              "param_author" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : { "data" : [ "entity-created:field-site-section" ], "value" : [ "term" ] } }
      ]
    }
  }');
  $items['rules_log_out_with_cas_after_logging_out'] = entity_import('rules_config', '{ "rules_log_out_with_cas_after_logging_out" : {
      "LABEL" : "Log out with CAS after logging out",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_logout" : [] },
      "DO" : [ { "redirect" : { "url" : "caslogout" } } ]
    }
  }');
  $items['rules_move_to_recycling_bin'] = entity_import('rules_config', '{ "rules_move_to_recycling_bin" : {
      "LABEL" : "Move to Recycling Bin",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "workbench" ],
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "workbench_moderation_transition_update" : [] },
      "IF" : [
        { "contents_current_state" : {
            "node" : [ "workbench-moderation-transition:feed-node" ],
            "moderation_state" : "recycled"
          }
        }
      ],
      "DO" : [
        { "node_unpublish" : { "node" : [ "workbench-moderation-transition:feed-node" ] } }
      ]
    }
  }');
  $items['rules_new_event'] = entity_import('rules_config', '{ "rules_new_event" : {
      "LABEL" : "New event by basic user",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--event" : { "bundle" : "event" } },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "node:author" ],
            "roles" : { "value" : {
                "4" : "4",
                "8" : "8",
                "5" : "5",
                "9" : "9",
                "7" : "7",
                "6" : "6",
                "3" : "3"
              }
            },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4", "6" : "6" } },
            "subject" : "Campus Calendar: new event submitted ",
            "message" : "An event has been submitted by [site:current-user]. \\r\\n\\r\\n[node:title]\\r\\n[node:field-event-date:value]\\r\\nCategory(ies): [node:field_category]\\r\\nFormat: [node:field_format]\\r\\n\\r\\nGo to http:\\/\\/collab.evergreen.edu\\/calendar\\/admin\\/workbench\\/needs-review to review all new events."
          }
        },
        { "drupal_message" : { "message" : "Thank you for submitting your event: [node:title]. A moderator will review your information and publish it to the calendar." } }
      ]
    }
  }');
  return $items;
}
