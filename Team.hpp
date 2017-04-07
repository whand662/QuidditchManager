#ifndef _TEAM
#define _TEAM

#include <stdio.h>
#include "RosterQ.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

class Team{
	public:
		
		Team();
		Team(string teamName);
    Team(ifstream *inFile);
		void display();
		bool isValid();
		Player getPlayer(string position);
		Player getPlayer(int position);
		int getTeamScuffle();
		int getOverall();
		string getName();
    string getSaveString();
    void tick();
		
	private:
		string name;
		int money = 0;
		RosterQ roster;
};

#endif

