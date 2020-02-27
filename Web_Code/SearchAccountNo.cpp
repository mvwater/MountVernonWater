//#include "ArtLookup.h"
//#include "Query.h"
#include "DatabaseBridge.h"
#include "JavaScriptBridge.h"
#include <iostream>
#include <string>

// Stuff for Ajax
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

// Fix later
using namespace cgicc;
using std::cout;

int main(){
  Cgicc cgi; // Ajax object
  JavaScriptBridge javaScriptBridge;

  //Receive info from web page
  string searchVal = javaScriptBridge.getElement("searchVal", cgi);
  string searchCategory = javaScriptBridge.getElement("searchCategory", cgi);

  ArtLookup artLookup;
  Query query;
  vector<Artwork> searchResults;

  //If the user didn't choose to search by category use general lookup to get
  //search results
  if( searchCategory == "undefined" ){
    searchResults = artLookup.lookupGeneral( searchVal );
  }
  //Else lookup using the category they specified to get search results
  else {
    searchResults = artLookup.lookupSingleCommand( query.matchSingleCol( searchVal, searchCategory ) );
    //vector<Artwork> searchResults = artLookup.lookupSingleCommand( query.matchSingleCol( searchVal, searchCategory ) );
  }

  //Sends artwork data to JavaScript
  Artwork artwork;
  string result = "";
  for (uint i = 0; i < searchResults.size(); i++){
    artwork = searchResults.at(i);
    result += jSCommunicator.printArtwork(artwork);
  }
  jSCommunicator.sendStringToJS(result);
  // cout << "Content-Type: text/plain\n\n";
  // cout << result << endl;

  return 0;
}
