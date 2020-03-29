var searchType; //Category to be searched by: accountNo or address
var ajaxUser = "brydon1"; //Your username for ajax calls

$(document).ready(function() {
    console.log("ready!");
    $("#search_button").click(searchDatabase);
});

// Function to send info to database
function searchDatabase(){
    console.log("Searching database");
    //console.log("Search Field: " + $("#search_field").value());
    console.log("Search Field: " + $("#search_field").val());
    console.log(document.getElementById('search_field').value);
    if ($("#search_field").val() == ""){
        console.log("Blank field");
        alert("Please enter an address or account number.") // Maybe do something else
    } else {
        console.log("Search field not empty.");
        console.log($("#search_field").value);
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
/*
function displayAccountInfo(results){

}*/

// Example result string: 104-23-1*85 Delaware Prk*MOUNT VERNON, OH  43050*T*83-26-19*101 Coshoctan Rd*MOUNT VERNON, OH  43050*F*
// Function to send info to database
function displayAddressMatches(results){
    // Finish me
    console.log(results);
}



