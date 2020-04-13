var searchType; //Category to be searched by: accountNo or address
var ajaxUser = "brydon1"; //Your username for ajax calls

// Problem: searchType not defined

$(document).ready(function() {
    console.log("ready!");
    $("#search_button").click(searchDatabase);
});

// Function to send info to database
function searchDatabase(){
    console.log("Searching database");
    //console.log("Search Field: " + $("#search_field").value());
    //console.log("Search Field: " + $("#search_field").val());
    console.log(document.getElementById('search_field').value);
    var userInput = document.getElementById('search_field').value;
    console.log(userInput);

    if (userInput == ""){
        console.log("Blank field");
        alert("Please enter an address or account number.") // Maybe do something else
    } else {
        console.log("Search field not empty.");
        console.log(userInput);
        searchType = getSearchType();
        console.log("Search Type: " + searchType);

        if (searchType == "AccountNo"){
            $.ajax({
                url: '/cgi-bin/'+ajaxUser+'_searchByAccountNo.cgi?accountNo=' + userInput, // Var not created yet
                dataType: 'text', // maybe JSON
                success: displayAccountInfo, 
                error: function(){alert("Error: Could not search by account number.");}
            });
        } else { // searchType == "Address"
            console.log("Searching by address.");
            console.log("Sending " + userInput);
            $.ajax({
                url: '/cgi-bin/'+ajaxUser+'_searchByAddress.cgi?address=' + userInput,
                dataType: 'text', // maybe JSON
                success: processAddressMatches, 
                error: function(){alert("Error: Could not search by address.");}
            });
        }
    }
}

// Function to send info to database
function getSearchType(){
    console.log("Getting searchType");
    if ($("#search_type").selectedIndex == 0) {
        // Search by accountNo
        return "AccountNo";
    } else {
        // Search by address
        return "Address";
    }
}

// Example result string: 104-23-1*85 Delaware Prk*MOUNT VERNON, OH  43050*T*83-26-19*101 Coshoctan Rd*MOUNT VERNON, OH  43050*F*
// Function to send info to database
function processAddressMatches(results){
    console.log("Temporarily does nothing.");


    /*
    console.log("&" + results + "&");
    $('#search_results').empty();
    console.log("About to show results");
    $('#search_results').append(showSearchResults(results));
    console.log("Finished show results");
    //$(".open_account").click(openAccount);
    //console.log("button click event was created.");*/
}


//Empties photo gallery (again?) builds new gallery using buildGallery function
/*
function processSearchResults(results) {

    //console.log("Results:"+results);
    $('#artworkResults').empty();
    //console.log("About to show photos");
    $('#artworkResults').append(showSearchResults(results));
    console.log("Finished show results");
    //$(".open_account").click(openAccount);
    //console.log("button click event was created.");
}*/


function showSearchResults(resultString){
    console.log("Length of result string: ", resultString.length);
    var accountData = resultString.split('*');
    //console.log("Account Data: " + accountData);
    console.log("Account Data: ", accountData);
    var listLength = accountData.length;

    if (listLength < 6){
        return "<h3>Internal Error</h3>";
    } else {
        console.log("We have results.");
        console.log(listLength);
        // Why do I need extra blank <th> tag?
        var result = "<div class='container text-left' style='background-color: #CCCCFF;margin-bottom: 0px;padding-bottom: 10px;padding-top: 0px;margin-top: 15px;><div class='table-responsive'><table class='table'><thead><tr><th></th><th></th><th>Address</th><th>Account No.</th><th>Has Comments</th></tr></thead><tbody>";

        var count=0; // Error stop
        for (var i = 0; i < listLength; i+=6){
            count++;
            if (count == 2000){
                console.log("Aborting loop.");
                break;
            }
            var accountNumber = accountData[i];
            var add1 = accountData[i+1];
            var add2 = accountData[i+2];
            var add3 = accountData[i+3];
            var lastLineAdd = accountData[i+4];
            var hasComments = accountData[i+5];

            // Construct address HTML
            // Eliminate vertical spacing between elements
            var addressHtml = "<p>" + add1 + "</p>";
            if (add2 != ""){
                addressHtml += "<p>" + add2 + "</p>";
            }
            if (add3 != ""){
                addressHtml += "<p>" + add3 + "</p>";
            }
            addressHtml += "<p>" + lastLineAdd + "</p>";

            // Replace - with * in accountNumber
            var accountNumberStars = accountNumber.replace("-","*").replace("-","*");

            // Get check or x for hasComments box
            var hasCommentsImg;
            if (hasComments == "T"){
                hasCommentsImg = "Green_Check.png";
            } else {
                hasCommentsImg = "Red_X.png";
            }

            // Move style instructions to css
            result += "<tr id='" + accountNumber + "'><td> </td><td id='open_" + accountNumber + "' class='open_account'><strong>Open</strong></td><td style='width: 205px;'>" + addressHtml + "</td><td>" + accountNumberStars + "</td><td><img src='assets/img/" + hasCommentsImg + "' style='height: 26px;'></td></tr>";

        }
        result += "</tbody></table></div></div>";
        console.log("Number of results:", count);
    }
    return result;
}


// Function to parse info from database
/*
function displayAccountInfo(results){

}*/





