//File Name: AccountSnapshot.cpp
//Author: Shane, Michaela, and Sejin
//Email Address: canfield1@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Mount Vernon City Water Database
//Description: Snapshot of an account
//Last Changed: April 7th, 2020

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
	//Address address;
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
	AccountInfo(string inputAccountNo, string inputStatus, string inputstartDate, Person inputresident, Person inputlandlord, Address inputResAddress, Address inputLandAddress);
    string getAccountNo();
    string getStatus();
	string getstartDate();
	Person getResident();
	Person getLandlord();
	Address getResAddress();
	Address getLandAddress();
	bool getHasComments();

    // Default Constructor
    
    

  private:
    string accountNo;
    string status;
    string startDate;
    Person resident;
    Person landlord;
	Address resAddress;
	Address landAddress;
};

#endif //ACCOUNTINFO_H
