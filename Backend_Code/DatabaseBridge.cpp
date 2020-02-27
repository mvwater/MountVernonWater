//File Name: DatabaseBridge.cpp
//Author: M Brydon, S Kim, and S Canfield
//Email Address: brydon1@kenyon.edu, kim3@kenyon.edu, and canfield1@kenyon.edu
//Assignment: Project 3
//Description: General class that can communicate with our database
//Last Changed: February 18, 2019

#include "DatabaseBridge.h"

Statement DatabaseBridge::createStatement(string query){
  Driver* driver = sql::mysql::get_driver_instance();
  Connection con(driver->connect(address, DBUsername, password));
  con->setSchema(DBName);
  Statement statement(con->createStatement());
  statement->execute(query);

  return statement;
}
