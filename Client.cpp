#include "World.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void logo(){
	printf(" _____     _   _   _ _ _       _      _____\n");
	printf("|     |_ _|_|_| |_| |_| |_ ___| |_   |     |___ ___ ___ ___ ___ ___\n");
	printf("|  |  | | | | . | . | |  _|  _|   |  | | | | .'|   | .'| . | -_|  _|\n");
	printf("|__  _|___|_|___|___|_|_| |___|_|_|  |_|_|_|__,|_|_|__,|_  |___|_|\n");
	printf("   |__|                                                |___|\n\n\n");
}

int main(){
	srand(time(NULL));
	string saveName;
	logo();
	World *world;
	
	printf("Enter a savefile name: ");
	cin >> saveName;
	saveName = "./save/" + saveName + ".txt";
	
	ifstream saveFile(saveName);
	if(saveFile.is_open()){
		cout << "Save file exists!\n";
    	saveFile.close();
		world = new World(saveName);
  	}else{
		cout << "Unable to open save file\n";
		printf("Creating savefile \"%s\"...\n\n", saveName.c_str());
		world = new World();
	}

	//run the world here!
	world->display();
	
	return 0;
}
