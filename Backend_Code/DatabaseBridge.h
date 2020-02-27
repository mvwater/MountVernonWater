#include <string>

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

#define HOST "localhost" // Set IP address instead of localhost
#define USER "brydon1"
#define DB "Team5" // RENAME!!!!!!!
#define PASS "S217079"

typedef std::unique_ptr<sql::Statement> Statement;
typedef sql::Driver Driver;
typedef std::unique_ptr<sql::Connection> Connection;
typedef std::unique_ptr<sql::ResultSet> ResultSet; // Not yet used

class DatabaseBridge{
  public:
    Statement queryDatabase(string query);
    // Returns sql Statement object with executed query

  private:
    const string password = PASS;
    const string DBName = DB;
    const string address = HOST;
    const string DBUsername = USER;
};

#endif //DATABASEBRIDGE_H
