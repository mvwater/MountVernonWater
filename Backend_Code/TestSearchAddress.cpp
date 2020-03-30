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

	vector<AccountSnapshot> searchResults = databaseBridge.queryDatabase(searchVal);

	// Receive vector of AccountSnapshot objects from database
	/*vector<AccountSnapshot> searchResults = databaseBridge.searchByAddress(searchVal);

	JavaScriptBridge javaScriptBridge;
	cout << javaScriptBridge.accountSnapshotsToStr(searchResults) << endl;*/
	return 0;
}
