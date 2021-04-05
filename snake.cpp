#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stropts.h>

using namespace std;

//dimensions of board
const int width = 50;
const int height = 25;
const char wall = '#';
const char* terminalclear = "clear";

//arrays and data structures to hold snake data and board data
int board[height][width];
int snake[50][2];         //max snake size
int food[2]={0,0};        //snake food
int score = 0;
int snakeStartLen = 3;
int snakeSpeedX = 1;
int snakeSpeedY = 1;
int split = 200;          //time between frames for animation


//temporary global variables
int px, py, nx, ny;       //coordinates for updating snake movement
char k;


int xmovement = snakeSpeedX;
int ymovement = 0;        //when snake starts out it moves horizontally but not vertically


//found from flipcode.com/archives/_kbhit_for_Linux
//recognize keyboard hits
int keyboardhit() {
  static const int STDIN = 0;
  static bool isInit = false;

  if(! isInit) {
    termios term;
    tcgetattr(STDIN, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN, TCSANOW, &term);
    setbuf(stdin, NULL);
    isInit = true;
  }
  int memoryBytes;
  ioctl(STDIN, FIONREAD, &memoryBytes);
  return memoryBytes;
}


//make board
void create_board(void) {
  int i;
  for(i=0; i<width; i++){ //top and bottom
    board[0][i]=1;
    board[height-1][i]=1;
  }
  for(i=0; i<height; i++){ //left and right
    board[i][0]=1;
    board[i][24]=1;
  }
}

//initialize snake
void create_snake(void){
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
}

//snake movement
void snake_coordinate_updates(void){
  px = snake[0][0];
  py = snake[0][1];
  snake[0][0] = px + xmovement;
  snake[0][1] = py + ymovement;
  nx = snake[0][0];
  ny = snake[0][1];

  for(int i=1; i<snakeStartLen; i++){
    nx = snake[i][0];
    ny = snake[i][1];
    snake[i][0] = px;
    snake[i][1] = py;
    px=nx;
    py=ny;
  }
}

//install snake onto the board
void install_snake (const int val){
  int x=0, y=0;
  for(int i=0; i<snakeStartLen; i++){
    x = snake[i][0];
    y = snake[i][1];
    if((x!=0)&&(y!=0)){
      board[y][x]=val;
    }
  }
}

//print board onto console
void print_board(void){
  int s;
  for(int i=0; i<height; i++){
    for(int j=0; j<height; j++){
      s = board[i][j];
      if(s==1){
        cout << wall;     //wall or snake
      }
      else if (s==2){
        cout << "+";  //+ is food
      }
      else{
        cout << " ";   //nothing there
      }
    }
    cout<<endl;
  }
}

//clear console
void clear_board(void){
  system(terminalclear);
}

//animation loop
void animation_loop(void){

  clear_board();
  install_snake(1);
  print_board();
  install_snake(0);

}

//delay
void sleepcp(int ms){
  clock_t timer_end;
  timer_end = clock() + ms * CLOCKS_PER_SEC/1000;
  while (clock() < timer_end){}
}

//response to keyboard press
void keyboard_responder(const char k){
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
    cout<<"Game Quit, Goodbye!"<<endl;
    exit(0);
  }
}

//initialize food for snake
void food_creation(void){
  srand(time(NULL));
  int fx=0, fy=0;
  if(food[0]==0){
    fx = rand() % width + 1;
    fy = rand() % height + 1;
    food[0]=fx;
    food[1]=fy;
    board[fy][fx]=2;
  }
}

void eat_food(void){
  int ex=0, ey=0;
  ex=food[0];
  ey=food[1];
  if((ex==snake[0][0])&&(ey==snake[0][1])){
    board[ey][ex] = 0;
    food[0]=0;
    score++;
    snakeStartLen++;
    food_creation();
  }
}

//dont let the snake touch the walls!
void check_walltouch(void){
  px=snake[0][0];
  py=snake[0][1];
  if((px==0)||(px==(width-1))||(py==0)||(py==(height-1))){
    cout<<"Game Over"<<endl;
    exit(0);
  }
}

//game loop
void primary_loop(){
  int frame = 0;
  int lx=0;
  int ly =0;

  while(lx<500){
    sleepcp(split);

    if(keyboardhit()){
      cin>>k;
      keyboard_responder(k);
    }

    animation_loop();
    snake_coordinate_updates();
    check_walltouch();
    food_creation();
    eat_food();
    cout<< food[0]<<food[1]<<endl;
    cout<<"< Frame: " << frame <<" | Score: "<< score<<" >"<<endl;
    frame++;
  }
}

int main(){

  create_board();
  create_snake();
  primary_loop();

  return(0);
}
