//File Name: BillingInfo.h
//Author: Shane, Michaela, and Sejin
//Email Address: canfield1@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Mount Vernon City Water Database
//Description: Header file for Account Billing Information
//Last Changed: 24 April 2020

#include <string>
#include <vector>

using namespace std;

#ifndef BILLINGINFO_H
#define BILLINGINFO_H

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

struct Payments{
	
	string Pay_date;
	string Amount_Paid;
	string Type;
	string Reference;
	string Batch; 
	string Seq;

};




class BillingInfo {
  public:
  
	BillingInfo();
	BillingInfo(string input_accountNo, vector<Receivables> input_receivables, vector<Consumption> input_consumption, vector<Payments> input_payments);
	
	string getAccountNo();
	vector<Receivables> getReceivables();
	vector<Consumption> getConsumption();
	vector<Payments> getPayments();
	

  private:
	string accountNo;
    vector<Receivables> receivables;
	vector<Consumption> consumption;
	vector<Payments> payments;
};

#endif //BILLINGINFO_H
