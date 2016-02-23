#!/usr/bin/env bash
drush dl --yes features_extra linkit rules select_or_other strongarm suggest_similar_titles telephone user_restrictions entityreference_feeds
drush dl --yes features-7.x-2.7
drush --yes @sites updb
