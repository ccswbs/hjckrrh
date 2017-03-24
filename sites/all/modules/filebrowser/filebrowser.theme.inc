<?php
/**
 * @file
 *
 * Several theme functions for filebrowser
 */

/**
 *
 * Enter description here ...
 * @param Node $node
 * @return string
 */
function theme_dir_listing_icon_view($node) {
  $node = $node['node'];
  $files = & $node->file_listing;

  // Record if directory listing is empty or not.
  $directory_empty = TRUE;
  $output = "<div class='dir-listing-icon-view'>";
  // Considered each file (or directory)
  foreach ($files as $file_name => $data) {
    // Skip dot folder
    if ($file_name == ".") {
      continue;
    }

    // At least one file
    $directory_empty = FALSE;

    // File extension case
    if ($file_name != ".." && $data['kind'] == 0 && $node->folder_presentation->hide_extension) {
      $pos = strrpos($data['display-name'], ".");
      $data[FILEBROWSER_DATA_NAME_DISPLAY_NAME] = substr($data['display-name'], 0, $pos);
    }
    $variables = array(
      'data' => $data,
    'thumbnail' => _filebrowser_thumbnails_generate($node, $data),
      'href' => $data['url'],
      'title' => $data['display-name'] == '..' ? t('Go up') : $data['display-name'],
      'new' => theme('mark', array('type' => $data['status'])),
    'description' => $data['description'],
  );
    $output .= theme('dir_listing_icon', $variables);
  }
  $output .= "</div>";
  return $output;
}

/**
 * Theming function for icon-view.
 *
 * @param $node the node to transform to icon  view.
 * @return A string containing icon view XHTML.
 */
function theme_dir_listing_statistics($statistics) {

  // $whitelist is used to restrict indexes to filebrowser indexes.
  // Issue #2616738 indicates addition of 'index' to the array

  $output = "<div class='dir-listing-status'>";
  if ($statistics['empty']) {
    $output .= $statistics['empty'];
  }
  else {
    $white_list = array('files', 'size', 'empty', 'folders');
    $white_listed_statistics = array();

    foreach($statistics as $key => $statistic) {
      if (in_array($key, $white_list) && !empty($statistic)) {
        $white_listed_statistics[] = $statistic;
      }
    }

    $output .= implode(" - ", $white_listed_statistics);
  }
  $output .= "</div>";
  return $output;
}

/**
 * Theming function for list view.
 *
 * @param Node $node the node to transform to list view.
 * @return string A string containing list view XHTML.
 */
