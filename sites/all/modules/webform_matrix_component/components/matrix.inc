<?php

/**
 * @file
 * Webform module matrix component.
 */

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_matrix() {
    return array(
        'name' => '',
        'form_key' => NULL,
        'pid' => 0,
        'weight' => 0,
        'value' => '',
        'mandatory' => 0,
        'extra' => array(
            'matrix_col' => '1',
            'matrix_row' => '1',
            'title_display' => 0,
            'description' => '',
            'description_above' => FALSE,
            'private' => FALSE,
        ),
    );
}

/**
 * Implements _webform_theme_component().
 */
function _webform_theme_matrix() {
    return array(
        'webform_matrix' => array(
            'render element' => 'element',
            'file' => 'components/matrix.inc',
            'path' => drupal_get_path('module', 'webform_matrix_component'),
        ),
        'webform_display_matrix' => array(
            'render element' => 'element',
            'file' => 'components/matrix.inc',
            'path' => drupal_get_path('module', 'webform_matrix_component'),
        ),
        'webform_date_matrix' => array(
            'render element' => 'element',
            'file' => 'components/matrix.inc',
            'path' => drupal_get_path('module', 'webform_matrix_component'),
        ),
    );
}

/**
 * Implements _webform_edit_component().
 */
function _webform_edit_matrix($component) {

    $form = array();
    $max_rows = variable_get('webform_matrix_component_webform_matrix_rows', 30);
    $form['extra']['matrix_row'] = array(
        '#type' => 'select',
        '#title' => t('Matrix Rows'),
        '#options' => array_combine(range(1, $max_rows), range(1, $max_rows)),
        '#default_value' => isset($component['extra']['matrix_row']) ? $component['extra']['matrix_row'] : "1",
        '#weight' => 0,
        '#parents' => array('extra', 'matrix_row'),
    );

    $form['extra']['add_row_feature'] = array(
        '#type' => 'checkbox',
        '#title' => t('Add row feature'),
        '#default_value' => isset($component['extra']['add_row_feature']) ? $component['extra']['add_row_feature'] : 0,
        '#weight' => 1,
        '#parents' => array('extra', 'add_row_feature'),
        '#return_value' => 1,
    );

    $form['extra']['remove_row_feature'] = array(
        '#type' => 'radios',
        '#title' => t('Remove row feature'),
        '#default_value' => isset($component['extra']['remove_row_feature']) ? $component['extra']['remove_row_feature'] : 0,
        '#weight' => 1,
        '#parents' => array('extra', 'remove_row_feature'),
        '#options' => array(1 => "Per Matrix single button", 2 => "Row wise delete button", 0 => "Not Required"),
    );

    $form['extra']['add_row_button_text'] = array(
        '#type' => 'textfield',
        '#title' => t('Add row button text'),
        '#default_value' => isset($component['extra']['add_row_button_text']) ? $component['extra']['add_row_button_text'] : t('Add a row'),
        '#weight' => 2,
        '#parents' => array('extra', 'add_row_button_text'),
        '#required' => 1,
        '#states' => array(
            // Hide the settings when the cancel notify checkbox is disabled.
            'invisible' => array(
                ':input[name="extra[add_row_feature]"]' => array('checked' => FALSE),
            ),
        ),
    );

    $form['extra']['remove_row_button_text'] = array(
        '#type' => 'textfield',
        '#title' => t('Remove row button text'),
        '#default_value' => isset($component['extra']['remove_row_button_text']) ? $component['extra']['remove_row_button_text'] : t('Remove a row'),
        '#weight' => 2,
        '#parents' => array('extra', 'remove_row_button_text'),
        '#required' => 1,
        '#states' => array(
            // Hide the settings when the cancel notify checkbox is disabled.
            'visible' => array(
                ':input[name="extra[remove_row_feature]"]' => array('value' => 2),
            ),
        ),
    );

    $form['extra']['remove_row_header_text'] = array(
        '#type' => 'textfield',
        '#title' => t('Remove row header text'),
        '#default_value' => isset($component['extra']['remove_row_header_text']) ? $component['extra']['remove_row_header_text'] : t('Remove action'),
        '#weight' => 2,
        '#parents' => array('extra', 'remove_row_header_text'),
        '#states' => array(
            // Hide the settings when the cancel notify checkbox is disabled.
            'invisible' => array(
                ':input[name="extra[remove_row_feature]"]' => array('value' => 0),
            ),
        ),
    );


    return $form;
}

