//File Name: AccountSnapshot.cpp
//Author: Shane, Michaela, and Sejin
//Email Address: canfield1@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Mount Vernon City Water Database
//Description: Snapshot of an account
//Last Changed: 21 April 2020

#include <string>
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

struct Payments{
	
	string Pay_date;
	string Amount_Paid;
	string Type;
	string Reference;
	string Batch; 
	string Seq;

};

struct Consumption{
	
	string Bill_date;
	string Beg_read;
	string End_read;
	string Read_date;
	string Service;
	string Cons;
	string Amount; 
	string Penalty;

};

struct Receivables{
	
	string Invoice;
	string Inv_date;
	string Amount;
	string To_post;
	string Amt_paid; 
	string Paid_date;
	string Refer;
	string Balance;

};

struct BillingInfo{
	vector<Receivables> receivables_info;
	vector<Consumption> consumption_info;
	vector<Payments> payments_info;
};

struct Comments{
	vector<string> comments_list;
	bool hasComments;
};

class AccountInfo {
  public:
  
	AccountInfo();
	AccountInfo(string inputAccountNo, string inputStatus, string inputstartDate, Person inputresident, Person inputlandlord, BillingInfo inputbillinginfo, Comments inputcomments);
	string getAccountNo();
	string getStatus();
	string getstartDate();
	Person getResident();
	Person getLandlord();
	BillingInfo getBillingInfo();
	Comments getComments();  
	bool getHasComments();

  private:
    string accountNo;
    string status;
	string startDate;
	Person resident;
	Person landlord;
	BillingInfo billinginfo;
	Comments comments;
};

#endif //ACCOUNTINFO_H
