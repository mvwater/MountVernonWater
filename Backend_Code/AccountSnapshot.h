#include <string>

using namespace std;

#ifndef ACCOUNTSNAPSHOT_H
#define ACCOUNTSNAPSHOT_H

struct Address {
  string streetname;
  string city;
  string state;
  string zip;
};

// Uppercase class does not work
class AccountSnapshot{
  public:
    // Constructor
    AccountSnapshot();
    // AccountSnapshot(string inputAccountNo, Address inputResAddress, bool inputHasComments, bool inputHasText);
    AccountSnapshot(string inputAccountNo, Address inputResAddress, bool inputHasComments);

    // Accessor Member Functions; all return data member
    string getAccountNo();
    Address getResAddress();
    bool getHasComments();
    //bool getHasText();

    string returnFullResAddress();

  private:
    string accountNo; // Maybe accountNo object?
    Address resAddress;
    bool hasComments;
    //bool hasText;
};

#endif //ACCOUNTSNAPSHOT_H
