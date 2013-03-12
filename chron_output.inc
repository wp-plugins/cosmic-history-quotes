<?php 

// chron_output.inc is the public plugin 
// activated where the shortcode is inserted

function start_chron() {

// Load a function file
	include_once('functions.inc');

// Path to files
	$path = "./wp-content/plugins/cosmic-history-quotes";

// Insert a css file
	wp_enqueue_style('cosmic-history-quotes-css', plugin_dir_url( __FILE__ ) . 'cosmic-history-quotes.css');

// Main Settings: Set defaults, change defaults
	$start_lang = get_option('starting_language'); if ($start_lang == ""){$start_lang = "en";}
	$text_color = get_option('text_color'); if ($text_color == ""){$text_color = "666";}
	$bg_color = get_option('background_color');
	$div_width_px = get_option('div_width');
	$font_size_px = get_option('font_size'); if ($font_size_px == ""){$font_size_px = 10;}
	$line_height_px = get_option('line_height_px'); if ($line_height_px == ""){$line_height_px = 14;}
	$info_position = get_option('info_position'); if ($info_position == ""){$info_position = B;}
// Add Ads 
	$permit_ads = get_option('permit_ads');

// Adjust Lang File to Current Setting
	 $curr_lang = $start_lang;

// Set a cookie
	if (isset($_GET[lang])){
		$curr_lang = $_GET[lang];
    }

if ($curr_lang === "en"){
	$title_text = "Cosmic History Quote"; $intro_text1 = " for"; $intro_text2 = "day"; $intro_text3 = "of Moon";
	$doot_text = "Day out of Time (July 25th)";
}

if ($curr_lang === "es"){
	$title_text = "Citas de la Historia Cósmica"; $intro_text1 = " por"; $intro_text2 = "dia"; $intro_text3 = "de Luna";
	$doot_text = "Día Fuera del Tiempo (25 julio)";
}

if ($curr_lang === "nl"){
	$title_text = "Kosmische Geschiedenis Citaat"; $intro_text1 = " voor"; $intro_text2 = "dag"; $intro_text3 = "van Maan";
	$doot_text = "Dag Buiten de Tijd (25 juli)";
}

// Assign filenames to vars
     $titles_filename = $curr_lang."_titles.txt";
     $data_filename = $curr_lang."_data.txt";

// Engage Output Buffer
	ob_start();
// Start outputting 


// Start main container
	echo " <DIV STYLE=\"";
	if ($bg_color === ""){} else {echo "background: #".$bg_color.";";}
	echo "width: ";
	if ($div_width_px < 50){echo "auto;";} else {echo $div_width_px."px;";}
	echo " padding: 2px;\">";


	echo " <DIV STYLE=\"color: #".$text_color."; font-size: ".$font_size_px."px;  line-height: ".$line_height_px."px;\">";

// Open Titles and Data Files into an array.
	$title_lines = file("$path/$titles_filename");
	$data_lines = file("$path/$data_filename");

// Get today's date
	$today_greg_month =  date("n"); // month numeral
	$today_greg_month_abbrev =  date("M"); // month numeral
	$today_greg_day =  date("j"); // day numeral without leading zeros

// Loop through our array, show HTML source as HTML source; and line numbers too.
     foreach ($data_lines as $line_num => $line) {

// Explode line
          $pieces = explode("_", $line);
		if (($pieces[0] === $today_greg_day)&&($pieces[1] === $today_greg_month)){

// Assign Vars to today's chronicle
			$this_moon 	= $pieces[2];
			$day_of_moon 	= $pieces[3];
			$text 		= $pieces[4];
			$ext_info 	= $pieces[5];

               // Deal with the Day out of Time
               if ($this_moon != 0){
               	$title_row = ($this_moon - 1);
               	$month_title = $title_lines[$title_row];
               } else { // it's the day out of time
               	$title_text = $doot_text;
               }

               $intro_output = "<div class=intro_section><a target=\"_BLANK\" href=\"http://lawoftime.org/\" title=\"Foundation for the Law of Time\">".htmlentities($title_text)."</a><br> ";
               $intro_output .= " $today_greg_month_abbrev $today_greg_day, $intro_text2 $day_of_moon $intro_text3 $this_moon, $month_title</i></div>";
               
               if ($info_position == "T"){echo "$intro_output <P>";}
               echo htmlentities($text);
               if ($info_position == "B"){echo "<P> $intro_output";}
			break;
		}
     }

echo "</div>";

// Get list of Language Files to verify which languages are available
	$txt_files = glob("$path/??_data.txt");
     foreach ($txt_files as $file) {
		$file = str_replace($path, '', $file); 
		$file = str_replace('/', '', $file); 
		$file = str_replace('.txt', '', $file);
		$pieces = explode("_", $file);
		$lang_name[] = $pieces[0];
	}
	$langs = array_unique($lang_name);

     foreach ($langs as $lang) {
		if ($lang != $curr_lang){$lang = "<a class=langa title=\"Change language to $lang\" href=\"?lang=$lang\">$lang</a>";}
		if (!isset($lang_string)){$lang_string = "$lang";} else {$lang_string .= " $lang";}
	}

// Provides: <body text='black'>
//	$lang_string = str_replace($curr_lang, " $curr_lang ", "$lang_string");

//	echo "</div>";

if ($permit_ads === "YES"){
	echo "<div class=ads>";
	echo "<a target=\"_BLANK\" href=\"http://lawoftime.org/\" title=\"Foundation for the Law of Time\">FLOT</a>";
	echo " ";
	echo "<a target=\"_BLANK\" href=\"http://www.planetartnetwork.info/\" title=\"Planet Art Network\">PAN</a>";
	echo " ";
	echo "<a target=\"_BLANK\" href=\"http://spacestationplaza.com/\" title=\"Space Station Plaza\">SSP</a>";
//	echo "<a target=\"_BLANK\" href=\"http://anthonyfogleman.com/blog/cosmic-history-quotes-wp-plugin/\" title=\"Cosmic History Quotes Plugin Home Page\">ARF</a>";
	echo "</div>";

}

	echo "<div class=langleft>$lang_string</div>\n";

// End main containers
	echo "</div>";


// Clear all 
	echo "<div style=clear:both;></div>";

// Stop Storing Output ...
	$content = ob_get_contents();

// End Output Buffer
	ob_end_clean();

// Send Output
	return $content;
}

?>