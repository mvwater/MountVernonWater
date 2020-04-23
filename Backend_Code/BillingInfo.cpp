//File Name: BillingInfo.cpp
//Author: Shane, Michaela, and Sejin
//Email Address: canfield1@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Mount Vernon City Water Database
//Description: Billing (Payments, Consumption, Receivables) Information for Account
//Last Changed: 23 April 2020

#include "BillingInfo.h"
#include <iostream>

using std::cout;

BillingInfo::BillingInfo(){
	vector<Receivables> blank_receivables;
	receivables = blank_receivables;
	
	vector<Consumption> blank_consumption;
	consumption = blank_receivables;
	
	vector<Payments> blank_payments;
	payments = blank_payments;
}

BillingInfo::BillingInfo(string input_accountNo, vector<Receivables> input_receivables, vector<Consumption> input_consumption, vector<Payments> input_payments){
	
    accountNo = inputAccountNo;
    
	receivables = input_receivables;
	consumption = input_consumption;
	payments = input_payments;

    
}


string BillingInfo::getAccountNo(){
	return accountNo;
}



Receivables BillingInfo::getReceivables(){
	return receivables;
}


Consumption BillingInfo::getConsumption(){
	return consumption;
}


Payments BillingInfo::getPayments(){
	return payments;
}