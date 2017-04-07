#ifndef _STAT
#define _STAT

#include <string>

#define STATMAX 99
#define STATMIN 1

using namespace std;

class Stat{

	public:

		Stat();
		Stat(string nm, int val);
		Stat(string nm, int val, int mod, int mDur);
		string getName();
		int getBase();
    void setBase(int val);
		int getActual();
    string display();
		void changeMod(int deltaMod, int deltaDur);
    string getSaveString();
    void tick();
	
	private:

		string name;
		int baseValue;
		int modifier, modDuration;

};

#endif

