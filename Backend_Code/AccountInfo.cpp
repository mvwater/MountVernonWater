//File Name: AccountInfo.cpp
//Author: Shane, Michaela, and Sejin
//Email Address: canfield1@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Mount Vernon City Water Database
//Description: Full Account Information
//Last Changed: 23 April 2020

#include "AccountSnapshot.h"
#include "AccountInfo.h"
#include <iostream>

using std::cout;

AccountInfo::AccountInfo(){
	accountNo = "";
	status = "";
	startDate = "";
	Person resident{"","","","","","","",""};
	Person landlord{"","","","","","","",""};

}

AccountInfo::AccountInfo(string inputAccountNo, string inputStatus, string inputstartDate, Person inputresident, Person inputlandlord){
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


