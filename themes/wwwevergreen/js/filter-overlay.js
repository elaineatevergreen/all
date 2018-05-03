jQuery(document).ready(function($) {
	
	//console.log("is this thing on?");
	
	var dialog;
	
	//make button to show form
	
	$("#set-filter-button").replaceWith("<button id='open-filter'><img src='/sites/all/themes/wwwevergreen/images/icons/dark/cog.svg'/> Set Filter</button>");
	
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