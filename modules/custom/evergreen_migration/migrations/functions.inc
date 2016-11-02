<?php 
    //this function cleans up a BUNCH of issues with the exported HTML from Cascade.
function tidyBlobs($row) {
	    //drush_print_r($row);
	    
	    // fix some of Cascade's linking methods
	    $replace[] = array('//evergreen.edu - old design','http://evergreen.edu');
	    $replace[] = array('site://','http://');
	    
	    // fix any outstanding bad links
	    $replace[] = array('_archive','');
	    $replace[] = array('_draft','');
	    
	    // just get rid of target=blank
	    $replace[] = array('target="_blank"','');
	    
	    // fix double-escaping problem
	    $replace[] = array("&amp;", "&");
	    
	    //do all the string replacing
	    foreach($replace as $r) {
		    $row = str_ireplace($r[0], $r[1], $row);
	    };
	    
	    /* 
		    fixing links to the old contact forms 
		    
		    old formats:
		    http://forms.evergreen.edu/contact?e=username@evergreen.edu&u=http://evergreen.edu/give/home
		    http://www.evergreen.edu/scripts/contact.php?sm=username&sub=Email%20from%20Native%20Programs%20Site%20&title=Contact%20Site%20Manager
		    
		    new format:
		    mailto:username@evergreen.edu ?

		    
	    */
	    
	    $contactforms = '/(?:(?:http:\/\/forms\.evergreen\.edu\/contact\?e=)|(?:http:\/\/www\.evergreen\.edu\/scripts\/contact\.php\?sm=))([a-z]+)(?:(?:@evergreen\.edu&u)|(?:&sub=))(?:[^"]+)/';
	    $mailto = 'mailto:$1@evergreen.edu';
		$row = preg_replace($contactforms,$mailto,$row);
	    
	    
	    /*
		  fixing links to non-HTML files...
		  
		  1) http://www.evergreen.edu/directory/structure/file.ext
		  2) directory/structure/file.ext
		  
		  strip http://evergreen.edu and http://www.evergreen.edu
		  
		  append "sites/all/default/files" to directory/structure/file.ext
		*/
		  
		$filepath='/((?:href)|(?:src))="(?:http:\/\/(?:www.)*evergreen.edu\/)*(?:\.\.\/)*([^"]+\.(?!htm).{1,5})"/';
		$drupalfilepath = '$1="/sites/default/files/$2"';
	    $row = preg_replace($filepath,$drupalfilepath,$row);
	    //rewrite _inc icon urls
	    $row = str_ireplace("/sites/default/files/_inc/", "/sites/all/themes/wwwevergreen/images/", $row);
	    
	    //remove .htm and .html from internal links
	    $internallink = '/((?:href)="(?:http:\/\/(?:www.)*evergreen.edu\/)*(?:\.\.\/)*([^"]+))\.(htm[l]*)"/';
	    $dropext = '$1"';
	    $row = preg_replace($internallink, $dropext, $row);
	    
	    
	    return $row;
	    
    }