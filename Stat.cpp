#include "Stat.hpp"

Stat::Stat(){
	name = "Not a stat";
	baseValue = STATMIN;
	modifier = 0;
	modDuration = 0;
}

Stat::Stat(string nm, int val){
	name = nm;
	if(val <= STATMAX){
		baseValue = val;
	}else{
		baseValue = STATMAX;
	}
	modifier = 0;
	modDuration = 0;
}

Stat::Stat(string nm, int val, int mod, int mDur){
	name = nm;
	if(val <= STATMAX){
		baseValue = val;
	}else{
		baseValue = STATMAX;
	}
	modifier = mod;
	modDuration = mDur;
}

string Stat::getName(){
	return name;
}

int Stat::getBase(){
	return baseValue;
}

void Stat::setBase(int val){
	baseValue = val;
}

int Stat::getActual(){
	int temp = baseValue + modifier;
	if(temp > STATMAX){
		return STATMAX;
	}else if(temp < STATMIN){
		return STATMIN;
	}
	return temp;
}

string Stat::display(){
  if(modifier == 0){
    return to_string(baseValue);
  }else{
    if(modifier > 0){
      return to_string(baseValue) + "+" + to_string(modifier);
    }else{
      return to_string(baseValue) + to_string(modifier);
    }
  }
}

void Stat::changeMod(int deltaMod, int deltaDur){
	modifier += deltaMod;
	modDuration += deltaDur;
}

string Stat::getSaveString(){
  string temp = to_string(baseValue) + " " + to_string(modifier) + " " + to_string(modDuration) + "\n";
  return temp;
}

void Stat::tick(){

}