/**
 * Webform_edit_form extra form elements.
 * @see webform_matrix_component_form_webform_component_edit_form_alter()
 */
function _webform_matrix_component_get_column_form($form, $form_state, $component) {


    $max_cols = variable_get('webform_matrix_component_webform_matrix_cols', 10);

    $num_rows = isset($component['extra']['matrix_row']) ? $component['extra']['matrix_row'] : 1;
    if (isset($form_state['values']['extra']['matrix_row'])) {
        $num_rows = $form_state['values']['extra']['matrix_row'];
    }

    $form['#attached']['css'][] = drupal_get_path('module', 'webform_matrix_component') . '/webform_matrix_component.css';
    $form['extra']['matrix_col'] = array(
        '#type' => 'select',
        '#title' => t('Matrix Column'),
        '#options' => array_combine(range(1, $max_cols), range(1, $max_cols)),
        '#default_value' => isset($component['extra']['matrix_col']) ? $component['extra']['matrix_col'] : "",
        '#description' => t('Choose this will remove all your previos settings'),
        '#parents' => array('extra', 'matrix_col'),
        '#ajax' => array(
            'wrapper' => 'matrix-settings-ajax',
            'callback' => '_webform_matrix_component_get_type_option',
        ),
    );

    $form['extra']['element'] = array(
        '#type' => 'item',
        '#title' => t('Configuration'),
        '#prefix' => '<div id="matrix-settings-ajax">',
        '#suffix' => '</div>',
        '#tree' => TRUE,
    );

    $input_component = !empty($form_state['values']) ? $form_state['values']['extra'] : $component['extra'];
    $matrix_col = isset($input_component['matrix_col']) ? $input_component['matrix_col'] : 1;
    $ele_options = array(
        'textfield' => t('Textfield'),
        'select' => t('Select Options'),
        'label' => t('Label'),
        'date' => t('Date'),
        'textarea' => t('Textarea'),
    );

    for ($i = 1; $i <= $matrix_col; $i++) {
        $element_type = 'textfield';
        $element_id = $element_title = 'element-' . $i;
        $option_array = $label_name = "";
        $element_mandatory = $is_datepicker = 0;
        if (isset($input_component['element'][$element_id])) {
            $elementvalue = $input_component['element'][$element_id];
            $element_type = @$elementvalue['type'];
            $element_title = @$elementvalue['title'];
            $element_mandatory = @$elementvalue['mandatory'];
            $is_datepicker = @$elementvalue['datepicker'];
        }

        $td = "<td id='$element_id' style='vertical-align:top'>";
        $prefix = ($i == 1) ? "<table id='matrix-options'><tbody><tr>" . $td : $td;
        $suffix = ($matrix_col == $i) ? "</td></tr></tbody></table>" : "</td>";

        $form['extra']['element'][$element_id]['#prefix'] = $prefix;
        $form['extra']['element'][$element_id]['#suffix'] = $suffix;

        $form['extra']['element'][$element_id]['type'] = array(
            '#type' => 'select',
            '#title' => check_plain($element_id),
            '#options' => $ele_options,
            '#default_value' => $element_type,
            '#parents' => array('extra', 'element', $element_id, 'type'),
            '#id' => "edit-extra-element-$element_id-type",
            '#ajax' => array(
                'wrapper' => 'matrix-settings-ajax',
                'callback' => '_webform_matrix_component_get_type_option',
            ),
        );

        $matrix_title_requied = variable_get("webform_matrix_component_webform_matrix_title_required", 1);
        $form['extra']['element'][$element_id]['title'] = array(
            '#type' => 'textfield',
            '#title' => t('Title'),
            '#size' => 15,
            '#default_value' => $element_title,
            '#parents' => array('extra', 'element', $element_id, 'title'),
            '#id' => "edit-extra-element-$element_id-title",
            '#required' => $matrix_title_requied,
        );

        $form['extra']['element'][$element_id]['mandatory'] = array(
            '#type' => 'checkbox',
            '#title' => t('Mandatory'),
            '#size' => 15,
            '#default_value' => $element_mandatory,
            '#parents' => array('extra', 'element', $element_id, 'mandatory'),
            '#return_value' => 1,
        );

        switch ($element_type) {

            case 'textfield':
                $size = !empty($elementvalue['size']) ? $elementvalue['size'] : 50;
                $form['extra']['element'][$element_id]['size'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Textfield Size'),
                    '#default_value' => $size,
                    '#size' => 15,
                    '#required' => TRUE,
                    '#parents' => array('extra', 'element', $element_id, 'size'),
                    '#element_validate' => array('_webform_matrix_component_validate_number'),
                );

                $default_value = !empty($elementvalue['default_value']) ? $elementvalue['default_value'] : "";
                $form['extra']['element'][$element_id]['default_value'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Default Value'),
                    '#default_value' => $default_value,
                    '#size' => 15,
                    '#parents' => array('extra', 'element', $element_id, 'default_value'),
                );

                $maxlength = !empty($elementvalue['maxlength']) ? $elementvalue['maxlength'] : 50;
                $form['extra']['element'][$element_id]['maxlength'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Maxlength'),
                    '#default_value' => $maxlength,
                    '#size' => 15,
                    '#required' => TRUE,
                    '#parents' => array('extra', 'element', $element_id, 'maxlength'),
                    '#element_validate' => array('_webform_matrix_component_validate_number'),
                );
                break;

            case 'select':
                $option_array = @$elementvalue['option'];
                $form['extra']['element'][$element_id]['option'] = array(
                    '#type' => 'textarea',
                    '#title' => t('Option'),
                    '#rows' => 2,
                    '#cols' => 15,
                    '#default_value' => $option_array,
                    '#parents' => array('extra', 'element', $element_id, 'option'),
                    '#required' => TRUE,
                    '#element_validate' => array('_webform_matrix_component_edit_select'),
                    '#description' => t('<strong>Key-value pairs MUST be specified as "safe_key|Some readable option"</strong>. Use of only alphanumeric characters and underscores is recommended in keys.'),
                );


                $select_type = @$elementvalue['select_type'];
                $form['extra']['element'][$element_id]['select_type'] = array(
                    '#type' => 'select',
                    '#title' => t('Select Type'),
                    '#default_value' => empty($select_type) ? array('list') : $select_type,
                    '#options' => array('list' => 'Listbox', 'radio' => 'Radio'),
                    '#parents' => array('extra', 'element', $element_id, 'select_type'),
                    '#required' => TRUE,
                    '#description' => t('Choose Select Option Type'),
                );

                $is_multiple = @$elementvalue['multiple'];
                $form['extra']['element'][$element_id]['multiple'] = array(
                    '#type' => 'checkbox',
                    '#title' => t('Multiple'),
                    '#size' => 15,
                    '#default_value' => $is_multiple,
                    '#parents' => array('extra', 'element', $element_id, 'multiple'),
                    '#return_value' => 1,
                );

                $default_value = !empty($elementvalue['default_value']) ? $elementvalue['default_value'] : "";
                $form['extra']['element'][$element_id]['default_value'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Default Value'),
                    '#default_value' => $default_value,
                    '#size' => 15,
                    '#parents' => array('extra', 'element', $element_id, 'default_value'),
                    '#description' => t("Enter key"),
                );
                break;

            case 'label':
                for ($row_num = 1; $row_num <= $num_rows; $row_num++) {
                    $label_name = @$elementvalue['label_name'][$row_num];
                    $form['extra']['element'][$element_id]['label_name'][$row_num] = array(
                        '#type' => 'textfield',
                        '#title' => t('Label Name') . " $row_num",
                        '#default_value' => $label_name,
                        '#size' => 15,
                        '#parents' => array('extra', 'element', $element_id, 'label_name', $row_num),
                    );
                }
                break;

            case 'date':
                $form['extra']['element'][$element_id]['datepicker'] = array(
                    '#type' => 'checkbox',
                    '#title' => t('Calendar'),
                    '#default_value' => $is_datepicker,
                    '#parents' => array('extra', 'element', $element_id, 'datepicker'),
                    '#return_value' => 1,
                    '#description' => t('Default date type or calendar one type element will show only.'),
                );

                $start_date = @$elementvalue['startdate'];
                $form['extra']['element'][$element_id]['startdate'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Start Date'),
                    '#default_value' => !empty($start_date) ? $start_date : "-2 years",
                    '#size' => 15,
                    '#parents' => array('extra', 'element', $element_id, 'startdate'),
                    '#description' => t('The earliest date that may be entered into the field.') . '<br/>' . t('Accepts any date in any <a href="http://www.gnu.org/software/tar/manual/html_chapter/Date-input-formats.html">GNU Date Input Format</a>.'),
                );

                $end_date = @$elementvalue['enddate'];
                $form['extra']['element'][$element_id]['enddate'] = array(
                    '#type' => 'textfield',
                    '#title' => t('End Date'),
                    '#default_value' => !empty($end_date) ? $end_date : "+2 years",
                    '#size' => 15,
                    '#parents' => array('extra', 'element', $element_id, 'enddate'),
                    '#description' => t('The latest date that may be entered into the field.') . '<br/>' . t('Accepts any date in any <a href="http://www.gnu.org/software/tar/manual/html_chapter/Date-input-formats.html">GNU Date Input Format</a>.'),
                );

                $default_date = @$elementvalue['default_date'];
                $form['extra']['element'][$element_id]['default_date'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Default Date'),
                    '#default_value' => !empty($default_date) ? $default_date : '',
                    '#size' => 15,
                    '#parents' => array('extra', 'element', $element_id, 'default_date'),
                );
                break;
            case 'textarea':
                $rows = !empty($elementvalue['rows']) ? $elementvalue['rows'] : 1;
                $form['extra']['element'][$element_id]['rows'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Rows'),
                    '#default_value' => $rows,
                    '#size' => 15,
                    '#required' => TRUE,
                    '#parents' => array('extra', 'element', $element_id, 'rows'),
                    '#element_validate' => array('_webform_matrix_component_validate_number'),
                );

                $cols = !empty($elementvalue['cols']) ? $elementvalue['cols'] : 60;
                $form['extra']['element'][$element_id]['cols'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Cols'),
                    '#default_value' => $cols,
                    '#size' => 15,
                    '#required' => TRUE,
                    '#parents' => array('extra', 'element', $element_id, 'cols'),
                    '#element_validate' => array('_webform_matrix_component_validate_number'),
                );
                break;
        }
        drupal_alter('webform_edit_matrix', $form['extra']['element'][$element_id], $elementvalue, $element_id);
    }

    return $form;
}

