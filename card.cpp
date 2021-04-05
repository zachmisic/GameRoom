/*--------------------------------------------------------------
 *
 *@file: card.cpp
 *@author: Jake Beesley
 *@assignment: EECS-448 project 3
 *@description: Implementation file for the card class, which works with the blackjack program
 *
 --------------------------------------------------------------*/

#include "card.h"

//Constructor for the card class
card::card(std::string face, std::string suit, int value){
  m_face = face;
  m_suit = suit;
  m_value = value;
}

//Returns the information of a card
std::string card::print() const{
  return("| " + m_face + " of " + m_suit + " |");
}

//Default constructor
card::card(){
}

//Returns the value of the card
int card::getValue(){
  return(m_value);
}
