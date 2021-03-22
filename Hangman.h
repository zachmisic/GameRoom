#ifndef HANGMAN_H
#define HANGMAN_H

#include<iostream>
#include<string.h>

class Hangman
{
	private:
		std::string word;
		std::string HMword;
		std::string previousGuesses;
		char guess;
		int winner = 0;
		int wordTracker = 0;
		int guessesLeft = 6;
		char playAgain;
	public:
		Hangman();
		void run();
		void wordGenerator();
		void display();
		void personDisplay();
		void isWinner();
		void reset();
};
#endif