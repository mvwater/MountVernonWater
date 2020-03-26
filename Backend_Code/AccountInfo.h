#include <string>

using namespace std;

#ifndef ACCOUNTINFO_H
#define ACCOUNTINFO_H

struct Address {
  string streetname;
  string address_number;
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

class AccountInfo{
  public:
    // Accessor Member Functions; all return data member
    string getAccountNo();
    string getStatus();

    // Default Constructor
    Account();

  private:
    string accountNo;
    string status;
    string startDate;
    Person resident;
    Person landlord;
};

#endif //ACCOUNTINFO_H
