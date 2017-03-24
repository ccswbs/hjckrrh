This module provides an interface for administrators to expose directories in
the file system to users through a file listing not unlike that provided by
Apache.

This module is useful when Drupal is an entire website and sits in the root
directory. All requests to the website are therefore passed to Drupal's 
index.php and directory listings cannot be found even if they're enabled.
This module alleviates those problems by passing those directory listings
through Drupal, effectively.

This module offers the following features:
 - Private downloads so that files (such as PHP files) can be downloaded.
 - File blacklists so that specific files can be removed from directory listings.
 - Node-based. All features available to nodes, such as path aliasing and access
   control can now be applied to directory listings.
 - Settings to limit exploration of subdirectories.
 - File icons. This module includes part of the Tango Icon Library for use as file
   icons. Many common file types are supported by default. To extend the icons you
   may alter those in the "modules/filebrowser/icons" directory or override those
   with your own in an "filebrowser" directory in your theme.
 - descript.ion, file.bbs: Files used for adding description text to file listings.
   The format for descript.ion and file.bbs is the same and there is an example in
   this directory. Filename (optionally within quotes) followed by any amount of
   whitespace and then the description.
 
Fundamental changes from earlier branches:
 - Path aliasing is now provided by path.module since directory listings are now
   nodes.