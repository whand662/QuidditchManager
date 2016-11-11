#ifndef _PLAYER
#define _PLAYER

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Stat.hpp"

#define BLANK Player("Empty")
#define STRENGTH 1
#define SPEED 2
#define REACTION 3
#define INTELLIGENCE 4
#define PERSONALITY 5

using namespace std;

class Player{
	public:
		
		Player();
		Player(string n);
		Player(int lvl);
		void display();
		bool gainEXP(int exp);
		bool isBlank();

		string getName();
		
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
		void levelUp();
		int level, age, value, experience;
		Stat stats[5];
};

#endif
