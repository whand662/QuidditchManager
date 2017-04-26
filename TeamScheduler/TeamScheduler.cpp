#include "TeamScheduler.hpp"

TeamScheduler::TeamScheduler(){
  numTeams = 2;
  numWeeks = 1;
  while(calender.size() < numWeeks){
    calender.push_back(vector<Match>());
  }
  generate();
}

TeamScheduler::TeamScheduler(int nT, int nW){
	numTeams = nT;
  numWeeks = nW;
  while(calender.size() < numWeeks){
    calender.push_back(vector<Match>());
  }
  generate();
}

void TeamScheduler::generate(){
  int table[numTeams];
  int rotation[numTeams];
  int crux = numTeams / 2;
  
  //set first table position
  for(int i = 0; i < numTeams; i++){
    table[i] = i;
  }
  //add to vector
  for(int i = 0; i < numWeeks; i++){
    for(int j = 0; j < crux; j++){
      calender[i].push_back(Match(table[j], table[j + crux]));
    }
    //rotate the table
    rotation[0] = table[0];
    for(unsigned int j = 1; j < numTeams; j++){      
      if(j < crux){
        if(j == crux-1){
          rotation[j] = table[numTeams-1];
        }else{
          rotation[j] = table[j+1];
        } 
      }else{
        if(j == crux){
          rotation[j] = table[1];
        }else{
          rotation[j] = table[j-1];
        }
      }
    }
    for(unsigned int k = 0; k < numTeams; k++){
      table[k] = rotation[k];
    }
  }
}

vector<Match> TeamScheduler::getWeek(int wk){
  return calender[wk - 1];
}

vector<vector<Match> > TeamScheduler::getYear(){
  return calender;
}

void TeamScheduler::print(){
  for(unsigned int i = 0; i < calender.size(); i++){
    printf("Week %d\n", i + 1);
    for(unsigned int j = 0; j < calender[i].size(); j++){
      printf("\t%d : %d\n", calender[i][j].team1, calender[i][j].team2);
    }
  }
}


