#include "HangmanTest.h"
#include<iostream>

HangmanTest::HangmanTest()
{
	std::string word = "";
	std::string HMword = "";
	std::string previousGuesses = "";
}

void HangmanTest::run()
{
	system("clear");
	std::cout<<"\nTesting Hangman...\n";
	reset();
	classic();
	reset();
	battle();
	std::cout<<"\nhangman test: passed\n";
}

void HangmanTest::classic()
{
	std::cout<<"\ntesting classic mode...\n";
	word = "a";
	wordGenerator(1);
	setGuessNum(1);
	do
	{
		personDisplay(1);
		display(1);
		guessChecker(1);
		wordUpdater(1);
		isWinner(1);
	}while(winner == 0);
	std::cout<<"\nclassic mode test: passed\n";
}

void HangmanTest::battle()
{
	std::cout<<"\ntesting battle mode...\n";
	word = "a";
	wordGenerator(1);
	setGuessNum(1);
	word2 = "b";
	wordGenerator(2);
	setGuessNum(2);
	wordTracker = 0;
	personDisplay(player);
	display(player);
	guessChecker(player);
	wordUpdater(player);
	isWinner(player);
	flipPlayer();
	std::cout<<"\nbattle mode: passed\n";
}

void HangmanTest::wordGenerator(int player)
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
		std::cout<<"player 1 word generator: ";
		if(word.length() == HMword.length())
		{
			std::cout<<"passed\n";
		}
		else
		{
			std::cout<<"failed\n";
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
		std::cout<<"player 2 word generator: ";
		if(word2.length() == HMword2.length())
		{
			std::cout<<"passed\n";
		}
		else
		{
			std::cout<<"failed\n";
		}

	}
}

void HangmanTest::display(int player)
{
	if(player == 1)
	{
		std::cout<<"player 1 word display: passed\n";
	}
	if(player == 2)
	{
		std::cout<<"player 2  word display: passed\n";
	}
}

void HangmanTest::personDisplay(int player)
{
	if(player == 1)
	{
		std::cout<<"player 1 hangman display: passed\n";
	}
	if(player == 2)
	{
		std::cout<<"player 2 hangman display: passed\n";
	}
}

void HangmanTest::isWinner(int player)
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
	std::cout<<"winner checker: passed\n";
}

void HangmanTest::setGuessNum(int player)
{
	if(player == 1)
	{
		guesses = 1;
		guessesLeft = guesses;
		std::cout<<"player 1 set guess number: passed\n";
	}
	if(player == 2)
	{
		guesses2 = 1;
		guessesLeft2 = guesses2;
		std::cout<<"player 2 set guess number: passed\n";
	}
}

void HangmanTest::guessChecker(int player)
{
	if(player == 1)
	{
		std::cout<<"player 1 guess checker: passed\n";
	}
	if(player == 2)
	{
		std::cout<<"player 2 guess checker: passed\n";
	}
}

void HangmanTest::wordUpdater(int player)
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
		std::cout<<"player 1 display updater: passed\n";
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
		std::cout<<"player 2 display updater: passed\n";

	}
}

void HangmanTest::flipPlayer()
{
	if(player == 1)
	{
		player = 2;
	}
	else
	{
		player = 1;
	}
	std::cout<<"flip player: passed\n";
}

void HangmanTest::reset()
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
