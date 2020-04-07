//File Name: AccountSnapshot.cpp
//Author: Shane, Michaela, and Sejin
//Email Address: canfield1@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Mount Vernon City Water Database
//Description: Snapshot of an account
//Last Changed: 7 April 2020

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
    
}

string AccountInfo::getAccountNo(){
	
	return accountNo;
}

string AccountInfo::getStatus(){
	
	return status;
}

string AccountInfo::getstartDate(){
	
	return startDate;
}

string AccountInfo::getResident(){
	
	return resident;
}

string AccountInfo::getLandlord(){
	
	return landlord;
}




	
	
	
	
	
}

