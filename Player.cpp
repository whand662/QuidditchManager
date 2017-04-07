#include "Player.hpp"

Player::Player(){
	name = "Empty";
  age = 0;
  level = 0;
  EXP = 0;

  stats[0] = Stat("STRENGTH", 1);
  stats[1] = Stat("SPEED", 1);
  stats[2] = Stat("REACTION", 1);
  stats[3] = Stat("INTELLIGENCE", 1);
  stats[4] = Stat("PERSONALITY", 1);

  updateValue();
}

Player::Player(string n){
	name = n;
  age = 16;
  level = (rand() % 49) + 1;
  EXP = 0;

	stats[0] = Stat("STRENGTH", randomStat(level));
  stats[1] = Stat("SPEED", randomStat(level));
  stats[2] = Stat("REACTION", randomStat(level));
  stats[3] = Stat("INTELLIGENCE", randomStat(level));
  stats[4] = Stat("PERSONALITY", randomStat(level));

  updateValue();
}

Player::Player(string n, int lvl){
  name = n;
  age = 21;
  level = lvl;
  EXP = 10;

	stats[0] = Stat("STRENGTH", randomStat(lvl));
  stats[1] = Stat("SPEED", randomStat(lvl));
  stats[2] = Stat("REACTION", randomStat(lvl));
  stats[3] = Stat("INTELLIGENCE", randomStat(lvl));
  stats[4] = Stat("PERSONALITY", randomStat(lvl));

  updateValue();
}

Player::Player(ifstream *inFile){
  int temp1, temp2;
  inFile->ignore(INT_MAX, '\n');
  getline(*inFile, name);
  *inFile >> level;  
  *inFile >> age;
  *inFile >> value;
  *inFile >> EXP;

  stats[0] = Stat("STRENGTH", 1);
  stats[1] = Stat("SPEED", 1);
  stats[2] = Stat("REACTION", 1);
  stats[3] = Stat("INTELLIGENCE", 1);
  stats[4] = Stat("PERSONALITY", 1);
  
  for(int i = 0; i < NUM_STATS; i++){
    *inFile >> temp1;
    stats[i].setBase(temp1);
    *inFile >> temp1;
    *inFile >> temp2;
    stats[i].changeMod(temp1, temp2);
  }
}

void Player::tick(){

}

int Player::randomStat(int lvl){
  if(lvl < 1){
    return (rand() % 99);
  }else{
    return (rand() % 50 + (lvl / 2));
  }
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
  printf("%s %d %s %s %s %s %s\n", name.c_str(), age, stats[0].display().c_str(), stats[1].display().c_str(), stats[2].display().c_str(), stats[3].display().c_str(), stats[4].display().c_str());
}

bool Player::gainEXP(int exp){

}

void Player::updateValue(){
  int count = 0;
  for(int i = 0; i < 5; i++){
    count += stats[i].getBase();
  }  
  value = ((level * 100) + count) * (1.25 - ((stats[4].getBase()/99) * (.5)));
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

// Save information generation
string Player::getSaveString(){  
  string temp = name + "\n" + to_string(level) + " " + to_string(age) + " " + to_string(value) + " " + to_string(EXP) + "\n";
  for(int i = 0; i < 5; i++){
    temp += stats[i].getSaveString();
  }
  return temp;
}

