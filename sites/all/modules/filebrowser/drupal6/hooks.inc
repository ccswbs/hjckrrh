<?php

/**
 * Implementation of hook_node_info().
 */
function filebrowser_node_info() {
  return array(
    'dir_listing' => array(
      'module' => 'filebrowser',
      'name' => t('Directory listing'),
      'description' => t("A listing of files similar to how Apache lists files in a directory."),
      'has_body' => FALSE
    )
  );
}

/**
 * hook_perm implementation.
 */
function filebrowser_perm() {
  return array(
      FILEBROWSER_CREATE_DIRECTORY_LISTING,
      FILEBROWSER_DELETE_OWN_DIRECTORY_LISTINGS,
      FILEBROWSER_DELETE_ANY_DIRECTORY_LISTINGS,
      FILEBROWSER_EDIT_OWN_DIRECTORY_LISTINGS,
      FILEBROWSER_EDIT_ANY_DIRECORY_LISTINGS,
      FILEBROWSER_VIEW_DIRECORY_LISTINGS,
      FILEBROWSER_UPLOAD,
      FILEBROWSER_DOWNLOAD_ARCHIVE,
      FILEBROWSER_DELETE_FILE,
      FILEBROWSER_DOWNLOAD,
      FILEBROWSER_CREATE_FOLDER
  );
}

