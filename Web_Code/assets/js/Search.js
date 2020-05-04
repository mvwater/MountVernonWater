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
            //console.log("/cgi-bin/"+ajaxUser+"_searchByAccount2.cgi?accountNo=" + userInput);
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
    $('#search_results').append(addressOutput(results));
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
    console.log("Opening Account");
    $.ajax({
        url: '/cgi-bin/'+ajaxUser+'_searchByAccount.cgi?accountNo=' + accountNo, // Var not created yet
        dataType: 'text', // maybe JSON
        success: processAccount,
        error: function(){alert("Error: Could not search by account number.");}
    });
}

function addressOutput(resultString){
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

    $('#search_results').append(accountOutput(accountData));
    console.log("Finished show results");
    // Get account number for click events
    var accountNumber = accountData[0];

    // View Comments Button
    $("#toggle_comments").click(function() {
        toggleButton(accountNumber,this,"Comments", "commentInfo", processComments,haveComments);
        console.log("Toggled comments.");
    });
    console.log("View comments click event was created.");

    // Consumption History Button
    $("#toggle_consumption").click(function() {

        toggleButton(accountNumber,this,"Consumption History", "consumption", processConsumption, haveConsumption);
        console.log("Toggled consumption.");
    });
    console.log("Consumption click event was created.");

    // Receivables History Button
    $("#toggle_receivables").click(function() {
        // MUST make processReceivables function
        toggleButton(accountNumber,this,"Receivables History", "receivables", processReceivables,haveReceivables);
        console.log("Toggled receivables.");
    });
    console.log("Receivables click event was created.");

    // Payment History Button
    $("#toggle_payments").click(function() {
        // MUST make processPayment function
        toggleButton(accountNumber,this,"Payments History", "payments", processPayments,havePayments);
        console.log("Toggled payments.");
    });
    console.log("Payment click event was created.");

}

var haveComments = false;
var haveConsumption = false;
var haveReceivables = false;
var havePayments = false;

// Example result string: 10-59-1*I*12-11-1977*Reinald Mallinar*CITY OF MOUNT VERNON
function accountOutput(accountData){
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
        result += "<div id='display_commentInfo_here' class='container text-left' style='" + containerStyle + "0px;display:none'></div>";

        // Billing Information Container
        result += "<div class= 'container text-left' style= '" + containerStyle + "0px;'><div class='row'><h3 style='padding: 20px;'>Billing Information</h3></div><div class='row'> <div class='col'><button id='toggle_consumption' class='btn btn-secondary' type='button' style='margin-right: 10px;' value='View Consumption History'>View Consumption History</button><button id='toggle_receivables' class='btn btn-secondary' type='button' style='margin-right: 10px;' value='View Receivables History'>View Receivables History</button><button id='toggle_payments' class='btn btn-secondary' type='button' value='View Payments History'>View Payments History</button></div></div></div>";

        // Adding hidden div for consumption history
        result += "<div id='display_consumption_here' class='container text-left' style='" + containerStyle + "0px;display:none'></div>";

        // Adding hidden div for receivables history
        result += "<div id='display_receivables_here' class='container text-left' style='" + containerStyle + "0px;display:none'></div>";

        // Adding hidden div for payment history
        result += "<div id='display_payments_here' class='container text-left' style='" + containerStyle + "0px;display:none'></div>";

        // Landlord Information Container
        result += "<div class='container text-left' style='" + containerStyle + "30px;'> <div class='row'><h3 style='padding: 20px;'>Landlord Information</h3></div><div class='row'> <div class='col'>";

        // Iterates through landlord data
        for (var i = 2; i < 15; i++){
            result += "<p id=land_'" + idNameList[i] + "'><b>"+labelNameList[i]+":&nbsp;</b> " + accountData[i+14] + "</p>";
        }

        result += "</div></div></div>";

        //Adds Print/Save Button
        result += "<div class='+container+'><div class='container text-left'style='background-color: #CCCCFF;margin-bottom: 0px;padding-bottom: 10px;padding-top: 0px;margin-top: 15px;><div class='><div class='col'><button class='btn btn-secondary' onclick='window.print()' type='button' style='margin-top: 15px; margin-right: 10px;'>Print/Save</button></div></div></div>";
    }

  return result;
}

// Indicates button has been used
function buttonUsed(buttonLabel){
    if (buttonLabel == "Comments"){
        haveComments = true;
    } else if (buttonLabel == "Receivables History"){
        haveReceivables = true;
    } else if (buttonLabel == "Consumption History"){
        haveConsumption = true;
    } else { // Payments History
        havePayments = true;
    }
}

function toggleButton(accountNo,buttonObj,buttonLabel, cgiString, processFunction,used){

    if (buttonObj.value == "View " + buttonLabel){
        console.log("Value: ", buttonObj.value);
        if (used){
            console.log("Already used button");
            $('#display_' + cgiString + '_here').show();
        } else {
            console.log("About to send query with ajax");
            console.log("Sending", accountNo);
            $('#display_' + cgiString + '_here').show();

            $.ajax({
                url: '/cgi-bin/'+ajaxUser+'_' + cgiString + 'ByAccountNo.cgi?accountNo=' + accountNo, // Var not created yet
                dataType: 'text', // maybe JSON
                success: processFunction,
                error: function(){alert("Error: Button failed.");}
            });
            buttonUsed(buttonLabel);
        }
        // Swap button name
        buttonObj.value = "Close " + buttonLabel;
        $(buttonObj).text("Close " + buttonLabel);
    } else {
        console.log("Hiding content.");
        $('#display_' + cgiString + '_here').hide();
        buttonObj.value = "View " + buttonLabel;
        $(buttonObj).text("View " + buttonLabel);
    }
}

