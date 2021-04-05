/*--------------------------------------------------------------
 *
 *@file: Memory.h
 *@author: Zach Misic
 *@assignment: EECS-448 project 3
 *@description: Contains headers for the "Memory" class
 *
 --------------------------------------------------------------*/
#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <string.h>

class Memory {

private:

	int size = 4;
	char board[size][size];
	char boardHid[size][size];
	char cards[] = { 'A','B','C','D','A','B','C','D','E','F','G','H','E','F','G','H' };


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


};
#endif