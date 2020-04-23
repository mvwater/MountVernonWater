//File Name: AccountSnapshot.cpp
//Author: Shane, Michaela, and Sejin
//Email Address: canfield1@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Mount Vernon City Water Database
//Description: Snapshot of an account
//Last Changed: 21 April 2020

#include "AccountInfo.h"
#include <iostream>

using std::cout;

AccountInfo::AccountInfo(){
	accountNo = "";
	status = "";
	startDate = "";
	Person resident{"","","","","","","",""};
	Person landlord{"","","","","","","",""};
	BillingInfo billinginfo;
	Comments comments;

}

AccountInfo::AccountInfo(string inputAccountNo, string inputStatus, string inputstartDate, Person inputresident, Person inputlandlord, BillingInfo inputbillinginfo, Comments inputcomments){
    accountNo = inputAccountNo;
    status = inputStatus;
    startDate = inputstartDate;
	
	resident.name = inputresident.name;
	resident.phoneNum = inputresident.phoneNum;
	resident.email = inputresident.email;
	resident.SScan = inputresident.SScan;
	resident.DLNum = inputresident.DLNum;
	resident.cellNum = inputresident.cellNum;
	resident.dob = inputresident.dob;
	
	landlord.name = inputlandlord.name;
	landlord.phoneNum = inputlandlord.phoneNum;
	landlord.email = inputlandlord.email;
	landlord.SScan = inputlandlord.SScan;
	landlord.DLNum = inputlandlord.DLNum;
	landlord.cellNum = inputlandlord.cellNum;
	landlord.dob = inputlandlord.dob;
	
	resident.address.add1 = inputresident.address.add1;
	resident.address.add2 = inputresident.address.add2;
	resident.address.add3 = inputresident.address.add3;
	resident.address.city = inputresident.address.city;
	resident.address.state = inputresident.address.state;
	resident.address.zip = inputresident.address.zip;
	
	landlord.address.add1 = inputlandlord.address.add1;
	landlord.address.add2 = inputlandlord.address.add2;
	landlord.address.add3 = inputlandlord.address.add3;
	landlord.address.city = inputlandlord.address.city;
	landlord.address.state = inputlandlord.address.state;
	landlord.address.zip = inputlandlord.address.zip;
	
	cout << "AccountInfo.cpp:Adding receivable info" << endl;
	
	for (uint i=0; i<inputbillinginfo.receivables_info.size(); i++){
		billinginfo.receivables_info[i].Invoice = inputbillinginfo.receivables_info[i].Invoice;
		billinginfo.receivables_info[i].Inv_date = inputbillinginfo.receivables_info[i].Inv_date;
		billinginfo.receivables_info[i].Amount = inputbillinginfo.receivables_info[i].Amount;
		billinginfo.receivables_info[i].To_post = inputbillinginfo.receivables_info[i].To_post;
		billinginfo.receivables_info[i].Amt_paid = inputbillinginfo.receivables_info[i].Amt_paid;
		billinginfo.receivables_info[i].Paid_date = inputbillinginfo.receivables_info[i].Paid_date;
		billinginfo.receivables_info[i].Refer = inputbillinginfo.receivables_info[i].Refer;
		billinginfo.receivables_info[i].Balance = inputbillinginfo.receivables_info[i].Balance;
	}
	
	cout << "AccountInfo.cpp:Adding consumption info" << endl;
	for (uint i=0; i<inputbillinginfo.consumption_info.size(); i++){
		
		billinginfo.consumption_info[i].Bill_date = inputbillinginfo.consumption_info[i].Bill_date;
		billinginfo.consumption_info[i].Beg_read = inputbillinginfo.consumption_info[i].Beg_read;
		billinginfo.consumption_info[i].End_read = inputbillinginfo.consumption_info[i].End_read;
		billinginfo.consumption_info[i].Read_date = inputbillinginfo.consumption_info[i].Read_date;
		billinginfo.consumption_info[i].Service = inputbillinginfo.consumption_info[i].Service;
		billinginfo.consumption_info[i].Cons = inputbillinginfo.consumption_info[i].Cons;
		billinginfo.consumption_info[i].Amount = inputbillinginfo.consumption_info[i].Amount;
		billinginfo.consumption_info[i].Penalty = inputbillinginfo.consumption_info[i].Penalty;
	}
	cout << "AccountInfo.cpp:Adding payments info" << endl;
	for (uint i=0; i<inputbillinginfo.payments_info.size(); i++){
		
		billinginfo.payments_info[i].Pay_date = inputbillinginfo.payments_info[i].Pay_date;
		billinginfo.payments_info[i].Amount_Paid = inputbillinginfo.payments_info[i].Amount_Paid;
		billinginfo.payments_info[i].Type = inputbillinginfo.payments_info[i].Type;
		billinginfo.payments_info[i].Reference = inputbillinginfo.payments_info[i].Reference;
		billinginfo.payments_info[i].Batch = inputbillinginfo.payments_info[i].Batch;
		billinginfo.payments_info[i].Seq = inputbillinginfo.payments_info[i].Seq;
		
	}
	
	cout << "AccountInfo.cpp: Adding comments info" << endl;
	for (uint i=0; i<inputcomments.comments_list.size(); i++){
		
		comments.comments_list[i] = inputcomments.comments_list[i];
		
	}
	cout << "AccountInfo.cpp: initializing hasComments" << endl;
	
	comments.hasComments = inputcomments.hasComments;
	
	cout << "AccountInfo.cpp: Done with constructor" << endl;
    
}

string AccountInfo::getAccountNo(){
	
	return accountNo;
}

string AccountInfo::getStatus(){
	
	return status;
}

string  AccountInfo::getstartDate(){
	
	return startDate;
}

Person AccountInfo::getResident(){
	
	return resident;
}

Person AccountInfo::getLandlord(){
	
	return landlord;
}

BillingInfo AccountInfo::getBillingInfo(){
	
	return billinginfo;
}

Comments AccountInfo::getComments(){
	
	return comments;
}

bool AccountInfo::getHasComments(){
	
	return comments.hasComments;
}

