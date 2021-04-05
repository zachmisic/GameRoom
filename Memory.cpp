/*--------------------------------------------------------------
 *
 *@file: Memory.cpp
 *@author: Zach Misic
 *@assignment: EECS-448 project 3
 *@description: Contains method definitions for the "Memory" class
 *
 --------------------------------------------------------------*/
#include "Memory.h"
#include <string.h>
#include <iostream>
#include <cstdlib>

Memory::Memory() {}

Memory::~Memory() {}

void Memory::run() {
	populate();
	int pairsFound = 0;
	int xchoice, ychoice;

	while (pairsFound < 8) {

		display();



	}

}

void Memory::populate() {

	int randSelect = -1;
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			do {
				randSelect = (rand() % 16);
			} while (cards[randSelect] == '-');

			board[x][y] = cards[randSelect];
			cards[randSelect] = '-';
		}
	}

	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			boardHid[x][y] = '#';
		}
	}
}

void Memory::display() {

	std::cout << "Memory!\n";
	std::cout << "    0 1 2 3\n";
	std::cout << "------------\n";

	for (int x = 0; x < size; x++) {

		std::cout << x<<" | ";
		for (int y = 0; y < size; y++) {
			std::cout << boardHid[x][y] << " ";
		}
		std::cout <<'\n';

	}

}
