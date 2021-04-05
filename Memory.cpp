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
	int xchoice1=-1, ychoice1=-1;
	int xchoice2 = -1, ychoice2 = -1;
	bool sameFlag;

	while (pairsFound < 8) {

		display();
		while (xchoice1 > 3 || xchoice1 < 0) {
			std::cout << "Column: ";
			std::cin >> xchoice1;
		}
		while (ychoice1 > 3 || ychoice1 < 0) {
			std::cout << "Row: ";
			std::cin >> ychoice1;
		}
		boardHid[xchoice1][ychoice1] = board[xchoice1][ychoice1];
		display();

		sameFlag = true;

		while (sameFlag) {
			while (xchoice2 > 3 || xchoice2 < 0) {
				std::cout << "Column: ";
				std::cin >> xchoice2;
			}
			while (ychoice2 > 3 || ychoice2 < 0) {
				std::cout << "Row: ";
				std::cin >> ychoice2;
			}
			if (!((xchoice1 == xchoice2) && (ychoice1 == ychoice2)) {
				sameFlag = false;
			}
		}
		boardHid[xchoice2][ychoice2] = board[xchoice2][ychoice2];
		display();


		if (board[xchoice1][ychoice1] == board[xchoice2][ychoice2]) {
			board[xchoice1][ychoice1] = '-';
			board[xchoice2][ychoice2] = '-';
			boardHid[xchoice1][ychoice1] = '-';
			boardHid[xchoice2][ychoice2] = '-';
			pairsFound++;
			std::cout << "You found a matching pair!\n";
		}
		else {
			boardHid[xchoice1][ychoice1] = '#';
			boardHid[xchoice2][ychoice2] = '#';
			std::cout << "Sorry! That pair did not match\n";
		}

		xchoice1 = -1;
		ychoice1 = -1;
		xchoice2 = -1;
		ychoice2 = -1;

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
		std::cout <<'\n\n';

	}

}
