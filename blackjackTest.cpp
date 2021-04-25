/*--------------------------------------------------------------
 *
 *@file: blackjackTest.cpp
 *@author: Jake Beesley
 *@assignment: EECS-448 project 4
 *@description: Implementation file for the blackjackTest class, which tests the core functionality of the blackjack program
 *
 --------------------------------------------------------------*/

#include "blackjackTest.h"

void blackjackTest::run(){
    std::cout << "\nTesting Blackjack...\n\n";
    testDeckConstructor(); //Test 1
    testEmptyCard(); //Test 2
    testDealSpecialAce(); //Test 3
    testInitializeHands(); //Test 4
    testShuffle(); //Test 5
}

//Test 1: Deck constructor works
void blackjackTest::testDeckConstructor(){
   deck deckTester;
   std::cout << "Test 1: Deck constructor populates deck of cards: ";
   if(deckTester.nextCard() == card("Ace", "Hearts", 11)){
       if(deckTester.nextCard() == card("King", "Hearts", 10)){
           std::cout << "PASSED\n";
       }
       else{
           std::cout << "FAILED\n";
       }
   }
   else{
       std::cout << "FAILED\n";
   }
}

//Test 2: Empty card is actually an empty card
void blackjackTest::testEmptyCard(){
    deck deckTester;
    std::cout << "Test 2: Empty card function returns empty card: ";
    if(deckTester.dealEmptyCard() == card("", "", 0)){
        std::cout << "PASSED\n";
    }
    else{
        std::cout << "FAILED\n";
    }
}

//Test 3: Ace with a value of 11 is changed to a value of 1
void blackjackTest::testDealSpecialAce(){
    deck deckTest;
    card handTest[10];
    handTest[0] = deckTest.nextCard();
    std::cout << "Test 3: Special ace function overrides value from 11 to 1: ";
    std::string aceSuit = handTest[0].getSuit();
    int elevenValue = handTest[0].getValue(); //Ace has a value of 11
    handTest[0] = deckTest.dealSpecialAce(aceSuit);
    int oneValue = handTest[0].getValue(); //Ace has a value of 1
    if(elevenValue != oneValue){
        if(elevenValue == 11 && oneValue == 1){
            std::cout << "PASSED\n";
        }
        else{
            std::cout << "FAILED\n";
        }
    }
    else{
        std::cout << "FAILED\n";
    }
}

//Test 4: Initialized hands are filled with empty cards
void blackjackTest::testInitializeHands(){
    deck deckTester;
    blackjack blackjackTester;
    blackjackTester.initializeHands();
    std::cout << "Test 4: Player and dealer hands are initialized to empty cards: ";
    for(int i = 0; i < 10; i++){
        if(((blackjackTester.playerHand[i]) == deckTester.dealEmptyCard()) && ((blackjackTester.dealerHand[i]) == deckTester.dealEmptyCard()) ){
            if(i == 9){
                std::cout << "PASSED\n";
            }
        }
        else{
            std::cout << "FAILED\n";
        }
    }
}

//Test 5: Deck is thoroughly shuffled
void blackjackTest::testShuffle(){
   deck deckTester1; //Deck gets shuffled
   deck deckTester2; //Deck does not get shuffled
   int appropriateShuffle = 0;
   deckTester1.shuffle();
   std::cout << "Test 5: Shuffle deck shuffles a deck of cards: ";
    for(int i = 0; i < 52; i++){
        if(deckTester1.nextCard() != deckTester2.nextCard()){
            appropriateShuffle = appropriateShuffle + 1;
        }
        else if(appropriateShuffle > 25){
            break;
        }
        else{
            appropriateShuffle = appropriateShuffle - 1;
        }
    }
    if(appropriateShuffle > 25){
        std::cout << "PASSED\n";
    }
    else{
        std::cout << "FAILED\n";
    }
}

