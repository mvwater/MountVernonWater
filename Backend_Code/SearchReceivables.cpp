#include <iostream>
#include <string>
#include <vector>
#include "DatabaseBridge.h"
#include "JavaScriptBridge.h"
#include "AccountInfo.h"
#include "AccountSnapshot.h"
#include "BillingInfo.h"
// Stuff for Ajax
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

// Fix later
using namespace cgicc;
//using std::cout;

int main(){
  Cgicc cgi; // Ajax object
  JavaScriptBridge javaScriptBridge;

  //Receive info from web page

  string searchVal = javaScriptBridge.getElement("accountNo", cgi);
  DatabaseBridge databaseBridge;

  // Receive vector of AccountSnapshot objects from database
  vector<Receivables> searchResult = databaseBridge.receivablesByAccountNo(searchVal);

  // Send search results to JavaScript
  javaScriptBridge.sendReceivablesInfos(searchResults);
  return 0;
}
