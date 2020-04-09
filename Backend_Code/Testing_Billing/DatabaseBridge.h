#include <string>
#include <vector>
#include "AccountInfo.h"

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

    //vector<AccountSnapshot> searchByAddress(string inputAddress);
    // Returns vector of AccountSnapshot objects after searching by address

    vector<string> commentsByAccountNo(string accountNo);
	
	
	vector<AccountInfo> searchByAccount(string inputAccount);
	
	
    // Returns vector of comments after searching comment database by accountNo

  private:
    const string password = PASS;
    const string DBName = DB;
    const string address = HOST;
    const string DBUsername = USER;
    //vector<string> resAddressCols;
};

#endif //DATABASEBRIDGE_H