//File Name: DatabaseBridge.cpp
//Author: M Brydon, S Kim, S Canfield
//Email Address: kim3@kenyon.edu, brydon1@kenyon.edu, canfield1@kenyon.edu
//Dev Project: Mount Vernon Water
//Description: General class that can communicate with our database
//Last Changed: 24 April 2020

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

	ResultSet searchMatches;
	vector<string> commentResultList;
	do {
    	searchMatches.reset(statement->getResultSet());
	    while (searchMatches->next()) {
	    	string comment = searchMatches -> getString("Comment");
	    	commentResultList.push_back(comment);
	    }
  	} while (statement->getMoreResults());
  	return commentResultList;
}

vector<Payments> DatabaseBridge::paymentsByAccountNo(string accountNo){
	string query("SELECT * FROM payment WHERE AccountNo = '" + accountNo + "';");
	Connection con = connectToDatabase();
	Statement statement(con->createStatement());
	statement->execute(query);

	ResultSet searchMatches;
	vector<Payments> paymentsResultList;

	do {
    	searchMatches.reset(statement->getResultSet());
	    while (searchMatches->next()) {
			Payments paymentsResult;

	    	paymentsResult.Amount_Paid = searchMatches -> getString("Amount_Paid");
			paymentsResult.Type = searchMatches -> getString("Type");
			paymentsResult.Reference = searchMatches -> getString("Reference");
			paymentsResult.Batch = searchMatches -> getString("Batch");
			paymentsResult.Seq = searchMatches -> getString("Seq");

	    	paymentsResultList.push_back(paymentsResult);
	    }
  	} while (statement->getMoreResults());
  	return paymentsResultList;
}

vector<Consumption> DatabaseBridge::consumptionByAccountNo(string accountNo){
	string query("SELECT * FROM consumption WHERE AccountNo = '" + accountNo + "';");
	Connection con = connectToDatabase();
	Statement statement(con->createStatement());
	statement->execute(query);

	ResultSet searchMatches;
	vector<Consumption> consumptionResultList;


	do {
    	searchMatches.reset(statement->getResultSet());
	    while (searchMatches->next()) {
			Consumption consumptionResult;
			consumptionResult.Beg_date = searchMatches -> getString("Bill_date");
	    	consumptionResult.Beg_read = searchMatches -> getString("Beg_read");
			consumptionResult.End_read = searchMatches -> getString("End_read");
			consumptionResult.Read_date = searchMatches -> getString("Read_date");
			consumptionResult.Service = searchMatches -> getString("Service");
			consumptionResult.Cons = searchMatches -> getString("Cons");
			consumptionResult.Amount = searchMatches -> getString("Amount");
			consumptionResult.Penalty = searchMatches -> getString("Penalty");
	    	consumptionResultList.push_back(consumptionResult);
	    }
  	} while (statement->getMoreResults());
  	return consumptionResultList;
}

vector<Receivables> DatabaseBridge::receivablesByAccountNo(string accountNo){
	string query("SELECT * FROM receivables WHERE AccountNo = '" + accountNo + "';");
	Connection con = connectToDatabase();
	Statement statement(con->createStatement());
	statement->execute(query);
	ResultSet searchMatches;
	vector<Receivables> receivablesResultList;
	do{
		searchMatches.reset(statement->getResultSet());
		while (searchMatches->next()){
			cout << "Starting to grab from database" << endl;
			Receivables receivablesResult;
			receivablesResult.Invoice = searchMatches -> getString("Invoice");
			cout << "Invoice" << endl;
			receivablesResult.Inv_date = searchMatches -> getString("Inv_date");
			cout << "Inv_date" << endl;
			receivablesResult.Amount = searchMatches -> getString("Amount");
					cout << "Amount" << endl;
			receivablesResult.To_post = searchMatches -> getString("To_post");
			receivablesResult.Amt_paid = searchMatches -> getString("Amt_paid");
			receivablesResult.Paid_date = searchMatches -> getString("Paid_date");
			receivablesResult.Refer = searchMatches -> getString("Refer");
			receivablesResult.Balance = searchMatches -> getString("Balance");
			receivablesResultList.push_back(receivablesResult);
		}
  	} while (statement->getMoreResults());


	return receivablesResultList;
}


CommentInfo DatabaseBridge::commentInfoByAccountNo(string inputAccountNo){
	string query("SELECT * FROM comments WHERE AccountNo = '" + inputAccountNo + "';");
	Connection con = connectToDatabase();
	Statement statement(con->createStatement());
	statement->execute(query);

	ResultSet searchMatches;
	CommentInfo *commentInfo;
	vector<CommentInfo> commentResultList;

	do {
    	searchMatches.reset(statement->getResultSet());
	    while (searchMatches->next()) {
			string accountNo = searchMatches -> getString("AccountNo");

			vector<string> comments;
			comments = commentsByAccountNo(accountNo);

			int numComments = comments.size();

			bool hasComments=false;
	    	if (numComments != 0){
	    		hasComments = true;
	    	}

			commentInfo = new CommentInfo(accountNo, comments, hasComments);
			commentResultList.push_back(*(commentInfo));
			delete commentInfo;
			//cout << "Done" << endl;
	    }
  	} while (statement->getMoreResults());
  	return commentResultList[0];
}

