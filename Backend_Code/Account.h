#include <string>

using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

// struct ArtistInfo {
//   string author;
//   string birthDeath;
//   };

// struct ArtSetting {
//     string date;
//     string location;
//     string timeframe;
//   };

// struct ArtStyle {
//     string technique;
//     string school;
//     string type;
//     string form;
//   };

// Uppercase class does not work
class Account{
  public:

    // Accessor Member Functions; all return data member
    int getAccountNo();
    //string getAddress();

    Account();
    //Preconditions: All variables must come from the table in the Team5 sql
    //database. The parameters are listed in the same order as the respective
    //columns
    //Postconditions: Relevant data is stored in member variables including ArtistInfo, ArtSetting and ArtStyle structs

    //Account(int artId, string author, string birthDeath, string title, string technique, string location, string url, string form, string type,
    //string school,string timeframe, string date, int numLikes);
    //Preconditions: None
    //Postconditions: The member variable numLikes will be incremented

  private:
    int accountNo;
    bool hasComments;
    //string address;

};

#endif //ACCOUNT_H
