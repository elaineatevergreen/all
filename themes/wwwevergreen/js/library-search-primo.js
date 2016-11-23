//JS provided by the vendor.
//appears to add a value to a hidden field, then submit the form
function searchPrimo() {

//added to code based on email thread forwarded by Andrea Heisel on August 15 - emn
//this is the actual line of code that was sent:
//string = string.replace(/[&\/\\#,+()$~%.'":*?<>{}]/g, '');
//I'm just guessing the rest based on email etc.
//new code:
var primoQueryTempVal = document.getElementById("primoQueryTemp").value;
primoQueryTempVal = primoQueryTempVal.replace(/[&\/\\#,+()$~%.'":*?<>{}]/g, '');


//original line of code, btw:
//        document.getElementById("primoQuery").value = "any,contains," + document.getElementById("primoQueryTemp").value;

//replaced by:
document.getElementById("primoQuery").value = "any,contains," + primoQueryTempVal;

        document.forms["searchForm"].submit();
}

//I'll be honest, I'm not sure what this does. maybe recognizes a "return/enter" keypress? -emn
function searchKeyPress(e) {
        if (typeof e == 'undefined' && window.event) { e = window.event; }
        if (e.keyCode == 13) {
                document.getElementById('go').click();
        }
}

//change the placeholder text in the search box based on the value of the "Search in" dropdown. -emn
$(document).ready(function(){
        
        //set up the messages for each selection
        var allPlaces = [];
        allPlaces['tesc_alma_summit'] = 'Books, journals, and media';
        allPlaces['tesc_alma'] = 'Books, journals, and media';
        allPlaces['everything'] = 'Books, articles, media and more';
        
        //when the selection has changed, change the placeholder text
        $('select#search_scope').change(
                function() { 
                        var place = $('select#search_scope').val();
                        $('#primoQueryTemp').attr('placeholder',allPlaces[place]);
                });

});