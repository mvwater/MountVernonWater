#include <string>
#include <vector>
#include "AccountSnapshot.h"

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

//#define HOST "174.138.60.6:3306" // Set IP address instead of localhost
#define HOST "localhost"
#define USER "brydon1" // Maybe rename
#define DB "mvwater" 
#define PASS "clangrelationsheet"
/*#define HOST "localhost"
#define USER "brydon1" // Maybe rename
#define DB "brydon1" 
#define PASS "S217079"*/

typedef std::unique_ptr<sql::Statement> Statement;
typedef sql::Driver Driver;
typedef std::unique_ptr<sql::Connection> Connection;
typedef std::unique_ptr<sql::ResultSet> ResultSet; // Not yet used

class DatabaseBridge{
  public:
  	//DatabaseBridge();

    Statement queryDatabase(string query);
    // Returns sql Statement object with executed query

    vector<AccountSnapshot> searchByAddress(string address);
    // Returns vector of AccountSnapshot objects after searching by address

    vector<string> commentsByAccountNo(string accountNo);
    // Returns vector of comments after searching comment database by accountNo

  private:
    const string password = PASS;
    const string DBName = DB;
    const string address = HOST;
    const string DBUsername = USER;
    //vector<string> resAddressCols;
};

#endif //DATABASEBRIDGE_H
