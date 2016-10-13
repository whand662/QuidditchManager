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

int Stat::getActual(){
	int temp = baseValue + modifier;
	if(temp > STATMAX){
		return STATMAX;
	}else if(temp < STATMIN){
		return STATMIN;
	}
	return temp;
}

void Stat::changeMod(int deltaMod, int deltaDur){
	modifier += deltaMod;
	modDuration += deltaDur;
}

