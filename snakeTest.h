/*--------------------------------------------------------------
 *
 *@file: snake.h
 *@author: Chloe Thornton
 *@assignment: EECS-448 project 3
 *@description: This file holds all methods for the Snake class.
 *@date: Friday, April 2nd 2021
 *
 --------------------------------------------------------------*/

#ifndef SNAKETEST_H
#define SNAKETEST_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stropts.h>
#include <string.h>

class SnakeTest
{
  private:
    //dimensions of board
    int width;
    int height;


  public:
    int** testboard;
    int** snake;         //max snake size
    int food[2]={0,0};        //snake food
    int score;
    int snakeStartLen;
    int snakeSpeedX;
    int snakeSpeedY;
    int xmovement;
    int ymovement;

    /**
    		* @pre The class is created
    		* @post The class is created
    		* @param none
    		* @return N/A
    		**/
    SnakeTest();


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
		* @pre Snake has been initialized on board
		* @post snake array is given values based in current length of the snake, calls check wall check_wall_values
		* @param val, the code for '#'
		* @return N/A
		**/
    void install_snake(const int val);

    /**
		* @pre all components are initialized
		* @post board is able to be printed to console
		* @param none
		* @return  this test returns true if the testboard values are in the right place for the walls
		**/
    bool check_wall_values();

    /**
    * @pre all components are initialized
    * @post food is able to be printed to console on the board
    * @param none
    * @return  this test returns true if the testboard values are in the right place for the food
    **/
    bool check_food_values();

    /**
    * @pre all components are initialized
    * @post snake is able to be printed to console on the board
    * @param none
    * @return  this test returns true if the testboard values are in the right place for the snake
    **/
    bool check_snake_values();

    /**
    * @pre none
    * @post tests are run
    * @param none
    * @return  this test returns true if the keys make the snakes movememnt chnage correctly
    **/
    bool keystroke_check();


    /**
		* @pre a key has been pressed
		* @post The snake's movement speed is altered depending on what key is pressed, runs test on it
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
    void food_creation_tester();

    /**
		* @pre food has been created
		* @post checks whether snake has eaten food
		* @param none
		* @return N/A
		**/
    void eat_food();

    /**
    * @pre food has been created
    * @post checks whether snake has eaten food
    * @param none
    * @return this test returns true if the snake has eaten the food, and the score and length has been updated
    **/
    bool eat_food_test();

    /**
		* @pre game is being played
		* @post ends game if snake is touching a wall, otherwise does nothing
		* @param none
		* @return this test returns true if a wall touch is registered correctly and will end the game.
		**/
    bool walltouch_test();

    /**
		* @pre all components and methods defined
		* @post test suite runs
		* @param none
		* @return N/A
		**/
    void runTests();
};

#endif
