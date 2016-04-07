<?php
/**
 * @file
 * campus_calendar.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function campus_calendar_default_rules_configuration() {
  $items = array();
  $items['rules_notice_of_new_event'] = entity_import('rules_config', '{ "rules_notice_of_new_event" : {
      "LABEL" : "New event by non-approver",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--event" : { "bundle" : "event" } },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "node:author" ],
            "roles" : { "value" : { "3" : "3", "4" : "4" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4" } },
            "subject" : "Campus Calendar: new event submitted ",
            "message" : "An event has been submitted by [site:current-user]. \\r\\n\\r\\n[node:title]\\r\\n[node:field-event-date:value]\\r\\nCategory(ies): [node:field_category]\\r\\nFormat: [node:field_format]\\r\\n\\r\\nGo to http:\\/\\/collabtest.evergreen.edu\\/calendar\\/admin\\/workbench\\/needs-review to review all new events."
          }
        },
        { "drupal_message" : { "message" : "Thank you for submitting your event: [node:title]. A moderator will review your information and publish it to the calendar." } }
      ]
    }
  }');
  return $items;
}
