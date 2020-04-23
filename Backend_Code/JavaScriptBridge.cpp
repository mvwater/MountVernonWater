//File Name: JavaScriptBridge.cpp
//Author: M Brydon, S Kim, S Canfield
//Email Address: brydon1@kenyon.edu, kim3@kenyon.edu, canfield1@kenyon.edu
//Project: Mount Vernon Water
//Description: Sends output and gets input to and from JavaScript through Ajax
//Last Changed: 20 April 2020

#include "JavaScriptBridge.h"

// Final string will have sep at end
string JavaScriptBridge::printAccountInfo(AccountInfo accountInfo){
	string result, sep("*");
	result += accountInfo.getAccountNo() + sep + accountInfo.getStatus()+ sep + accountInfo.getstartDate() + sep + accountInfo.getResident().name + sep + accountInfo.getResident().address.add1 + sep + accountInfo.getResident().address.add2 + sep + accountInfo.getResident().address.add3 + sep + accountInfo.getResident().address.city + sep + accountInfo.getResident().address.state + sep + accountInfo.getResident().address.zip + sep + accountInfo.getResident().phoneNum + sep + accountInfo.getResident().email + sep + accountInfo.getResident().SScan + sep + accountInfo.getResident().DLNum + sep + accountInfo.getResident().cellNum + sep + accountInfo.getResident().dob + sep + accountInfo.getLandlord().name + sep + accountInfo.getLandlord().address.add1 + sep + accountInfo.getLandlord().address.add2 + sep + accountInfo.getLandlord().address.add3 + sep + accountInfo.getLandlord().address.city + sep + accountInfo.getLandlord().address.state + sep + accountInfo.getLandlord().address.zip + sep + accountInfo.getLandlord().phoneNum + sep + accountInfo.getLandlord().email + sep + accountInfo.getLandlord().SScan + sep + accountInfo.getLandlord().DLNum + sep + accountInfo.getLandlord().cellNum + sep + accountInfo.getLandlord().dob + sep;
	
	//Adding BillingInfo
	for (uint i = 0; i<accountInfo.getBillingInfo().receivables_info.size(); i ++){
		result += accountInfo.getBillingInfo().receivables_info[i].Invoice + sep + accountInfo.getBillingInfo().receivables_info[i].Inv_date + sep + accountInfo.getBillingInfo().receivables_info[i].Amount + sep + accountInfo.getBillingInfo().receivables_info[i].To_post + sep + accountInfo.getBillingInfo().receivables_info[i].Amt_paid + sep + accountInfo.getBillingInfo().receivables_info[i].Paid_date + sep + accountInfo.getBillingInfo().receivables_info[i].Refer + sep + accountInfo.getBillingInfo().receivables_info[i].Balance + sep;
		//result += sep;
	}
	
	for (uint i = 0; i<accountInfo.getBillingInfo().consumption_info.size(); i ++){
		result += accountInfo.getBillingInfo().consumption_info[i].Bill_date + sep + accountInfo.getBillingInfo().consumption_info[i].Beg_read + sep + accountInfo.getBillingInfo().consumption_info[i].End_read + sep + accountInfo.getBillingInfo().consumption_info[i].Read_date + sep + accountInfo.getBillingInfo().consumption_info[i].Service + sep + accountInfo.getBillingInfo().consumption_info[i].Cons + sep + accountInfo.getBillingInfo().consumption_info[i].Amount + sep + accountInfo.getBillingInfo().consumption_info[i].Penalty + sep;
		//result += sep;
	}
	
	for (uint i = 0; i<accountInfo.getBillingInfo().payments_info.size(); i ++){
		result += accountInfo.getBillingInfo().payments_info[i].Pay_date + sep + accountInfo.getBillingInfo().payments_info[i].Amount_Paid + sep + accountInfo.getBillingInfo().payments_info[i].Type + sep + accountInfo.getBillingInfo().payments_info[i].Reference + sep + accountInfo.getBillingInfo().payments_info[i].Batch + sep + accountInfo.getBillingInfo().payments_info[i].Seq + sep;
		//result += sep;
	}
	

		
	//result += accountInfo.getBillingInfo().receivables_info[i] + sep + accountInfo.getBillingInfo().payments_info + sep + accountInfo.getBillingInfo().consumption_info + sep;

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

string JavaScriptBridge::printAccountSnapshot(AccountSnapshot accountSnapshot){
	string result, sep("*");
	Address resAddress = accountSnapshot.getResAddress();
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

string JavaScriptBridge::accountInfosToStr(vector<AccountInfo> searchResults){
	AccountInfo accountInfo;
  	string jsMessage = "";
	for (uint i=0; i<searchResults.size(); i++){
	    accountInfo = searchResults.at(i);
	    jsMessage += printAccountInfo(accountInfo);
	}
	return jsMessage;
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

void JavaScriptBridge::sendAccountInfos(vector<AccountInfo> searchResults){
	sendMessage(accountInfosToStr(searchResults));
}

void JavaScriptBridge::sendAccountSnapshots(vector<AccountSnapshot> searchResults){
	sendMessage(accountSnapshotsToStr(searchResults));
}

void JavaScriptBridge::sendMessage(string message){
  cout << "Content-Type: text/plain\n\n" << message;
}
