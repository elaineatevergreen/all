/*
Simple program to read in CSV for tuition & fees and then output relevant data.
Script originally written by Gavin Plesko, 2016-17.

To add this to a page, create a div with the id="Tuition-Box". 
	- Use class="box" to make it look nice.
	- Put in some default text for non-JS visitors and for editing in Drupal WYSIWYG.
To add this to a new DRUPAL node, you also need to update the related Context.

Updating a year? Go to lines 58-59 to edit.
Developing locally? Check out lines 75 and 97
Adding a fee? Go to line 181 to add math and line 31 to add HTML.
*/

//initialize global variable for imported CSV
var fullData = [];

/* -- Function to format into currency -- */
function format(n, currency) {
  val = parseFloat(n).toFixed(2);
  return currency + ' ' + val.replace(/./g, function (c, i, a) {
    return i > 0 && c !== '.' && (a.length - i) % 3 === 0 ? ',' + c : c;
  });
}

/* -- Function to format an HTML table from our data -- */
function createTable(tuitionType, summerBool, Credits, summerCredits, Tuition, summerTuition, Health, summerHealth, Transit, summerTransit, CleanEnergy, summerCleanEnergy, CabFee, summerCabFee, WashPirg, summerWashPirg, Total, summerTotal) {
  //To edit format, copy section after "myTable =" into text editor, replace all " with newline, and prettify code 
  var myTable = '';
  if (summerBool) {   myTable = "<table>    <caption>" + tuitionType + 
    "</caption><thead><tr><th>&nbsp;</th><th>Per Quarter</th><th>Three Quarters (F-S)</th><th>Summer</th></tr></thead><tbody>"+
    "<tr><th>Credits</th><td>" + Credits + "</td><td>" + Credits * 3 + "</td><td>" + summerCredits + "</td></tr>"+
    "<tr><th>Tuition</th><td>" + format( Tuition , '$') + "</td><td>" + format( Tuition * 3 , '$') + "</td><td>" + format(  summerTuition, '$') + "</td></tr>"+
    "<tr><th>Health</th><td>" + format( Health , '$') + "</td><td>" + format( Health * 3 , '$') + "</td><td>" + format(  summerHealth, '$') + "</td></tr>"+
    "<tr><th>Transit &amp; Shuttle</th><td>" + format( Transit , '$') + "</td><td>" + format( Transit* 3 , '$') + "</td><td>" + format(  summerTransit, '$') + "</td></tr>"+
    "<tr><th>Clean Energy</th><td>" + format( CleanEnergy , '$') + "</td><td>" + format( CleanEnergy * 3 , '$') + "</td><td>" + format(  summerCleanEnergy, '$') + "</td></tr>"+
    "<tr><th>CAB Fee</th><td>" + format( CabFee , '$') + "</td><td>" + format( CabFee * 3 , '$') + "</td><td>" + format(  summerCabFee, '$') + "</td></tr>"+
    "<tr><th>WashPIRG (optional)</th><td>" + format( WashPirg , '$') + "</td><td>" + format( WashPirg * 3 , '$') + "</td><td>" + format(  summerWashPirg, '$') + "</td></tr>  "+  
    "</tbody><tfoot><tr><th>Total</th><td>" + format( Total , '$') + "</td><td>" + format( Total * 3 , '$') + "</td><td>" + format(  summerTotal, '$') + "</td></tr></tfoot></table>";
  }else{//no summer 
    myTable = "<table><caption>" + tuitionType + "</caption><thead><tr><th>&nbsp;</th><th>Per Quarter</th><th>Three Quarters (F-S)</th></tr></thead><tbody>"+
    "<tr><th>Credits</th><td>" + Credits + "</td><td>" + Credits * 3 + "</td></tr>"+
    "<tr><th>Tuition</th><td>" + format( Tuition , '$') + "</td><td>" + format( Tuition * 3 , '$') + "</td></tr>"+
    "<tr><th>Health</th><td>" + format( Health , '$') + "</td><td>" + format( Health * 3 , '$') + "</td></tr>"+
    "<tr><th>Transit &amp; Shuttle</th><td>" + format( Transit , '$') + "</td><td>" + format( Transit* 3 , '$') + "</td></tr>"+
    "<tr><th>Clean Energy</th><td>" + format( CleanEnergy , '$') + "</td><td>" + format( CleanEnergy * 3 , '$') + "</td></tr>"+
    "<tr><th>CAB Fee</th><td>" + format( CabFee , '$') + "</td><td>" + format( CabFee * 3 , '$') + "</td></tr>"+
    "<tr><th>WashPIRG (optional)</th><td>" + format( WashPirg , '$') + "</td><td>" + format( WashPirg * 3 , '$') + "</td></tr>"+  
    "</tbody><tfoot><tr><th>Total</th><td>" + format( Total , '$') + "</td><td>" + format( Total * 3 , '$') + "</td></tr></tfoot></table>";
  }
  document.getElementById('tuitionTable').innerHTML = myTable;  // prints myTable into the HTML in the div 'tuitionTable'
}
//End table building section


  /* --  HTML on page load -- */
