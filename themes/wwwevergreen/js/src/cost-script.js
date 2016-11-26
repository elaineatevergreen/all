/*
Simple program to read in CSV for tuition & fees and allow users to add in other cost of living values.
In the case a fee needs to be added or removed, line 95 needs to be updated from 15 to however many values there should be, also edit the table on line 61
Update: Because graduates are feed for health at 8 credits instead of 10 credits there is a chunk of little weird code. It is in the table creation spot, and is commented thoroughly. This needs to be fixed if graduates are made able to take more than 16 credits, and should be replaced by making a new column in the csv and using that instead of the current solution. This will also need to be changed if Health fee starts applying in summer.
    ctrl+f gradBool to find where this is in effect.

Table of Contents for future editing:
HTML into table - 71
CSV Read in - 106
Graduate Credits Special Condition - 147
MS to wait before loading new table - 133
Function to prepare selected values to find the information in CSV to use - 130

Fields array = Index 4-22 Regular Year Pricing, Index 27-45 Summer Quarter
Fields child array:
Index 0 = Resident Undergraduate total
Index 1 = Non-Resident Undergraduate total
Index 2 = Resident Graduate Total
Index 3 = Non-Resident Graduate Total
Index 4 = Total Fee
Index 5 = Resident Undergraduate Tuition
Index 6 = Non-Resident Undergraduate Tuition
Index 7 = Resident Graduate Tuition
Index 8 = Non-Resident Graduate Tuition
Index 9 = Number of Credits 
Index 10 = Health fee 
Index 11 = Transit fee
Index 12 = Energy fee
Index 13 = CAB fee
Index 14 = Washpirg fee
*/


//global variable for imported CSV
var fullData = [];

/* -------------------------------------Function to format into currency----------------------------------------*/
function format(n, currency) {
    val = parseFloat(n).toFixed(2);
    return currency + " " + val.replace(/./g, function(c, i, a) {
        return i > 0 && c !== "." && (a.length - i) % 3 === 0 ? "," + c : c;
    });
}
       
   /* -------------------------------------Function to format an HTML table from our data----------------------------------------*/
function createTable(costRate, cred){
    /*This function creates the HTML tables from 2 values. It takes the costRate which is a number to offset the array,
    and cred, which is the number of credits + an offset to make it match up with the CSV*/
    tuitionType ='';
    if (costRate === 0){// Cost Rate 0 means undergrad Resident
        tuitionType+='Resident Undergraduate ';
    }else if (costRate === 1){//cost rate 1 means undergrad non-resident
        tuitionType+='Non-Resident Undergraduate ';
    }else if (costRate === 2){// costrate 2 means grad resident
        tuitionType+='Resident Graduate ';
    }else if (costRate === 3){// cost rate 3 means grad non-resident
        tuitionType+='Non-Resident Graduate ';
    }
    var insideArray = fullData[cred];// this will make an array of values stored at the credit count
    var summerInsideArray = fullData[cred+23];// this does the same thing as insideArray but it has +23 to offset for the summer values.
    
    var summerBool = true;
    if (parseFloat(summerInsideArray[costRate+5])<=1){
        summerBool=false;
    }//console.log(insideArray); //uncomment for debugging
    var gradBool=false;
    if(costRate>=2){//graduates take health fees at 8 credits instead of 10 so offset health by 2
        var gradOffsetArray = fullData[cred+2];
        gradBool=true;
    }
    //Table HTML Formatting, refer to top of document for what the array indexes are.
    var myTable="<table>";
        myTable+="<caption>"+tuitionType+" Quarterly Tuition &amp; Fees</caption>";
        myTable+="<thead><tr><th>&nbsp;</th><th>Per Quarter</th><th>Three Quarters (F-S)</th>"; 
        if(summerBool){myTable+="<th>Summer</th></tr></thead>";}else{ myTable+="</tr></thead>";}// if there is no value in summer tuition do not display summer costs.
        myTable+="<tr><th>Credits</th><td>"+insideArray[9]+"</td><td>"+(3*(insideArray[9]))+"</td>";
        if(summerBool){myTable+="<td>"+summerInsideArray[9]+"</td></tr>";}else{ myTable+="</tr>";}
        myTable+="<tr><th>Tuition</th><td>"+format(insideArray[costRate+5],'$')+"</td><td>"+format((3*insideArray[costRate+5]), '$')+"</td>";
        if(summerBool){myTable+="<td>"+format(summerInsideArray[costRate+5],'$')+"</td></tr>";}else{ myTable+="</tr>";}
        if(gradBool){//if graduate use grad offset
            myTable+="<tr><th>Health</th><td>"+format(gradOffsetArray[10],'$')+"</td><td>"+format((3*gradOffsetArray[10]), '$')+"</td>";
            if(summerBool){myTable+="<td>"+format(summerInsideArray[10],'$')+"</td></tr>";}else{ myTable+="</tr>";}
        }else{
            myTable+="<tr><th>Health</th><td>"+format(insideArray[10],'$')+"</td><td>"+format((3*insideArray[10]), '$')+"</td>";
            if(summerBool){myTable+="<td>"+format(summerInsideArray[10],'$')+"</td></tr>";}else{ myTable+="</tr>";}
        }
        myTable+="<tr><th>Transit &amp; Shuttle</th><td>"+format(insideArray[11],'$')+"</td><td>"+format((3*insideArray[11]), '$')+"</td>";
        if(summerBool){myTable+="<td>"+format(summerInsideArray[11],'$')+"</td></tr>";}else{ myTable+="</tr>";}
        myTable+="<tr><th>Clean Energy</th><td>"+format(insideArray[12],'$')+"</td><td>"+format((3*insideArray[12]), '$')+"</td>";
        if(summerBool){myTable+="<td>"+format(summerInsideArray[12],'$')+"</td></tr>";}else{ myTable+="</tr>";}
        myTable+="<tr><th>CAB Fee</th><td>"+format(insideArray[13],'$')+"</td><td>"+format((3*insideArray[13]), '$')+"</td>";
        if(summerBool){myTable+="<td>"+format(summerInsideArray[13],'$')+"</td></tr>";}else{ myTable+="</tr>";}
        myTable+="<tr><th>WashPIRG (optional)</th><td>"+format(insideArray[14],'$')+"</td><td>"+format((3*insideArray[14]),'$')+"</td>";
        if(summerBool){myTable+="<td>"+format(summerInsideArray[14],'$')+"</td></tr>";}else{ myTable+="</tr>";}
        myTable+="<tfoot><tr><th>Total</th><td>" + format(insideArray[costRate],'$')+ "</td><td>" + format((3*insideArray[costRate]),'$') + "</td>";
        if(summerBool){myTable+="<td>" + format(summerInsideArray[costRate],'$') + "</td></tr></tfoot>";}else{ myTable+="</tr></tfoot>";}
        myTable+="</table>";
    document.getElementById('tuitionTable').innerHTML = myTable;// prints myTable into the HTML in the div 'tuitionTable'
}
jQuery(document).ready(function($){
    document.getElementById('Tuition-Box').innerHTML = '<aside class="box"><h2>Calculate Tuition &amp; Fees</h2><form action="" name="studentStatus"><p><label for="selCSV">Academic Year:</label>    <select id="selCSV"><option value="-1" selected="selected">Please Select Option</option><option value="tuition-csv/1516.csv">2015-16</option><option value="tuition-csv/1617.csv">2016-17</option></select></p><p><label for="creditCount">Number of credits:</label> <select id="creditCount" id="changed"><option value="-1">Please Choose Credits</option><option value="2">2</option><option value="3">3</option><option value="4">4</option><option value="5">5</option><option value="6">6</option><option value="7">7</option><option value="8">8</option><option value="9">9</option><option value="10">10</option><option value="11">11</option><option value="12">12</option><option value="13">13</option><option value="14">14</option><option value="15">15</option><option value="16">16</option><option value="17">17</option><option value="18">18</option><option value="19">19</option><option value="20">20</option></select>   </p><p><label for="resident">Resident or Non-resident:</label> <select id="resident"><option value="-1" selected="selected">Please Select Option</option><option value="0">Resident</option><option value="1">Non-resident</option></select>   </p> <p><label for="graduate">Undergraduate or Graduate:</label> <select id="graduate"><option value="-1" selected="selected">Please Select Option</option><option value="0">Undergraduate</option><option value="2">Graduate</option></select>   </p> </form><button  class="prime" onclick="clickFunction()">Calculate</button><div id="tuitionTable"></div></aside>';
});

