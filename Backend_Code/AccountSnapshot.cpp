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
  //hasText = 0;
}

// AccountSnapshot::AccountSnapshot(string inputAccountNo, Address inputAddress, bool inputHasComments, bool inputHasText){
AccountSnapshot::AccountSnapshot(string inputAccountNo, Address inputAddress, bool inputHasComments){
  accountNo = inputAccountNo;
  resAddress.streetname = inputAddress.streetname;
  resAddress.city = inputAddress.city;
  resAddress.state = inputAddress.state;
  resAddress.zip = inputAddress.zip;
  hasComments = inputHasComments;
  //hasText = inputHasText;
}

string AccountSnapshot::getAccountNo(){
  return accountNo;
}

Address AccountSnapshot::getResAddress(){
  return address;
}

bool AccountSnapshot::getHasComments(){
  return hasComments;
}

// bool AccountSnapshot::getHasText(){
//   return hasText;
// }

string AccountSnapshot::returnFullResAddress(){
	string result(resAddress.streetname);
	result+= "\n" + resAddress.city + ", " + resAddress.state + resAddress.zip;
	return result;
}




