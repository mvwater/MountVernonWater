//File Name: DatabaseBridge.cpp
//Author: M Brydon, S Kim, S Canfield
//Email Address: kim3@kenyon.edu, brydon1@kenyon.edu, canfield1@kenyon.edu
//Dev Project: Mount Vernon Water
//Description: General class that can communicate with our database
//Last Changed: 7 April 2020

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


Connection DatabaseBridge::connectToDatabase(){
	//cout << "About to connect."<< endl;
	Driver* driver = sql::mysql::get_driver_instance();
	//cout << "Created driver."<< endl;
	Connection con(driver->connect(address, DBUsername, password));
	//cout << "Created connection."<< endl;
	con->setSchema(DBName);
	//cout << "Setting database."<< endl;
	return con;
}


vector<string> DatabaseBridge::commentsByAccountNo(string accountNo){
	string query("SELECT * FROM comments WHERE AccountNo = '" + accountNo + "';");
	Connection con = connectToDatabase();
	Statement statement(con->createStatement());
	statement->execute(query);

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




vector<AccountInfo> DatabaseBridge::searchByAccount(string inputAccountNo){
	//cout << "About to create query."<< endl;
	string query("SELECT * FROM accounts WHERE AccountNo = '" + inputAccountNo + "';");

	Connection con = connectToDatabase();
	Statement statement(con->createStatement());
	//cout << "Creating statement."<< endl;
	statement->execute(query);

	ResultSet searchMatches;
	AccountInfo *accountInfo;
	vector<AccountInfo> accountResultList;

	do {
	    searchMatches.reset(statement->getResultSet());
	    while (searchMatches->next()) {
	    	string accountNo = searchMatches -> getString("AccountNo");
			string status = searchMatches -> getString("AcctStatus");
			string startDate = searchMatches -> getString("SrtDate");
	    	//cout << "AccountNo: " << accountNo << endl;
	    	Address resAddress;
			Address landAddress;
			Person resident;
			Person landlord;
	    	
			
			//We need address info for account search anyway so we can leave Michaela's resAddress work here
	    	resAddress.add1 += searchMatches -> getString("TAdd1");
	    	//cout << "Add1: " << resAddress.add1 << endl;
	    	resAddress.add2 += searchMatches -> getString("TAdd2");
	    	//cout << "Add2: " << resAddress.add2 << endl;
	    	resAddress.add3 += searchMatches -> getString("TAdd3");
	    	//cout << "Add3: " << resAddress.add3 << endl;

	    	resAddress.city += searchMatches -> getString("TCity");
	    	//cout << "City: " << resAddress.city << endl;
	    	resAddress.state += searchMatches -> getString("TState");
	    	//cout << "State: " << resAddress.state << endl;
	    	resAddress.zip += searchMatches -> getString("TZip");
	    	//cout << "Zip: " << resAddress.zip << endl << endl;
			
			landAddress.add1 += searchMatches -> getString("LAdd1");
	    	landAddress.add2 += searchMatches -> getString("LAdd2");
	    	landAddress.add3 += searchMatches -> getString("LAdd3");
	    	landAddress.city += searchMatches -> getString("LCity");
	    	landAddress.state += searchMatches -> getString("LSt");
	    	landAddress.zip += searchMatches -> getString("LZip");
				
			
			resident.name += searchMatches -> getString("TName");
			resident.phoneNum += searchMatches -> getString("TPhone");
			resident.email += searchMatches -> getString("TEmail");
			resident.SScan += searchMatches -> getString("TSScan");
			resident.DLNum += searchMatches -> getString("TDL#");
			resident.cellNum += searchMatches -> getString("TCell#");
			resident.dob += searchMatches -> getString("TDoB");
			
			landlord.name += searchMatches -> getString("LName");
			landlord.phoneNum += searchMatches -> getString("LPhone");
			landlord.email += searchMatches -> getString("LEmail");
			landlord.SScan += searchMatches -> getString("LSScan");
			landlord.DLNum += searchMatches -> getString("LDL#");
			landlord.cellNum += searchMatches -> getString("LCell#");
			landlord.dob += searchMatches -> getString("LDoB");

			
			
			
			
			int numComments = commentsByAccountNo(accountNo).size();
			cout << "NumComments: " << numComments << endl;
			bool hasComments(false);
	    	if (numComments != 0){
	    		hasComments = true;
	    	}
			
			
			

			//Use pointer to dynamically create accountSnapshot
			accountInfo = new AccountInfo(accountNo, status, startDate, resident, landlord, resAddress, landAddress, hasComments);
			//accountSnapshot = new AccountSnapshot(accountNo, resAddress, true);
			accountResultList.push_back(*(accountInfo));
			delete accountInfo; // Deallocate memory in accountSnapshot
	    }
  	} while (statement->getMoreResults());
  //cout << "Done."<< endl;
  return accountResultList;
}

