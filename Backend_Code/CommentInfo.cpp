//File Name: CommentInfo.cpp
//Author: Shane, Michaela, and Sejin
//Email Address: canfield1@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Mount Vernon City Water Database
//Description: Comment Information for Account
//Last Changed: 24 April 2020

#include "CommentInfo.h"
#include <iostream>

using std::cout;
using std::vector;

CommentInfo::CommentInfo(){
	accountNo = "";
	vector<string> comments;
	bool hasComments = 0;
}

CommentInfo::CommentInfo(string input_accountNo, vector<string> input_comments, bool input_hasComments){
	
    accountNo = input_accountNo;
	comments = input_comments;
	hasComments = input_hasComments;

}


string CommentInfo::getAccountNo(){
	return accountNo;
}

vector<string> CommentInfo::getComments(){
	return comments;
}

bool CommentInfo::getHasComments(){
	return hasComments;
}