//File Name: AccountSnapshot.cpp
//Author: Shane, Michaela, and Sejin
//Email Address: canfield1@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Mount Vernon City Water Database
//Description: Snapshot of an account
//Last Changed: March 26, 2020

#include "AccountSnapshot.h"
#include <iostream>

using std::cout;

AccountSnapshot::AccountSnapshot(){
  accountNo = "";
  Address resAddress{ "", "", "", "" };
  hasComments = 0;
  hasText = 0;
}

AccountSnapshot::AccountSnapshot(string inputAccountNo, Address inputAddress, bool inputHasComments, bool inputHasText){
  accountNo = inputAccountNo;
  resAddress = inputAddress;
  hasComments = titleFromDB;
  hasText = urlFromDB;
}

string AccountSnapshot::getAccountNo(){
  return accountNo;
}

Address AccountSnapshot::getAddress(){
  return address;
}

bool AccountSnapshot::getHasComments(){
  return hasComments;
}

bool AccountSnapshot::getHasText(){
  return hasText;
}

  string streetname;
  string city;
  string state;
  string zip;

string AccountSnapshot::returnFullResAddress(){
	string result(address.streetname);
	result+= "\n" + address.city + ", " + address.state + address.zip;
	return result;
}




