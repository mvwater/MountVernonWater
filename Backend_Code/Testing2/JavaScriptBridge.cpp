//File Name: JavaScriptBridge.cpp
//Author: M Brydon, S Kim, S Canfield
//Email Address: brydon1@kenyon.edu, kim3@kenyon.edu, canfield1@kenyon.edu
//Project: Mount Vernon Water
//Description: Sends output and gets input to and from JavaScript through Ajax
//Last Changed: March 26, 2020

#include "JavaScriptBridge.h"

// Final string will have sep at end
string JavaScriptBridge::printAccountInfo(AccountInfo accountInfo){
	string result, sep("*");
	result += accountInfo.getAccountNo() + sep + accountInfo.getStatus()+ sep + accountInfo.getstartDate() + sep + accountInfo.getResident().name + sep + accountInfo.getLandlord().name; 

	// Has comments
	//if (accountInfo.getHasComments()){
	//	result += "T" + sep;
	//} else {
	//	result += "F" + sep;
	//}

	/*// Has text
	if (accountInfo.getHasText()){
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

string JavaScriptBridge::accountInfosToStr(vector<AccountInfo> searchResults){
	AccountInfo accountInfo;
  	string jsMessage = "";
	for (uint i=0; i<searchResults.size(); i++){
	    accountInfo = searchResults.at(i);
	    jsMessage += printAccountInfo(accountInfo);
	}
	return jsMessage;
}

void JavaScriptBridge::sendAccountInfos(vector<AccountInfo> searchResults){
	sendMessage(accountInfosToStr(searchResults));
}

void JavaScriptBridge::sendMessage(string message){
  cout << "Content-Type: text/plain\n\n" << message;
}
