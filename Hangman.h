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
		/**
		* @pre The class is created
		* @post The class is created
		* @param none
		* @return N/A
		**/
	
		void run();
		/**
		* @pre we need the game to run
		* @post game is run, communicates with all other classes
		* @param none
		* @return N/A
		**/
	
		void wordGenerator();
		/**
		* @pre need to convert word to dashed string
		* @post dashed string is created
		* @param none
		* @return N/A
		**/
	
		void display();
		/**
		* @pre need to display the hangman board
		* @post hangman board is generated
		* @param none
		* @return N/A
		**/
	
		void personDisplay();
		/**
		* @pre need to display the updated hangman figure
		* @post updated hangman figure is generated
		* @param none
		* @return N/A
		**/
	
		void isWinner();
		/**
		* @pre need to check if there is a winner and who it is
		* @post winner is checked
		* @param none
		* @return N/A
		**/
	
		void reset();
		/**
		* @pre need to reset board and hangman figure
		* @post board and hangman figure are reset
		* @param none
		* @return N/A
		**/
};
#endif
