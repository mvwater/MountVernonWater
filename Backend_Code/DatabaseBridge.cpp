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
	statement->execute(query);
	cout << "Query executed."<< endl;
	return statement;
}

// Must input accountNo with - instead of * as separaters
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
}

vector<AccountSnapshot> DatabaseBridge::searchByAddress(string address){
	string query("SELECT * FROM accounts WHERE CONCAT(TAdd1, ' ', TAdd2, ' ', TAdd3) LIKE '%" + address + "%';");
	Statement statement = queryDatabase(query);

	ResultSet searchMatches;
	AccountSnapshot *accountSnapshot;
	vector<AccountSnapshot> accountResultList;

	do {
	    searchMatches.reset(statement->getResultSet());
	    while (searchMatches->next()) {
	    	string accountNo = searchMatches -> getString("AccountNo");
	    	Address resAddress;
	    	//How to best add spacing?
	    	resAddress.streetname += searchMatches -> getString("TAdd1") + " ";
	    	resAddress.streetname += searchMatches -> getString("TAdd2") + " ";
	    	resAddress.streetname += searchMatches -> getString("TAdd3");

	    	resAddress.city += searchMatches -> getString("TCity");
	    	resAddress.state += searchMatches -> getString("TState");
	    	resAddress.zip += searchMatches -> getString("TZip");
			
			int numComments = commentsByAccountNo(accountNo).size();
			bool hasComments(false);
	    	if (numComments != 0){
	    		hasComments = true;
	    	}

			//Use pointer to dynamically create accountSnapshot
			accountSnapshot = new AccountSnapshot(accountNo, resAddress, hasComments);
			accountResultList.push_back(*(accountSnapshot));
			delete accountSnapshot; // Deallocate memory in accountSnapshot
	    }
  	} while (statement->getMoreResults());
  return accountResultList;
}



