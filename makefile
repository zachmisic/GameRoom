run: main.o Hangman.o HangmanTest.o CheckersTest.o Checkers.o Checkers_Player.o snake.o snakeTest.o blackjack.o blackjackTest.o deck.o card.o Memory.o MemoryTest.o
	g++ -std=c++11 -g -Wall main.o Hangman.o HangmanTest.o Checkers.o Checkers_Player.o snake.o snakeTest.o blackjack.o blackjackTest.o deck.o card.o Memory.o MemoryTest.o -o run

main.o: main.cpp Hangman.h HangmanTest.h CheckersTest.h Checkers.h snake.h snakeTest.h blackjack.h blackjackTest.h Memory.h
	g++ -std=c++11 -g -Wall -c main.cpp

Hangman.o: Hangman.h Hangman.cpp
	g++ -std=c++11 -g -Wall -c Hangman.cpp

HangmanTest.o: HangmanTest.h HangmanTest.cpp
	g++ -std=c++11 -g -Wall -c HangmanTest.cpp

CheckersTest.o: CheckersTest.h CheckersTest.cpp Checkers.h
	g++ -std=c++11 -g -Wall -c CheckersTest.cpp

Checkers.o: Checkers.h Checkers.cpp Checkers_Player.h
	g++ -std=c++11 -g -Wall -c Checkers.cpp

Checkers_Player.o: Checkers_Player.h Checkers_Player.cpp
	g++ -std=c++11 -g -Wall -c Checkers_Player.cpp

snake.o: snake.h snake.cpp
	g++ -std=c++11 -g -Wall -c snake.cpp

snakeTest.o: snakeTest.h snakeTest.cpp
	g++ -std=c++11 -g -Wall -c snakeTest.cpp

Memory.o: Memory.h Memory.cpp
	g++ -std=c++11 -g -Wall -c Memory.cpp

MemoryTest.o: MemoryTest.h MemoryTest.cpp
	g++ -std=c++11 -g -Wall -c MemoryTest.cpp

blackjack.o: blackjack.h blackjack.cpp
	g++ -std=c++11 -g -Wall -c blackjack.cpp

blackjackTest.o: blackjackTest.h blackjackTest.cpp
	g++ -std=c++11 -g -Wall -c blackjackTest.cpp

card.o: card.h card.cpp
	g++ -std=c++11 -g -Wall -c card.cpp

deck.o: deck.h deck.cpp
	g++ -std=c++11 -g -Wall -c deck.cpp

clean:
	rm *.o run
