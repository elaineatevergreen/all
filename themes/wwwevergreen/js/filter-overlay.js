jQuery(document).ready(function($) {
	
	//console.log("is this thing on?");
	
	var dialog;
	
	//make button to show form
	
	$("#views-exposed-form-catalog-page").before("<button id='open-filter'>Search</button>");
	
	//open dialog
	
	dialog = $( "#views-exposed-form-catalog-page" ).dialog({
      autoOpen: false,
      title: 'Filter the Catalog', //this should probably come from the actual form title? which means there should be one
      height: 'auto',
      width: 600,
      modal: true
    });
    
    // set the button to open the form
    $( "#open-filter" ).on( "click", function() {
      dialog.dialog( "open" );
      event.preventDefault();
    });
	
	
});