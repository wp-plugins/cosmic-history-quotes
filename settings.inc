<?php

function chq_create_menu() {

	//create new top-level menu
	add_menu_page('CHQ Plugin Settings', 'CHQ Settings', 'administrator', __FILE__, 'chq_settings_page',plugins_url('peeps.png?ver=20111329', __FILE__));
	add_action( 'admin_init', 'register_mysettings' );
}

function register_mysettings() {
	//register our settings
	register_setting( 'chq-settings-group', 'starting_language' );
	register_setting( 'chq-settings-group', 'text_color' );
	register_setting( 'chq-settings-group', 'background_color' );
	register_setting( 'chq-settings-group', 'div_width' );
	register_setting( 'chq-settings-group', 'font_size' );
	register_setting( 'chq-settings-group', 'line_height_px' );
	register_setting( 'chq-settings-group', 'last_save_time' );
	register_setting( 'chq-settings-group', 'info_position' );
}

function chq_settings_page() {
?>
<div class="wrap">
<h2>Cosmic History Quotes (CHQ) Settings</h2>

<P>
<hr>
Cosmic History Quotes - 365 daily quotes from the seven volume Cosmic History Chronicles available at Lawoftime.org.  After installing this plugin copy and paste the shortcode: [cosmic-quotes] into any page, post or text widget. Visit <a href="http://anthonyfogleman.com/blog/wordpress-plugins/">Visit plugin site</a> for the latest version, language files, or support.
<hr>
<?php


if ($_GET["settings-updated"] === "true"){
	$table_bg = "#AEA";
} else {
	$table_bg = "";
}

$curr_date = date("D F j, Y g:i:s a  ");
$save_time_mess = get_option('last_save_time');
echo "<table bgcolor=$table_bg>";
if ($_GET["settings-updated"] === "true"){
	echo "<tr><th colspan=2><h2>Settings Saved!</h2></th><tr>";
}
echo "<tr><td>Current Date:</td><td>$curr_date</td></tr>";
echo "<tr><td>Last Save:</td><td>$save_time_mess</td></tr>";
echo "</table>";
?>

<hr>

</P>

<form method="post" action="options.php">
    <?php settings_fields( 'chq-settings-group' ); ?>
    <?php // do_settings( 'chq-settings-group' ); ?>
    <table class="form-table">


<?php
// Path to files
$path = "../wp-content/plugins/cosmic-history-quotes";

// Get list of Language Files to verify which languages are available
	$txt_files = glob("$path/*.txt");
     foreach ($txt_files as $file) {
		$file = str_replace($path, '', $file); 
		$file = str_replace('/', '', $file); 
		$file = str_replace('.txt', '', $file);
		$pieces = explode("_", $file);
		$lang_name[] = $pieces[0];
	}
	$langs = array_unique($lang_name);

// Testing
// echo "<hr>";
// echo $txt_files;
// echo "<hr>";

?>
	   <tr valign="top">
	   <th scope="row"><b>Starting Language</b> <br> All installed languages should appear as options.  Visit <a href="http://anthonyfogleman.com/blog/wordpress-plugins/">plugin site</a> for updates and other interesting plugins.</th>
<td>
<?php

	$lang_selected = get_option('starting_language');

     foreach ($langs as $lang) {
		echo "<input type=radio name=starting_language value=$lang";
		if ($lang === $lang_selected){echo " CHECKED";}
		echo "> $lang<BR>";
	}
?>

</td>
	   </tr>
	    
	   <tr valign="top">
	   <th scope="row"><b>Font Color</b> (default: 666)</th>
	   <td>Hex: #<input size=8 maxlength=6 type="text" name="text_color" value="<?php echo get_option('text_color'); ?>" /></td>
	   </tr>
	   
	   <tr valign="top">
	   <th scope="row"><b>Background Color</b> (default: 000000)</th>
	   <td>Hex: #<input size=8 maxlength=6 type="text" name="background_color" value="<?php echo get_option('background_color'); ?>" /></td>
	   </tr>

	   <tr valign="top">
	   <th scope="row"><b>Width of div</b> in pixels (default: auto)</th>
	   <td><input size=8 maxlength=4 type="text" name="div_width" value="<?php echo get_option('div_width'); ?>" />px -- leave blank for auto-sizing</td>
	   </tr>

	   <tr valign="top">
	   <th scope="row"><b>Font Size</b> in pixels (default: 12)</th>
	   <td><input size=6 maxlength=2 type="text" name="font_size" value="<?php echo get_option('font_size'); ?>" />px</td>
	   </tr>

	   <tr valign="top">
	   <th scope="row"><b>Line Height</b> in pixels (default: 14)</th>
	   <td><input size=6 maxlength=2 type="text" name="line_height_px" value="<?php echo get_option('line_height_px'); ?>" />px</td>
	   </tr>

	   <tr valign="top">
	   <th scope="row"><b>Header &amp; Info Postion</b> (default: bottom)</th>
	   <td>

<?php
$posit = get_option('info_position');
?>

		<input type=radio name="info_position" value="T" <?php if ($posit === "T"){echo " CHECKED";} ?> /> Top
		<input type=radio name="info_position" value="B" <?php if ($posit === "B"){echo " CHECKED";} ?> /> Bottom
		<input type=radio name="info_position" value="N" <?php if ($posit === "N"){echo " CHECKED";} ?> /> None

		</td>
	   </tr>


    </table>
    
    <p class="submit">
	<input type="hidden" name="last_save_time" value="<?php echo $curr_date; ?>" />
<br>
    <input type="submit" class="button-primary" value="<?php _e('Save Changes') ?>" />
    </p>

</form>

<h2>Credits</h2>
	<li><a class=credits href="http://lawoftime.org/" title="Foundation for the Law of Time">Foundation for the Law of Time (FLT)</a></li>
	<li><a class=credits href="http://planetartnetwork.info/" title="Planet Art Network">Planet Art Network (PAN)</a></li>
	<li><a class=credits href="http://spacestationplaza.com/" title="Space Station Plaza Galactic Portal">Space Station Plaza (SSP)</a></li>
	<li><a class=credits href="http://anthonyfogleman.com/blog/wordpress-plugins/" title="Plugin author: Anthony Fogleman (Anka) Kin 139 Solar Storm">Plugins by Anka (kin 139)</a></li>
	<li><a class=credits href="http://www.wetvantijd.nl" title="Dutch translation: Juryt Abma Kin-243 Solar Night">Foundation for the Law of Time Netherlands</a></li>


</div>
<?php } ?>