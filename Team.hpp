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
		bool isPlayer();
		bool isValid();
		Player getPlayer(string position);
		Player getPlayer(int position);
		int getTeamScuffle();
		int getOverall();
		
	private:
		string name;
		int money = 0;
		Roster roster;
		bool humanControlled = false;
};

#endif

