#include "World.hpp"

World::World(){
  numTeams = LEAGUESIZE;
  teams.resize(numTeams);
	initialize("Player Team");
	week = 1;
}

World::World(string fileName, bool newGame){
  printf("there0\n");  
  ifstream saveFile;  
  string temp;
  saveName = fileName;
  printf("there1\n");
  if(newGame == true){
    numTeams = LEAGUESIZE;
    teams.resize(numTeams);
	  week = 1;
    printf("Enter a name for your team!\nQMAN: ");
    cin >> temp;
    initialize(temp);
    printf("there2\n");
  }else{
    printf("there3\n");
    saveFile.open("./save/" + saveName + ".txt");
	  if(saveFile.is_open()){
		
    }
    saveFile.close();
  }
}

void World::saveGame(string fileName){
  ofstream saveFile;  
  if(fileName == "#"){
    saveFile.open("./save/" + saveName + ".txt");
  }else{
    saveFile.open("./save/" + fileName + ".txt");
  }
	if(saveFile.is_open()){
		saveFile << to_string(numTeams) + " " + to_string(week) + "\n"; 
    for(int i = 0; i < numTeams; i++){
      saveFile << teams[i].getSaveString();
    }
  }else{
    printf("ERROR: could not open saveFile for writing\n"); 
  }
  saveFile.close();
}

int World::transaction(){
	
}

void World::display(){
	for(int i = 0; i < numTeams; i++){
		teams[i].display();
	}
}

int World::simWeek(){
	//check that teams have valid rosters	
	//play games
	//update team money
	//level players
	//if new year check retirements
	if(week == 52){
		//new year things		
		week == 1;
	}else{
		week++;
	}
}

void World::initialize(string myTeam){
	ng = NameGen();
	teams[0] = Team(myTeam);
	for(int i = 1; i < numTeams; i++){
		teams[i] = Team(ng.genTeam(true));
	}
}

int World::simGame(int homeTeam, int awayTeam){
	bool snitchCaught = false;
	int quaffleHeld = -1;
	int homeScore = 0, awayScore = 0;
	int bl;
	int timer = 0;
	int sHome = 0, sAway = 0;
	bool commentate = false;
	srand(time(NULL));

	if(homeTeam * awayTeam == 0){
		commentate = true;
	}

	//print pregame things here
	if(commentate){
		printf("\nThe %s OVR: %d\n", teams[homeTeam].getName().c_str(), teams[homeTeam].getOverall());
		printf("VS\n");
		printf("The %s OVR %d\n\n", teams[awayTeam].getName().c_str(), teams[awayTeam].getOverall());
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

		//bludger stuff
		for(int i = 0; i <2; i++){
			bl = rand() % 20;
			if(bl <= 13){
				if(bl > 6){
					//away team
					bl -= 7;
					
				}else{
					//home team
					
				}
			}
		}
		
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