function processConsumption(results){
    console.log("Processing consumption");
    console.log(results);

    console.log("About to show results");
    $('#display_consumption_here').append(consumptionOutput(results));

    console.log("Finished show results");
    console.log("Success");
}

function consumptionOutput(resultString){
    console.log("Length of result string: ", resultString.length);
    var consumptionData = resultString.split('*');
    consumptionData.pop(); // Remove empty string from end of list

    //console.log("Account Data: " + accountData);
    console.log("Consumption Data: ", consumptionData);
    var listLength = consumptionData.length;

// Edit listlen max
    if (listLength < 7)
    {
    return "<h3>Sorry! We could not find an consumption details associated with this account number. </h3>";
    }
    else
    {
        console.log("We have results.");
        console.log(listLength);

        var result = "";
        result += "<div class='container text-left' style='background-color: #CCCCFF;margin-bottom: 0px;padding-bottom: 10px;padding-top: 0px;margin-top: 15px;><div class='row'>";

        // Add Consumption History Title
        result += "<h3 style = 'padding-top:20px'>Consumption History</h3></div>";

        // Add table
        result += "<div class='table-responsive'><table class='table'><thead><tr><th>Bill Date</th><th>Beg_read</th><th>End_read</th><th>Read_Date</th><th>Service</th><th>Cons</th><th>Amount</th><th>Penalty</th></tr></thead><tbody>";

        //var idNameList = ["accountNo","Bill_date","Beg_read","End_read","Read_date","Service","Cons","Amount","Penalty"];

        for (var i = 0; i < listLength; i += 8){
            result += "<tr>";
            for (var j = i; j < i+8; j++){
                result += "<td>" + consumptionData[j] + "</td>";
            }
            result += "</tr>";
        }

      result += "</tbody></table></div></div>";
      //result += displayPrintButton();

    return result;
  }
}

function processComments(results){
    var comments = results.split('*');
    comments.pop(); // Remove empty string from end of list
    $('#display_commentInfo_here').append(commentOutput(comments));
    $('#display_commentInfo_here').show();
    //console.log(results);
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
    return result;
}

function processReceivables(results){
    var receivables = results.split('*');
    receivables.pop(); // Remove empty string from end of list
    $('#display_receivables_here').append(receivablesOutput(receivables));
    $('#display_receivables_here').show();
    console.log(results);
}

function receivablesOutput(receivablesList){
  console.log("Receivables Data: ", receivablesList);
  var listLength = receivablesList.length;

// Edit listlen max
  if (listLength < 7)
  {
  return "<h3>Sorry! We could not find receivables details associated with this account number. </h3>";
  }
  else
  {
      console.log("We have results.");
      console.log(listLength);

      var result = "";
      result += "<div class='container text-left' style='background-color: #CCCCFF;margin-bottom: 0px;padding-bottom: 10px;padding-top: 0px;margin-top: 15px;><div class='row'>";

      // Add Receivables History Title
      result += "<h3 style = 'padding-top:20px'>Receivables History</h3></div>";

      // Add table
      result += "<div class='table-responsive'><table class='table'><thead><tr><th>Invoice</th><th>Inv_date</th><th>Amount</th><th>To_post</th><th>Amt_paid</th><th>Paid_date</th><th>Refer</th><th>Balance</th></tr></thead><tbody>";

      for (var i = 0; i < listLength; i += 8){
          result += "<tr>";
          for (var j = i; j < i+8; j++){
              result += "<td>" + receivablesList[j] + "</td>";
          }
          result += "</tr>";
      }

    result += "</tbody></table></div></div>";
    //result += displayPrintButton();

    return result;
  }
}

function processPayments(results){
    var payments = results.split('*');
    payments.pop(); // Remove empty string from end of list
    $('#display_payments_here').append(paymentsOutput(payments));
    $('#display_payments_here').show();
    console.log(results);
}

function paymentsOutput(paymentsList){
  console.log("Payments Data: ", paymentsList);
  var listLength = paymentsList.length;

// Edit listlen max
  if (listLength < 5)
  {
  return "<h3>Sorry! We could not find payments details associated with this account number. </h3>";
  }
  else
  {
      console.log("We have results.");
      console.log(listLength);

      var result = "";
      result += "<div class='container text-left' style='background-color: #CCCCFF;margin-bottom: 0px;padding-bottom: 10px;padding-top: 0px;margin-top: 15px;><div class='row'>";

      // Add Payments History Title
      result += "<h3 style = 'padding-top:20px'>Payments History</h3></div>";

      // Add table
      result += "<div class='table-responsive'><table class='table'><thead><tr><th>Pay_date</th><th>Amount_Paid</th><th>Type</th><th>Reference</th><th>Batch</th><th>Seq</th></tr></thead><tbody>";

      for (var i = 0; i < listLength; i += 6){
          result += "<tr>";
          for (var j = i; j < i+6; j++){
              result += "<td>" + paymentsList[j] + "</td>";
          }
          result += "</tr>";
      }

    result += "</tbody></table></div></div>";

    return result;
  }
}
