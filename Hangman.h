/**
* @Hangman.h
* @Author: Brooke Jackson
* @Holds methods for the Hangman class
**/

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
		/**
		* @pre The class is created
		* @post The class is created
		* @param none
		* @return N/A
		**/
		Hangman();
	
		/**
		* @pre we need the game to run
		* @post game is run, communicates with all other classes
		* @param none
		* @return N/A
		**/
		void run();
	
		void classic();
		void battle();
	
		/**
		* @pre need to convert word to dashed string
		* @post dashed string is created
		* @param int player
		* @return N/A
		**/
		void wordGenerator(int player);
	
		/**
		* @pre need to display the hangman board
		* @post hangman board is generated
		* @param int player
		* @return N/A
		**/
		void display(int player);
	
		/**
		* @pre need to display the updated hangman figure
		* @post updated hangman figure is generated
		* @param int player
		* @return N/A
		**/
		void personDisplay(int player);
	
		void setGuessNum(int player);
		void guessChecker(int player);
		void wordUpdater(int player);
		void flipPlayer();
	
		/**
		* @pre need to check if there is a winner and who it is
		* @post winner is checked
		* @param int player
		* @return N/A
		**/
		void isWinner(int player);
	
		/**
		* @pre need to reset board and hangman figure
		* @post board and hangman figure are reset
		* @param none
		* @return N/A
		**/
		void reset();
};
#endif
