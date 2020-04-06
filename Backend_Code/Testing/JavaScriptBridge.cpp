//File Name: JavaScriptBridge.cpp
//Author: M Brydon, S Kim, S Canfield
//Email Address: brydon1@kenyon.edu, kim3@kenyon.edu, canfield1@kenyon.edu
//Project: Mount Vernon Water
//Description: Sends output and gets input to and from JavaScript through Ajax
//Last Changed: March 26, 2020

#include "JavaScriptBridge.h"

// Final string will have sep at end
string JavaScriptBridge::printAccountSnapshot(AccountSnapshot accountSnapshot){
	string result, sep("*");
	Address resAddress = accountSnapshot.getResAddress()
	result += accountSnapshot.getAccountNo() + sep + resAddress.add1 + sep + resAddress.add2 + sep + resAddress.add3 + sep + accountSnapshot.resAddressLastLine() + sep; 

	// Has comments
	if (accountSnapshot.getHasComments()){
		result += "T" + sep;
	} else {
		result += "F" + sep;
	}

	/*// Has text
	if (accountSnapshot.getHasText()){
		result += "T" + sep;
	} else {
		result += "F" + sep;
	}*/

   return result;
}

string JavaScriptBridge::getElement(string element, Cgicc &cgi){

  form_iterator itElement = cgi.getElement(element);
  string returnElement = **itElement;

  return returnElement;
}

string JavaScriptBridge::accountSnapshotsToStr(vector<AccountSnapshot> searchResults){
	AccountSnapshot accountSnapshot;
  	string jsMessage = "";
	for (uint i=0; i<searchResults.size(); i++){
	    accountSnapshot = searchResults.at(i);
	    jsMessage += printAccountSnapshot(accountSnapshot);
	}
	return jsMessage;
}

void JavaScriptBridge::sendAccountSnapshots(vector<AccountSnapshot> searchResults){
	sendMessage(accountSnapshotsToStr(searchResults));
}

void JavaScriptBridge::sendMessage(string message){
  cout << "Content-Type: text/plain\n\n" << message;
}
