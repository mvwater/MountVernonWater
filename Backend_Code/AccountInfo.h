//File Name: AccountInfo.h
//Author: Shane, Michaela, and Sejin
//Email Address: canfield1@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Mount Vernon City Water Database
//Description: Full Account Information
//Last Changed: 23 April 2020

#include <string>
#include <vector>
#include "AccountSnapshot.h"

using namespace std;

#ifndef ACCOUNTINFO_H
#define ACCOUNTINFO_H

//struct Address {
//	string add1;
//	string add2;
//	string add3;
//	string city;
//	string state;
//	string zip;
//};

//Address struct defined in AccountSnapshot.h


struct Person {
	string name;
	Address address;
	string phoneNum;
	string email;
	string SScan;
	string DLNum;
	string cellNum;
	string dob;
};



class AccountInfo {
  public:
  
	AccountInfo();
	AccountInfo(string inputAccountNo, string inputStatus, string inputstartDate, Person inputresident, Person inputlandlord);
	string getAccountNo();
	string getStatus();
	string getstartDate();
	Person getResident();
	Person getLandlord();


  private:
    string accountNo;
    string status;
	string startDate;
	Person resident;
	Person landlord;

};

#endif //ACCOUNTINFO_H
