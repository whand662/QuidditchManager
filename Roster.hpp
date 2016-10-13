#ifndef _ROSTER
#define _ROSTER

#include <stdio.h>
#include "Player.hpp"
#include <string>
#include <algorithm>

using namespace std;

class Roster{
	public:
		
		Roster();
		Roster(string fileName);
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
		
	private:

		Player roster[10];
		int pos2int(string pos);
		string int2pos(int pos);
};

#endif

