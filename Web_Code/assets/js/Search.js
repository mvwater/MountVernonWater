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

        if (searchType == "AccountNo"){
            console.log("Searching by account.");
            console.log("Sending " + userInput);
            console.log("/cgi-bin/"+ajaxUser+"_searchByAccount2.cgi?accountNo=" + userInput);
            console.log("/cgi-bin/"+ajaxUser+"_searchByAccount.cgi?accountNo=" + userInput);
            openAccount(userInput);
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

    $(".open_account").click(function() {
        var accountNum = $(this).attr("id").replace("open_","");
        console.log("Account Number to be opened: ", accountNum);
        openAccount(accountNum);
    });
    console.log("button click event was created.");
}

// Use this function in SearchDatabase function
function openAccount(accountNo){
    console.log("openAccount function blank for now.");
    $.ajax({
        url: '/cgi-bin/'+ajaxUser+'_searchByAccount.cgi?accountNo=' + accountNo, // Var not created yet
        dataType: 'text', // maybe JSON
        success: processAccount,
        error: function(){alert("Error: Could not search by account number.");}
    });
}

function showSearchResults(resultString){
    console.log("Length of result string: ", resultString.length);
    var accountData = resultString.split('*');
    accountData.pop(); // Remove empty string from end of list

    //console.log("Account Data: " + accountData);
    console.log("Account Data: ", accountData);
    var listLength = accountData.length;

    if (listLength < 6){
        return "<h3 style='margin-bottom: 0px;padding-left: 10px;padding-top: 10px;margin-top: 15px;'>This address is not in the system.</h3>";
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





function processAccount(results){
    console.log("&" + results + "&");
    $('#search_results').empty();
    console.log("About to show results");

    var accountData = results.split('*');
    accountData.pop(); // Remove empty string from end of list

    $('#search_results').append(displayAccountInfo(accountData));
    console.log("Finished show results");
    // Get account number for click events
    var accountNumber = accountData[0];
    
    // View Comments Button
    $("#toggle_comments").click(function() {
        //console.log($(this).val());
        //console.log(this.value);

        toggleComments(accountNumber,this); // MAKE ME
        console.log('Brand new code here.');
        //$(this).text("Close Comments");
    });
    console.log("View comments click event was created.");

    // Consumption History Button
    $("#view_consumption_history").click(function() {
        viewConsumptionHistory(accountNumber); // MAKE ME
    });
    console.log("Consumption click event was created.");

    // Recievables History Button
    $("#view_recievables_history").click(function() {
        viewRecievablesHistory(accountNumber); // MAKE ME
    });
    console.log("Recievables click event was created.");

    // Payment History Button
    $("#view_payment_history").click(function() {
        viewPaymentHistory(accountNumber); // MAKE ME
    });
    console.log("Payment click event was created.");

}

// Example result string: 10-59-1*I*12-11-1977*Reinald Mallinar*CITY OF MOUNT VERNON
function displayAccountInfo(accountData){

    //console.log("Length of result string: ", resultString.length);
    //var accountData = resultString.split('*');
    //accountData.pop(); // Remove empty string from end of list

    //console.log("Account Data: " + accountData);
    console.log("Account Data: ", accountData);
    var listLength = accountData.length;

    if (listLength < 6) // WHY did you choose 6 again?
    {
      return "<h3>Sorry! We could not find an account with this account number. Please try again!</h3>";
    }
    else
    {
        console.log("We have results.");
        console.log(listLength);

        var res_accountNumber = accountData[0];

        // Same style used in each section container
        containerStyle = "background-color: #CCCCFF;padding-bottom: 10px;padding-top: 0px;margin-top: 15px;margin-bottom: ";

        // Account Number in separate container
        var result = "<div class='container text-left' style='background-color: #CCCCFF;padding-bottom: 5px;padding-top: 15px;margin-top: 15px;margin-bottom: 0px;'> <div class='row'><div class='col'> <p id='res_account_number'><b>Account Number:&nbsp;</b>" + res_accountNumber + "</p> </div></div></div>";

/*
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
        var land_dob = accountData[28];*/

        var idNameList = ["account_status","start_date","name","add1","add2","add3","city","state","zip","phoneNum","email","sscan","dlnum","cellNum","dob","land_name","land_add1","land_add2","land_add3","land_city","land_state","land_zip","land_phoneNum","land_email","land_sscan","land_dlnum","land_cellNum","land_dob"];

        var labelNameList = ["Account Status","Start Date","Name","Address 1","Address 2","Address 3","City","State","ZIP","Phone Number","Email","SScan","DLnum","Cell Phone Number","Date of Birth"];

        // General Information Container
        result += "<div class='container text-left' style='" + containerStyle + "0px;'><div class='row'><h3 style='padding: 20px;'>General Information</h3></div><div class='row'><div class='col'>";

        var hasComments = 'No';
        if (accountData[29] == "T"){
            hasComments = 'Yes';
        }

        // EDIT href
        result += "<p id='has_comments'><b>Has Comments: </b>&nbsp; " + hasComments + "</p>";

        // Loops through resident information
        for (var i = 0; i < 15; i++){
            result += "<p id=res_'" + idNameList[i] + "'><b>"+labelNameList[i]+":&nbsp;</b> " + accountData[i+1] + "</p>";
        }

        // Puts comment button in second column
        result += "</div> <div class='col-4' style='right-align'> <button id='toggle_comments' class='btn btn-secondary' href='#' type='button' value='View Comments'>View Comments</button> </div></div></div></div>"; 

        // Adding hidden div for comments
        result += "<div id='display_comments_here' class='container text-left' style='" + containerStyle + "0px;display:none'></div>";

        // Billing Information Container
        result += "<div class= 'container text-left' style= '" + containerStyle + "0px;'><div class='row'><h3 style='padding: 20px;'>Billing Information</h3></div><div class='row'> <div class='col'><button id='view_consumption_history' class='btn btn-secondary' type='button' style='margin-right: 10px;'>Consumption History</button><button id='view_recievables_history' class='btn btn-secondary' type='button' style='margin-right: 10px;'>Receivables History</button><button id='view_payment_history' class='btn btn-secondary' type='button'>Payment History</button></div></div></div>";

        // Landlord Information Container
        result += "<div class='container text-left' style='" + containerStyle + "30px;'> <div class='row'><h3 style='padding: 20px;'>Landlord Information</h3></div><div class='row'> <div class='col'>";

        // Iterates through landlord data
        for (var i = 2; i < 15; i++){
            result += "<p id=land_'" + idNameList[i] + "'><b>"+labelNameList[i]+":&nbsp;</b> " + accountData[i+14] + "</p>";
        }

        result += "</div></div></div>";
    }

  return result;
}









// Change functionality of button to hide comments after 
// Change name of button to "Hide Comments"
// Make it so user can only add comments one time
// Make it so query can only happen once

var haveComments = false;

function toggleComments(accountNo,buttonObj) {
    console.log("About to perform ajax for view comments.");
    console.log("Sending", accountNo);

    if (buttonObj.value == "View Comments"){
        if (haveComments){
            $('#display_comments_here').show(); 
        } else {
            console.log("About to perform ajax for view comments.");
            console.log("Sending", accountNo);

            $.ajax({
                url: '/cgi-bin/'+ajaxUser+'_commentInfoByAccountNo.cgi?accountNo=' + accountNo, // Var not created yet
                dataType: 'text', // maybe JSON
                success: processComments,
                error: function(){alert("Error: Could not get comments.");}
            });
        }

        // Swap button name
        $(this).text("Close Comments");
    } else {
        // Hide comments
        $('#display_comments_here').hide();
        $(this).text("View Comments");
    }
}

function processComments(results){
    var comments = results.split('*');
    comments.pop(); // Remove empty string from end of list

    console.log("Comments: ", comments);

    $('#display_comments_here').append(commentOutput(comments));
    $('#display_comments_here').show(); 
    console.log(results);
}

function commentOutput(commentList){

    console.log("Comments: ", commentList);
    var numComments = commentList.length;
    var result = "";

    result += "<div class='row'><h3 style='padding: 20px;'>Comments</h3></div><div class='row'><div class='col'>";

    for (var i = 0; i < numComments; i++){
        result += "<p>" + commentList[i] + "</p>";
    }

    result += "</div></div>";
    
    console.log(result);
    return result;
}

function viewBillingInfo(accountNo, infoType){
    $.ajax({
        url: '/cgi-bin/'+ajaxUser+'_billingInfoByAccountNo.cgi?accountNo=' + accountNo, // Var not created yet
        dataType: 'text', // maybe JSON
        success: processInfo,
        error: function(){alert("Error: Could not search by account number.");}
    });
}

function processInfo(results){
    console.log("Nothing");
    console.log(results);
}

/*
function viewConsumptionHistory(accountNo) {
    $.ajax({
        url: '/cgi-bin/'+ajaxUser+'_billingInfoByAccountNo.cgi?accountNo=' + accountNo, // Var not created yet
        dataType: 'text', // maybe JSON
        success: processComments,
        error: function(){alert("Error: Could not search by account number.");}
    });
}

function viewRecievablesHistory(accountNo) {
    $.ajax({
        url: '/cgi-bin/'+ajaxUser+'_billingInfoByAccountNo.cgi?accountNo=' + accountNo, // Var not created yet
        dataType: 'text', // maybe JSON
        success: processComments,
        error: function(){alert("Error: Could not search by account number.");}
    });
}

function viewPaymentHistory(accountNo) {
    $.ajax({
        url: '/cgi-bin/'+ajaxUser+'_billingInfoByAccountNo.cgi?accountNo=' + accountNo, // Var not created yet
        dataType: 'text', // maybe JSON
        success: processComments,
        error: function(){alert("Error: Could not search by account number.");}
    });
}*/





