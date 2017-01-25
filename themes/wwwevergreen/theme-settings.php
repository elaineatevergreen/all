<?php
function wwwevergreen_form_system_theme_settings_alter(&$form, &$form_state) {
  $form['theme_settings']['evergreen_blocks'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Evergreen.edu search and footer'),
    '#default_value' => theme_get_setting('evergreen_blocks'),
  );
  $form['theme_settings']['evergreen_ad_tracking'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include Evergreen.edu ad tracking scripts'),
    '#default_value' => theme_get_setting('evergreen_ad_tracking'),
  );
}

