#include <iostream>
#include <string>
#include <vector>
#include "AccountInfo.h"
#include "BillingInfo.h"
#include "AccountSnapshot.h"

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#ifndef JAVASCRIPTBRIDGE_H
#define JAVASCRIPTBRIDGE_H

using namespace cgicc;

class JavaScriptBridge{
  public:
    string printAccountInfo(AccountInfo accountInfo);
	
	string printBillingInfo(BillingInfo billingInfo);

    string printAccountSnapshot(AccountSnapshot accountSnapshot);


    string getElement(string element, Cgicc &cgi);
    //Preconditions: element must be a string corresponding to an ajax element
    //sent from JavaScript. cgi is a Cgicc ajax object.
    //Postconditions: Returns the value of the ajax element as a string.

    string accountInfosToStr(vector<AccountInfo> searchResults);
    // Returns string of AccountInfo objects that will be sent to JavaScript
	
	string billingInfoToStr(BillingInfo searchResult);
	// Returns string of BillingInfo that will be sent to JavaScript
 
    string accountSnapshotsToStr(vector<AccountSnapshot> searchResults);
    // Returns string of AccountInfo objects that will be sent to JavaScript

    void sendAccountInfos(vector<AccountInfo> searchResults);
	
	void sendBillingInfo(BillingInfo searchResult);
    //Preconditions:
    //Postconditions:
    void sendAccountSnapshots(vector<AccountSnapshot> searchResults);
    //Preconditions:
    //Postconditions:

    void sendMessage(string message);
    //Preconditions: stringForJS must be a string that is intended to be sent
    //to a JavaScript file linked through Ajax.
    //Postconditions: String will be sent to a JavaScript file using a cout
};

#endif //JAVASCRIPTBRIDGE_H
