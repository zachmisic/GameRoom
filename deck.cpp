/*--------------------------------------------------------------
 *
 *@file: deck.cpp
 *@author: Jake Beesley
 *@assignment: EECS-448 project 3
 *@description: Implementation file for the deck class, which works with the blackjack program
 *
 --------------------------------------------------------------*/

#include "deck.h"

//Constructor for the deck of cards
deck::deck(){
  m_topOfDeck = 0;
  std::string faces[13] = {"Ace", "King", "Queen", "Jack", "Ten", "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two"};
  std::string suits[4] = {"Hearts", "Diamonds", "Spades", "Clubs"};
  int values[13] = {11,10,10,10,10,9,8,7,6,5,4,3,2};

  for(int i = 0; i < m_totalCards; i++){
    m_deck[i] = card(faces[i % 13], suits[i % 4], values[i % 13]);
  }
}

//Shuffles the deck of cards
void deck::shuffle(){
  for(int x = 0; x < m_totalCards; x++){
    int j = (rand() + time(0)) % 52;
    card temp = m_deck[x];
    m_deck[x] = m_deck[j];
    m_deck[j] = temp;
  }
}

//Prints the card at the top of the deck
void deck::printCard(){
  std::cout << m_deck[m_topOfDeck].print() << "\n";
}

//Increments the top of the deck by 1
void deck::deal(){
  m_topOfDeck = m_topOfDeck+1;
}

//Returns the value of the top of the deck
int deck::getValue(){
  return(m_deck[m_topOfDeck].getValue());
}

//Prints the entire deck of cards (used for testing)
void deck::printDeck() const{
  for(int i = 0; i < m_totalCards;i++){
    std::cout << m_deck[i].print() << std::endl;
  }
}
