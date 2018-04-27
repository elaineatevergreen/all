jQuery(document).ready(function ($) {
 //Following string contains all of the html displayed on the page before the user does anything.
  document.getElementById('LoginGenerator').innerHTML = "" +
  "  <form action=\"LoginGenerator\" method=\"get\">" + 
  "    <ul class=\"element-list\">" + 
  "      <li>" + 
  "        <p>Automatically determine your Evergreen login credentials.</p>" + 
  "      </li>" + 
  "      <li>" + 
  "        <h3>Name</h3>" + 
  "      </li>" + 
  "      <li>" + 
  "        <div class=\"grid\">" + 
  "          <div class=\"unit-1-2\">" + 
  "            <label for=\"fname\">First name:</label><br/>" + 
  "            <input type=\"text\" name=\"fname\" id=\"fname\" placeholder=\"John\" required=\"required\" size=\"1\">" + 
  "          </div>" + 
  "          <div class=\"unit-1-2\">" + 
  "            <label for=\"lname\">Last name:</label><br/>" + 
  "            <input type=\"text\" name=\"lname\" id=\"lname\" placeholder=\"Doe\" required=\"required\" size=\"1\">" + 
  "          </div>" + 
  "        </div>" + 
  "      </li>" + 
  "      <li>" + 
  "        <fieldset>" + 
  "          <h3>Birthday</h3>" + 
  "          <div class=\"grid\">" + 
  "            <div class=\"unit-1-3\">" + 
  "              <label for=\"monthselect\">Month:</label><br/>" + 
  "              <select id=\"monthselect\" name=\"month\" required>" + 
  "        <option value=\"January\">January</option>" + 
  "        <option value=\"Febuary\">Febuary</option>" + 
  "        <option value=\"March\">March</option>" + 
  "        <option value=\"April\">April</option>" + 
  "        <option value=\"May\">May</option>" + 
  "        <option value=\"June\">June</option>" + 
  "        <option value=\"July\">July</option>" + 
  "        <option value=\"August\">August</option>  " + 
  "        <option value=\"September\">September</option>" + 
  "        <option value=\"October\">October</option>" + 
  "        <option value=\"November\">November</option>" + 
  "        <option value=\"December\">December</option>" + 
  "              </select>" + 
  "            </div>" + 
  "            <div class=\"unit-1-3\">" + 
  "              <label for=\"dayselect\">Day:</label><br/>" + 
  "              <select id=\"dayselect\" name=\"day\" required>" + 
  "        <option value=\"01\">01</option>" + 
  "        <option value=\"02\">02</option>" + 
  "        <option value=\"03\">03</option>" + 
  "        <option value=\"04\">04</option>" + 
  "        <option value=\"05\">05</option>" + 
  "        <option value=\"06\">06</option>" + 
  "        <option value=\"07\">07</option>" + 
  "        <option value=\"08\">08</option>" + 
  "        <option value=\"09\">09</option>" + 
  "        <option value=\"10\">10</option>" + 
  "        <option value=\"11\">11</option>" + 
  "        <option value=\"12\">12</option>" + 
  "        <option value=\"13\">13</option>" + 
  "        <option value=\"14\">14</option>" + 
  "        <option value=\"15\">15</option>" + 
  "        <option value=\"16\">16</option>" + 
  "        <option value=\"17\">17</option>" + 
  "        <option value=\"18\">18</option>" + 
  "        <option value=\"19\">19</option>" + 
  "        <option value=\"20\">20</option>" + 
  "        <option value=\"21\">21</option>" + 
  "        <option value=\"22\">22</option>" + 
  "        <option value=\"23\">23</option>" + 
  "        <option value=\"24\">24</option>" + 
  "        <option value=\"25\">25</option>" + 
  "        <option value=\"26\">26</option>" + 
  "        <option value=\"27\">27</option>" + 
  "        <option value=\"28\">28</option>" + 
  "        <option value=\"29\">29</option>" + 
  "        <option value=\"30\">30</option>" + 
  "        <option value=\"31\">31</option>" + 
  "        <option value=\"32\">32</option>" + 
  "              </select>" + 
  "            </div>" + 
  "            <div class=\"unit-1-3\">" + 
  "              <label for=\"yearselect\">Year:</label><br/>" + 
  "              <select id=\"yearselect\" name=\"year\" required>" + 
  "        <option value=\"18\">2018</option>" + 
  "        <option value=\"17\">2017</option>" + 
  "        <option value=\"16\">2016</option>" + 
  "        <option value=\"15\">2015</option>" + 
  "        <option value=\"14\">2014</option>" + 
  "        <option value=\"13\">2013</option>" + 
  "        <option value=\"12\">2012</option>" + 
  "        <option value=\"11\">2011</option>" + 
  "        <option value=\"10\">2010</option>" + 
  "        <option value=\"09\">2009</option>" + 
  "        <option value=\"08\">2008</option>" + 
  "        <option value=\"07\">2007</option>" + 
  "        <option value=\"06\">2006</option>" + 
  "        <option value=\"05\">2005</option>" + 
  "        <option value=\"04\">2004</option>" + 
  "        <option value=\"03\">2003</option>" + 
  "        <option value=\"02\">2002</option>" + 
  "        <option value=\"01\">2001</option>" + 
  "        <option value=\"00\">2000</option>" + 
  "        <option value=\"99\">1999</option>" + 
  "        <option value=\"98\">1998</option>" + 
  "        <option value=\"97\">1997</option>" + 
  "        <option value=\"96\">1996</option>" + 
  "        <option value=\"95\">1995</option>" + 
  "        <option value=\"94\">1994</option>" + 
  "        <option value=\"93\">1993</option>" + 
  "        <option value=\"92\">1992</option>" + 
  "        <option value=\"91\">1991</option>" + 
  "        <option value=\"90\">1990</option>" + 
  "        <option value=\"89\">1989</option>" + 
  "        <option value=\"88\">1988</option>" + 
  "        <option value=\"87\">1987</option>" + 
  "        <option value=\"86\">1986</option>" + 
  "        <option value=\"85\">1985</option>" + 
  "        <option value=\"84\">1984</option>" + 
  "        <option value=\"83\">1983</option>" + 
  "        <option value=\"82\">1982</option>" + 
  "        <option value=\"81\">1981</option>" + 
  "        <option value=\"80\">1980</option>" + 
  "        <option value=\"79\">1979</option>" + 
  "        <option value=\"78\">1978</option>" + 
  "        <option value=\"77\">1977</option>" + 
  "        <option value=\"76\">1976</option>" + 
  "        <option value=\"75\">1975</option>" + 
  "        <option value=\"74\">1974</option>" + 
  "        <option value=\"73\">1973</option>" + 
  "        <option value=\"72\">1972</option>" + 
  "        <option value=\"71\">1971</option>" + 
  "        <option value=\"70\">1970</option>" + 
  "        <option value=\"69\">1969</option>" + 
  "        <option value=\"68\">1968</option>" + 
  "        <option value=\"67\">1967</option>" + 
  "        <option value=\"66\">1966</option>" + 
  "        <option value=\"65\">1965</option>" + 
  "        <option value=\"64\">1964</option>" + 
  "        <option value=\"63\">1963</option>" + 
  "        <option value=\"62\">1962</option>" + 
  "        <option value=\"61\">1961</option>" + 
  "        <option value=\"60\">1960</option>" + 
  "        <option value=\"59\">1959</option>" + 
  "        <option value=\"58\">1958</option>" + 
  "        <option value=\"57\">1957</option>" + 
  "        <option value=\"56\">1956</option>" + 
  "        <option value=\"55\">1955</option>" + 
  "        <option value=\"54\">1954</option>" + 
  "        <option value=\"53\">1953</option>" + 
  "        <option value=\"52\">1952</option>" + 
  "        <option value=\"51\">1951</option>" + 
  "        <option value=\"50\">1950</option>" + 
  "        <option value=\"49\">1949</option>" + 
  "        <option value=\"48\">1948</option>" + 
  "        <option value=\"47\">1947</option>" + 
  "        <option value=\"46\">1946</option>" + 
  "        <option value=\"45\">1945</option>" + 
  "        <option value=\"44\">1944</option>" + 
  "        <option value=\"43\">1943</option>" + 
  "        <option value=\"42\">1942</option>" + 
  "        <option value=\"41\">1941</option>" + 
  "        <option value=\"40\">1940</option>" + 
  "        <option value=\"39\">1939</option>" + 
  "        <option value=\"38\">1938</option>" + 
  "        <option value=\"37\">1937</option>" + 
  "        <option value=\"36\">1936</option>" + 
  "        <option value=\"35\">1935</option>" + 
  "        <option value=\"34\">1934</option>" + 
  "        <option value=\"33\">1933</option>" + 
  "        <option value=\"32\">1932</option>" + 
  "        <option value=\"31\">1931</option>" + 
  "        <option value=\"30\">1930</option>" + 
  "        <option value=\"29\">1929</option>" + 
  "        <option value=\"28\">1928</option>" + 
  "        <option value=\"27\">1927</option>" + 
  "        <option value=\"26\">1926</option>" + 
  "        <option value=\"25\">1925</option>" + 
  "        <option value=\"24\">1924</option>" + 
  "        <option value=\"23\">1923</option>" + 
  "        <option value=\"22\">1922</option>" + 
  "        <option value=\"21\">1921</option>" + 
  "        <option value=\"20\">1920</option>" + 
  "        <option value=\"19\">1919</option>" + 
  "        <option value=\"18\">1918</option>" + 
  "        <option value=\"17\">1917</option>" + 
  "        <option value=\"16\">1916</option>" + 
  "        <option value=\"15\">1915</option>" + 
  "        <option value=\"14\">1914</option>" + 
  "        <option value=\"13\">1913</option>" + 
  "        <option value=\"12\">1912</option>" + 
  "        <option value=\"11\">1911</option>" + 
  "        <option value=\"10\">1910</option>" + 
  "        <option value=\"09\">1909</option>" + 
  "        <option value=\"08\">1908</option>" + 
  "        <option value=\"07\">1907</option>" + 
  "        <option value=\"06\">1906</option>" + 
  "        <option value=\"05\">1905</option>" + 
  "        <option value=\"04\">1904</option>" + 
  "        <option value=\"03\">1903</option>" + 
  "        <option value=\"02\">1902</option>" + 
  "        <option value=\"01\">1901</option>" + 
  "        <option value=\"00\">1900</option>" + 
  "              </select>" + 
  "            </div>" + 
  "          </div>" + 
  "        </fieldset>" + 
  "      </li>" + 
  "    </ul>" + 
  "    <input type=\"button\" value=\"Submit\" onClick=\"writeValues(form)\" class=\"prime\">" + 
  "  </form>";
});

