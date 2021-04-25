/*--------------------------------------------------------------
 *
 *@file: blackjackTest.cpp
 *@author: Jake Beesley
 *@assignment: EECS-448 project 4
 *@description: Header file for the blackjackTest class, which tests the core functionality of the blackjack program
 *
 --------------------------------------------------------------*/

#ifndef BLACKJACKTEST_H
#define BLACKJACKTEST_H
#include <string>
#include "blackjack.h"
#include "deck.h"
#include "card.h"

class blackjackTest
{

    public:

        /**
        * @pre Test suite is executed
        * @post Runs through all test of the blackjack test suite
        * @return N/A
        **/
        void run();

        /**
        * @pre Test suite is executed
        * @post Tests that the initialized hands for dealer and player are all empty
        * @return N/A
        **/
        void testInitializeHands();

        /**
        * @pre Test suite is executed
        * @post Tests that the deck shuffle function thoroughly shuffles the deck (at least half the cards are not in their original position)
        * @return N/A
        **/
        void testShuffle();

        /**
        * @pre Test suite is executed
        * @post Tests that the deck is populated with the appropriate cards on creation
        * @return N/A
        **/
        void testDeckConstructor();

        /**
        * @pre Test suite is executed
        * @post Confirms that a dealt empty card is indeed an empty card
        * @return N/A
        **/
        void testEmptyCard();

        /**
        * @pre Test suite is executed
        * @post Ensures that an ace with a value of 11 is overriden to an ace with a value of 1
        * @return N/A
        **/
        void testDealSpecialAce();

};
#endif
