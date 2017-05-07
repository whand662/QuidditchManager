/**
  StringTokenizer.cpp
  Tool for parsing input strings

  @author Willis Hand
  @version 1.0
  @copyright 2017 Willis Hand
*/

#include "StringTokenizer.hpp"

StringTokenizer::StringTokenizer(){
  delimiters = DEFAULT_DELIMITERS;
}

StringTokenizer::StringTokenizer(string delims){
  delimiters = delims;
}

vector<string> StringTokenizer::tokenize(string line){
  vector<string> temp;	
	string holder = "";
	for(unsigned int i = 0; i < line.length(); i++){
    if(delimiters.find(line.at(i)) != string::npos){
      if(holder != ""){
        temp.push_back(holder);
        holder = "";
      }
		}else{
      holder += line.at(i);
    }
	}
  if(holder != ""){
    temp.push_back(holder);
    holder = "";
  }
  return temp;
}

vector<string> StringTokenizer::tokenize(string line, string delims){
  vector<string> temp;	
	string holder = "";
	for(unsigned int i = 0; i < line.length(); i++){
    if(delims.find(line.at(i)) != string::npos){
      if(holder != ""){
        temp.push_back(holder);
        holder = "";
      }
		}else{
      holder += line.at(i);
    }
	}
  if(holder != ""){
    temp.push_back(holder);
    holder = "";
  }
  return temp;
}

void StringTokenizer::setDefaultDelimiters(string delims){
  delimiters = delims;
}

