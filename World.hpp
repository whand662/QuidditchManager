#ifndef _WORLD
#define _WORLD

#include <stdio.h>
#include "Team.hpp"
#include "NameGen.hpp"
#include <string>
#include <stdlib.h>
#include <time.h> 

#define LEAGUESIZE 24
#define CATCHCOUNT 3

using namespace std;

class World{
	public:
		
		World();
		World(string fileName);
		int transaction();
		void display();
		void simWeek();
		
	private:
		
		Team teams[LEAGUESIZE];
		vector<Player> freeAgents;
		int simGame(int homeTeam, int awayTeam);
		void initialize(string myTeam);
		NameGen ng;
};

#endif
