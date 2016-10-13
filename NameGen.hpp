#ifndef _NAMEGEN
#define _NAMEGEN

#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h> 

using namespace std;

class NameGen{
	public:
		
		NameGen();
		string genFirst();
		string genLast();
		string genFull();
		string genPlace();
		string genTeam(bool withPlace);
		
	private:
		vector<string> firstBank, lastBank, placeBank, teamBank;
};
#endif
