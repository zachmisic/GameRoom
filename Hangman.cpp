#include "Hangman.h"
#include<iostream>

Hangman::Hangman()
{
	std::string word = "";
	std::string HMword = "";
	std::string previousGuesses = "";
	int winner = 0;
	int wordTracker = 0;
	int guessesLeft = 6;
}

void Hangman::run()
{
do
{
	reset();
	std::cout<<"\nWelcome to Hangman\n\n";
	std::cout<<"Player one\nEnter a word or phrase(put a '-' in between words): ";
	std::cin>>word;
	wordGenerator();
	do
	{
		wordTracker = 0;
		personDisplay();
		display();
		std::cout<<"Guess: ";
		std::cin>>guess;
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
			previousGuesses = previousGuesses + guess + " ";
		}
		isWinner();
	}while(winner == 0);
	personDisplay();
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
	std::cout<<"Would you like to play again?(y/n): ";
	std::cin>>playAgain;
}while(playAgain == 'y' || playAgain == 'Y');
std::cout<<"Returning to main menu...\n\n";
}

void Hangman::wordGenerator()
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

void Hangman::display()
{
	std::cout<<"\n";
	for(int i=0; i<word.length(); i++)
	{
		std::cout<<HMword.at(i)<<" ";
	}
	std::cout<<"\n\n";
	std::cout<<"Previous Guesses: "<<previousGuesses<<"\n";
	std::cout<<"Guesses Left: "<<guessesLeft<<"\n";
}

void Hangman::personDisplay()
{
	if(guessesLeft == 6)
	{
		std::cout<<"\n   _____\n   |\n   |\n   |\n   |\n -------\n\n";
	}
	if(guessesLeft == 5)
	{
		std::cout<<"\n   _____\n   |   O\n   |\n   |\n   |\n -------\n\n";
	}
	if(guessesLeft == 4)
	{
		std::cout<<"\n   _____\n   |   O\n   |   |\n   |\n   |\n -------\n\n";
	}
	if(guessesLeft == 3)
	{
		std::cout<<"\n   _____\n   |   O\n   |  /|\n   |\n   |\n -------\n\n";
	}
	if(guessesLeft == 2)
	{
		std::cout<<"\n   _____\n   |   O\n   |  /|\\\n   |\n   |\n -------\n\n";
	}
	if(guessesLeft == 1)
	{
		std::cout<<"\n   _____\n   |   O\n   |  /|\\\n   |  /\n   |\n -------\n\n";
	}
	if(guessesLeft == 0)
	{
		std::cout<<"\n   _____\n   |   O\n   |  /|\\\n   |  / \\\n   |\n -------\n\n";
	}
}

void Hangman::isWinner()
{
	wordTracker = 0;
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

void Hangman::reset()
{
	word = "";
	HMword = "";
	previousGuesses = "";
	winner = 0;
	wordTracker = 0;
	guessesLeft = 6;
}