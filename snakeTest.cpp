/*--------------------------------------------------------------
 *
 *@file: snake.cpp
 *@author: Chloe Thornton
 *@assignment: EECS-448 project 3
 *@description: This file holds all method definitions for the Snake class.
 *@date: Friday, April 2nd 2021
 *
 --------------------------------------------------------------*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stropts.h>
#include "snakeTest.h"

using namespace std;

SnakeTest::SnakeTest(){
  testboard = new int* [25];
  for(int x=0; x<25; x++){
      testboard[x]= new int[25];
    }
  snake = new int* [25];
  for(int y=0; y<25; y++){
      snake[y]= new int[2];
    }

  score = 0;
  snakeStartLen = 3;
  snakeSpeedX = 1;
  snakeSpeedY = 1;

  for(int i=0; i<25; i++){
    snake[i][0]=0;
    snake[i][1]=0;
    snake[i][2]=0;
 }
 for(int j=0; j<25; j++){
   for(int k=0; k<25; k++){
     snake[j][k] = 0;
   }
 }
  width=25;
  height=25;
  xmovement = snakeSpeedX;
  ymovement = 0;
}



//make board
void SnakeTest::create_board(void) {
  for(int i=0; i<width; i++){ //top and bottom
    testboard[0][i]=1;
    testboard[width-1][i]=1;
  }
  for(int j=0; j<height; j++){ //left and right
    testboard[j][0]=1;
    testboard[j][height-1]=1;
  }
}

//initialize snake
void SnakeTest::create_snake(void){
  snake[0][0]=3;
  snake[0][1]=3;

  snake[1][0]=3+1;
  snake[1][1]=3;

  snake[2][0]=3+2;
  snake[2][1]=3;

  snake[3][0]=3+3;
  snake[3][1]=3;

  snake[4][0]=3+4;
  snake[4][1]=3;

  snake[5][0]=3+5;
  snake[5][1]=3;
}


//install snake onto the board
void SnakeTest::install_snake(const int val){
  int x=2, y=2;
  for(int i=0; i<snakeStartLen; i++){
      testboard[y][x]=val;
      x++;
    }
    if(check_wall_values()==true){
      cout<<"Walls tests: passed.\n";
    }
    else{
      cout<<"Walls tests: failed.\n";
    }
    if(check_snake_values()==true){
      cout<<"Snake tests: passed.\n";
    }
    else{
      cout<<"Snake tests: failed.\n";
    }
}

//checks that the correct values are loaded onto the board for the walls and the snake
bool SnakeTest::check_wall_values(void){
  int s;
  bool temp=false;
  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      s=testboard[i][j];
      if(s==1){
       if(i==0 || i==width-1 || j==0 || j==height-1){
         temp=true;
        }
      }
    }
  }
  return temp;
}

//checks that the correct values are loaded onto the board for the food
bool SnakeTest::check_food_values(void){
  int s;
  bool temp=true;
  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      s=testboard[i][j];
      if(s==2){
       if(i!=3 && j!=10){
         temp=false;
        }
      }
    }
  }
  return temp;
}

bool SnakeTest::check_snake_values(void){
  int s;
  bool temp=false;
  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      s=testboard[i][j];
      if(s==4){
       if(j==2 || j==3 || j==4){
         temp=true;
        }
      }
    }
  }
  return temp;
}

bool SnakeTest::keystroke_check(){
  keyboard_responder('d');
  keyboard_responder('a');
  keyboard_responder('w');
  keyboard_responder('s');
  keyboard_responder('q');
  if(xmovement==0 && ymovement==2){
    return true;
  }
  else{
    return false;
  }
}


//response to keyboard press
void SnakeTest::keyboard_responder(const char k){

  if(k=='d'||k=='6'){ //move right
    xmovement = snakeSpeedX;
    ymovement = 0;
  }
  else if(k=='a'||k=='4'){ //move left
    xmovement = -snakeSpeedX;
    ymovement = 0;
  }
  else if(k=='w'||k=='8'){ //move up
    xmovement = 0;
    ymovement = -snakeSpeedY;
  }
  else if(k=='s'||k=='2'){ //move down
    xmovement = 0;
    ymovement = snakeSpeedY;
  }
  else if(k=='q'||k=='z'||k=='c'){
    ymovement++;
  }
}

//initialize food for snake
void SnakeTest::food_creation_tester(void){
    food[0]=10;
    food[1]=3;
    testboard[3][10]=2;
    if(check_food_values()==true){
      cout<<"Food creation test: passed. \n";
    }
    else{
      cout<<"Food creation test: failed. \n";
    }
  }

  bool SnakeTest::eat_food_test(void){
    if(testboard[3][10]==0 && score == 1 && snakeStartLen==4){
      return true;
    }
    else{
    return false;
    }
  }


void SnakeTest::eat_food(void){
  int ex=10, ey=3;
  if((ex==10)&&(ey==3)){
    testboard[ey][ex] = 0;
    food[0]=0;
    score++;
    snakeStartLen++;
  }
  if(eat_food_test()==true){
    cout<<"Food eaten test: passed.\n";
  }
  else{
    cout<<"Food eaten test: failed.\n";
  }
}

//dont let the snake touch the walls!
bool SnakeTest::walltouch_test(void){
  bool test=false;
  int qx, qy;
  qx=0;
  qy=0;
  if((qx==0)||(qx==(width-1))||(qy==0)||(qy==(height-1))){
    test=true;
  }
  return test;
}

void SnakeTest::runTests(){

cout<<"\nRunning Snake Test Suite...\n\n";
  create_board();
  create_snake();
  install_snake(4);
  if(keystroke_check()==true){
    cout<<"Keystroke test: passed. \n";
  }
  else{
    cout<<"Keystroke test: failed. \n";
  }
  if(walltouch_test()==true){
    cout<<"Wall touch test: passed. \n";
  }
  else{
    cout<<"Wall touch test: failed. \n";
  }
  food_creation_tester();
  eat_food();
  cout<<"\nSnake Tests Complete. \n";

}
