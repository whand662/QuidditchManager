#include "Roster.hpp"

Roster::Roster(){
	for(int i = 0; i <= 9; i++){
		roster[i] = BLANK;
	}
}

Roster::Roster(string fileName){
	//blah do saving/loading things
}

int Roster::add(Player player, string position){
	if(roster[pos2int(position)].isBlank()){	
		roster[pos2int(position)] = player;
		return 0;
	}else{
		printf("FAILURE: Destination is full: %s\n", position.c_str());
		return 1;
	}
}

Player Roster::drop(string position){
	if(roster[pos2int(position)].isBlank()){
		printf("FAILURE: No player to drop: %s\n", position.c_str());
		return BLANK;
	}	
	Player temp = roster[pos2int(position)];	
	roster[pos2int(position)] = BLANK;
	return temp;
}

int Roster::swap(string from, string to){
	Player temp = roster[pos2int(to)];
	roster[pos2int(to)] = roster[pos2int(from)];
	roster[pos2int(from)] = temp;
	return 0;
}

int Roster::move(string from, string to){
	if(roster[pos2int(to)].isBlank()){
		roster[pos2int(to)] = roster[pos2int(from)];
		roster[pos2int(from)] = BLANK;
		return 0;
	}else{
		printf("FAILURE: Destination is occupied: %s\n", to.c_str());
		return 1;
	}
}

Player Roster::getPlayer(string position){
	return roster[pos2int(position)];
}

Player Roster::getPlayer(int position){
	return roster[position];
}

bool Roster::isValid(){
	for(int i = 0; i <= 6; i++){
		if(roster[i].isBlank()){
			printf("FAILURE: Unfilled position: %s\n", int2pos(i).c_str());
			return false;
		}
		//check for broom?
	}

	return true;
}

int Roster::pos2int(string pos){
	transform(pos.begin(), pos.end(), pos.begin(), ::tolower);

	if(!pos.compare("seeker")){
		return 0;
	}else if(!pos.compare("keeper")){
		return 1;
	}else if(!pos.compare("leftbeater")){
		return 2;
	}else if(!pos.compare("rightbeater")){
		return 3;
	}else if(!pos.compare("leftchaser")){
		return 4;
	}else if(!pos.compare("rightchaser")){
		return 5;
	}else if(!pos.compare("centerchaser")){
		return 6;
	}else if(!pos.compare("firstbench")){
		return 7;
	}else if(!pos.compare("secondbench")){
		return 8;
	}else if(!pos.compare("thirdbench")){
		return 9;
	}else{
		printf("ERROR: Unrecognizable position string: %s\n", pos.c_str());
		printf("Returning thirdbench\n");
		printf("Try not leaving spaces in position?\n");		
		return 9;
	}
}

string Roster::int2pos(int pos){
	switch(pos){
		case 0:
			return "Seeker";
		case 1:
			return "Keeper";
		case 2:
			return "Left Beater";
		case 3:
			return "Right Beater";
		case 4:
			return "Left Chaser";
		case 5:
			return "Right Chaser";
		case 6:
			return "Center Chaser";
		case 7:
			return "First Bench";
		case 8:
			return "Second Bench";
		case 9:
			return "Third Bench";
		default:
			return "ERROR: Invalid position index";
	}
}

void Roster::display(){
	for(int i = 0; i <= 9; i++){
		printf("%s", int2pos(i).c_str());
		printf(": ");
		if(getPlayer(i).isBlank()){
			printf("Empty");
		}else{
			getPlayer(i).display();
		}
		printf("\n");
	}
	printf("\n");
}

int Roster::getTeamScuffle(){
	int temp = 0;
	for(int i = 0; i < 7; i++){
		temp += roster[i].getScuffle();
	}
	return temp / 7;
}

