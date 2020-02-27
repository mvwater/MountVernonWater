//File Name: DatabaseBridge.cpp
//Author: M Brydon, S Kim, S Canfield

//Email Address: kim3@kenyon.edu, brydon1@kenyon.edu, canfield1@kenyon.edu
//Dev Project: Mount Vernon Water
//Description: General class that can communicate with our database
//Last Changed: 23 February 2020

#include "DatabaseBridge.h"

Statement DatabaseBridge::createStatement(string query){
  Driver* driver = sql::mysql::get_driver_instance();
  Connection con(driver->connect(address, DBUsername, password));
  con->setSchema(DBName);
  Statement statement(con->createStatement());
  statement->execute(query);

  return statement;
}
