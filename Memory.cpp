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

Memory::Memory() {
	board = new char*[size];
	boardHid = new char*[size];
	for (int i=0; i<size; i++)
	{
		board[i] = new char[4];
		boardHid[i] = new char[4];
	}
}

Memory::~Memory() {
	for (int i = 0; i < size; i++)
	{
		delete board[i];
		delete boardHid[i];
	}
	delete board;
	delete boardHid;
}

void Memory::run() {
	populate();
	int pairsFound = 0;
	int xchoice1=-1, ychoice1=-1;
	int xchoice2 = -1, ychoice2 = -1;
	bool sameFlag;
	bool dashFlag;

	std::cout << "Memory!\n";
	while (pairsFound < 8) {
		display();

		dashFlag = false;
		do {
			while (xchoice1 > 3 || xchoice1 < 0) {
				std::cout << "Column: ";
				std::cin >> xchoice1;
			}
			while (ychoice1 > 3 || ychoice1 < 0) {
				std::cout << "Row: ";
				std::cin >> ychoice1;
			}
			if (board[ychoice1][xchoice1] == '-') {
				dashFlag = true;
				xchoice1 = -1;
				ychoice1 = -1;
			}
			else {
				dashFlag = false;
			}
		} while (dashFlag == true);


		boardHid[ychoice1][xchoice1] = board[ychoice1][xchoice1];
		display();


		do {

			dashFlag = false;
			do {

				while (xchoice2 > 3 || xchoice2 < 0) {
					std::cout << "Column: ";
					std::cin >> xchoice2;
				}
				while (ychoice2 > 3 || ychoice2 < 0) {
					std::cout << "Row: ";
					std::cin >> ychoice2;
				}
				if (board[ychoice2][xchoice2] == '-') {
					dashFlag = true;
					xchoice2 = -1;
					ychoice2 = -1;
				}
				else {
					dashFlag = false;
				}
			} while (dashFlag == true);

			if ( (xchoice1 == xchoice2) && (ychoice1 == ychoice2) ) {
				sameFlag = true;
				xchoice2 = -1;
				ychoice2 = -1;
			}
			else {
				sameFlag = false;
			}

		} while (sameFlag);

		boardHid[ychoice2][xchoice2] = board[ychoice2][xchoice2];
		display();


		if (board[ychoice1][xchoice1] == board[ychoice2][xchoice2]) {
			board[ychoice1][xchoice1] = '-';
			board[ychoice2][xchoice2] = '-';
			boardHid[ychoice1][xchoice1] = '-';
			boardHid[ychoice2][xchoice2] = '-';
			pairsFound++;
			std::cout << "You found a matching pair!\n";
		}
		else {
			boardHid[ychoice1][xchoice1] = '#';
			boardHid[ychoice2][xchoice2] = '#';
			std::cout << "Sorry! That pair did not match\n";
		}

		xchoice1 = -1;
		ychoice1 = -1;
		xchoice2 = -1;
		ychoice2 = -1;

	}
	std::cout << "Congratulations! You win!\n";

}

void Memory::populate() {
	std::cout << "started populate";
	char cards[] = { 'A','B','C','D','A','B','C','D','E','F','G','H','E','F','G','H' };
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
	std::cout << "populated";
}

void Memory::display() {

	std::cout << "    0 1 2 3\n";
	std::cout << "------------\n";

	for (int x = 0; x < size; x++) {

		std::cout << x<<" | ";
		for (int y = 0; y < size; y++) {
			std::cout << boardHid[x][y] << " ";
		}
		std::cout <<'\n';

	}
	std::cout << '\n';

}
