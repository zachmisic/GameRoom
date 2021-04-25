/*--------------------------------------------------------------
 *
 *@file: MemoryTest.h
 *@author: Zach Misic
 *@assignment: EECS-448 project 4
 *@description: Contains headers for the "MemoryTest" class
 *
 --------------------------------------------------------------*/
#ifndef MEMORYTEST_H
#define MEMORYTEST_H

#include <iostream>
#include <string.h>
#include "Memory.h"

class MemoryTest {

private:
	Memory test;

public:

	/**
	* @pre Test suite instantiated
	* @post Executes test methods
	* @return N/A
	**/
	void run();

	/**
	* @pre Test suite instantiated
	* @post Tests whether Memory is populated
	* @return N/A
	**/
	void testPopulate();

	/**
	* @pre Test suite instantiated
	* @post Executes test methods
	* @return N/A
	**/
	void testDisplay();

	/**
	* @pre Test suite instantiated
	* @post Executes test methods
	* @return N/A
	**/
	void testFlipFirst();

	/**
	* @pre Test suite instantiated
	* @post Executes test methods
	* @return N/A
	**/
	void testFlipSecond();

	/**
	* @pre Test suite instantiated
	* @post Executes test methods
	* @return N/A
	**/
	void testPairs();


};
#endif