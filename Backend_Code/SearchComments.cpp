#include <iostream>
#include <string>
#include <vector>
#include "DatabaseBridge.h"
#include "JavaScriptBridge.h"
#include "AccountInfo.h"
#include "BillingInfo.h"
#include "CommentInfo.h"

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
  
  CommentInfo searchResult = databaseBridge.commentInfoByAccountNo(searchVal);

  // Send search results to JavaScript 
  

// REPLACED for testing
  javaScriptBridge.sendMessage("Hello.");
  //javaScriptBridge.sendCommentInfo(searchResult);
  return 0;
}
