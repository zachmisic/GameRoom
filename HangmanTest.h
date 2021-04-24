#ifndef HANGMANTEST_H
#define HANGMANTEST_H

#include<iostream>
#include<string.h>

class HangmanTest
{
	private:
		std::string word;
		std::string HMword;
		std::string previousGuesses;
		int guesses = 0;
		int guessesLeft = 0;

		std::string word2;
		std::string HMword2;
		std::string previousGuesses2;
		int guesses2 = 0;
		int guessesLeft2 = 0;

		char guess;
		int winner = 0;
		int mode;
		int player = 2;
		int wordTracker = 0;

	public:
		HangmanTest();
		void run();
		void classic();
		void battle();
		void wordGenerator(int player);
		void display(int player);
		void personDisplay(int player);
		void setGuessNum(int player);
		void guessChecker(int player);
		void wordUpdater(int player);

		void flipPlayer();
		void isWinner(int player);
		void reset();
};
#endif
