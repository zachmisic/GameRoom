#include<iostream>
#include "Hangman.h"
#include "HangmanTest.h"
#include "Checkers.h"
#include "snake.h"
#include "snakeTest.h"
//#include "Memory.h"
#include "blackjack.h"
#include "blackjackTest.h"

int main()
{
	int option;

	do
	{
		std::cout<<"\nMain Menu\n\n1. Hangman\n2. Memory\n3. Snake\n4. Blackjack\n5. Checkers\n6. Test\n7. Quit\n\n";
		std::cout<<"Select an option: ";
		std::cin>>option;
		if(option == 1)
		{
			Hangman HMprogram;
			HMprogram.run();
		}
		else if(option == 2)
		{
			//Memory Mprogram;
		//	Mprogram.run();
		}
		else if(option == 3)
		{
			int height, width;
			do{
				std::cout<<"Enter the size of your game board \n(height and width must BOTH be greater than 9 and less than 31):\nWidth:";
				std::cin>>width;
				std::cout<<"Height:";
				std::cin>>height;
			}while(height<=9 || width <=9 || height>30 || width>30);
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
			HangmanTest HMtest;
			HMtest.run();
			SnakeTest sTest;
			sTest.runTests();
			blackjackTest myBlackJackTester;
			myBlackJackTester.run();
		}
		else if(option == 7)
		{
			std::cout<<"exiting...\n";
		}
		else
		{
			std::cout<<"Invaid option\n";
		}
	}while(option != 7);

return(0);
}
