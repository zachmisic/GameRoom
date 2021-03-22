run: main.o Hangman.o
	g++ -std=c++11 -g -Wall main.o Hangman.o -o run

main.o: main.cpp Hangman.h
	g++ -std=c++11 -g -Wall -c main.cpp

Hangman.o: Hangman.h Hangman.cpp
	g++ -std=c++11 -g -Wall -c Hangman.cpp

clean:
	rm *.o run