window.writeValues = function(form) {
  var fname = form.fname.value;
  var year = form.year.value;
  var month = form.month.value;
  var day = form.day.value;
  var lname = form.lname.value;
  fname = fname.toLowerCase();
  lname = lname.toLowerCase();
  month = month.toLowerCase();
  if (fname == "") {
    document.getElementById('alertcontainer').innerHTML = "<strong>Error</strong><ul> <li>Your First Name is Required</li> </ul>";
    document.getElementById('gentitle').innerHTML = "";
    document.getElementById('genuser').innerHTML = "";
    document.getElementById('genpass').innerHTML = "";
    return false;
  } else if (lname == "") {
    document.getElementById('alertcontainer').innerHTML = "<strong>Error</strong><ul> <li>Your Last Name is Required</li> </ul>";
    document.getElementById('gentitle').innerHTML = "";
    document.getElementById('genuser').innerHTML = "";
    document.getElementById('genpass').innerHTML = "";
    return false;
  } else {
    document.getElementById('alertcontainer').innerHTML = "";
    document.getElementById('gentitle').innerHTML = "Your login credentials";

    document.getElementById('genuser').innerHTML = "<p>Your Username: </p>" + lname.substring(0, 3) + fname.substring(0, 3) + day;
    document.getElementById('genpass').innerHTML = "<p>Your Password: </p>" + day + month.substring(0, 3) + year;

  }
}
