#include "Team.hpp"

Team::Team(){
	name = "I didn't name my team!";
	money = 5000;
	roster = Roster();
}

Team::Team(string teamName){
	name = teamName;
	money = 5000;
	roster = Roster();
}

string Team::getName(){
	return name;
}

void Team::display(){
	printf("%s\n", name.c_str());
	printf("Funds: %d\n", money);
	roster.display();
}

bool Team::isPlayer(){
	return humanControlled;
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


