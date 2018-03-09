
window.writeValues = function(form) {
  var fname = form.fname.value;
  var year = form.year.value;
  var month = form.month.value;
  var day   = form.day.value;
  var lname = form.lname.value;
  fname = fname.toLowerCase();
  lname = lname.toLowerCase();
  month = month.toLowerCase();

  document.getElementById('genuser').innerHTML = lname.substring(0, 3) + fname.substring(0, 3) + day;
  document.getElementById('genpass').innerHTML = day + month.substring(0,3) + year;


}
