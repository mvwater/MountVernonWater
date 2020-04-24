//File Name: DatabaseBridge.h
//Author: M Brydon, S Kim, S Canfield
//Email Address: brydon1@kenyon.edu, kim3@kenyon.edu, canfield1@kenyon.edu
//Project: Mount Vernon Water
//Description: Header file for Database Communication
<<<<<<< HEAD
//Last Changed: 24 April 2020
=======
//Last Changed: 22 April 2020
>>>>>>> master

#include <string>
#include <vector>
#include "AccountInfo.h"
#include "AccountSnapshot.h"
#include "BillingInfo.h"
#include "CommentInfo.h"

using std::string;

// Need to save these packages in right location!
#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#ifndef DATABASEBRIDGE_H
#define DATABASEBRIDGE_H

#define HOST "localhost"
#define USER "canfield1"
#define DB "canfield1"
#define PASS "S216408"

//#define HOST "174.138.60.6:3306"
//#define USER "canfield1"
//#define DB "mvwater"
//#define PASS "mousesandwichhospital"

typedef std::unique_ptr<sql::Statement> Statement;
typedef sql::Driver Driver;
typedef std::unique_ptr<sql::Connection> Connection;
typedef std::unique_ptr<sql::ResultSet> ResultSet; // Not yet used

class DatabaseBridge{
  public:
  	//DatabaseBridge();

    Connection connectToDatabase();
    // Returns sql Connection object

    vector<AccountSnapshot> searchByAddress(string inputAddress);
    // Returns vector of AccountSnapshot objects after searching by address

    vector<string> commentsByAccountNo(string accountNo);
    // Returns vector of comments after searching comment database by accountNo
<<<<<<< HEAD
	
	vector<Payments> paymentsByAccountNo(string accountNo);
	// Returns vector of payments structs after searcching payment database by accountNo	
	
	vector<Consumption> consumptionByAccountNo(string accountNo);
	// Returns vector of consumption structs after searching consumption database by accountNo	
	
	vector<Receivables> receivablesByAccountNo(string accountNo);
	// Returns vector of receivable structs after searching receivables database by accountNo

	BillingInfo billingInfoByAccountNo(string inputAccountNo);
	// Returns a BillingInfo object after searching by accountNo
	
	CommentInfo commentInfoByAccountNo(string inputAccountNo);
	// Returns a CommentInfo object after searching by accountNo
	
	vector<AccountInfo> searchByAccount2(string inputAccountNo);
=======

	vector<AccountInfo> searchByAccount(string inputAccount);
>>>>>>> master
    // Returns vector of AccountInfo objects after searching account database by accountNo

  private:
    const string password = PASS;
    const string DBName = DB;
    const string address = HOST;
    const string DBUsername = USER;
    //vector<string> resAddressCols;
};

#endif //DATABASEBRIDGE_H
