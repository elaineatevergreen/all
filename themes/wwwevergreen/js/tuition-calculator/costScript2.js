/*
Simple program to read in CSV for tuition & fees and then output relevant data.
USAGE: have a div with id "'Tuition-Box'" on the home html

Table of Contents for future editing:
Format function             line 25
Array read in values        line 64
Table HTML                  line 82
Onload user inteface HTML   line 111
Current CSV's to use        line 117
Data Processing             line 149
Delay time                  line 157
Graduate credit max         line 177




Array = Index 4-22 Regular Year Pricing, Index 27-45 Summer Quarter
*/

//global variable for imported CSV
var fullData = [];

/* -------------------------------------Function to format into currency----------------------------------------*/
function format(n, currency) {
  val = parseFloat(n).toFixed(2);
  return currency + ' ' + val.replace(/./g, function (c, i, a) {
    return i > 0 && c !== '.' && (a.length - i) % 3 === 0 ? ',' + c : c;
  });
}

/* -------------------------------------Function to format an HTML table from our data----------------------------------------*/
function createTable(costRate, cred) {
  /*This function creates the HTML tables from 2 values. It takes the costRate which is a number to offset the array,
    and cred, which is the number of credits + an offset to make it match up with the CSV*/
  tuitionType = '';
  if (costRate === 0) {
    // Cost Rate 0 means undergrad Resident
    tuitionType += 'Resident Undergraduate ';
  } else if (costRate === 1) {
    //cost rate 1 means undergrad non-resident
    tuitionType += 'Non-Resident Undergraduate ';
  } else if (costRate === 2) {
    // costrate 2 means grad resident
    tuitionType += 'Resident Graduate ';
  } else if (costRate === 3) {
    // cost rate 3 means grad non-resident
    tuitionType += 'Non-Resident Graduate ';
  }

  var summerOffset = 23;// Summer values start at line 23
  var summerBool = true;
  if (parseFloat(fullData[cred+summerOffset][costRate + 5]) <= 1) {// if summer total cost is less than 1 do not display
    summerBool = false;
  }
  var gradBool = false;
  if (costRate >= 2) {
    //graduates take health fees at 8 credits instead of 10 so offset health by 2
    var gradOffset = 2;
    gradBool = true;
  }

  //array sections to variables.
  var tCredits              = fullData[cred][9];
  var tSummerCredits        = fullData[cred+summerOffset][9];
  var tTuition              = fullData[cred][costRate + 5];
  var tSummerTuition        = fullData[cred+summerOffset][costRate+5];
  var tHealth               = gradBool ? fullData[cred+gradOffset][10] : fullData[cred][10];//terniery operator if gradbool then a else b
  var tSummerHealth         = fullData[cred+summerOffset][10];
  var tTransit              = fullData[cred][11];
  var tSummerTransit        = fullData[cred+summerOffset][11];
  var tCleanEnergy          = fullData[cred][12];
  var tSummerCleanEnergy    = fullData[cred+summerOffset][12];
  var tCabFee               = fullData[cred][13];
  var tSummerCabFee         = fullData[cred+summerOffset][13];
  var tWashPirg             = fullData[cred][14];
  var tSummerWashPirg       = fullData[cred+summerOffset][14];
  var tGSU                  = fullData[cred][15];
  var tSummerGSU            = fullData[cred+summerOffset][15];
  var tTotal                = fullData[cred][costRate];
  var tSummerTotal          = fullData[cred+summerOffset][costRate];

  //Table HTML Formatting, refer to top of document for what the array indexes are.
  var myTable = '<table>';
  myTable += '<caption>' + tuitionType + ' Quarterly Tuition &amp; Fees</caption>';
  myTable += '<thead><tr><th>&nbsp;</th><th>Per Quarter</th><th>Three Quarters (F-S)</th>';
  // if there is no value in summer tuition do not display summer costs.
  if (summerBool) {   myTable += '<th>Summer</th></tr></thead>';  }                                             else {    myTable += '</tr></thead>';  }
  myTable += '<tr><th>Credits</th><td>'                 + tCredits + '</td><td>' + 3 * tCredits + '</td>';  
  if (summerBool) {    myTable += '<td>'                + tSummerCredits + '</td></tr>';  }                     else {    myTable += '</tr>';  }
  myTable += '<tr><th>Tuition</th><td>'                 + format(tTuition, '$') + '</td><td>' + format(3 *      tTuition, '$') + '</td>';  
  if (summerBool) {    myTable += '<td>'                + format(tSummerTuition, '$') + '</td></tr>';  }        else {    myTable += '</tr>';  }
  myTable += '<tr><th>Health</th><td>'                  + format(tHealth, '$') + '</td><td>' + format(3 *       tHealth, '$') + '</td>';  
  if (summerBool) {    myTable += '<td>'                + format(tSummerHealth, '$') + '</td></tr>';  }         else {    myTable += '</tr>';  }
  myTable += '<tr><th>Transit &amp; Shuttle</th><td>'   + format(tTransit, '$') + '</td><td>' + format(3 *      tTransit, '$') + '</td>';  
  if (summerBool) {    myTable += '<td>'                + format(tSummerTransit, '$') + '</td></tr>';  }        else {    myTable += '</tr>';  }
  myTable += '<tr><th>Clean Energy</th><td>'            + format(tCleanEnergy, '$') + '</td><td>' + format(3 *  tCleanEnergy, '$') + '</td>';  
  if (summerBool) {    myTable += '<td>'                + format(tSummerCleanEnergy, '$') + '</td></tr>';  }    else {    myTable += '</tr>';  }
  myTable += '<tr><th>CAB Fee</th><td>'                 + format(tCabFee, '$') + '</td><td>' + format(3 *       tCabFee, '$') + '</td>';  
  if (summerBool) {    myTable += '<td>'                + format(tSummerCabFee, '$') + '</td></tr>';  }         else {    myTable += '</tr>';  }
  myTable += '<tr><th>WashPIRG (optional)</th><td>'     + format(tWashPirg, '$') + '</td><td>' + format(3 *     tWashPirg, '$') + '</td>';  
  if (summerBool) {    myTable += '<td>'                + format(tSummerWashPirg, '$') + '</td></tr>';  }       else {    myTable += '</tr>';  }
  myTable += '<tr><th>GSU (optional)</th><td>'          + format(tGSU, '$') + '</td><td>' + format(3 *          tGSU, '$') + '</td>';  
  if (summerBool) {    myTable += '<td>'                + format(tSummerGSU, '$') + '</td></tr>';  }       else {    myTable += '</tr>';  } 
  myTable += '<tfoot><tr><th>Total</th><td>'            + format(tTotal, '$') + '</td><td>' + format(3 *        tTotal, '$') + '</td>';  
  if (summerBool) {    myTable += '<td>'                + format(tSummerTotal, '$') + '</td></tr></tfoot>';  }  else {    myTable += '</tr></tfoot>';  }
  myTable += '</table>';
  myTable += '<p><strong>&ast;&ast; This chart is for Fall/Winter/Spring quarters only. Summer quarter tuition information is usually available by the end of March.</strong></p>';
  document.getElementById('tuitionTable').innerHTML = myTable;  // prints myTable into the HTML in the div 'tuitionTable'
}
//End table building section


  /* ------------------------------------- HTML on page load ----------------------------------------*/
