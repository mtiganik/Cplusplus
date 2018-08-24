/// FILE NAME: functions11.h
/// PROJECT: Exercise11
/// AUTHOR: Mihkel Tiganik
/// CREATED: 21.06.2018
///
/// DESCRIPTION:  Declarations of functions for Exercise11


#ifndef EXERCISE11_HEADER_
#define EXERCISE11_HEADER_

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


const int height = 20;
const int width = 20;
const int obstacles = 50;


static char area[height][width];

void initializeArea();
void displayArea();
void game();

int moveup(int i, int j);
int movedown(int i, int j);
int moveleft(int i, int j);
int moveright(int i, int j);

#endif // !EXERCISE11_HEADER_

