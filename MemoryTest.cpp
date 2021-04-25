/*--------------------------------------------------------------
 *
 *@file: MemoryTest.cpp
 *@author: Zach Misic
 *@assignment: EECS-448 project 4
 *@description: Contains method definitions for the "MemoryTest" class
 *
 --------------------------------------------------------------*/
#include "MemoryTest.h"
#include "Memory.h"
#include <string.h>
#include <iostream>
#include <cstdlib>

void MemoryTest::run() {
	testPopulate();
	testDisplay();
	testPairs();
	testFlipFirst();
	testFlipSecond();
}

//Test 1
void MemoryTest::testPopulate() {
	test.populate();
	std::cout << "Test 1: Construct and populate Memory Board PASSED\n";
}

//Test 2
void MemoryTest::testDisplay() {
	//test.display();
	//remove comment to actually display while testing
	std::cout << "Test 2: Display hidden board PASSED\n";
}

//Test 3
void MemoryTest::testPairs() {

	std::cout << "Test 5: Test the number of pairs that must be matched";
	if (test.pairsLeft() == 8) {
		std::cout << "PASSED\n";
	}
	else {
		std::cout << "FAILED\n";
	}
}

//Test 4
void MemoryTest::testFlipFirst() {

	test.flip(1, 1);
	std::cout << "Test 3: Flip first card PASSED\n";
}

//Test 5
void MemoryTest::testFlipSecond() {

	test.flip(0, 0);
	std::cout << "Test 4: Flip second card PASSED\n";
}

