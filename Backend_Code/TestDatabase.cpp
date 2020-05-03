#include <iostream>
#include <string>
#include <vector>
#include "DatabaseBridge.h"
#include "JavaScriptBridge.h"
#include "AccountInfo.h"
#include "AccountSnapshot.h"
#include "BillingInfo.h"
#include "CommentInfo.h"

using std::cout;
using std::vector;

int main(){
	string searchVal = "104-23-1";

	//string query("SELECT * FROM accounts WHERE CONCAT(TAdd1, ' ', TAdd2, ' ', TAdd3) LIKE '%" + searchVal + "%';");


	DatabaseBridge databaseBridge;
	// Receive vector of AccountSnapshot objects from database
	//vector<AccountInfo> searchResults = databaseBridge.searchByAccount2(searchVal);

	cout << "Making CommentInfo object" << endl;

	//BillingInfo searchResult = databaseBridge.billingInfoByAccountNo(searchVal);

	//CommentInfo searchResult = databaseBridge.commentInfoByAccountNo(searchVal);


	//vector<AccountSnapshot> searchResults = databaseBridge.queryDatabase(query);
	vector<Payments> searchResult = databaseBridge.paymentsByAccountNo(searchVal);

	JavaScriptBridge javaScriptBridge;

	cout << "Making Javascript statement" << endl;
	//cout << javaScriptBridge.accountInfosToStr(searchResults) << endl;

	//cout << javaScriptBridge.billingInfoToStr(searchResult) << endl;
	//cout << javaScriptBridge.commentInfoToStr(searchResult) << endl;
	cout << javaScriptBridge.paymentsInfoToStr(searchResult) << endl;

	return 0;
}
