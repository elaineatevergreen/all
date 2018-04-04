jQuery(document).ready(function($) {
	
	console.log("is this thing on?");
	
	var dialog;
	
	//hide form
	
	//make button to show form
	
	$("#views-exposed-form-catalog-page").before("<button id='open-filter'>Search</button>");
	
	//open dialog
	
	dialog = $( "#views-exposed-form-catalog-page" ).dialog({
      autoOpen: false,
      height: 400,
      width: 350,
      modal: true
    });
    
    // set the button to open the form
    $( "#open-filter" ).button().on( "click", function() {
      dialog.dialog( "open" );
      event.preventDefault();
    });
	
	
});