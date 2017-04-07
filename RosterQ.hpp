#ifndef _ROSTERQ
#define _ROSTERQ

#include <stdio.h>
#include "Player.hpp"
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>

#define ROSTER_SIZE 10

using namespace std;

class RosterQ{
	public:
		
		RosterQ();
		RosterQ(ifstream *inFile);
		int add(Player player, string position);
		Player drop(string position);
		int move(string from, string to);
		int swap(string from, string to);
		Player getPlayer(string position);
		Player getPlayer(int position);
		void display();
		bool isValid();
		int getTeamScuffle();
		int getOverall();
    string getSaveString();
    void tick();
		
	private:

		Player roster[ROSTER_SIZE];
		int pos2int(string pos);
		string int2pos(int pos);
};

#endif