function clickFunction(){

/* -------------------------------------csv read in to fields array. ----------------------------------------*/
    jQuery(document).ready(function($){
        var CSV = document.getElementById("selCSV");
        CSV = CSV.options[CSV.selectedIndex].value;
        $.ajax({
            type: "GET",
            url: CSV,// The name of the CSV currently being used.
            dataType: "text",
            error: function(){document.getElementById('tuitionTable').innerHTML = '<p>Please make sure all fields are selected.</p>';},
            success: function(data) {processData(data);}
             });
        function processData(info) {
            var theData = info;
            var row = theData.split(/[\n\r]/g);// Splits read in file at each line break
            var fields = [];
            for (var i=0*0; i<row.length; ++i) {//Loop through each Line of the CSV
            var temp = row[i].split(','); // Break each value at current line by comma
            fields[i] = temp;
            fullData = fields;
            }
        }


    
/* -------------------------------------Function to prepare selected values to find the information in CSV to use ----------------------------------------*/
        setTimeout(function(){//This timeout makes sure that the document can be loaded in time
            callBack();
        }, 50);//50 ms to wait before performing contained operations
        function callBack(){
        var credits = document.getElementById("creditCount");
        var graduate = document.getElementById("graduate");
        var resident = document.getElementById("resident");
        if (parseInt(credits.options[credits.selectedIndex].value) > -1 && 
        parseInt(graduate.options[graduate.selectedIndex].value) > -1 && 
        parseInt(resident.options[resident.selectedIndex].value) > -1){
            var selectionCr = parseInt(credits.options[credits.selectedIndex].value);//We later add 2 to this because of the 2 rows of formatting information in the csv
            var selectionGr = parseInt(graduate.options[graduate.selectedIndex].value);
            var selectionRe = parseInt(resident.options[resident.selectedIndex].value);
            //console.log(selectionCr, selectionRe, selectionGr);

            var costRow = selectionGr+selectionRe;//cost row changes to the appropriate offset for which type of tuition the student will use, will reinititialize
            if (selectionGr === 2 && selectionCr > 16){
                createTable(costRow, 18);// 18 because of the +2 offset, in the case graduates become able to take 16+ credits comment out this if statement and move the else information outside of the if.
               document.getElementById('tuitionTable').innerHTML = '<p>Graduates may only take up to 16 credits.</p>' + document.getElementById('tuitionTable').innerHTML;// append message to beginning of table
               }
            else{
                createTable(costRow, selectionCr+2);//Create a table with the value of credits selected (+2 for the offset)
            }
        }else {
            document.getElementById('tuitionTable').innerHTML = '<p>Please make sure all fields are selected.</p>';
        }
    }
    });
}