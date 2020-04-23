#include <iostream>
#include <string>
#include <vector>
#include "DatabaseBridge.h"
#include "JavaScriptBridge.h"
#include "AccountInfo.h"
#include "AccountSnapshot.h"
#include "BillingInfo.h"

using std::cout;

int main(){
	string searchVal = "104-23-1";
	
	//string query("SELECT * FROM accounts WHERE CONCAT(TAdd1, ' ', TAdd2, ' ', TAdd3) LIKE '%" + searchVal + "%';");
	

	DatabaseBridge databaseBridge;
	// Receive vector of AccountSnapshot objects from database
	//vector<AccountInfo> searchResults = databaseBridge.searchByAccount2(searchVal);
	
	
	BillingInfo searchResult = databaseBridge.billingInfoByAccountNo(searchVal);
	

	//vector<AccountSnapshot> searchResults = databaseBridge.queryDatabase(query);

	JavaScriptBridge javaScriptBridge;
	//cout << javaScriptBridge.accountInfosToStr(searchResults) << endl;
	
	cout << javaScriptBridge.billingInfoToStr(searchResult) << endl;
	return 0;
}