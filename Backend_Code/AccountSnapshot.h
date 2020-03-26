#include <string>

using namespace std;

#ifndef ACCOUNTSNAPSHOT_H
#define ACCOUNTSNAPSHOT_H

// struct ArtistInfo {
//   string author;
//   string birthDeath;
//   };

// Uppercase class does not work
class AccountInfo{
  public:

    // Accessor Member Functions; all return data member
    int getAccountNo();
    //string getAddress();

    Account();
    //Preconditions: All variables must come from the table in the Team5 sql
    //database. The parameters are listed in the same order as the respective
    //columns
    //Postconditions: Relevant data is stored in member variables including ArtistInfo, ArtSetting and ArtStyle structs

  private:
    int accountNo;
    bool hasComments;
    //string address;

};

#endif //ACCOUNTSNAPSHOT_H
