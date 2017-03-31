all: main clean

main: Client.o World.o Team.o Roster.o Player.o Stat.o NameGen.o
	g++ -std=c++11 Client.o World.o Team.o Roster.o Player.o Stat.o NameGen.o -o qman
Client.o: Client.cpp
	g++ -c -std=c++11 Client.cpp
World.o: World.cpp World.hpp
	g++ -c -std=c++11 World.cpp
Team.o: Team.cpp Team.hpp
	g++ -c -std=c++11 Team.cpp
Roster.o: Roster.cpp Roster.hpp
	g++ -c -std=c++11 Roster.cpp
Player.o: Player.cpp Player.hpp
	g++ -c -std=c++11 Player.cpp
NameGen.o: ./nameGen/NameGen.cpp ./nameGen/NameGen.hpp
	g++ -c -std=c++11 ./nameGen/NameGen.cpp
Stat.o: Stat.cpp Stat.hpp
	g++ -c -std=c++11 Stat.cpp
clean:
	rm *.o

