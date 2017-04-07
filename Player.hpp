#ifndef _PLAYER
#define _PLAYER

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <limits.h>
#include "Stat.hpp"

#define BLANK Player()
#define NUM_STATS 5
#define STRENGTH 0
#define SPEED 1
#define REACTION 2
#define INTELLIGENCE 3
#define PERSONALITY 4

using namespace std;

class Player{
	public:
		
		Player();
		Player(string n);
		Player(string n, int lvl);
    Player(ifstream *inFile);
		void display();
		bool gainEXP(int exp);
		bool isBlank();
    string getSaveString();
		string getName();
    void tick();
		
		//stat checkers
		int getSeek();
		int getPass();
		int getShoot();
		int getBlock();
		int getDefend();
		int getScuffle();
		int getPersonality();
		
	private:
		
		string name;
		int level, age, value, EXP;
		Stat stats[NUM_STATS];

    void levelUp();
    int randomStat(int lvl);
    void updateValue();
};

#endif
