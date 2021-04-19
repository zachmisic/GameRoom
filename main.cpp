#include<iostream>
#include "Hangman.h"
#include "Checkers.h"
#include "snake.h"
#include "Memory.h"
#include "blackjack.h"

int main()
{
	int option;

	do
	{
		std::cout<<"\nMain Menu\n\n1. Hangman\n2. Memory\n3. Snake\n4. Blackjack\n5. Checkers\n6. Quit\n\n";
		std::cout<<"Select an option: ";
		std::cin>>option;
		if(option == 1)
		{
			Hangman HMprogram;
			HMprogram.run();
		}
		else if(option == 2)
		{
			Memory Mprogram;
			Mprogram.run();
		}
		else if(option == 3)
		{
			int height, width;
			std::cout<<"Enter the size of your game board:\nWidth:";
			std::cin>>width;
			std::cout<<"Height:";
			std::cin>>height;
			Snake snakeProgram(width, height);
			snakeProgram.run();
		}
		else if(option == 4)
		{
			blackjack myBlackJack;
			myBlackJack.run();
		}
		else if(option == 5)
		{
			Checkers Cprogram;
			Cprogram.run();
		}
		else if(option == 6)
		{
			std::cout<<"exiting...\n";
		}
		else
		{
			std::cout<<"Invaid option\n";
		}
	}while(option != 6);

return(0);
}
