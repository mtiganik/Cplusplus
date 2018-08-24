/// FILE NAME: functions11.cpp
/// PROJECT: Exercise11
/// AUTHOR: Mihkel Tiganik
/// CREATED: 21.06.2018
///
/// DESCRIPTION:  Definitions of functions for Exercise11

#include <iostream>
#include <conio.h>
#include <time.h>

#include "functions11.h"

void game() {
  int c = 0;
  int result = 0;
  displayArea();
  do
  {
    c = _getch();
    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
        if (area[i][j] == 'G') {
          switch (c) {
          case KEY_UP:
            result = moveup(i, j);
            break;
          case KEY_DOWN:
            result = movedown(i, j);
            break;
          case KEY_LEFT:
            result = moveleft(i, j);
            break;
          case KEY_RIGHT:
            result = moveright(i, j);
            break;
          default:
            break;
          }
          goto endloop;
        }
      }
    }
  endloop:;
    system("cls");
    displayArea();
  } while (result == 0);
  if (result == 2) {
    std::cout << "you lost!" << std::endl;
  }if (result == 1) {
    std::cout << "Congratulation, you won!" << std::endl;
  }
  std::cout << "Press enter for new game" << std::endl;
  do {
    c = _getch();
  } while (c != 13);
  initializeArea();
  game();
}

int moveup(int i, int j) {
  if (i == 0) return 0; // player next to border, no movement
  switch (area[i - 1][j]) {
  case('T'):
    return 2; // Lost of game;
    break;
  case('X'):
    return 1; // player won game;
    break;
  default:
    area[i][j] = '.';
    area[i - 1][j] = 'G';
    return 0; // continue game;
    break;
  }
}

int movedown(int i, int j) {
  if (i == height - 1) return 0; // player next to border, no movement
  switch (area[i + 1][j]) {
  case('T'):
    return 2; // Lost of game;
    break;
  case('X'):
    return 1; // player won game;
    break;
  default:
    area[i][j] = '.';
    area[i + 1][j] = 'G';
    return 0; // continue game;
    break;
  }
}

int moveleft(int i, int j) {
  if (j == 0) return 0; // player next to border, no movement
  switch (area[i][j - 1]) {
  case('T'):
    return 2; // Lost of game;
    break;
  case('X'):
    return 1; // player won game;
    break;
  default:
    area[i][j] = '.';
    area[i][j - 1] = 'G';
    return 0; // continue game;
    break;
  }
}
int moveright(int i, int j) {
  if (j == width - 1) return 0; // player next to border, no movement
  switch (area[i][j + 1]) {
  case('T'):
    return 2; // Lost of game;
    break;
  case('X'):
    return 1; // player won game;
    break;
  default:
    area[i][j] = '.';
    area[i][j + 1] = 'G';
    return 0; // continue game;
    break;
  }
}



void initializeArea() {
  int i, j, count = 0;
  bool playerSet = false, exitSet = false;

  // set initial empty area
  for (i = 0; i < height; ++i) {
    for (j = 0; j < width; ++j) {
      area[i][j] = '.';
    }
  }
  srand(time(NULL));
  //set obstacles, players and exit
  do {
    i = rand() % height;
    j = rand() % width;
    if (area[i][j] == '.' && count < obstacles) {
      area[i][j] = 'T';
      count++;
    }
    if (count >= obstacles) {
      if (area[i][j] == '.') {
        if (!playerSet) {
          area[i][j] = 'G';
          playerSet = true;
        }
        else if (!exitSet) {
          area[i][j] = 'X';
          exitSet = true;
        }
      }
    }
  } while (!(playerSet && exitSet));
}

void displayArea() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      std::cout << area[i][j];
    }
    std::cout << std::endl;
  }
}