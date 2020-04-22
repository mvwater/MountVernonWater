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
    //Address resAddress{ "", "", "", "" };
    Address resAddress{ "", "", "", "", "", "" };
    hasComments = 0;
}

// AccountSnapshot::AccountSnapshot(string inputAccountNo, Address inputAddress, bool inputHasComments, bool inputHasText){
AccountSnapshot::AccountSnapshot(string inputAccountNo, Address inputAddress, bool inputHasComments){
    accountNo = inputAccountNo;
    resAddress.add1 = inputAddress.add1;
    resAddress.add2 = inputAddress.add2;
    resAddress.add3 = inputAddress.add3;
    resAddress.city = inputAddress.city;
    resAddress.state = inputAddress.state;
    resAddress.zip = inputAddress.zip;
    hasComments = inputHasComments;
}

string AccountSnapshot::getAccountNo(){
    return accountNo;
}

Address AccountSnapshot::getResAddress(){
    return resAddress;
}

bool AccountSnapshot::getHasComments(){
    return hasComments;
}

// Maybe Delete?
string AccountSnapshot::resAddressLastLine(){
    string result(resAddress.city);
    result += ", " + resAddress.state + " " + resAddress.zip;
    return result;
}