/**
 * Returns matrix_options.
 *
 * @see _webform_matrix_component_get_column_form()
 */
function _webform_matrix_component_get_type_option(&$form, &$form_state) {
    return $form['extra']['element'];
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_matrix($component, $value = NULL, $filter = TRUE) {
    $node = isset($component['nid']) ? node_load($component['nid']) : NULL;

    $element = array();
    $element['#weight'] = $component['weight'];
    $element['#webform_component'] = $component;
    $element['#component_value'] = $value;
    $element['#title'] = $filter ? webform_filter_xss($component['name']) : $component['name'];
    if (isset($component['extra']['description'])) {
        $element['#description'] = $filter ? webform_filter_descriptions($component['extra']['description'], $node) : $component['extra']['description'];
    }
    if ($component['extra']['title_display'] != 0) {
        $element['value'] = array(
            '#markup' => "<label>" . _webform_filter_xss($component['name']) . "</label>",
        );
    };
    $element['#translatable'] = array('title', 'description');
    return $element;
}

/**
 * Theme for date subcomponent for matrix.
 */
function theme_webform_date_matrix($variables) {

    drupal_add_js(drupal_get_path('module', 'webform') . '/js/webform.js');

    $element = $variables['element'];

    $element['year']['#attributes']['class'] = array('year');
    $element['month']['#attributes']['class'] = array('month');
    $element['day']['#attributes']['class'] = array('day');

    // Add error classes to all items within the element.
    if (form_get_error($element)) {
        $element['year']['#attributes']['class'][] = 'error';
        $element['month']['#attributes']['class'][] = 'error';
        $element['day']['#attributes']['class'][] = 'error';
    }

    $class = array('webform-container-inline');

    // Add the JavaScript calendar if available (provided by Date module package).
    if (!empty($element['#datepicker'])) {
        $class[] = 'webform-datepicker';
        $calendar_class = array('webform-calendar');
        if ($element['#start_date']) {
            $calendar_class[] = 'webform-calendar-start-' . $element['#start_date'];
        }
        if ($element['#end_date']) {
            $calendar_class[] = 'webform-calendar-end-' . $element['#end_date'];
        }
        $calendar_class[] = 'webform-calendar-day-' . variable_get('date_first_day', 0);

        $calendar = theme('webform_calendar', array('component' => NULL, 'calendar_classes' => $calendar_class));
    }

    $output = '';
    $output .= '<div class="' . implode(' ', $class) . '">';
    $output .= drupal_render_children($element);
    $output .= isset($calendar) ? $calendar : '';
    $output .= '</div>';

    return $output;
}

/**
 * Implements _webform_submit_component().
 */
function _webform_submit_matrix($component, $value) {


    $form_key = $component['form_key'];

    if (isset($value['add_row_' . $form_key])) {
        unset($value['add_row_' . $form_key]);
    }
    if (isset($value['remove_row_' . $form_key])) {
        unset($value['remove_row_' . $form_key]);
    }

    if (is_array($value)) {
        $keys = array_keys($value);
        foreach ($keys as $key) {
            if (preg_match('/remove_row_line_' . $form_key . '_.$/', $key)) {
                unset($value[$key]);
            }
        }
    }
    return serialize($value);
}

/**
 * Validate webform_edit_form matrix components.
 */
function _webform_matrix_component_edit_select($element, &$form_state) {

    $lines = explode("\n", trim($element['#value']));
    $existing_keys = array();
    $duplicate_keys = array();
    $missing_keys = array();
    $long_keys = array();
    $group = '';
    foreach ($lines as $line) {
        $matches = array();
        $line = trim($line);
        if (preg_match('/^\<([^>]*)\>$/', $line, $matches)) {
            $group = $matches[1];
            // No need to store group names.
            $key = NULL;
        } elseif (preg_match('/^([^|]*)\|(.*)$/', $line, $matches)) {
            $key = $matches[1];
            if (strlen($key) > 128) {
                $long_keys[] = $key;
            }
        } else {
            $missing_keys[] = $line;
        }

        if (isset($key)) {
            if (isset($existing_keys[$group][$key])) {
                $duplicate_keys[$key] = $key;
            } else {
                $existing_keys[$group][$key] = $key;
            }
        }
    }

    if (!empty($missing_keys)) {
        form_error($element, t('Every option must have a key specified. Specify each option as "safe_key|Some readable option".'));
    }

    if (!empty($long_keys)) {
        form_error($element, t('Option keys must be less than 128 characters. The following keys exceed this limit:') . theme('item_list', $long_keys));
    }

    if (!empty($duplicate_keys)) {
        form_error($element, t('Options within the select list must be unique. The following keys have been used multiple times:') . theme('item_list', array('items' => $duplicate_keys)));
    }
}

/**
 * Implements _webform_matrix_component_edit_date().
 */
function _webform_matrix_component_edit_date($element, $form_state) {
    // Check if the user filled the required fields.
    foreach (array('day', 'month', 'year') as $field_type) {
        if (!is_numeric($element[$field_type]['#value']) && $element['#required']) {
            form_error($element, t('@name field is required.', array('@name' => $element['#title'])));
            return;
        }
    }
}

/**
 * Implements _webform_display_component().
 */
function _webform_display_matrix($component, $value, $format = 'html') {

    $headers = array();
    $value_array = isset($value[0]) ? unserialize($value[0]) : '';
    if (empty($value_array)) {
        return array();
    }
    $sub_elements = $component['extra']['element'];

    $display_array = _webform_display_array($sub_elements, $value_array, $headers);

    $matrix_value = array('headers' => $headers, 'rows' => $display_array);

    return array(
        '#title' => $component['name'],
        '#weight' => $component['weight'],
        '#theme' => 'webform_display_matrix',
        '#theme_wrappers' => $format == 'html' ? array('webform_element') : array('webform_element_text'),
        '#format' => $format,
        '#value' => $matrix_value,
        '#translatable' => array('title'),
    );
}

/**
 * Format the text output for this component.
 */
function theme_webform_display_matrix($variables) {

    $matrix_value = $variables['element']['#value'];
    //$output = theme('table', array('header' => $matrix_value['headers'], 'rows' => $matrix_value['rows']));

    if ($variables['element']['#format'] == 'html') {
        $output = theme('table', array('header' => $matrix_value['headers'], 'rows' => $matrix_value['rows']));
    } else {
        $output = implode(' ~  ', $matrix_value['headers']) . "\n";
        foreach ($matrix_value['rows'] as $row) {
            $output .= implode(' ~ ', $row) . "\n";
        }
    }

//    $output = theme('table', array('header' => $matrix_value['headers'], 'rows' => $matrix_value['rows']));
    return $output;
}

/**
 * Implements _webform_analysis_component().
 */
function _webform_analysis_matrix($component, $sids = array()) {

    $query = db_select('webform_submitted_data', 'wsd', array('fetch' => PDO::FETCH_ASSOC))
            ->fields('wsd', array('no', 'data'))
            ->condition('nid', $component['nid'])
            ->condition('cid', $component['cid'])
            ->orderBy('sid');

    if (count($sids)) {
        $query->condition('sid', $sids, 'IN');
    }

    $result = $query->execute();

    $matrixs = array();
    $submissions = 0;
    foreach ($result as $row) {
        $submissions++;
        if ($row['data']) {
            $matrixs[] = _webform_matrix_component_array($row['data']);
        }
    }

    // Display stats.
    $nonblanks = count($matrixs);
    $rows[0] = array(t('Left Blank'), ($submissions - $nonblanks));
    $rows[1] = array(t('User entered value'), $nonblanks);
    return $rows;
}

/**
 * Implements _webform_table_component().
 */
function _webform_table_matrix($component, $value) {

    if ($value[0]) {

        $sub_elements = $component['extra']['element'];

        $value_array = unserialize($value[0]);

        if (empty($value_array)) {
            return array();
        }

        $col = 1;
        $headers = array();
        $display_array = _webform_display_array($sub_elements, $value_array, $headers);

        $output = theme('table', array('header' => $headers, 'rows' => $display_array));

        return $output;
    } else {
        return '';
    }
}

/**
 * Implements _webform_csv_headers_component().
 */
function _webform_csv_headers_matrix($component, $export_options) {
    $header = array();
    $sub_elements = $component['extra']['element'];
    foreach ($sub_elements as $sub_element) {
        $header[1][] = check_plain($component['name']);
        $header[2][] = check_plain($sub_element['title']);
    }
    return $header;
}

/**
 * Implements _webform_csv_data_component().
 */
function _webform_csv_data_matrix($component, $export_options, $value) {

    if ($value[0]) {
        $value_array = _webform_matrix_component_array($value[0]);
        if (empty($value_array)) {
            return array_fill(0, $size, "");
        }
        $sub_elements = $component['extra']['element'];

        //Return managable display array
        $display_array = _webform_display_array($sub_elements, $value_array);

        $reverse_array = _webform_matrix_component_array_reverse($display_array);
        $csv_array = array();
        foreach ($reverse_array as $value) {
            $csv_array[] = implode(" - ", empty($value) ? "NA" : $value);
        }
        return $csv_array;
    } else {
        return array_fill(0, $size, "");
    }
}

/**
 * Unseriaze matrix components values.
 */
function _webform_matrix_component_array($value) {
    return ($value != '') ? unserialize($value) : "";
}

/**
 * Convert matrix select option values to options array.
 */
function _webform_matrix_component_select_option_from_text($options) {
    if ($options != '') {
        foreach (preg_split("/((\r?\n)|(\r\n?))/", $options) as $line) {
            if (strstr($line, '|')) {
                list($key, $value) = explode('|', $line);
            } else {
                $key = $value = $line;
            }
            $option_array[$key] = $value;
        }
    }
    $option_array = (count($option_array) == 0) ? array(0 => 'None') : $option_array;
    return $option_array;
}

/**
 * This is simple function to convert array rows to cols.
 */
function _webform_matrix_component_array_reverse($array) {
    $out = array();
    foreach ($array as $rowkey => $row) {
        foreach ($row as $colkey => $col) {
            $out[$colkey][$rowkey] = $col;
        }
    }
    return $out;
}

/**
 * This is return display array
 * @param array $sub_elements matrix node compoenent
 * @param array $value_array matrix submission result
 * @return $display_array display result
 */
function _webform_display_array($sub_elements, $value_array, &$headers = array()) {

    $col = 1;

    foreach ($sub_elements as $sub_element) {

        $headers[] = check_plain($sub_element['title']);

        if ($sub_element['type'] == 'textfield') {
            foreach ($value_array as $key => $value_row) {
                if (!empty($value_row[$col])) {
                    $display_array[$key][$col] = check_plain($value_row[$col]);
                } else {
                    $display_array[$key][$col] = "";
                }
            }
        } elseif ($sub_element['type'] == 'select') {
            $option_array = _webform_matrix_component_select_option_from_text($sub_element['option']);

            foreach ($value_array as $key => $value_row) {
                if (isset($value_row[$col])) {
                    // Check for multiple
                    $is_multiple = @$sub_element['multiple'];

                    if (is_array($value_row[$col])) {
                        $select_values_options = array();
                        foreach ($value_row[$col] as $select_values) {
                            if (array_key_exists($select_values, $option_array)) {
                                $select_values_options[] = $option_array[$select_values];
                            }
                        }
                        if (!empty($select_values_options)) {
                            $display_array[$key][$col] = implode(',', $select_values_options);
                        } else {
                            $display_array[$key][$col] = '';
                        }
                    } else {
                        // Previous functionality
                        if (array_key_exists($value_row[$col], $option_array)) {
                            $display_array[$key][$col] = $option_array[$value_row[$col]];
                        } else {
                            $display_array[$key][$col] = $value_row[$col];
                        }
                    }
                } else {
                    $display_array[$key][$col] = '';
                }
            }
        } elseif ($sub_element['type'] == 'date') {
            foreach ($value_array as $key => $value_row) {
                if ($value_array[$key][$col]['year'] && $value_array[$key][$col]['month'] && $value_array[$key][$col]['day']) {
                    $timestamp = webform_strtotime($value_array[$key][$col]['month'] . '/' . $value_array[$key][$col]['day'] . '/' . $value_array[$key][$col]['year']);
                    $format = webform_date_format('short');
                    $display_array[$key][$col] = format_date($timestamp, 'custom', $format, 'UTC');
                } else {
                    $display_array[$key][$col] = "";
                }
            }
        } elseif ($sub_element['type'] == 'label') {
            foreach ($value_array as $key => $value_row) {
                $display_array[$key][$col] = $sub_element['label_name'][$key];
            }
        } elseif ($sub_element['type'] == 'textarea') {
            foreach ($value_array as $key => $value_row) {
                if (!empty($value_row[$col])) {
                    $display_array[$key][$col] = check_plain($value_row[$col]);
                } else {
                    $display_array[$key][$col] = "";
                }
            }
        }
        $col++;
    }

    return $display_array;
}

/**
 * Validate Number
 */
function _webform_matrix_component_validate_number($element, &$form_state) {
    $value = trim($element['#value']);
    if (!is_numeric($value) && !is_int($value)) {
        form_error($element, t('Maxlength and Size should be integer.'));
    }
}
