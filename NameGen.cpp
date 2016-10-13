#include "NameGen.hpp"

NameGen::NameGen(){
	ifstream inFile1("./res/first.txt");
	ifstream inFile2("./res/last.txt");
	ifstream inFile3("./res/team.txt");
	ifstream inFile4("./res/place.txt");
	string temp;

	if(inFile1.is_open()){
    	while(getline(inFile1, temp)){
			firstBank.push_back(temp);
		}
    	inFile1.close();
  	}else printf("Unable to open input file\n");
	
	if(inFile2.is_open()){
    	while(getline(inFile2, temp)){
			lastBank.push_back(temp);
		}
    	inFile2.close();
  	}else printf("Unable to open input file\n");

	if(inFile3.is_open()){
    	while(getline(inFile3, temp)){
			teamBank.push_back(temp);
		}
    	inFile3.close();
  	}else printf("Unable to open input file\n");

	if(inFile4.is_open()){
    	while(getline(inFile4, temp)){
			placeBank.push_back(temp);
		}
    	inFile4.close();
  	}else printf("Unable to open input file\n");

	firstBank.shrink_to_fit();
	lastBank.shrink_to_fit();
	teamBank.shrink_to_fit();
	placeBank.shrink_to_fit();
}

string NameGen::genFirst(){
	int temp = rand() % firstBank.size();
	return firstBank[temp];
}

string NameGen::genLast(){
	int temp = rand() % firstBank.size();
	return lastBank[temp];
}

string NameGen::genFull(){
	return genFirst() + " " + genLast();
}

string NameGen::genPlace(){
	int temp = rand() % placeBank.size();
	return placeBank[temp];
}

string NameGen::genTeam(bool withPlace){
	int temp = rand() % teamBank.size();	
	string hold = teamBank[temp];
	if(withPlace){
		return genPlace() + " " + hold;
	}else{
		return hold;
	}
}

