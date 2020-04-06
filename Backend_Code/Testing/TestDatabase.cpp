#include <iostream>
#include <string>
#include <vector>
#include "DatabaseBridge.h"
#include "JavaScriptBridge.h"
#include "AccountSnapshot.h"

using std::cout;

int main(){
	string searchVal = "Delaware";
	DatabaseBridge databaseBridge;
	// Receive vector of AccountSnapshot objects from database
	//vector<AccountSnapshot> searchResults = databaseBridge.searchByAddress(searchVal);
	vector<AccountSnapshot> searchResults = databaseBridge.queryDatabase(searchVal);

	JavaScriptBridge javaScriptBridge;
	cout << javaScriptBridge.accountSnapshotsToStr(searchResults) << endl;
	return 0;
}