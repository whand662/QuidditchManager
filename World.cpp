#include "World.hpp"

World::World(){
	initialize("Player Team");
}

World::World(string fileName){
	//try to load from file, if not create new world and savefile
}

int World::transaction(){
	
}

void World::display(){
	for(int i = 0; i < LEAGUESIZE; i++){
		teams[i].display();
	}
}

void World::simWeek(){
	//check that teams have valid rosters	
	//play games
	//update team money
	//level players
	//if new year check retirements
}

void World::initialize(string myTeam){
	ng = NameGen();
	teams[0] = Team(myTeam);
	for(int i = 1; i < LEAGUESIZE; i++){
		teams[i] = Team(ng.genTeam(true));
	}
}

int World::simGame(int homeTeam, int awayTeam){
	bool snitchCaught = false;
	int quaffleHeld = -1;
	int homeScore = 0, awayScore = 0;
	int b1, b2;
	int timer = 0;
	int sHome = 0, sAway = 0;
	bool commentate = false;
	srand(time(NULL));

	if(teams[homeTeam].isPlayer() || teams[awayTeam].isPlayer()){
		commentate = true;
	}

	//print pregame things here
	if(commentate){
		printf("\nThe %s OVR: %d\n", teams[homeTeam].getName(), teams[homeTeam].getOverall());
		printf("VS\n");
		printf("The %s OVR %d\n\n", teams[awayTeam].getName(), teams[awayTeam].getOverall());
	}

	while(!snitchCaught){

		if(quaffleHeld != -1){
			//shoot or pass
			
		}else{
			if(teams[homeTeam].getTeamScuffle() + (rand() % teams[homeTeam].getTeamScuffle()) >= teams[awayTeam].getTeamScuffle() + (rand() % teams[awayTeam].getTeamScuffle())){
				//give ball to home team
				quaffleHeld = (rand() % 3) + 4;
				if(commentate)
					printf("Quaffle picked up by %s!\n", teams[homeTeam].getPlayer(quaffleHeld).getName().c_str());
			}else{
				//give ball to away team
				quaffleHeld = (rand() % 3) + 14;
				if(commentate)
					printf("Quaffle picked up by %s!\n", teams[homeTeam].getPlayer(quaffleHeld - 10).getName().c_str());
			}
		}

		b1 = rand() % 40;
		b2 = rand() % 50;
		//deal with b1

		//deal with b2

		
		if((rand() % 100) < teams[homeTeam].getPlayer("seeker").getSeek()){
			sHome++;
		}
		if((rand() % 100) < teams[awayTeam].getPlayer("seeker").getSeek()){
			sAway++;
		}

		//victory checking
		if(sHome >= CATCHCOUNT && sHome > sAway){
			snitchCaught = true;
			homeScore += 150;
		}else if(sAway >= CATCHCOUNT && sHome < sAway){
			snitchCaught = true;
			awayScore += 150;
		}
		timer++;
	}

	//end of game things
	
}

