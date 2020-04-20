var searchType; //Category to be searched by: accountNo or address
var ajaxUser = "canfield1"; //Your username for ajax calls

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

        if (searchType == "Account No."){
            $.ajax({
                url: '/cgi-bin/'+ajaxUser+'_searchByAccountNo.cgi?accountNo=' + userInput, // Var not created yet
                dataType: 'text', // maybe JSON
                success: processAccount, 
                error: function(){alert("Error: Could not search by account number.");}
            });
        } else { // searchType == "Address"
            console.log("Searching by address.");
            console.log("Sending " + userInput);

            $.ajax({
                url: '/cgi-bin/' + ajaxUser + '_searchByAddress.cgi?address=' + userInput,
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
    if ($("#search_type option:selected").val() == "0") {
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
    console.log("&" + results + "&");
    $('#search_results').empty(); //$('#account_search).empty();
    console.log("About to show results");
    $('#search_results').append(showSearchResults(results));
    console.log("Finished show results");
    //$(".open_account").click(openAccount);
    //console.log("button click event was created.");
}


function processAccount(results){
  console.log("&" + results + "&");
  $('#search_results').empty();
  console.log("About to show results");
  $('#search_results').append(displayAccountInfo(results));
  console.log("Finished show results");

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
    accountData.pop(); // Remove empty string from end of list

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

// Example result string: 10-59-1*I*12-11-1977*Reinald Mallinar*CITY OF MOUNT VERNON
function displayAccountInfo(results){

    console.log("Length of result string: ", resultString.length);
    var accountData = resultString.split('*');
    accountData.pop(); // Remove empty string from end of list

    //console.log("Account Data: " + accountData);
    console.log("Account Data: ", accountData);
    var listLength = accountData.length;

    if (listLength < 6)
    {
      return "<h3>Sorry! We could not find an account with this account number. Please try again!</h3>";
    } 
    else 
    {
      console.log("We have results.");
      console.log(listLength);
    
      var result = "<div class='container'><div class='row'><div class='col'><input type='text' id='status' value='Success!' name='status' style='width: 100%;margin-bottom: 10px;'></div></div><div class='row'><div class='col'><label>Account Number:&nbsp;</label><input type='text' id="+res_accountNumber+" name='Account Number' style='width: 100%;margin-bottom: 10px;'></div></div></div>";
        
      var res_accountNumber = accountData[0];
      var res_accountStatus = accountData[1];
      var res_startDate = accountData[2];
      var res_name = accountData[3];
      var res_add1 = accountData[4];
      var res_add2 = accountData[5];
      var res_add3 = accountData[6];
      var res_city = accountData[7];
      var res_state = accountData[8];
      var res_zip = accountData[9];
      var res_phoneNum = accountData[10];
      var res_email = accountData[11];
      var res_sscan = accountData[12];
      var res_dlnum = accountData[13];
      var res_cellNum = accountData[14];
      var res_dob = accountData[15];

      var land_name = accountData[16];
      var land_add1 = accountData[17];
      var land_add2 = accountData[18];
      var land_add3 = accountData[19];
      var land_city = accountData[20];
      var land_state = accountData[21];
      var land_zip = accountData[22];
      var land_phoneNum = accountData[23];
      var land_email = accountData[24];
      var land_sscan = accountData[25];
      var land_dlnum = accountData[26];
      var land_cellNum = accountData[27];
      var land_dob = accountData[28];
          
      // Move style instructions to css
      result += "<div class='+container+'><div class='row'><div class='col'><div><p><span style='text-decoration: underline;'>General Information</span></p><fieldset><label>Comments?&nbsp;</label><input type='text' id='comments' name='comments' placeholder='FALSE'><a id='openComments' href='#' style='margin-left: 10px;'>Open Comments</a></fieldset><fieldset><label for='AcctStatus'>Account Status:&nbsp;</label><input type='text' id='"+res_accountStatus+"' name='AcctStatus' placeholder='(A)' style='width: 30px;'></fieldset><fieldset><label for='StartDt'>Start Date:&nbsp;</label><input type='text' id='"+res_startDate+"' name='StartDt' placeholder='(08-15-2017)' style='width: 100px;'></fieldset><fieldset><label for='Name'>Name:&nbsp;</label><input type='text' id='"+res_name+"' name='Name' placeholder='(WATER TREATMENT PLANT)' style='width: 80%;'></fieldset><fieldset><label for='Add1'>Address 1:&nbsp;</label><input type='text' id='"+res_add1+"' name='Add1' placeholder='(1550 OLD DELAWARE RD)' style='width: 70%;'></fieldset><fieldset><label for='Add2'>Address 2:&nbsp;</label><input type='text' id='"+res_add2+"' name='Add2' style='width: 70%;'></fieldset><fieldset><label for='Add3'>Address 3:&nbsp;</label><input type='text' id='"+res_add3+"' name='Add3' style='width: 70%;'></fieldset><fieldset><label for='City'>City:&nbsp;</label><input type='text' id='"+res_city+"' name='City' placeholder='(MOUNT VERNON)' style='width: 50%;'></fieldset><fieldset><label for='State'>State:&nbsp;</label><input type='text' id='"+res_state+"' name='State' placeholder='(OH)' style='width: 60px;'></fieldset><fieldset><label for='Zip'>ZIP:&nbsp;</label><input type='text' id='"+res_zip+"' name='Zip' placeholder='(43050)' style='width: 90px;'></fieldset><fieldset><label for='PhoneNum'>Phone Number:&nbsp;</label><input type='text' id='"+res_phoneNum+"' name='PhoneNum' placeholder='(330-465-0240)' style='width: 90px;'></fieldset><fieldset><label for='Email'>Email:&nbsp;</label><input type='text' id='"+res_email+"' name='Email' placeholder='(canfield1@kenyon.edu)' style='width: 90px;'></fieldset><fieldset><label for='SScan'>SScan:&nbsp;</label><input type='text' id='"+res_sscan+"' name='SScan' placeholder='(????)' style='width: 90px;'></fieldset><fieldset><label for='DLnum'>DLnum:&nbsp;</label><input type='text' id='"+res_dlnum+"' name='DLnum' placeholder='(!!!!!!)' style='width: 90px;'></fieldset><fieldset><label for='CellNum'>Cell phone number:&nbsp;</label><input type='text' id='"+res_cellNum+"' name='CellNum' placeholder='(43050)' style='width: 90px;'></fieldset><fieldset><label for='DoB'>Date of Birth:&nbsp;</label><input type='text' id='"+res_dob+"' name='DoB' placeholder='(04-13-1998)' style='width: 90px;'></fieldset></div></div></div></div>";

      result+= "<div class='container'><div class='row'><div class='col'><p>Billing Information</p><button class='btn btn-secondary' type='button' style='margin-right: 10px;'>Consumption History</button><button class='btn btn-secondary' type='button' style='margin-right: 10px;'>Receivables History</button><button class='btn btn-secondary' type='button'>Payment History</button></div></div></div>";

      result += "<div class='+container+'><div class='row'><div class='col'><div><p><span style='text-decoration: underline;'>Landlord Information</span></p><fieldset><label for='Name'>Name:&nbsp;</label><input type='text' id='"+land_name+"' name='Name' placeholder='(WATER TREATMENT PLANT)' style='width: 80%;'></fieldset><fieldset><label for='Add1'>Address 1:&nbsp;</label><input type='text' id='"+land_add1+"' name='Add1' placeholder='(1550 OLD DELAWARE RD)' style='width: 70%;'></fieldset><fieldset><label for='Add2'>Address 2:&nbsp;</label><input type='text' id='"+land_add2+"' name='Add2' style='width: 70%;'></fieldset><fieldset><label for='Add3'>Address 3:&nbsp;</label><input type='text' id='"+land_add3+"' name='Add3' style='width: 70%;'></fieldset><fieldset><label for='City'>City:&nbsp;</label><input type='text' id='"+land_city+"' name='City' placeholder='(MOUNT VERNON)' style='width: 50%;'></fieldset><fieldset><label for='State'>State:&nbsp;</label><input type='text' id='"+land_state+"' name='State' placeholder='(OH)' style='width: 60px;'></fieldset><fieldset><label for='Zip'>ZIP:&nbsp;</label><input type='text' id='"+land_zip+"' name='Zip' placeholder='(43050)' style='width: 90px;'></fieldset><fieldset><label for='PhoneNum'>Phone Number:&nbsp;</label><input type='text' id='"+land_phoneNum+"' name='PhoneNum' placeholder='(330-465-0240)' style='width: 90px;'></fieldset><fieldset><label for='Email'>Email:&nbsp;</label><input type='text' id='"+land_email+"' name='Email' placeholder='(canfield1@kenyon.edu)' style='width: 90px;'></fieldset><fieldset><label for='SScan'>SScan:&nbsp;</label><input type='text' id='"+land_sscan+"' name='SScan' placeholder='(????)' style='width: 90px;'></fieldset><fieldset><label for='DLnum'>DLnum:&nbsp;</label><input type='text' id='"+land_dlnum+"' name='DLnum' placeholder='(!!!!!!)' style='width: 90px;'></fieldset><fieldset><label for='CellNum'>Cell phone number:&nbsp;</label><input type='text' id='"+land_cellNum+"' name='CellNum' placeholder='(43050)' style='width: 90px;'></fieldset><fieldset><label for='DoB'>Date of Birth:&nbsp;</label><input type='text' id='"+land_dob+"' name='DoB' placeholder='(04-13-1998)' style='width: 90px;'></fieldset></div></div></div></div>";

    }
  return result;
}

