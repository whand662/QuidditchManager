#include "Team.hpp"

Team::Team(){
	name = "Default constructor teamname!";
	money = 5000;
	roster = RosterQ();
}

Team::Team(string teamName){
	name = teamName;
	money = 5000;
	roster = RosterQ(true);
}

Team::Team(ifstream *inFile){ 
  inFile->ignore(INT_MAX, '\n');
  getline(*inFile, name);
  *inFile >> money;
  roster = RosterQ(inFile);
}

string Team::getName(){
	return name;
}

void Team::display(){
	printf("%s\n", name.c_str());
	printf("Funds: %d\n", money);
	roster.display();
}

bool Team::isValid(){
	return roster.isValid();
}

Player Team::getPlayer(string position){
	return roster.getPlayer(position);
}

Player Team::getPlayer(int position){
	return roster.getPlayer(position);
}

int Team::getTeamScuffle(){
	return roster.getTeamScuffle();
}

int Team::getOverall(){

}

string Team::getSaveString(){
  string temp = name + "\n" + to_string(money) + "\n";
  temp += roster.getSaveString();
  return temp;
}

void Team::tick(){

}

