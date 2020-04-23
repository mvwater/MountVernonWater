//File Name: JavaScriptBridge.cpp
//Author: M Brydon, S Kim, S Canfield
//Email Address: brydon1@kenyon.edu, kim3@kenyon.edu, canfield1@kenyon.edu
//Project: Mount Vernon Water
//Description: Sends output and gets input to and from JavaScript through Ajax
//Last Changed: 23 April 2020

#include "JavaScriptBridge.h"

// Final string will have sep at end

string JavaScriptBridge::printAccountInfo(AccountInfo accountInfo){
	string result, sep("*");
	result += accountInfo.getAccountNo() + sep + accountInfo.getStatus()+ sep + accountInfo.getstartDate() + sep + accountInfo.getResident().name + sep + accountInfo.getResident().address.add1 + sep + accountInfo.getResident().address.add2 + sep + accountInfo.getResident().address.add3 + sep + accountInfo.getResident().address.city + sep + accountInfo.getResident().address.state + sep + accountInfo.getResident().address.zip + sep + accountInfo.getResident().phoneNum + sep + accountInfo.getResident().email + sep + accountInfo.getResident().SScan + sep + accountInfo.getResident().DLNum + sep + accountInfo.getResident().cellNum + sep + accountInfo.getResident().dob + sep + accountInfo.getLandlord().name + sep + accountInfo.getLandlord().address.add1 + sep + accountInfo.getLandlord().address.add2 + sep + accountInfo.getLandlord().address.add3 + sep + accountInfo.getLandlord().address.city + sep + accountInfo.getLandlord().address.state + sep + accountInfo.getLandlord().address.zip + sep + accountInfo.getLandlord().phoneNum + sep + accountInfo.getLandlord().email + sep + accountInfo.getLandlord().SScan + sep + accountInfo.getLandlord().DLNum + sep + accountInfo.getLandlord().cellNum + sep + accountInfo.getLandlord().dob + sep;
	

   return result;
}

string JavaScriptBridge::printBillingInfo(BillingInfo billingInfo){
	
	string result, sep("*");
	
	//Adding BillingInfo
	for (uint i = 0; i<billingInfo.getReceivables().size(); i ++){
		result += billingInfo.getReceivables().receivables[i].Invoice + sep + billingInfo.getReceivables().receivables[i].Inv_date + sep + billingInfo.getReceivables().receivables[i].Amount + sep + billingInfo.getReceivables().receivables[i].To_post + sep + billingInfo.getReceivables().receivables[i].Amt_paid + sep + billingInfo.getReceivables().receivables[i].Paid_date + sep + billingInfo.getReceivables().receivables[i].Refer + sep + billingInfo.getReceivables().receivables[i].Balance + sep;
	}
	
	for (uint i = 0; i<billingInfo.getConsumption().size(); i ++){
		result += billingInfo.getConsconsumption().consumption[i].Bill_date + sep + billingInfo.getConsconsumption().consumption[i].Beg_read + sep + billingInfo.getConsconsumption().consumption[i].End_read + sep + billingInfo.getConsconsumption().consumption[i].Read_date + sep + billingInfo.getConsconsumption().consumption[i].Service + sep + billingInfo.getConsconsumption().consumption[i].Cons + sep + billingInfo.getConsconsumption().consumption[i].Amount + sep + billingInfo.getConsconsumption().consumption[i].Penalty + sep;
	}
	
	for (uint i = 0; i<billingInfo.getPayments().size(); i ++){
		result += billingInfo.getPayments().payments[i].Pay_date + sep + billingInfo.getPayments().payments[i].Amount_Paid + sep + billingInfo.getPayments().payments[i].Type + sep + billingInfo.getPayments().payments[i].Reference + sep + billingInfo.getPayments().payments[i].Batch + sep + billingInfo.getPayments().payments[i].Seq + sep;
	}


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

string JavaScriptBridge::accountBillingToStr(BillingInfo searchResult){
	BillingInfo billingInfo;
	billingInfo = searchResult;
  	string jsMessage = "";
	
	jMessage += printBillingInfo(billingInfo);
	
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

void JavaScriptBridge::sendBillingInfo(BillingInfo searchResult){
	sendMessage(accountBillingToStr(searchResult));
}

void JavaScriptBridge::sendMessage(string message){
  cout << "Content-Type: text/plain\n\n" << message;
}
