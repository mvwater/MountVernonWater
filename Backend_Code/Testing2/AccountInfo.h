#include <string>

using namespace std;

#ifndef ACCOUNTINFO_H
#define ACCOUNTINFO_H


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

class AccountInfo{
  public:
  
	AccountInfo();
	AccountInfo(string inputAccountNo, string inputStatus, string inputstartDate, Person inputresident, Person inputlandlord);
    string getAccountNo();
    string getStatus();

    // Default Constructor
    
    

  private:
    string accountNo;
    string status;
    string startDate;
    Person resident;
    Person landlord;
};

#endif //ACCOUNTINFO_H
