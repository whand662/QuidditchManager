#include "RosterQ.hpp"

RosterQ::RosterQ(){
	for(int i = 0; i <= 9; i++){
		roster[i] = BLANK;
	}
}

RosterQ::RosterQ(bool autofill){
  NameGen ng = NameGen();
  if(autofill){
    for(int i = 0; i <= 6; i++){
		  roster[i] = Player(ng.genFull());
	  }
    for(int i = 7; i <= 9; i++){
		  roster[i] = BLANK;
	  }
  }else{
    for(int i = 0; i <= 9; i++){
		  roster[i] = BLANK;
	  }
  }
}

RosterQ::RosterQ(ifstream *inFile){
	for(int i = 0; i < ROSTER_SIZE; i++){
    roster[i] = Player(inFile);
  }
}

int RosterQ::add(Player player, string position){
	if(roster[pos2int(position)].isBlank()){	
		roster[pos2int(position)] = player;
		return 0;
	}else{
		printf("FAILURE: Destination is full: %s\n", position.c_str());
		return 1;
	}
}

Player RosterQ::drop(string position){
	if(roster[pos2int(position)].isBlank()){
		printf("FAILURE: No player to drop: %s\n", position.c_str());
		return BLANK;
	}	
	Player temp = roster[pos2int(position)];	
	roster[pos2int(position)] = BLANK;
	return temp;
}

int RosterQ::swap(string from, string to){
	Player temp = roster[pos2int(to)];
	roster[pos2int(to)] = roster[pos2int(from)];
	roster[pos2int(from)] = temp;
	return 0;
}

int RosterQ::move(string from, string to){
	if(roster[pos2int(to)].isBlank()){
		roster[pos2int(to)] = roster[pos2int(from)];
		roster[pos2int(from)] = BLANK;
		return 0;
	}else{
		printf("FAILURE: Destination is occupied: %s\n", to.c_str());
		return 1;
	}
}

Player RosterQ::getPlayer(string position){
	return roster[pos2int(position)];
}

Player RosterQ::getPlayer(int position){
	return roster[position];
}

bool RosterQ::isValid(){
	for(int i = 0; i <= 6; i++){
		if(roster[i].isBlank()){
			printf("FAILURE: Unfilled position: %s\n", int2pos(i).c_str());
			return false;
		}
		//check for broom?
	}

	return true;
}

int RosterQ::pos2int(string pos){
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

string RosterQ::int2pos(int pos){
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

void RosterQ::display(){
  printf("POSITION     NAME    AGE STR SPD RCT INT PER\n");
	for(int i = 0; i <= 9; i++){
		printf("%s", int2pos(i).c_str());
		printf(": ");
		if(getPlayer(i).isBlank()){
			printf("Empty\n");
		}else{
			getPlayer(i).display();
		}
	}
	printf("\n");
}

int RosterQ::getTeamScuffle(){
	int temp = 0;
	for(int i = 0; i < 7; i++){
		temp += roster[i].getScuffle();
	}
	return temp / 7;
}

string RosterQ::getSaveString(){
  string temp = "";
  for(int i = 0; i < 10; i++){
    temp += roster[i].getSaveString();
  }
  return temp;
}

void RosterQ::tick(){

}

