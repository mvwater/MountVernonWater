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

class AccountInfo{
  public:
    // Accessor Member Functions; all return data member
    string getAccountNo();
    Address getAddress();

    // Default Constructor
    Account();

  private:
    string accountNo;
    Address address;
};

#endif //ACCOUNTINFO_H
