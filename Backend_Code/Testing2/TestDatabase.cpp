#include <iostream>
#include <string>
#include <vector>
#include "DatabaseBridge.h"
#include "JavaScriptBridge.h"
#include "AccountSnapshot.h"

using std::cout;

int main(){
	string searchVal = "23-60-8";
		

	DatabaseBridge databaseBridge;
	// Receive vector of AccountSnapshot objects from database
	vector<AccountInfo> searchResults = databaseBridge.searchByAccount(searchVal);
	

	//vector<AccountSnapshot> searchResults = databaseBridge.queryDatabase(query);

	JavaScriptBridge javaScriptBridge;
	cout << javaScriptBridge.accountSnapshotsToStr(searchResults) << endl;
	return 0;
}
