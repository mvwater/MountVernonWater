//File Name: AccountInfo.cpp
//Author: Shane, Michaela, and Sejin
//Email Address: canfield1@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Mount Vernon City Water Database
//Description: Detailed data representation of an account
//Last Changed: March 26, 2020

#include "AccountInfo.h"
#include <iostream>

using std::cout;

string AccountInfo::getAccountNo(){
  return accountNo;
}

string AccountInfo::getAddress(){
  return address;
}

