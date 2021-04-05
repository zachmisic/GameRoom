/*--------------------------------------------------------------
 *
 *@file: blackjack.h
 *@author: Jake Beesley
 *@assignment: EECS-448 project 3
 *@description: Header file for the blackjack program
 *
 --------------------------------------------------------------*/

#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <string>

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
};
#endif
