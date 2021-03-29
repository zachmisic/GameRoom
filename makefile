run: main.o Hangman.o Checkers.o Checkers_Player.o
	g++ -std=c++11 -g -Wall main.o Hangman.o Checkers.o Checkers_Player.o -o run

main.o: main.cpp Hangman.h Checkers.h
	g++ -std=c++11 -g -Wall -c main.cpp

Hangman.o: Hangman.h Hangman.cpp
	g++ -std=c++11 -g -Wall -c Hangman.cpp

Checkers.o: Checkers.h Checkers.cpp Checkers_Player.h
	g++ -std=c++11 -g -Wall -c Checkers.cpp

Checkers_Player.o: Checkers_Player.h Checkers_Player.cpp
	g++ -std=c++11 -g -Wall -c Checkers_Player.cpp

clean:
	rm *.o run