jQuery(document).ready(function ($) {//Following string contains all of the html displayed on the page before the user does anything.
  var years = ["2016-17","2017-18"];
  var yearLinks = ["1617.csv","1718.csv"];

  document.getElementById('Tuition-Box').innerHTML = '<h2>Calculate Tuition &amp; Fees</h2><form action="" name="studentStatus"><p><label for="selCSV">Academic Year:</label>    '+
  '<select id="selCSV"><option value="-1" selected="selected">Please Select Option</option>'+
  '<option value="'+yearLinks[0]+'">'+years[0]+'</option><option value="'+yearLinks[1]+'">'+years[1]+'</option></select>'+
  '</p><p><label for="creditCount">Number of credits:</label> <select id="creditCount" id="changed">'+
  '<option value="-1">Please Choose Credits</option><option value="2">2</option><option value="3">3</option><option value="4">4</option><option value="5">5</option><option value="6">6</option><option value="7">7</option><option value="8">8</option><option value="9">9</option><option value="10">10</option><option value="11">11</option><option value="12">12</option><option value="13">13</option><option value="14">14</option><option value="15">15</option><option value="16">16</option><option value="17">17</option><option value="18">18</option><option value="19">19</option><option value="20">20</option></select>   </p>'+
  '<p><label for="resident">Resident or Non-resident:</label> <select id="resident"><option value="-1" selected="selected">Please Select Option</option><option value="0">Resident</option><option value="1">Non-resident</option></select>   </p>'+
  '<p><label for="graduate">Undergraduate or Graduate:</label> <select id="graduate"><option value="-1" selected="selected">Please Select Option</option><option value="0">Undergraduate</option><option value="2">Graduate</option></select>'+
  '</p></form><button  class="prime" onclick="clickFunction()">Calculate</button><div id="tuitionTable"></div>';
  /* -- Preload csv files -- */
  //prepares each CSV file for use.
  /*for(i in yearLinks){
    //gets file name from selected csv 
    $.ajax({
      type: 'GET',
      url: "/sites/all/themes/wwwevergreen/js/tuition-calculator/" + yearLinks[i],
      //uncomment the following line if developing locally.
	  //url: yearLinks[i],
      // The name of the CSV currently being used.
      dataType: 'text',
      error: function () {
       console.log(yearLinks[i] + " failed to load.");
      },
      success: function (data) {
        //processData(data);
      }
    });*/
  }
  
});
/* -- csv read in to fields array. -- */
function clickFunction() {
	jQuery(document).ready(function ($) {
		var CSV;
		var stringOfCSV;
		if(CSV != document.getElementById('selCSV').options[document.getElementById('selCSV').selectedIndex].value ){
			CSV = document.getElementById('selCSV');
			CSV = CSV.options[CSV.selectedIndex].value;
			//comment out the following line if developing locally
			CSV = "/sites/all/themes/wwwevergreen/js/tuition-calculator/" + CSV,
			console.log(CSV);
			$.ajax({
				type: 'GET',
				url: CSV,
				// The name of the CSV currently being used.
				dataType: 'text',
				error: function () {
					document.getElementById('tuitionTable').innerHTML = '<p>The tuition and fee listing could not be loaded.</p>';
      			},
	  			success: function (data) {
	  				stringOfCSV = data;
      			}
    		}); //end ajax
    		processData(stringOfCSV);
    	} //end check for existence of CSV
		var year = document.getElementById('selCSV').options[document.getElementById('selCSV').selectedIndex].text;
		searchData(year);
	}); //end jquery document ready
};
/* -- Format data --*/
function processData(info) {
  var theData = info;
  var row = theData.split(/[\n\r]/g);// Splits read in file at each line break
  var fields = [];
  for (var i = 0 * 0; i < row.length; ++i) {//Loop through each Line of the CSV
    var temp = row[i].split(',');// Break each value at current line by comma
    fields[i] = temp;
  }
  fullData = fields;
}
/* -- Find user requested data -- */
function searchData(year) {
  var formatOffset = 2; //there are 2 lines of boilerplate on the csv.
  var credits = document.getElementById('creditCount');
  var graduate = document.getElementById('graduate');
  var resident = document.getElementById('resident');
  if (parseInt(credits.options[credits.selectedIndex].value) > -1 && parseInt(graduate.options[graduate.selectedIndex].value) > -1 && parseInt(resident.options[resident.selectedIndex].value) > -1) {//checks to make sure options were selected
    var selectionCr = parseInt(credits.options[credits.selectedIndex].value);
    var selectionGr = parseInt(graduate.options[graduate.selectedIndex].value);
    var selectionRe = parseInt(resident.options[resident.selectedIndex].value);
    var costRow = selectionGr + selectionRe;
    //cost row changes to the appropriate offset for which type of tuition the student will use, will reinititialize
    if (selectionGr === 2 && selectionCr > 16) {
      grabData(costRow, 16+formatOffset); // display 16 credits if over 16 are selected for graduate
      document.getElementById('tuitionTable').innerHTML = '<p>Graduate students may only take up to 16 credits.</p>' + document.getElementById('tuitionTable').innerHTML;  // append message to beginning of table
    } else {
      grabData(costRow, selectionCr + formatOffset, year);  //get data from csv and then create table
    }
  } else {
    document.getElementById('tuitionTable').innerHTML = '<p>Please make sure all fields are selected.</p>';
  }
}
/* -- Assign found data to variables -- */
function grabData(costRate, cred, year){
   /*T his function takes the costRate which is a number to offset the array, and cred, which is the number of credits + a formatting offset to make it match up with the CSV */
  var tuitionType = year;
  if (costRate === 0) {
    // Cost Rate 0 means undergrad Resident
    tuitionType += ' Resident Undergraduate ';
  } else if (costRate === 1) {
    //cost rate 1 means undergrad non-resident
    tuitionType += ' Non-Resident Undergraduate ';
  } else if (costRate === 2) {
    // costrate 2 means grad resident
    tuitionType += ' Resident Graduate ';
  } else if (costRate === 3) {
    // cost rate 3 means grad non-resident
    tuitionType += ' Non-Resident Graduate ';
  }
  var gradOffset = 0;
  var summerOffset = 23;// Summer values start at line 23
  var summerBool = true;
  if (parseFloat(fullData[cred+summerOffset][costRate + 5]) <= 1) {// if summer tuition cost is less than 1 do not display
    summerBool = false;
  }
  var gradBool = false;
  if (costRate >= 2) {//graduates take health fees at 8 credits instead of 10 so offset health by 2
    gradOffset = 2;
    gradBool = true;
  }
  //array sections to variables.
  var Credits  = fullData[cred][9];
  var summerCredits= fullData[cred+summerOffset][9];
  var Tuition  = fullData[cred][costRate + 5];
  var summerTuition= fullData[cred+summerOffset][costRate + 5];
  var Health   = gradBool ? fullData[cred+gradOffset][10] : fullData[cred][10];//terniery operator if gradbool then a else b
  var summerHealth = fullData[cred+summerOffset][10];
  var Transit  = fullData[cred][11];
  var summerTransit= fullData[cred+summerOffset][11];
  var CleanEnergy  = fullData[cred][12];
  var summerCleanEnergy    = fullData[cred+summerOffset][12];
  var CabFee   = fullData[cred][13];
  var summerCabFee = fullData[cred+summerOffset][13];
  var WashPirg = fullData[cred][14];
  var summerWashPirg       = fullData[cred+summerOffset][14];
  //To add any more fees in the future, add them to the csv to the right of current filled values, make them line up with other fees and credits then modify create table. 
  //example fee::
  //var GCU                 = fullData[cred][15];
  //var summerGCU                 = fullData[cred+summerOffset][15];
  var Total    = fullData[cred][costRate];
  var summerTotal  = fullData[cred+summerOffset][costRate];
  createTable(tuitionType, summerBool, Credits, summerCredits, Tuition, summerTuition, Health, summerHealth, Transit, summerTransit, CleanEnergy, summerCleanEnergy, CabFee, summerCabFee, WashPirg, summerWashPirg, Total, summerTotal);
}