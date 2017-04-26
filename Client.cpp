#include "World.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string/predicate.hpp>

#define INVALID_COMMAND -1
#define SAVE_COMMAND -2
#define QUIT_COMMAND -3
#define HELP_COMMAND -4
#define SIMWEEK_COMMAND -5

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

int checkValidCommand(string input){
  //special client commands  
  if(boost::iequals(input, "help")){
    return HELP_COMMAND;
  }
  if(boost::iequals(input, "exit") || boost::iequals(input, "quit")){
    return QUIT_COMMAND;
  }
  if(boost::iequals(input, "save")){
    return SAVE_COMMAND;
  }
  if(boost::iequals(input, "simweek")){
    return SIMWEEK_COMMAND;
  }
  //world commands
  if(boost::iequals(input, "display")){
    return 0;
  }
  //catch-all return -4 means input was not matched to a valid command
  return INVALID_COMMAND;
}

int main(){
	srand(time(NULL));
	string saveName, input;
  bool done = false;
  bool loadLoop = true;
  int handler;
	World *world;
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
  int temp; // for misc uses
  while(!done){
    printf("QMAN: ");
    cin >> input;
    /*
      HANDLER CODES
      returned from checkValidCommand function

      Anything >= 0 is the number of additional arguments needed
      This implies a valid command
      
      Negative values are defined above and will be special client-
      handled commands
    */
    handler = checkValidCommand(input);
    if(handler == INVALID_COMMAND){
      cout << "Invalid Command: " << input << "\n";
    }else if(handler == QUIT_COMMAND){
      cout << "Saving and exiting...\n";
      world->saveGame("#");
      done = true;
    }else if(handler == HELP_COMMAND){
      printHelp();
    }else if(handler == SAVE_COMMAND){
      cout << "Saving...\n";
      world->saveGame("#");
    }else if(handler == SIMWEEK_COMMAND){
      cout << "Advancing week...\n";
      temp = world->simWeek();
      if(temp >= 0){
        cout << "Your team is invalid! Fix it and try again!\n";
      }else{
        cout << "Successfully advanced\n";
      }
    }else{
      //gather arguments and pass to world
      world->display();
    }
    cout << "\n";
  }
  //end client loop
	return 0;
}
