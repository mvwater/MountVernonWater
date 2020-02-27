var searchType; //Category to be searched by: accountNo or address
var ajaxUser = "brydon1"; //Your username for ajax calls

$(document).ready(function() {
  console.log("ready!");
  $(#search_button).click(searchDatabase);
});

// Function to send info to database
function searchDatabase(){
  if ($("#search_field").text() == ""){
    // Add something here
  } else {
    setSearchType(searchType);
    if (searchType == "AccountNo"){
      $.ajax({
        url: '/cgi-bin/'+ajaxUser+'_searchByAccountNo.cgi?accountNo=' + searchType,
        dataType: 'text', // maybe JSON
        success: displayAccountInfo, 
        error: function(){alert("Error: Could not search by account number.");}
      });
    } else { // searchType == "Address"
      $.ajax({
        url: '/cgi-bin/'+ajaxUser+'_searchByAddress.cgi?address=' + searchType,
        dataType: 'text', // maybe JSON
        success: displayAddressMatches, 
        error: function(){alert("Error: Could not search by address.");}
      });
    }
    
  }
}

// Function to send info to database
function setSearchType(searchTypeVar){
  if ($("#search_type").selectedIndex == 0) {
    // Search by accountNo
    searchTypeVar = "AccountNo";
  } else {
    // Search by address
    searchTypeVar = "Address";
  }
}

// Function to parse info from database
function displayAccountInfo(results){

}

// Function to send info to database
function displayAddressMatches(results){

}


