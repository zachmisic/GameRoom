#include<iostream>
#include "Hangman.h"

int main()
{
	int option;
	
	std::cout<<"Main Menu\n\n1. Hangman\n2. Memory\n3. Snake\n4. Blackjack\n5. Checkers\n\n";
	std::cout<<"Which game would you like to play?: ";
	std::cin>>option;
	if(option == 1)
	{
		Hangman HMprogram;
		HMprogram.run();
	}
	if(option == 2)
	{
	}
	if(option == 3)
	{
	}
	if(option == 4)
	{
	}
	if(option == 5)
	{
	}
return(0);
}
