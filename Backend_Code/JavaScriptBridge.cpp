//File Name: JavaScriptBridge.cpp
//Author: M Brydon, S Kim, S Canfield
//Email Address: brydon1@kenyon.edu, kim3@kenyon.edu, canfield1@kenyon.edu
//Project: Mount Vernon Water
//Description: Sends output and gets input to and from JavaScript through Ajax
//Last Changed: 24 April 2020

#include "JavaScriptBridge.h"

// Final string will have sep at end

string JavaScriptBridge::printAccountInfo(AccountInfo accountInfo){
	string result, sep("*");
	// Resident
	result += accountInfo.getAccountNo() + sep + accountInfo.getStatus()+ sep + accountInfo.getstartDate() + sep + accountInfo.getResident().name + sep + accountInfo.getResident().address.add1 + sep + accountInfo.getResident().address.add2 + sep + accountInfo.getResident().address.add3 + sep + accountInfo.getResident().address.city + sep + accountInfo.getResident().address.state + sep + accountInfo.getResident().address.zip + sep + accountInfo.getResident().phoneNum + sep + accountInfo.getResident().email + sep + accountInfo.getResident().SScan + sep + accountInfo.getResident().DLNum + sep + accountInfo.getResident().cellNum + sep + accountInfo.getResident().dob + sep;

	// Landlord
	result +=  accountInfo.getLandlord().name + sep + accountInfo.getLandlord().address.add1 + sep + accountInfo.getLandlord().address.add2 + sep + accountInfo.getLandlord().address.add3 + sep + accountInfo.getLandlord().address.city + sep + accountInfo.getLandlord().address.state + sep + accountInfo.getLandlord().address.zip + sep + accountInfo.getLandlord().phoneNum + sep + accountInfo.getLandlord().email + sep + accountInfo.getLandlord().SScan + sep + accountInfo.getLandlord().DLNum + sep + accountInfo.getLandlord().cellNum + sep + accountInfo.getLandlord().dob + sep;

   return result;
}


// CANNOT PARSE; must edit
string JavaScriptBridge::printBillingInfo(BillingInfo billingInfo){
	
	string result, sep("*");
	
	//Adding BillingInfo
	for (uint i = 0; i<billingInfo.getReceivables().size(); i ++){
		result += billingInfo.getReceivables()[i].Invoice + sep + billingInfo.getReceivables()[i].Inv_date + sep + billingInfo.getReceivables()[i].Amount + sep + billingInfo.getReceivables()[i].To_post + sep + billingInfo.getReceivables()[i].Amt_paid + sep + billingInfo.getReceivables()[i].Paid_date + sep + billingInfo.getReceivables()[i].Refer + sep + billingInfo.getReceivables()[i].Balance + sep;
	}
	
	for (uint i = 0; i<billingInfo.getConsumption().size(); i ++){
		result += billingInfo.getConsumption()[i].Bill_date + sep + billingInfo.getConsumption()[i].Beg_read + sep + billingInfo.getConsumption()[i].End_read + sep + billingInfo.getConsumption()[i].Read_date + sep + billingInfo.getConsumption()[i].Service + sep + billingInfo.getConsumption()[i].Cons + sep + billingInfo.getConsumption()[i].Amount + sep + billingInfo.getConsumption()[i].Penalty + sep;
	}
	
	for (uint i = 0; i<billingInfo.getPayments().size(); i ++){
		result += billingInfo.getPayments()[i].Pay_date + sep + billingInfo.getPayments()[i].Amount_Paid + sep + billingInfo.getPayments()[i].Type + sep + billingInfo.getPayments()[i].Reference + sep + billingInfo.getPayments()[i].Batch + sep + billingInfo.getPayments()[i].Seq + sep;
	}


   return result;
}


string JavaScriptBridge::printCommentInfo(CommentInfo commentInfo){
	string result, sep("*");
	for (uint i = 0; i<commentInfo.getComments().size(); i ++){
		result += commentInfo.getComments()[i] + sep;
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

   return result;
}

string JavaScriptBridge::getElement(string element, Cgicc &cgi){

  form_iterator itElement = cgi.getElement(element);
  string returnElement = **itElement;

  return returnElement;
}

// Consider making template functions
string JavaScriptBridge::accountInfosToStr(vector<AccountInfo> searchResults){
	AccountInfo accountInfo;
  	string jsMessage = "";
	for (uint i=0; i<searchResults.size(); i++){
	    accountInfo = searchResults.at(i);
	    jsMessage += printAccountInfo(accountInfo);
	}
	return jsMessage;
}

string JavaScriptBridge::billingInfoToStr(BillingInfo searchResult){
	BillingInfo billingInfo;
	billingInfo = searchResult;
  	string jsMessage = "";
	
	jsMessage += printBillingInfo(billingInfo);
	
	return jsMessage;
}

string JavaScriptBridge::commentInfoToStr(CommentInfo searchResult){
	CommentInfo commentInfo;
	commentInfo = searchResult;
  	string jsMessage = "";
	
	jsMessage += printCommentInfo(commentInfo);
	
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
	sendMessage(billingInfoToStr(searchResult));
}

void JavaScriptBridge::sendCommentInfo(CommentInfo searchResult){
	sendMessage(commentInfoToStr(searchResult));
}

void JavaScriptBridge::sendMessage(string message){
  cout << "Content-Type: text/plain\n\n" << message;
}
