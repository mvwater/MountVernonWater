
#include <iostream>
#include <string>
#include <vector>


//#include "DatabaseBridge.h"
//#include "JavaScriptBridge.h"


#include "AccountSnapshot.h"

// Stuff for Ajax
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

// Fix later
using namespace cgicc;


using std::cout;
using std::endl;


// MUST Always print out line or you will get 500 error
int main(){
  //Cgicc cgi; // Ajax object
  //JavaScriptBridge javaScriptBridge;

  //Receive info from web page
  //string searchVal = javaScriptBridge.getElement("address", cgi);
  //DatabaseBridge databaseBridge;

  // Receive vector of AccountSnapshot objects from database
  
  //vector<AccountSnapshot> searchResults = databaseBridge.searchByAddress(searchVal);

  // Send search results to JavaScript 
  //javaScriptBridge.sendAccountSnapshots(searchResults);

  //cout << "Content-Type: text/plain\n\n" << endl;
  return 0;
}
