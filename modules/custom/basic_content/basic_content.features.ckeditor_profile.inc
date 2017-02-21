<?php
/**
 * @file
 * basic_content.features.ckeditor_profile.inc
 */

/**
 * Implements hook_ckeditor_profile_defaults().
 */
function basic_content_ckeditor_profile_defaults() {
  $data = array(
    'Basic_tags' => array(
      'name' => 'Basic_tags',
      'settings' => array(
        'ss' => 2,
        'toolbar' => '[
    [\'PasteFromWord\',\'Format\',\'Styles\',\'Bold\',\'Italic\',\'-\',\'NumberedList\',\'BulletedList\',\'Outdent\',\'Indent\',\'-\',\'linkit\',\'Unlink\',\'Media\',\'-\',\'Maximize\']
]',
        'expand' => 't',
        'default' => 't',
        'show_toggle' => 't',
        'uicolor' => 'default',
        'uicolor_user' => 'default',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'allowed_content' => 'f',
        'extraAllowedContent' => '',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;h2;h3;h4',
        'custom_formatting' => 't',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
            'breakBeforeClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'self',
        'css_path' => '%t/css/dist/custom-css/ckeditor.css',
        'css_style' => 'theme',
        'styles_path' => '',
        'filebrowser' => 'none',
        'filebrowser_image' => '',
        'filebrowser_flash' => '',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'forcePasteAsPlainText' => 'f',
        'html_entities' => 'f',
        'scayt_autoStartup' => 't',
        'theme_config_js' => 'f',
        'js_conf' => '',
        'loadPlugins' => array(
          'counter' => array(
            'name' => 'counter',
            'desc' => 'Plugin to count symbols, symbols without blanks and words',
            'path' => '%plugin_dir%counter/',
            'buttons' => FALSE,
            'default' => 'f',
          ),
          'linkit' => array(
            'name' => 'linkit',
            'desc' => 'Support for Linkit module',
            'path' => '%base_path%sites/all/modules/contrib/linkit/editors/ckeditor/',
            'buttons' => array(
              'linkit' => array(
                'label' => 'Linkit',
                'icon' => 'icons/linkit.png',
              ),
            ),
          ),
          'media' => array(
            'name' => 'media',
            'desc' => 'Plugin for embedding files using Media CKEditor',
            'path' => '%base_path%sites/all/modules/contrib/media_ckeditor/js/plugins/media/',
            'buttons' => array(
              'Media' => array(
                'icon' => 'images/icon.gif',
                'label' => 'Add media',
              ),
            ),
            'default' => 'f',
          ),
          'mediaembed' => array(
            'name' => 'mediaembed',
            'desc' => 'Plugin for embedding HTML snippets',
            'path' => '%plugin_dir%mediaembed/',
            'buttons' => array(
              'MediaEmbed' => array(
                'label' => 'MediaEmbed',
                'icon' => 'images/icon.png',
              ),
            ),
            'default' => 'f',
          ),
          'tableresize' => array(
            'name' => 'tableresize',
            'desc' => 'Table Resize plugin. See <a href="http://ckeditor.com/addon/tableresize">addon page</a> for more details.',
            'path' => '//cdn.ckeditor.com/4.5.4/full-all/plugins/tableresize/',
            'buttons' => FALSE,
            'default' => 't',
          ),
        ),
      ),
      'input_formats' => array(
        'basic_tags' => 'Basic tags',
      ),
    ),
    'CKEditor Global Profile' => array(
      'name' => 'CKEditor Global Profile',
      'settings' => array(
        'ckeditor_path' => '//cdn.ckeditor.com/4.5.4/full-all',
      ),
      'input_formats' => array(),
    ),
    'Extended_tags' => array(
      'name' => 'Extended_tags',
      'settings' => array(
        'ss' => 2,
        'toolbar' => '[
    [\'PasteFromWord\',\'Format\',\'Styles\',\'Bold\',\'Italic\',\'-\',\'NumberedList\',\'BulletedList\',\'Outdent\',\'Indent\',\'-\',\'linkit\',\'Unlink\',\'Media\',\'-\',\'Table\',\'CodeSnippet\',\'Maximize\']
]',
        'expand' => 't',
        'default' => 't',
        'show_toggle' => 't',
        'uicolor' => 'default',
        'uicolor_user' => 'default',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'allowed_content' => 'f',
        'extraAllowedContent' => '',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;h2;h3;h4',
        'custom_formatting' => 't',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
            'breakBeforeClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'self',
        'css_path' => '%t/css/dist/custom-css/ckeditor.css',
        'css_style' => 'theme',
        'styles_path' => '',
        'filebrowser' => 'none',
        'filebrowser_image' => '',
        'filebrowser_flash' => '',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'forcePasteAsPlainText' => 'f',
        'html_entities' => 'f',
        'scayt_autoStartup' => 't',
        'theme_config_js' => 'f',
        'js_conf' => '',
        'loadPlugins' => array(
          'codesnippet' => array(
            'name' => 'codesnippet',
            'desc' => 'Plugin for inserting Code Snippets. See <a href="http://ckeditor.com/addon/codesnippet">addon page</a> for more details. See <a href="/feature-breakup/admin/help/ckeditor#codesnippet">help</a> for additional instructions.',
            'path' => '//cdn.ckeditor.com/4.5.4/full-all/plugins/codesnippet/',
            'buttons' => array(
              'CodeSnippet' => array(
                'icon' => 'icons/codesnippet.png',
                'label' => 'Insert Code Snippet',
              ),
            ),
            'default' => 'f',
          ),
          'counter' => array(
            'name' => 'counter',
            'desc' => 'Plugin to count symbols, symbols without blanks and words',
            'path' => '%plugin_dir%counter/',
            'buttons' => FALSE,
            'default' => 'f',
          ),
          'linkit' => array(
            'name' => 'linkit',
            'desc' => 'Support for Linkit module',
            'path' => '%base_path%sites/all/modules/contrib/linkit/editors/ckeditor/',
            'buttons' => array(
              'linkit' => array(
                'label' => 'Linkit',
                'icon' => 'icons/linkit.png',
              ),
            ),
          ),
          'media' => array(
            'name' => 'media',
            'desc' => 'Plugin for embedding files using Media CKEditor',
            'path' => '%base_path%sites/all/modules/contrib/media_ckeditor/js/plugins/media/',
            'buttons' => array(
              'Media' => array(
                'icon' => 'images/icon.gif',
                'label' => 'Add media',
              ),
            ),
            'default' => 'f',
          ),
          'mediaembed' => array(
            'name' => 'mediaembed',
            'desc' => 'Plugin for embedding HTML snippets',
            'path' => '%plugin_dir%mediaembed/',
            'buttons' => array(
              'MediaEmbed' => array(
                'label' => 'MediaEmbed',
                'icon' => 'images/icon.png',
              ),
            ),
            'default' => 'f',
          ),
          'tableresize' => array(
            'name' => 'tableresize',
            'desc' => 'Table Resize plugin. See <a href="http://ckeditor.com/addon/tableresize">addon page</a> for more details.',
            'path' => '//cdn.ckeditor.com/4.5.4/full-all/plugins/tableresize/',
            'buttons' => FALSE,
            'default' => 't',
          ),
        ),
      ),
      'input_formats' => array(
        'extended_tags' => 'Extended tags',
      ),
    ),
  );
  return $data;
}
