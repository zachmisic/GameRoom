run: main.o Hangman.o Checkers.o Checkers_Player.o snake.o
	g++ -std=c++11 -g -Wall main.o Hangman.o Checkers.o Checkers_Player.o snake.o -o run

main.o: main.cpp Hangman.h Checkers.h snake.h
	g++ -std=c++11 -g -Wall -c main.cpp

Hangman.o: Hangman.h Hangman.cpp
	g++ -std=c++11 -g -Wall -c Hangman.cpp

Checkers.o: Checkers.h Checkers.cpp Checkers_Player.h
	g++ -std=c++11 -g -Wall -c Checkers.cpp

Checkers_Player.o: Checkers_Player.h Checkers_Player.cpp
	g++ -std=c++11 -g -Wall -c Checkers_Player.cpp

snake.o: snake.h snake.cpp
	g++ -std=c++11 -g -Wall -c snake.cpp

clean:
	rm *.o run
