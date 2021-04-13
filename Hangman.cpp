/**
* @Hangman.cpp
* @Author: Brooke Jackson
* @Defines methods for the Hangman class
**/

#include "Hangman.h"
#include<iostream>

Hangman::Hangman()
{
	std::string word = "";
	std::string HMword = "";
	std::string previousGuesses = "";
}

void Hangman::run()
{
	system("clear");
	std::cout<<"\nWelcome to Hangman\n\n";
	do
	{
		reset();
		std::cout<<"Select a mode or return to main menu\n1. Classic\n2. Battle\n3. Main Menu\n\n";
		std::cout<<"Option: ";
		std::cin>>mode;
		if(mode == 1)
		{
			classic();
		}
		else if(mode == 2)
		{
			battle();
		}
		else if(mode < 1 || mode > 3)
		{
			std::cout<<"Invalid option\n";
			run();
		}
	}while(mode != 3);
	system("clear");
}

void Hangman::classic()
{
	system("clear");
	std::cout<<"\n\nClassic Mode\n\n";
	std::cout<<"Player 1\nEnter a word or phrase for player 2 to guess\n";
	std::cout<<"(put a '-' in between words): ";
	std::cin>>word;
	wordGenerator(1);
	setGuessNum(1);
	system("clear");
	do
	{
		wordTracker = 0;
		personDisplay(1);
		display(1);
		guessChecker(1);
		wordUpdater(1);
		isWinner(1);
		system("clear");
	}while(winner == 0);
	personDisplay(1);
	std::cout<<"\n\nThe phrase was: ";
	for(int i=0; i<word.length(); i++)
	{
		if(word.at(i) == '-')
		{
			std::cout<<" ";
		}
		else
		{
			std::cout<<word.at(i);
		}
	}
	std::cout<<"\n\nPlayer "<<winner<<" Wins!\n\n";
}

void Hangman::battle()
{
	system("clear");
	std::cout<<"\n\nBattle Mode\n\n";
	std::cout<<"Player 1\nEnter a word or phrase for player 2 to guess\n";
	std::cout<<"(put a '-' in between words): ";
	std::cin>>word;
	wordGenerator(1);
	setGuessNum(1);
	system("clear");
	std::cout<<"\nPlayer 2\nEnter a word or phrase for player 1 to guess\n";
	std::cout<<"(put a '-' in between words): ";
	std::cin>>word2;
	wordGenerator(2);
	setGuessNum(2);
	system("clear");
	do
	{
		if(player == 1)
		{
			std::cout<<"Player 2's turn";
		}
		else
		{
			std::cout<<"Player 1's turn";
		}
		wordTracker = 0;
		personDisplay(player);
		display(player);
		guessChecker(player);
		wordUpdater(player);
		system("clear");
		isWinner(player);
		flipPlayer();
	}while(winner == 0);
	personDisplay(1);
	std::cout<<"\n\nPlayer 1's phrase was: ";
	for(int i=0; i<word.length(); i++)
	{
		if(word.at(i) == '-')
		{
			std::cout<<" ";
		}
		else
		{
			std::cout<<word.at(i);
		}
	}
	personDisplay(2);
	std::cout<<"\n\nPlayer 2's phrase was: ";
	for(int i=0; i<word2.length(); i++)
	{
		if(word2.at(i) == '-')
		{
			std::cout<<" ";
		}
		else
		{
			std::cout<<word2.at(i);
		}
	}

	std::cout<<"\n\nPlayer "<<winner<<" Wins!\n\n";
}

void Hangman::wordGenerator(int player)
{
	if(player == 1)
	{
		for(int i=0; i<word.length(); i++)
		{
			if(word.at(i) == '-')
			{
				HMword = HMword + " ";
			}
			else
			{
				HMword = HMword + "_";
			}
		}
	}
	if(player == 2)
	{
		for(int i=0; i<word2.length(); i++)
		{
			if(word2.at(i) == '-')
			{
				HMword2 = HMword2 + " ";
			}
			else
			{
				HMword2 = HMword2 + "_";
			}
		}
	}
}

void Hangman::display(int player)
{
	std::cout<<"\n";
	if(player == 1)
	{
		for(int i=0; i<word.length(); i++)
		{
			std::cout<<HMword.at(i)<<" ";
		}
		std::cout<<"\n\n";
		std::cout<<"Previous Guesses: "<<previousGuesses<<"\n";
		std::cout<<"Guesses Left: "<<guessesLeft<<"\n";
	}
	if(player == 2)
	{
		for(int i=0; i<word2.length(); i++)
		{
			std::cout<<HMword2.at(i)<<" ";
		}
		std::cout<<"\n\n";
		std::cout<<"Previous Guesses: "<<previousGuesses2<<"\n";
		std::cout<<"Guesses Left: "<<guessesLeft2<<"\n\n";
	}
}

