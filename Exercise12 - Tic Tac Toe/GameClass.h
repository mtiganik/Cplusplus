/// FILE NAME: GameClass.h
/// PROJECT: Exercise12
/// AUTHOR: Mihkel Tiganik
/// CREATED: 14.06.2018
/// MODIFIED 21.06.2018
///
/// DESCRIPTION:  Header file for GameClass

#ifndef EXERCISE12_GAMECLASS_
#define EXERCISE12_GAMECLASS_

#include <iostream>
#include <vector>
#include <windows.h>

class GameClass
{
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define SPACE 32
#define ENTER 13

  std::vector <std::vector<char> > m_area_vector;
  HANDLE m_h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD m_coord;

  int m_size;
  bool m_isPlayerA, m_isGameOn, m_playerAWon, m_playerBWon;
  void InitializeBooleans();
  void Move(int column, int line);
  void Gotoxy(int column, int line);
  COORD GetConsoleCursorPosition(HANDLE hConsoleOutput);
  void PlaceValue(COORD coord);
  bool CheckForWin();

public:
  GameClass();
  ~GameClass();
  void GetAreaSize();
  void SetAreaSize(int i);
  void InitializeArea();
  void StartGame();
  void Game();
};

#endif // !EXERCISE12_GAMECLASS_