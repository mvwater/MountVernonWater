//File Name: DatabaseBridge.cpp
//Author: Michaela, Sejin, and Shane

// Add Shane's email!!!!!!

//Email Address: kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: General class that can communicate with our database
//Last Changed: November 13, 2019

#include "DatabaseBridge.h"

Statement DatabaseBridge::createStatement(string query){
  Driver* driver = sql::mysql::get_driver_instance();
  Connection con(driver->connect(address, DBUsername, password));
  con->setSchema(DBName);
  Statement statement(con->createStatement());
  statement->execute(query);
  
  return statement;
}
