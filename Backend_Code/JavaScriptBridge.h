//File Name: JavaScript.h
//Author: Shane, Michaela, and Sejin
//Email Address: canfield1@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Mount Vernon City Water Database
//Description: Header file for Javascript functions
//Last Changed: 24 April 2020

#include <iostream>
#include <string>
#include <vector>
#include "AccountInfo.h"
#include "BillingInfo.h"
#include "AccountSnapshot.h"
#include "CommentInfo.h"

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

    string printConsumptionInfo(Consumption consumptionInfo);
    string printPaymentsInfo(Payments paymentsInfo);
    string printReceivablesInfo(Receivables receivablesInfo);

    string printCommentInfo(CommentInfo commentInfo);

    string printAccountSnapshot(AccountSnapshot accountSnapshot);

    string getElement(string element, Cgicc &cgi);
    //Preconditions: element must be a string corresponding to an ajax element
    //sent from JavaScript. cgi is a Cgicc ajax object.
    //Postconditions: Returns the value of the ajax element as a string.

    string accountInfosToStr(vector<AccountInfo> searchResults);
    // Returns string of AccountInfo objects that will be sent to JavaScript

	string billingInfoToStr(BillingInfo searchResult);
	// Returns string of BillingInfo that will be sent to JavaScript

    string consumptionInfoToStr(vector<Consumption> searchResults);
    string paymentsInfoToStr(vector<Payments> searchResults);
    string receivablesInfoToStr(vector<Receivables> searchResults);

	string commentInfoToStr(CommentInfo searchResult);

    string accountSnapshotsToStr(vector<AccountSnapshot> searchResults);
    // Returns string of AccountInfo objects that will be sent to JavaScript

    void sendAccountInfos(vector<AccountInfo> searchResults);

	void sendBillingInfo(BillingInfo searchResult);
    //Preconditions:
    //Postconditions:

    void sendConsumptionInfos(vector<Consumption> searchResults);
    void sendReceivablesInfos(vector<Receivables> searchResults);
    void sendPaymentsInfos(vector<Payments> searchResults);






	void sendCommentInfo(CommentInfo searchResult);

    void sendAccountSnapshots(vector<AccountSnapshot> searchResults);
    //Preconditions:
    //Postconditions:

    void sendMessage(string message);
    //Preconditions: stringForJS must be a string that is intended to be sent
    //to a JavaScript file linked through Ajax.
    //Postconditions: String will be sent to a JavaScript file using a cout
};

#endif //JAVASCRIPTBRIDGE_H
