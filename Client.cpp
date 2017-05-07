#include "World.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string/predicate.hpp>
#include "./StringTokenizer/StringTokenizer.hpp"

using namespace std;

void logo(){
	printf(" _____     _   _   _ _ _       _      _____\n");
	printf("|     |_ _|_|_| |_| |_| |_ ___| |_   |     |___ ___ ___ ___ ___ ___\n");
	printf("|  |  | | | | . | . | |  _|  _|   |  | | | | .'|   | .'| . | -_|  _|\n");
	printf("|__  _|___|_|___|___|_|_| |___|_|_|  |_|_|_|__,|_|_|__,|_  |___|_|\n");
	printf("   |__|                                                |___|\n\n\n");
}

void printHelp(){
  printf("COMMANDS\n");
  printf("  help\n");
  printf("    -shows this menu\n");
  printf("  quit\n");
  printf("    -saves and exits\n");
  printf("  save\n");
  printf("    -just saves the game\n");
  printf("  display\n");
  printf("    -prints the roster for every team\n");
}

int main(){
	srand(time(NULL));
	string saveName, input;
  bool done = false;
  bool loadLoop = true;
	World *world;
  StringTokenizer ST;
  logo();
	
  //begin loading loop
  while(loadLoop){
    ifstream saveFile;
	  printf("Enter a savefile name, or type 'new' to start a new game!\nQMAN: ");
	  cin >> saveName;
	
    if(boost::iequals(saveName, "new")){
      printf("Starting a new game! Enter a name for your savefile\nQMAN: ");
      cin >> saveName;
      world = new World(saveName, true);
      loadLoop = false;
    }else{
	    saveFile.open("./save/" + saveName + ".txt");
	    if(saveFile.is_open()){
		    cout << "Save file exists!\n";
        	saveFile.close();
		    world = new World(saveName, false);
        loadLoop = false;
      }else{
		    cout << "Unable to open save file\n";
	    }
    }
  }

  printf("type 'help' for list of commands\n");

  //begin client loop	
  vector<string> temp;
  int tempInt;
  cin.ignore(INT_MAX, '\n');
  cin.clear();
  while(!done){
    printf("QMAN: ");
    
    getline(cin, input);
    temp = ST.tokenize(input);

    if(boost::iequals(temp[0], "help")){
      printHelp();
    }else if(boost::iequals(temp[0], "exit") || boost::iequals(temp[0], "quit")){
      cout << "Saving and exiting...\n";
      world->saveGame("#");
      done = true;
    }else if(boost::iequals(temp[0], "save")){
      cout << "Saving...\n";
      world->saveGame("#");
      cout << "Saved!\n";
    }else if(boost::iequals(temp[0], "simweek")){
      cout << "Advancing week...\n";
      tempInt = world->simWeek();
      if(tempInt >= 0){
        cout << "Your team is invalid! Fix it and try again!\n";
      }else{
        cout << "Successfully advanced\n";
      }
    }else if(boost::iequals(temp[0], "display")){
      world->display();
    }

    cout << "\n";
  }
  //end client loop
	return 0;
}
