#include <iostream>
#include <string>
#include "DatabaseBridge.h"
#include "JavascriptBridge.h"
#include "AccountSnapshot.h"

// Stuff for Ajax
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

// Fix later
using namespace cgicc;
using std::cout;

int main(){
  Cgicc cgi; // Ajax object
  JavaScriptBridge javaScriptBridge;

  //Receive info from web page
  string searchVal = javaScriptBridge.getElement("searchVal", cgi);
  vector<AccountSnapshot> searchResults;

  DatabaseBridge databaseBridge;
  vector<AccountSnapshot> results = databaseBridge.searchByAddress(searchVal);

  JavascriptBridge.sendAccountSnapshots(results);
  return 0;
}
