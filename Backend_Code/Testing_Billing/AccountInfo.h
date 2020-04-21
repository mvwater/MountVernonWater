//File Name: AccountSnapshot.cpp
//Author: Shane, Michaela, and Sejin
//Email Address: canfield1@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Mount Vernon City Water Database
//Description: Snapshot of an account
//Last Changed: 19 April 2020

#include <string>

using namespace std;

#ifndef ACCOUNTINFO_H
#define ACCOUNTINFO_H

struct Address {
	string add1;
	string add2;
	string add3;
	string city;
	string state;
	string zip;
};


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
	AccountInfo(string inputAccountNo, string inputStatus, string inputstartDate, Person inputresident, Person inputlandlord, bool inputHasComments);
	string getAccountNo();
	string getStatus();
	string getstartDate();
	Person getResident();
	Person getLandlord();
	bool getHasComments();   

  private:
    	string accountNo;
    	string status;
	string startDate;
	Person resident;
	Person landlord;
	bool hasComments;
};

#endif //ACCOUNTINFO_H
