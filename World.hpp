#ifndef _WORLD
#define _WORLD

#include <limits.h>
#include <stdio.h>
#include "Team.hpp"
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "./nameGen/NameGen.hpp"
#include "./TeamScheduler/TeamScheduler.hpp"

#define LEAGUESIZE 24
#define CATCHCOUNT 3

using namespace std;

class World{

	public:
		
		World();
		World(string fileName, bool newGame);
		int transaction();
		void display();
		int simWeek();
    void saveGame(string fileName);
		
	private:
		
    string saveName;
		int week;
		vector<Team> teams;
		vector<Player> freeAgents;
		int simGame(int homeTeam, int awayTeam);
		void initialize(string myTeam);
    int numTeams;
		NameGen ng;
    TeamScheduler ts;
};

#endif
