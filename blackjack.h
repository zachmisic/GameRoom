/*--------------------------------------------------------------
 *
 *@file: blackjack.h
 *@author: Jake Beesley
 *@assignment: EECS-448 project 4
 *@description: Header file for the blackjack program
 *
 --------------------------------------------------------------*/

#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <string>
#include <stdlib.h>
#include "deck.h"

class blackjack
{

public:

  /**
  * @pre N/A
  * @post calls the blackjackGame method
  * @return N/A
  **/
  void run();

  /**
  * @pre run() is called
  * @post the blackjack game is executed
  * @return N/A
  **/
  void blackjackGame();

  /**
  * @pre blackjackGame() is called
  * @post Shuffles the deck of cards 100 times
  * @return N/A
  **/
  void superShuffle();

  /**
  * @pre blackjackGame() is called
  * @post Fills the dealer and player's hands with empty cards
  * @return N/A
  **/
  void initializeHands();

  /**
  * @pre N/A
  * @post Outputs every card of the dealer and player's hands
  * @return N/A
  **/
  void printHands();

  /**
  * @pre Player chooses to hit within blackjackGame()
  * @post Checks if the next index of the player's hand is empty, then replaces it with a card from the deck
  * @return N/A
  **/
  void dealPlayer();

  /**
  * @pre houseValue is less than 17 within blackjackGame()
  * @post Checks if the next index of the dealer's hand is empty, then replaces it with a card from the deck
  * @return N/A
  **/
  void dealHouse();

  /**
  * @pre N/A
  * @post Sums the values of the house's hand
  * @return integer: houseValue (the value of the house's hand)
  **/
  int generateHouseValue();

  /**
  * @pre The player is going to bust due to an ace in their hand
  * @post Replaces the value of the ace from an 11 to a 1
  * @return N/A
  **/
  void playerAceChecker();

  /**
  * @pre The dealer is going to bust due to an ace in their hand
  * @post Replaces the value of the ace from an 11 to a 1
  * @return N/A
  **/
  void dealerAceChecker();

  /**
  * @pre N/A
  * @post Outputs the values of the player and dealer's hand in order to determine a winner
  * @return N/A
  **/
  void endGame();

  deck myDeck;
  int playerValue = 0;
  int houseValue = 0;
  int maximumCards = 10;
  card dealerHand[10];
  card playerHand[10];

};
#endif