<?php
/*
Plugin Name: Cosmic-History-Quotes
Plugin URI: http://anthonyfogleman.com/blog/cosmic-history-quotes-wp-plugin/
Description: Inserts one of 365 daily quotes from the seven volume Cosmic History Chronicles available at Lawoftime.org into your WP site.
Version: 1.2.2
Author: Anthony Raymond Fogleman
Author URI: http://anthonyfogleman.com
License: GPLv2
*/

/*  Copyright 2013  Anthony Raymond Fogleman  ( circle@uptimehosting.com )

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as 
    published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
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