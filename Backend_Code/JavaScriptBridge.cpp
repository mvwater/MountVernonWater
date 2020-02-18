//File Name: JavaScriptBridge.cpp
//Author: Michaela, Sejin, and Shane
//Email Address: brydon1@kenyon.edu, kim3@kenyon.edu,
//Project: City Water Archival Database
//Description: Sends output and gets input to and from JavaScript through Ajax
//Last Changed: February 17, 2020

#include "JavaScriptBridge.h"

/*
string JavaScriptBridge::printArtwork(Artwork artwork){
  string result, sep("*");
  result +=  to_string(artwork.getArtId()) + sep + artwork.getArtistInfo().author + sep + artwork.getArtistInfo().birthDeath + sep + artwork.getTitle() + sep + artwork.getArtStyle().technique + sep + artwork.getArtSetting().location + sep + artwork.getUrl() + sep + artwork.getArtStyle().form + sep + artwork.getArtStyle().type + sep + artwork.getArtStyle().school + sep + artwork.getArtSetting().timeframe + sep + artwork.getArtSetting().date + sep + to_string(artwork.getNumLikes()) + sep;

   return result;
}

string JavaScriptBridge::getElement(string element, Cgicc &cgi){

  form_iterator itElement = cgi.getElement(element);
  string returnElement = **itElement;

  return returnElement;
}
*/

void JavaScriptBridge::sendString(string message){
  cout << "Content-Type: text/plain\n\n" << message;
}
