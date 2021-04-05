/**
* @Checkers.h
* @Author: Andrew Hughes
* @Holds methods for checkers
**/

#ifndef CHECKERS_H
#define CHECKERS_H

#include "Checkers_Player.h"
#include <string>
#include <fstream>
#include <iostream>

class Checkers
{
	public:
		/**
		* @pre The class must be created
		* @post The class is created
		* @return N/A
		**/
		Checkers();

		/**
		* @pre The class must be destroyed
		* @post The class is destroyed
		* @return N/A
		**/
		~Checkers();

    	/**
		* @pre The function is called
		* @post The the function runs
		* @return void
		**/
		void run();

		/**
		* @pre The function is called
		* @post The board is printed on the screen
		* @return void
		**/
		void printBoard();

		/**
		* @pre The board must be reset
		* @post The board is reset to starting positions
		* @return void
		**/
		void ResetBoard();

	private:
		char** m_Board;
		Checkers_Player* m_Player1;
		Checkers_Player* m_Player2;

		/**
		* @pre The function is called
		* @post any piece at the edge of the board is promoted
		* @return bool, if something was promoted, return true
		**/
		bool promote();

		/**
		* @pre The game is ongoing, and we need to know if it should end
		* @post The we know if the game should end
		* @return return true, if all pieces of one player is gone.
		**/
		bool Gameover();
};
#endif