jQuery(document).ready(function ($) {//Following string contains all of the html displayed on the page before the user does anything.
  document.getElementById('Tuition-Box').innerHTML = '<h2>Calculate Tuition &amp; Fees</h2><form action="" name="studentStatus"><p><label for="selCSV">Academic Year:</label>    '+
  '<select id="selCSV"><option value="-1" selected="selected">Please Select Option</option>'+
  '<option value="1718AdjustedGradHealthFee.csv">2017-18</option></select>'+
  '</p><p><label for="creditCount">Number of credits:</label> <select id="creditCount" id="changed">'+
  '<option value="-1">Please Choose Credits</option><option value="2">2</option><option value="3">3</option><option value="4">4</option><option value="5">5</option><option value="6">6</option><option value="7">7</option><option value="8">8</option><option value="9">9</option><option value="10">10</option><option value="11">11</option><option value="12">12</option><option value="13">13</option><option value="14">14</option><option value="15">15</option><option value="16">16</option><option value="17">17</option><option value="18">18</option><option value="19">19</option><option value="20">20</option></select>   </p>'+
  '<p><label for="resident">Resident or Non-resident:</label> <select id="resident"><option value="-1" selected="selected">Please Select Option</option><option value="0">Resident</option><option value="1">Non-resident</option></select>   </p>'+
  ' <p><label for="graduate">Undergraduate or Graduate:</label> <select id="graduate"><option value="-1" selected="selected">Please Select Option</option><option value="0">Undergraduate</option><option value="2">Graduate</option></select>'+
  '   </p> </form><button  class="prime" onclick="clickFunction()">Calculate</button><div id="tuitionTable"></div>';
});
function clickFunction() {
  /* -------------------------------------csv read in to fields array. ----------------------------------------*/
  
  
  jQuery(document).ready(function ($) {
    var CSV = "notdefined";
    if(CSV == "notdefined" ){
        CSV = document.getElementById('selCSV');
        CSV = CSV.options[1].value; 
        CSV = "/sites/all/themes/wwwevergreen/js/tuition-calculator/" + CSV;
        //console.log(CSV);
        //gets file name from selected csv 
        $.ajax({
          type: 'GET',
          url: CSV,
          // The name of the CSV currently being used.
          dataType: 'text',
          error: function () {
            document.getElementById('tuitionTable').innerHTML = '<p>The tuition and fee listing could not be loaded.</p>';
          },
          success: function (data) {
            processData(data);
          }
        });
    }
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
    /* -------------------------------------Function to prepare selected values to find the information in CSV to use ----------------------------------------*/
    setTimeout(function () {
      //This timeout makes sure that the document can be loaded in time
      callBack();
    }, 5);
    //50 ms to wait before performing contained operations
    function callBack() {
      var credits = document.getElementById('creditCount');
      var graduate = document.getElementById('graduate');
      var resident = document.getElementById('resident');
      if (parseInt(credits.options[credits.selectedIndex].value) > -1 && parseInt(graduate.options[graduate.selectedIndex].value) > -1 && parseInt(resident.options[resident.selectedIndex].value) > -1) {//checks to make sure options were selected
        var selectionCr = parseInt(credits.options[credits.selectedIndex].value);
        //We later add 2 to this because of the 2 rows of formatting information in the csv
        var selectionGr = parseInt(graduate.options[graduate.selectedIndex].value);
        var selectionRe = parseInt(resident.options[resident.selectedIndex].value);
        var costRow = selectionGr + selectionRe;
        //cost row changes to the appropriate offset for which type of tuition the student will use, will reinititialize
        if (selectionGr === 2 && selectionCr > 16) {
          createTable(costRow, 18);
          // 18 because of the +2 offset, in the case graduates become able to take 16+ credits comment out this if statement and move the else information outside of the if.
          document.getElementById('tuitionTable').innerHTML = '<p>Graduates may only take up to 16 credits.</p>' + document.getElementById('tuitionTable').innerHTML;  // append message to beginning of table
        } else {
          createTable(costRow, selectionCr + 2);  //Create a table with the value of credits selected (+2 for the offset)
        }
      } else {
        document.getElementById('tuitionTable').innerHTML = '<p>Please make sure all fields are selected.</p>';
      }
    }
  });
};