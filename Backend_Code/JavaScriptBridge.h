#include <iostream>
#include <string>
#include <vector>
#include "AccountSnapshot.h"

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#ifndef JAVASCRIPTBRIDGE_H
#define JAVASCRIPTBRIDGE_H

using namespace cgicc;

class JavaScriptBridge{
  public:
    string printAccountSnapshot(AccountSnapshot accountSnapshot);
    //Preconditions: artwork must be an Artwork object
    //Postconditions: Returns artwork info delimited by * as a string
    
    string getElement(string element, Cgicc &cgi);
    //Preconditions: element must be a string corresponding to an ajax element
    //sent from JavaScript. cgi is a Cgicc ajax object.
    //Postconditions: Returns the value of the ajax element as a string.

    void sendAccountSnapshots(vector<AccountSnapshot> searchResults);
    //Preconditions: 
    //Postconditions:

    void sendMessage(string message);
    //Preconditions: stringForJS must be a string that is intended to be sent
    //to a JavaScript file linked through Ajax.
    //Postconditions: String will be sent to a JavaScript file using a cout
};

#endif //JAVASCRIPTBRIDGE_H
