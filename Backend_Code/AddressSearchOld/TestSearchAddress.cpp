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








	cout << "About to create query."<< endl;
	string query("SELECT * FROM accounts WHERE CONCAT(TAdd1, ' ', TAdd2, ' ', TAdd3) LIKE '%" + searchVal + "%';");

	vector<AccountSnapshot> searchResults = databaseBridge.queryDatabase(query);



	// Receive vector of AccountSnapshot objects from database
	//vector<AccountSnapshot> searchResults = databaseBridge.searchByAddress(searchVal);



	/*
	JavaScriptBridge javaScriptBridge;
	cout << javaScriptBridge.accountSnapshotsToStr(searchResults) << endl;*/
	return 0;
}