BillingInfo DatabaseBridge::billingInfoByAccountNo(string inputAccountNo){

	cout << "billingInfoByAccountNo function starting..." << endl;
	string query("SELECT * FROM accounts WHERE AccountNo = '" + inputAccountNo + "';");

	Connection con = connectToDatabase();
	Statement statement(con->createStatement());
	cout << "Creating statement."<< endl;
	statement->execute(query);

	ResultSet searchMatches;

	cout << "Declaring BillingInfo Object"<< endl;
	BillingInfo *billingInfo;
	//searchMatches.reset(statement->getResultSet());
	//cout << "Starting loop"<< endl;

	vector<BillingInfo> billingResultList;

	do {
	    searchMatches.reset(statement->getResultSet());
		//cout << "searchMatches.reset(statement->getResultSet());" << endl;
	    while (searchMatches->next()) {
			//cout << "while (searchMatches->next()) {" << endl;
			cout << "Getting account number" << endl;
			string accountNo = searchMatches -> getString("AccountNo");
			cout << "Account No grabbed" << endl;

			cout << "Generating Receivables" << endl;
			vector<Receivables> receivables;
			receivables = receivablesByAccountNo(accountNo);

			cout << "Generating Consumption" << endl;
			vector<Consumption> consumption;
			consumption = consumptionByAccountNo(accountNo);

			cout << "Generating Payements" << endl;
			vector<Payments> payments;
			payments = paymentsByAccountNo(accountNo);

			cout << "Prepping BillingInfo object creation" << endl;

			billingInfo = new BillingInfo(accountNo, receivables, consumption, payments);
			billingResultList.push_back(*(billingInfo));
			delete billingInfo;
			cout << "Done" << endl;
		}
  	} while (statement->getMoreResults());

	return billingResultList[0];

}




vector<AccountSnapshot> DatabaseBridge::searchByAddress(string inputAddress){
	//cout << "About to create query."<< endl;
	string query("SELECT * FROM accounts WHERE CONCAT(TAdd1, ' ', TAdd2, ' ', TAdd3) LIKE '%" + inputAddress + "%';");

	Connection con = connectToDatabase();
	Statement statement(con->createStatement());
	//cout << "Creating statement."<< endl;
	statement->execute(query);

	ResultSet searchMatches;
	AccountSnapshot *accountSnapshot;
	vector<AccountSnapshot> accountResultList;
	int count(0);
	do {
	    searchMatches.reset(statement->getResultSet());
	    while (searchMatches->next()) {
	    	count++; // Testing

	    	string accountNo = searchMatches -> getString("AccountNo");
	    	//cout << "AccountNo: " << accountNo << endl;
	    	Address resAddress;

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


			int numComments = commentsByAccountNo(accountNo).size();
			//cout << "NumComments: " << numComments << endl;
			bool hasComments(false);
	    	if (numComments != 0){
	    		hasComments = true;
	    	}

			//Use pointer to dynamically create accountSnapshot
			accountSnapshot = new AccountSnapshot(accountNo, resAddress, hasComments);
			//accountSnapshot = new AccountSnapshot(accountNo, resAddress, true);
			accountResultList.push_back(*(accountSnapshot));
			delete accountSnapshot; // Deallocate memory in accountSnapshot
	    }
  	} while (statement->getMoreResults());
  //cout << count << endl;
  //cout << "Done."<< endl;
  return accountResultList;
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

			Person resident;
			Person landlord;

	    	resident.address.add1 += searchMatches -> getString("TAdd1");
	    	resident.address.add2 += searchMatches -> getString("TAdd2");
	    	resident.address.add3 += searchMatches -> getString("TAdd3");
	    	resident.address.city += searchMatches -> getString("TCity");
	    	resident.address.state += searchMatches -> getString("TState");
	    	resident.address.zip += searchMatches -> getString("TZip");

			landlord.address.add1 += searchMatches -> getString("LAdd1");
	    	landlord.address.add2 += searchMatches -> getString("LAdd2");
	    	landlord.address.add3 += searchMatches -> getString("LAdd3");
	    	landlord.address.city += searchMatches -> getString("LCity");
	    	landlord.address.state += searchMatches -> getString("LSt");
	    	landlord.address.zip += searchMatches -> getString("LZip");


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
			//landlord.cellNum += searchMatches -> getString("LCell#"); maybe make a new column for this
			landlord.dob += searchMatches -> getString("LDoB");


			//Use pointer to dynamically create accountInfo
			accountInfo = new AccountInfo(accountNo, status, startDate, resident, landlord);
			//accountSnapshot = new AccountSnapshot(accountNo, resAddress, true);
			accountResultList.push_back(*(accountInfo));

			delete accountInfo; // Deallocate memory in accountInfo
	    }
  	} while (statement->getMoreResults());
	//cout << "Done."<< endl;
	return accountResultList;
}
