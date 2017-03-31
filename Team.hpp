#ifndef _TEAM
#define _TEAM

#include <stdio.h>
#include "Roster.hpp"
#include <string>

using namespace std;

class Team{
	public:
		
		Team();
		Team(string teamName);
		void display();
		bool isValid();
		Player getPlayer(string position);
		Player getPlayer(int position);
		int getTeamScuffle();
		int getOverall();
		string getName();
    string getSaveString();
		
	private:
		string name;
		int money = 0;
		Roster roster;
};

#endif

