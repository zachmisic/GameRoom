/*--------------------------------------------------------------
 *
 *@file: snake.h
 *@author: Chloe Thornton
 *@assignment: EECS-448 project 3
 *@description: This file holds all methods for the Snake class.
 *@date: Friday, April 2nd 2021
 *
 --------------------------------------------------------------*/

#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stropts.h>
#include <string.h>

class Snake
{
  private:
    //dimensions of board
    int width;
    int height;


  public:
    int snake[25][2];
    int board[25][25];         //max snake size
    int food[2]={0,0};        //snake food
    int score;
    int snakeStartLen;
    int snakeSpeedX;
    int snakeSpeedY;
    int split;
    int xmovement;
    int ymovement;
    char wall;

    /**
    		* @pre The class is created
    		* @post The class is created
    		* @param none
    		* @return N/A
    		**/
    Snake();

    /**
		* @pre none
		* @post a keyboard hit is registered and the key is passed on to keyboard_responder
		* @param none
		* @return N/A
		**/
    int keyboardhit();

    /**
		* @pre the board is called
		* @post The game board is initialized
		* @param none
		* @return N/A
		**/
    void create_board();

    /**
		* @pre snake is called
		* @post Snake is initialized
		* @param none
		* @return N/A
		**/
    void create_snake();

    /**
		* @pre Game has begun, snake is moving
		* @post depending on key that has been hit and the speed of the snake, the snake's coordinates are updated
		* @param none
		* @return N/A
		**/
    void snake_coordinate_updates();

    /**
		* @pre Snake has been initialized on board
		* @post snake array is given values based in current length of the snake
		* @param val, the code for '#'
		* @return N/A
		**/
    void install_snake(const int val);

    /**
		* @pre all components are initialized
		* @post board is able to be printed to console
		* @param none
		* @return N/A
		**/
    void print_board();

    /**
		* @pre board has been printed, terminal is non empty
		* @post board is cleared from terminal
		* @param none
		* @return N/A
		**/
    void clear_board();

    /**
		* @pre all components initialized, game being played
		* @post initializes snake, prints board and clears board
		* @param none
		* @return N/A
		**/
    void animation_loop();

    /**
		* @pre none
		* @post sets a time delay that will be used in the final loop
		* @param ms, the time delay in milliseconds
		* @return N/A
		**/
    void sleepcp(int ms);

    /**
		* @pre a key has been pressed
		* @post The snake's movement speed is altered depending on what key is pressed
		* @param k, the key that was pressed
		* @return N/A
		**/
    void keyboard_responder(const char k);

    /**
		* @pre none
		* @post food is created, board array is updated to reflect it
		* @param none
		* @return N/A
		**/
    void food_creation();

    /**
		* @pre food has been created
		* @post checks whether snake has eaten food, creates new food if yes.
		* @param none
		* @return N/A
		**/
    void eat_food();

    /**
		* @pre game is being played
		* @post ends game if snake is touching a wall, otherwise does nothing
		* @param none
		* @return N/A
		**/
    void check_walltouch();

    /**
		* @pre none
		* @post The loop runs updating as the snake moves and eats food, prompting creation of more food
		* @param none
		* @return N/A
		**/
    void primary_loop();

    /**
		* @pre all components and methods defined
		* @post game runs
		* @param none
		* @return N/A
		**/
    void run();
};

#endif
