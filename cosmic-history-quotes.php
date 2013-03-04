<?php
/*
Plugin Name: Cosmic-History-Quotes
Plugin URI: http://anthonyfogleman.com/blog/cosmic-history-quotes-wp-plugin/
Description: Cosmic History Quotes - 365 daily quotes from the seven volume Cosmic History Chronicles available at Lawoftime.org.  After installing this plugin copy and paste the shortcode: [cosmic-quotes] into any page, post or text widget.  After installing, a new menu appears in your dashboard called "CHC Settings" allowing control of language, visibility, and style.
Version: 1.2.1
Author: Anthony Raymond Fogleman
Author URI: http://anthonyfogleman.com
License: GPLv2
*/

// error_reporting(E_ALL);

// Include main game output
require_once('chron_output.inc');

// This code creates the ability to use shortcodes
add_shortcode('cosmic-quotes', 'start_chron');  // called from page with: [chronicles default_lang="en"]

// Include wp menu and settings file
require_once('settings.inc');

// create custom plugin settings menu
add_action('admin_menu', 'chq_create_menu');

/* EOF */