function theme_dir_listing_list_view($node) {

  $node = $node['node'];
  $files = & $node->file_listing;
  // Deal with files.
  $unsorted_rows = array();

  // add optional colunmns
  // $node->folder_presentation->visible_columns['description'] = TRUE;

  // Visible columns
  $visible_columns = array();
  $column_names = _filebrowser_externals('metadata_info');

  // Record if directory listing is empty or not.
  $directory_empty = TRUE;

  // Available actions
  $actions = module_invoke_all('filebrowser_actions_info', $node);
  $has_actions = count($actions) > 0;

  // Header building
  $header = array();
  if ($has_actions) {
  // data column removed because we use theme_tableselect to
  // build the checkboxes
  }

  // Considered each file (or directory)
  foreach ($files as $file_name => $data) {
    // Skip dot folder
    if ($file_name == ".") {
      continue;
    }

    // At least one file
    $directory_empty = FALSE;

    // File extension case
    if ($file_name != ".." && $data['kind'] == 0 && $node->folder_presentation->hide_extension) {
      $pos = strrpos($data[FILEBROWSER_DATA_NAME_DISPLAY_NAME], ".");
      $data[FILEBROWSER_DATA_NAME_DISPLAY_NAME] = substr($data[FILEBROWSER_DATA_NAME_DISPLAY_NAME], 0, $pos);
    }
    if ($has_actions) {
      // checkboxes are now provided by theme_tableselect
      $unsorted_rows[$file_name]['fid'] = ($data['mime-type'] != 'folder/parent' ? "{$data['fid']}" : '');
    }
    foreach ($column_names as $column_name => $column_spec) {
      if (isset($node->folder_presentation->visible_columns[$column_name]) && $node->folder_presentation->visible_columns[$column_name]) {
        switch ($column_name) {
          case FILEBROWSER_DATA_NAME_ICON :
            $visible_columns[$column_name] = TRUE;
            $unsorted_rows[$file_name][FILEBROWSER_DATA_NAME_ICON] = array(
                'data' => _filebrowser_thumbnails_generate($node, $data),
                'style' => 'width:1%;'
            );
            break;

          case FILEBROWSER_DATA_NAME_DISPLAY_NAME :
            $unsorted_rows[$file_name][FILEBROWSER_DATA_NAME_DISPLAY_NAME] =
              '<a href="' . $data['url'] . '">' .
                ($data['display-name'] == '..' ? t('Go up') : $data['display-name']) .
              '</a>' .
              theme('mark', array('type' => $data['status']));
            $visible_columns[$column_name] = TRUE;
            break;

          case FILEBROWSER_DATA_NAME_SIZE :
            $used = ($data['size']) != 0 && ($data['kind'] == 0);
            $unsorted_rows[$file_name][FILEBROWSER_DATA_NAME_SIZE] = $used ? format_size($data['size']) : "";
            if ($used) {
              $visible_columns[$column_name] = TRUE;
            }
            break;

          case FILEBROWSER_DATA_NAME_CREATED :
            isset($data['created']) ? null : $data['created'] = 0;
            if ($data['created']) {
              $visible_columns[$column_name] = TRUE;
            }
            $unsorted_rows[$file_name][FILEBROWSER_DATA_NAME_CREATED] = format_date($data['created'], "small");
            break;

          case FILEBROWSER_DATA_NAME_MODIFIED :
            isset($data['modified']) ? null : $data['modified'] = 0;
            if ($data['modified'] != 0) {
              $visible_columns[$column_name] = TRUE;
            }
            $unsorted_rows[$file_name][FILEBROWSER_DATA_NAME_MODIFIED] = format_date($data['modified'], "small");
            break;

          case FILEBROWSER_DATA_NAME_TYPE :
            $used = $data['mime-type'] != 'folder' && $data['mime-type'] != 'folder/parent';
            if ($used) {
              $visible_columns[$column_name] = TRUE;
            }
            $unsorted_rows[$file_name][FILEBROWSER_DATA_NAME_TYPE] = $used ? t($data['mime-type']) : "";
            break;

          case FILEBROWSER_DATA_NAME_DESCRIPTION :
            if (!empty($data['description'])) {
              $visible_columns[$column_name] = TRUE;
            }
            $unsorted_rows[$file_name]['description'] = str_replace("\n", "<br/>", $data['description']);
            break;

          default :
            $visible_columns[$column_name] = isset($data[$column_name]);
            if ($visible_columns[$column_name]) {
              $unsorted_rows[$file_name][$column_name] = $data[$column_name];
            }
            break;
        }
      }
    }
  }

  if (!$directory_empty) {
    // Builder header and clean up unused columns
    foreach ($column_names as $column_name => $column_spec) {
      if (isset($visible_columns[$column_name]) && $visible_columns[$column_name]) {
        if ($column_name == FILEBROWSER_DATA_NAME_ICON) {
          $header[$column_name] = array();
        }
        else {
          $header[$column_name] = array(
              'data' => $column_spec['title'],
              'field' => $column_name
          );
        }
      }
      else {
        // If unused data then clean up !
        foreach ($unsorted_rows as & $row) {
          unset($row[$column_name]);
        }
      }
    }
    $header[$node->folder_presentation->default_sort]['sort'] = $node->folder_presentation->default_sort_order;

    // Handle any and all sorting.
    $table_sort = tablesort_init($header);

    // Split files in two heaps to preserve folders and files
    $just_folders = array();
    $just_files = array();

    // TODO : take data from $unsorted_rows and not $data
    foreach ($files as $name => $data) {
      if ($name != '.') {
        if ($data['kind'] == 0) {
          $just_files[] = $data;
        }
        else {
          // Do not retain the '.' folder
          $just_folders[] = $data;
        }
      }
    }

    // Sort files according to correct column.
    if (isset($table_sort['sql'])) {
      $field = $table_sort['sql'];
      $columns = _filebrowser_externals('metadata_info');

      if (isset($columns[$table_sort['sql']]) && isset($columns[$table_sort['sql']]['sortable']) && $columns[$table_sort['sql']]['sortable']) {
        switch ($columns[$table_sort['sql']]['type']) {
          case 'integer' :
            $code = '$a=isset($a["' . $field . '"])?$a["' . $field . '"]:0;';
            $code .= '$b=isset($b["' . $field . '"])?$b["' . $field . '"]:0;';
            $code .= 'return $a-$b;';
            break;

          case 'string' :
            $code = '$a=isset($a["' . $field . '"])?$a["' . $field . '"]:"";';
            $code .= '$b=isset($b["' . $field . '"])?$b["' . $field . '"]:"";';
            $code .= 'return -strcmp(strtolower($a),strtolower($b));';
            break;

        }
        $sorter = create_function('$a,$b', $code);
        usort($just_folders, $sorter);
        if ($table_sort['sort'] == 'asc') {
          $just_folders = array_reverse($just_folders, TRUE);
        }
        usort($just_files, create_function('$a,$b', $code));
        if ($table_sort['sort'] == 'asc') {
          $just_files = array_reverse($just_files, TRUE);
        }
      }
    }

    // Combine folders and files array and setup correct order.
    //$rows = array_merge($just_folders, $just_files);
    $rows = array();
    foreach ($just_folders as $data) {
      //debug($data, 'folders');
      $rows[$data['fid']] = $unsorted_rows[$data['display-name']];
    }
    foreach ($just_files as $data) {
      //debug($data, 'files');
      $rows[$data['fid']] = $unsorted_rows[$data['display-name']];
    }
    $output = theme('table', array('header' => $header, 'rows' => $rows));
    if ($has_actions) {
      // in D7 we don't send the table to the form builder. The table is build by theme_tableselect
      $form = drupal_get_form('filebrowser_form_actions', $header, $rows, $actions, $node);
		  $output = drupal_render($form);
    }
    return $output;
  } // Directory is not empty
}

// FIXME: Rendering the thumbnail gives error
// Temp solution by using the already rendered img $form['thumbnail']['#value']
function theme_dir_listing_metadata_group($array_form) {
  $form = $array_form[''];
  //$thumbnail = drupal_render($form['thumbnail']);
  $output = "<table>";
  foreach (element_children($form) as $key) {
    if ($key != 'thumbnail') {
      //$output .= "<tr><td>$thumbnail</td><td>"
      $output .= "<tr><td>" . $form['thumbnail']['#value'] . "</td><td>" . drupal_render($form[$key]) . "</td></tr>";
   //   $thumbnail = '';
    }
  }
  $output .= "</table>";
  return $output;
}