void Hangman::personDisplay(int player)
{
	int tempGL;
	int tempG;
	if(player == 1)
	{
		tempGL = guessesLeft;
		tempG = guesses;
	}
	if(player == 2)
	{
		tempGL = guessesLeft2;
		tempG = guesses2;
	}
	if(tempGL > tempG/6*5)
	{
		std::cout<<"\n   _____\n   |\n   |\n   |\n   |\n -------\n\n";
	}
	else if(tempGL > tempG/6*4)
	{
		std::cout<<"\n   _____\n   |   O\n   |\n   |\n   |\n -------\n\n";
	}
	else if(tempGL > tempG/6*3)
	{
		std::cout<<"\n   _____\n   |   O\n   |   |\n   |\n   |\n -------\n\n";
	}
	else if(tempGL > tempG/6*2)
	{
		std::cout<<"\n   _____\n   |   O\n   |  /|\n   |\n   |\n -------\n\n";
	}
	else if(tempGL > tempG/6*1)
	{
		std::cout<<"\n   _____\n   |   O\n   |  /|\\\n   |\n   |\n -------\n\n";
	}
	else if(tempGL > 0)
	{
		std::cout<<"\n   _____\n   |   O\n   |  /|\\\n   |  /\n   |\n -------\n\n";
	}
	else if(tempGL == 0)
	{
		std::cout<<"\n   _____\n   |   O\n   |  /|\\\n   |  / \\\n   |\n -------\n\n";
	}
}

void Hangman::isWinner(int player)
{
	wordTracker = 0;
	if(player == 1)
	{
		for(int i=0; i<word.length(); i++)
		{
			if(HMword.at(i) == '_')
			{
				wordTracker = 1;
			}
		}
		if(wordTracker == 0)
		{
			winner = 2;
		}
		if(guessesLeft == 0)
		{
			winner = 1;
		}
	}
	if(player == 2)
	{
		for(int i=0; i<word2.length(); i++)
		{
			if(HMword2.at(i) == '_')
			{
				wordTracker = 1;
			}
		}
		if(wordTracker == 0)
		{
			winner = 1;
		}
		if(guessesLeft2 == 0)
		{
			winner = 2;
		}
	}	
}

void Hangman::setGuessNum(int player)
{
	if(player == 1)
	{
		std::cout<<"How many guesses would you like to give player 2?: ";
		std::cin>>guesses;
		guessesLeft = guesses;
		if(guesses < 6 || guesses > 25)
		{
			std::cout<<"\nInvalid input\nNumber should be between 6 and 25\n\n";
			setGuessNum(1);
		}
	}
	if(player == 2)
	{
		std::cout<<"How many guesses would you like to give player 1?: ";
		std::cin>>guesses2;
		guessesLeft2 = guesses2;
		if(guesses2 < 6 || guesses2 > 25)
		{
			std::cout<<"\nInvalid input\nNumber should be between 6 and 25\n\n";
			setGuessNum(2);
		}
	}
}

void Hangman::guessChecker(int player)
{
	std::cout<<"Guess: ";
	std::cin>>guess;
	if(player == 1)
	{
		for(int i=0; i<previousGuesses.length(); i++)
		{
			if(guess == previousGuesses.at(i))
			{
				std::cout<<"\nOpps, you already guessed "<<guess<<".\n";
				guessChecker(player);
			}
		}
	}
	if(player == 2)
	{
		for(int i=0; i<previousGuesses2.length(); i++)
		{
			if(guess == previousGuesses2.at(i))
			{
				std::cout<<"\nOpps, you already guessed "<<guess<<".\n";
				guessChecker(player);
			}
		}
	}
}

void Hangman::wordUpdater(int player)
{
	if(player == 1)
	{
		for(int i=0; i<word.length(); i++)
		{
			if(word.at(i) == guess)
			{
				HMword.at(i) = word.at(i);
				wordTracker = 1;
			}
		}
		if(wordTracker == 0)
		{
			guessesLeft = guessesLeft-1;
		}
		previousGuesses = previousGuesses + guess + " ";
	}
	if(player == 2)
	{
		for(int i=0; i<word2.length(); i++)
		{
			if(word2.at(i) == guess)
			{
				HMword2.at(i) = word2.at(i);
				wordTracker = 1;
			}
		}
		if(wordTracker == 0)
		{
			guessesLeft2 = guessesLeft2-1;
		}
		previousGuesses2 = previousGuesses2 + guess + " ";
	}
}

void Hangman::flipPlayer()
{
	if(player == 1)
	{
		player = 2;
	}
	else
	{
		player = 1;
	}
}

void Hangman::reset()
{
	word = "";
	HMword = "";
	previousGuesses = "";
	wordTracker = 0;
	word2 = "";
	HMword2 = "";
	previousGuesses2 = "";
	winner = 0;
	guesses = 0;
	guessesLeft = 0;
	player = 2;
}
