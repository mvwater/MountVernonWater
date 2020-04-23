#include <iostream>
#include <string>
#include <vector>
#include "DatabaseBridge.h"
#include "JavaScriptBridge.h"
#include "AccountInfo.h"
#include "AccountSnapshot.h"

using std::cout;

int main(){
	string searchVal = "10-59-1";
	
	//string query("SELECT * FROM accounts WHERE CONCAT(TAdd1, ' ', TAdd2, ' ', TAdd3) LIKE '%" + searchVal + "%';");
	

	DatabaseBridge databaseBridge;
	// Receive vector of AccountSnapshot objects from database
	vector<AccountInfo> searchResults = databaseBridge.searchByAccount2(searchVal);
	

	//vector<AccountSnapshot> searchResults = databaseBridge.queryDatabase(query);

	JavaScriptBridge javaScriptBridge;
	cout << javaScriptBridge.accountInfosToStr(searchResults) << endl;
	return 0;
}