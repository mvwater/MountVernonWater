//File Name: DatabaseBridge.cpp
//Author: M Brydon, S Kim, S Canfield

//Email Address: kim3@kenyon.edu, brydon1@kenyon.edu, canfield1@kenyon.edu
//Dev Project: Mount Vernon Water
//Description: General class that can communicate with our database
//Last Changed: 27 March 2020

#include "DatabaseBridge.h"
using std::cout;

/*
DatabaseBridge::DatabaseBridge(){
	resAddressCols.push_back("TAdd1");
	resAddressCols.push_back("TAdd2");
	resAddressCols.push_back("TAdd3");
	resAddressCols.push_back("TCity");
	resAddressCols.push_back("TState");
	resAddressCols.push_back("TZip");
}*/

Statement DatabaseBridge::queryDatabase(string query){
	cout << "About to connect."<< endl;
	Driver* driver = sql::mysql::get_driver_instance();
	cout << "Created driver."<< endl;
	Connection con(driver->connect(address, DBUsername, password));
	cout << "Created connection."<< endl;
	con->setSchema(DBName);
	cout << "Setting database."<< endl;
	Statement statement(con->createStatement());
	cout << "Creating statement."<< endl;
	

	//statement->execute(query);
	//cout << "Query executed."<< endl;
	return statement;
}



/*
vector<AccountSnapshot> DatabaseBridge::queryDatabase(string query){
//Statement DatabaseBridge::queryDatabase(string query){
	cout << "About to connect."<< endl;
	Driver* driver = sql::mysql::get_driver_instance();
	cout << "Created driver."<< endl;
	Connection con(driver->connect(address, DBUsername, password));
	cout << "Created connection."<< endl;
	con->setSchema(DBName);
	cout << "Setting database."<< endl;
	Statement statement(con->createStatement());
	cout << "Creating statement."<< endl;
	statement->execute(query);
	cout << "Query executed."<< endl;
	

	ResultSet searchMatches;
	AccountSnapshot *accountSnapshot;
	vector<AccountSnapshot> accountResultList;

	cout << "Beginning while loop."<< endl;
	do {
		// Issue here
	    searchMatches.reset(statement->getResultSet());

	    cout << "Reset resultSet."<< endl;
	    while (searchMatches->next()) {
	    	string accountNo = searchMatches -> getString("AccountNo");
	    	cout << "AccountNo: " << accountNo << endl;
	    	Address resAddress;

	    	resAddress.add1 += searchMatches -> getString("TAdd1");
	    	cout << "Add1: " << resAddress.add1 << endl;
	    	resAddress.add2 += searchMatches -> getString("TAdd2");
	    	cout << "Add2: " << resAddress.add2 << endl;
	    	resAddress.add3 += searchMatches -> getString("TAdd3");
	    	cout << "Add3: " << resAddress.add3 << endl;

	    	resAddress.city += searchMatches -> getString("TCity");
	    	cout << "City: " << resAddress.city << endl;
	    	resAddress.state += searchMatches -> getString("TState");
	    	cout << "State: " << resAddress.state << endl;
	    	resAddress.zip += searchMatches -> getString("TZip");
	    	cout << "Zip: " << resAddress.zip << endl << endl;

			//Use pointer to dynamically create accountSnapshot
			accountSnapshot = new AccountSnapshot(accountNo, resAddress, true);
			accountResultList.push_back(*(accountSnapshot));
			delete accountSnapshot; // Deallocate memory in accountSnapshot
	    }
  	} while (statement->getMoreResults());
  	cout << "Done."<< endl;
  	return accountResultList;

	//return statement;
}*/



// Must input accountNo with - instead of * as separaters
/*
vector<string> DatabaseBridge::commentsByAccountNo(string accountNo){
	string query("SELECT * FROM comments WHERE AccountNo = '" + accountNo + "';");
	Statement statement = queryDatabase(query);
	ResultSet commentMatches;
	vector<string> commentResultList;
	do {
    	commentMatches.reset(statement->getResultSet());
	    while (commentMatches->next()) {
	    	string comment = commentMatches -> getString("Comment");
	    	commentResultList.push_back(comment);
	    }
  	} while (statement->getMoreResults());
  	return commentResultList;
}*/



vector<AccountSnapshot> DatabaseBridge::searchByAddress(string inputAddress){
	cout << "About to create query."<< endl;
	string query("SELECT * FROM accounts WHERE CONCAT(TAdd1, ' ', TAdd2, ' ', TAdd3) LIKE '%" + inputAddress + "%';");

	//Statement statement = queryDatabase(query);
	//cout << "Statement created."<< endl;

	// ADDED fix?????
	cout << "About to connect."<< endl;
	Driver* driver = sql::mysql::get_driver_instance();
	cout << "Created driver."<< endl;
	Connection con(driver->connect(address, DBUsername, password));
	cout << "Created connection."<< endl;
	con->setSchema(DBName);
	cout << "Setting database."<< endl;
	Statement statement(con->createStatement());
	cout << "Creating statement."<< endl;
	statement->execute(query);






	ResultSet searchMatches;
	AccountSnapshot *accountSnapshot;
	vector<AccountSnapshot> accountResultList;

	cout << "Beginning while loop."<< endl;
	do {
		// Issue here
	    searchMatches.reset(statement->getResultSet());



	    cout << "Reset resultSet."<< endl;
	    while (searchMatches->next()) {
	    	string accountNo = searchMatches -> getString("AccountNo");
	    	cout << "AccountNo: " << accountNo << endl;
	    	Address resAddress;
	    	
	    	resAddress.add1 += searchMatches -> getString("TAdd1");
	    	cout << "Add1: " << resAddress.add1 << endl;
	    	resAddress.add2 += searchMatches -> getString("TAdd2");
	    	cout << "Add2: " << resAddress.add2 << endl;
	    	resAddress.add3 += searchMatches -> getString("TAdd3");
	    	cout << "Add3: " << resAddress.add3 << endl;

	    	resAddress.city += searchMatches -> getString("TCity");
	    	cout << "City: " << resAddress.city << endl;
	    	resAddress.state += searchMatches -> getString("TState");
	    	cout << "State: " << resAddress.state << endl;
	    	resAddress.zip += searchMatches -> getString("TZip");
	    	cout << "Zip: " << resAddress.zip << endl;
			
			/*
			int numComments = commentsByAccountNo(accountNo).size();
			cout << "NumComments: " << numComments << endl;
			bool hasComments(false);
	    	if (numComments != 0){
	    		hasComments = true;
	    	}*/

			//Use pointer to dynamically create accountSnapshot
			//accountSnapshot = new AccountSnapshot(accountNo, resAddress, hasComments);
			accountSnapshot = new AccountSnapshot(accountNo, resAddress, true);
			accountResultList.push_back(*(accountSnapshot));
			delete accountSnapshot; // Deallocate memory in accountSnapshot
	    }
  	} while (statement->getMoreResults());
  cout << "Done."<< endl;
  return accountResultList;
}



