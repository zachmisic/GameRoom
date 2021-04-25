/*--------------------------------------------------------------
 *
 *@file: Memory.h
 *@author: Zach Misic
 *@assignment: EECS-448 project 4
 *@description: Contains headers for the "Memory" class
 *
 --------------------------------------------------------------*/
#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <string.h>

class Memory {

private:

	int pairsTotal = 8;
	int pairsFound = 0;
	int size = 4;
	char** board;
	char** boardHid;


public:

	/**
	* @pre N/A
	* @post Creates an instance of the "Memory" class
	* @return N/A
	**/
	Memory();
	~Memory();

	/**
	* @pre An instance of "Memory" has been created
	* @post Runs the memory game
	* @return N/A
	**/
	void run();

	/**
	* @pre An instance of "Memory" has been created
	* @post Populates the memory game board
	* @return N/A
	**/
	void populate();

	/**
	* @pre An instance of "Memory" has been created and the board has been populated
	* @post Displays the game board
	* @return N/A
	**/
	void display();

	/**
	* @pre An instance of "Memory" has been created and the board has been populated
	* @post Flips a card on the game board
	* @return N/A
	**/
	void flip(int c, int r);

	/**
	* @pre An instance of "Memory" has been created and the board has been populated
	* @post N/A
	* @return number of pairs that have not been found
	**/
	int pairsLeft();

};
#endif