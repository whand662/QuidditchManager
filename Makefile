all: main teams clean

main: Client.o World.o Team.o RosterQ.o Player.o Stat.o NameGen.o TeamScheduler.o StringTokenizer.o
	g++ -std=c++11 Client.o World.o Team.o RosterQ.o Player.o Stat.o NameGen.o TeamScheduler.o StringTokenizer.o -o qman
teams: testTeam.o Team.o RosterQ.o Player.o Stat.o NameGen.o
	g++ -std=c++11 testTeam.o Team.o RosterQ.o Player.o Stat.o NameGen.o -o testteams
testTeam.o: testTeam.cpp
	g++ -c -std=c++11 testTeam.cpp
Client.o: Client.cpp
	g++ -c -std=c++11 Client.cpp
World.o: World.cpp World.hpp
	g++ -c -std=c++11 World.cpp
Team.o: Team.cpp Team.hpp
	g++ -c -std=c++11 Team.cpp
RosterQ.o: RosterQ.cpp RosterQ.hpp
	g++ -c -std=c++11 RosterQ.cpp
Player.o: Player.cpp Player.hpp
	g++ -c -std=c++11 Player.cpp
NameGen.o: ./nameGen/NameGen.cpp ./nameGen/NameGen.hpp
	g++ -c -std=c++11 ./nameGen/NameGen.cpp
TeamScheduler.o: ./TeamScheduler/TeamScheduler.cpp ./TeamScheduler/TeamScheduler.hpp
	g++ -c -std=c++11 ./TeamScheduler/TeamScheduler.cpp
StringTokenizer.o: ./StringTokenizer/StringTokenizer.cpp ./StringTokenizer/StringTokenizer.hpp
	g++ -c -std=c++11 ./StringTokenizer/StringTokenizer.cpp
Stat.o: Stat.cpp Stat.hpp
	g++ -c -std=c++11 Stat.cpp
clean:
	rm *.o

