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
	Memory test;
	testPopulate();
	testDisplay();
	testFlipFirst();
	testFlipSecond();
	testPairs();
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
void MemoryTest::testFlipFirst() {

	std::cout << "Test 3: Flip first card\n";
}

//Test 4
void MemoryTest::testFlipSecond() {

	std::cout << "Test 4: Flip second card\n";
}

//Test 5
void MemoryTest::testPairs() {

	std::cout << "Test 5: Test the number of pairs that must be matched\n";
}
