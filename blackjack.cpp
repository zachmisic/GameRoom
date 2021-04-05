/*--------------------------------------------------------------
 *
 *@file: blackjack.cpp
 *@author: Jake Beesley
 *@assignment: EECS-448 project 3
 *@description: Contains the implementation for the blackjack program
 *
 --------------------------------------------------------------*/


#include <iostream>
#include "blackjack.h"
#include "deck.h"

//The full implementation of the blackjack game
void blackjack::blackjackGame(){
  int playerValue = 0;
  int houseValue = 0;
  char gameContinuation;
  char userInput;

  deck myDeck;
  myDeck.shuffle();
  myDeck.shuffle();
  std::cout << "\n\nWelcome to Blackjack!\n\n";
  std::cout << "House hits on a 16\n\n";

  std::cout << "House's hand : | ** of ** | and ";
  myDeck.printCard();
  houseValue = myDeck.getValue();
  std::cout << "House's current value : ?? + " << houseValue << "\n\n";
  myDeck.deal(); //Adjusts to new card in the deck

  std::cout << "You have been dealt a: \t";
  myDeck.printCard();
  playerValue = myDeck.getValue();
  myDeck.deal();
  std::cout << "\t \t \t";
  myDeck.printCard();
  playerValue = myDeck.getValue() + playerValue;
  myDeck.deal();
  std::cout << "Value of the hand : " << playerValue << "\n\n";

  do{
    std::cout << "Do you want to hit or stay? (h/s): ";
    std::cin >> userInput;
    if(userInput == 'h'){https://github.com/zachmisic/GameRoom.git
      std::cout << "\n";
      std::cout << "You have been dealt a: \t";
      myDeck.printCard();
      playerValue = myDeck.getValue() + playerValue;
      myDeck.deal();
      std::cout << "Value of the hand : " << playerValue << "\n";
    }
    else if(userInput == 's'){
      break;
    }
    else{
      std::cout << "Invalid input! Try again. \n";
    }
  }while(playerValue < 21);

  if(playerValue > 21){
    std::cout << "You busted! \n";
  }
  else{
    std::cout << "The house's second card was a : ";
    myDeck.printCard();
    houseValue = myDeck.getValue() + houseValue;
    std::cout << "House's current value : " << houseValue << "\n\n";
    myDeck.deal();
    if(houseValue < 17){
      do{
        std::cout << "The house's has been dealt a : ";
        myDeck.printCard();
        houseValue = myDeck.getValue() + houseValue;
        std::cout << "House's current value : " << houseValue << "\n\n";
        myDeck.deal();
      }while(houseValue < 17);
    }
    std::cout << "House's current value : " << houseValue << "\n";
    std::cout << "Your current value : " << playerValue << "\n\n";
    if(playerValue > houseValue || houseValue > 21){
      std::cout << "You won! \n\n";
    }
    else if(houseValue > playerValue){
      std::cout << "You lost! \n\n";
    }
    else{
      std::cout << "You both tied! \n\n";
    }
  }

  std::cout << "Would you like to play again? (y/n): ";
  std::cin >> gameContinuation;
  if(gameContinuation == 'y'){
    system("clear");
    blackjackGame();
  }
  else if(gameContinuation == 'n'){
    std::cout << "Thanks for playing! \n";
  }
  else{
    std::cout << "Thanks for playing! \n";
  }
}

//Runs the blackjack game
void blackjack::run(){
  blackjackGame();
}
}
