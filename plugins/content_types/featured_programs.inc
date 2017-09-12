<?php

$plugin = array(
  'title' => t('Featured Programs'),
  'category' => t('Custom Content & Features'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_feature_ee_program_display_featured_programs_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
    $featured_programs = _gsb_feature_ee_program_display_featured_programs_field_markup_featured_programs();
    return (object) array(
      'title' => 'Featured Programs',
      'content' => array(
      '#markup' => $featured_programs,
    ),
  );
}