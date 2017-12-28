<?php
/*

This code merges together two XML feeds: the campus directory and the faculty directory.
Primarily, it just applies two different XSLT files to the original XML.	
	
*/
	
//make sure output is served as XML
header('Content-Type: application/xml');

//hide unless debugging
//error_reporting(E_ALL); ini_set('display_errors', 1); 

// Load the faculty directory XML
$facultySource = new DOMDocument;
$facultySource->load('http://my.evergreen.edu/public/faculty_for_web');

// Load and configure the first transformer
$converter = new DOMDocument;
$converter->load('faculty-to-directory-format.xsl');
$proc1 = new XSLTProcessor;
$proc1->importStyleSheet($converter); // attach the xsl rules

// do the transformation
$facultyTransformed = $proc1->transformToXML($facultySource);
//print_r($facultyTransformed);

// Turn the string created in the transformation into actual XML
$faculty = new DOMDocument;
$faculty->loadXML($facultyTransformed);
//print_r($faculty);


// Load the campus directory XML
$directorySource = new DOMDocument;
$directorySource->load('https://my.evergreen.edu/forena/xml/mybanner.directory.person_export');

// Append the transformed faculty XML into the campus XML
$people = $faculty->getElementsByTagName('person');
foreach($people as $p) {
	$append = $directorySource->importNode($p,true);
	$directorySource->documentElement->appendChild($append);
};

//print_r($directorySource);
//echo $directorySource->saveXML();

// now use a second stylesheet to merge people in the new XML

// Load and configure the transformer
$merger = new DOMDocument;
$merger->load('merge-people.xsl');
$proc2 = new XSLTProcessor;
$proc2->importStyleSheet($merger); // attach the xsl rules

// do the transformation
$mergedDirectory = $proc2->transformToXML($directorySource);
//print_r($mergedDirectory);

//turn the string into XML, because that's a thing.
$directory = new DOMDocument;
$directory->loadXML($mergedDirectory);

//output the XML for use in Drupal!
echo $directory->saveXML();
?>