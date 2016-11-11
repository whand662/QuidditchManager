#include "Player.hpp"

Player::Player(){
	
}

Player::Player(int lvl){

}


Player::Player(string n){
	name = n;
	
}

string Player::getName(){
	return name;
}

bool Player::isBlank(){
	if(name.compare("Empty") == 0){
		return true;
	}
	return false;
}

void Player::display(){

}

bool Player::gainEXP(int exp){

}

//stat checkers

int Player::getSeek(){
	return (stats[SPEED].getActual() + stats[REACTION].getActual() + stats[INTELLIGENCE].getActual()) / 3;
}

int Player::getPass(){
	return stats[INTELLIGENCE].getActual();
}

int Player::getShoot(){
	return stats[STRENGTH].getActual();
}

int Player::getBlock(){
	return (stats[SPEED].getActual() + stats[REACTION].getActual()) / 2;
}

int Player::getDefend(){
	return (stats[STRENGTH].getActual() + stats[REACTION].getActual()) / 2;
}

int Player::getScuffle(){
	return (stats[SPEED].getActual() + stats[REACTION].getActual() + stats[STRENGTH].getActual()) / 3;
}

int Player::getPersonality(){
	return stats[PERSONALITY].getActual();
}

