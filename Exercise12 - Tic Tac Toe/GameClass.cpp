/// FILE NAME: GameClass.cpp
/// PROJECT: Exercise12
/// AUTHOR: Mihkel Tiganik
/// CREATED: 14.06.2018
/// MODIFIED 21.06.2018
///
/// DESCRIPTION:  Definitions of GameClass methods

#include "conio.h"
#include <iostream>

#include "GameClass.h"

GameClass::GameClass()
{
}


GameClass::~GameClass()
{
}


void GameClass::StartGame() {

  //GetAreaSize(); // Area size for user input
  SetAreaSize(3); // Let just set area size automatically
  InitializeArea();
  Game();
}

void GameClass::Game() {
  int c = 0;
  Gotoxy(1, 2);
  do {
    c = _getch();
    m_coord = GetConsoleCursorPosition(m_h);
    switch (c) {
    case KEY_UP:
      Move(m_coord.X, m_coord.Y - 4);
      break;
    case KEY_DOWN:
      Move(m_coord.X, m_coord.Y + 4);
      break;
    case KEY_LEFT:
      Move(m_coord.X - 4, m_coord.Y);
      break;
    case KEY_RIGHT:
      Move(m_coord.X + 4, m_coord.Y);
      break;
    case SPACE:
      PlaceValue(m_coord);
    default:
      break;

    }

  } while (m_isGameOn);
  Gotoxy(0, m_size * 4);
  std::cout << "Press ENTER for new game" << std::endl;
  do {
    c = _getch();
  } while (c != ENTER);
  StartGame();

}
void GameClass::PlaceValue(COORD coord) {
  if (m_area_vector[(coord.X) / 4][(coord.Y - 2) / 4] == '_') {
    if (m_isPlayerA) {
      putchar('X');
      m_area_vector[(coord.X) / 4][(coord.Y - 2) / 4] = 'X';
      Gotoxy(7, 0);
      putchar('B');

    }
    else {
      putchar('O');
      m_area_vector[(coord.X) / 4][(coord.Y - 2) / 4] = 'O';
      Gotoxy(7, 0);
      putchar('A');

    }
    m_isGameOn = CheckForWin();
    m_isPlayerA = !m_isPlayerA;
  }

  Gotoxy(coord.X, coord.Y);

}
bool GameClass::CheckForWin() {
  int ACounter = 0;
  int BCounter = 0;

  //Check for vertical win
  for (int i = 0; i < m_size; i++) {
    for (int j = 0; j < m_size; j++) {
      if (m_area_vector[i][j] == 'X') {
        ACounter++;
        BCounter = 0;
      }
      else if (m_area_vector[i][j] == 'O') {
        BCounter++;
        ACounter = 0;
      }
      else { ACounter = 0; BCounter = 0; }
      if (ACounter >= 3) {
        Gotoxy(0, 0);
        std::cout << "Player A wins";
        return false;
      }
      if (BCounter >= 3) {
        Gotoxy(0, 0);
        std::cout << "Player B wins";
        return false;
      }
    }
    ACounter = 0;
    BCounter = 0;

  }
  // Check for horizontal win
  for (int i = 0; i < m_size; i++) {
    for (int j = 0; j < m_size; j++) {
      if (m_area_vector[j][i] == 'X') {
        ACounter++;
        BCounter = 0;
      }
      else if (m_area_vector[j][i] == 'O') {
        BCounter++;
        ACounter = 0;
      }
      else { ACounter = 0; BCounter = 0; }

      if (ACounter >= 3) {
        Gotoxy(0, 0);
        std::cout << "Player A wins";
        return false;
      }
      if (BCounter >= 3) {
        Gotoxy(0, 0);
        std::cout << "Player B wins";
        return false;
      }
    }
    ACounter = 0;
    BCounter = 0;
  }

  // Check for down-diagonal win
  for (int i = 0; i < m_size; i++) {
    if (m_area_vector[i][i] == 'X') {
      ACounter++;
      BCounter = 0;
    }
    else if (m_area_vector[i][i] == 'O') {
      ACounter = 0;
      BCounter++;
    }
    else { ACounter = 0; BCounter = 0; }
    if (ACounter >= 3) {
      Gotoxy(0, 0);
      std::cout << "Player A wins";
      return false;
    }
    if (BCounter >= 3) {
      Gotoxy(0, 0);
      std::cout << "Player B wins";
      return false;
    }
  }
  ACounter = 0;
  BCounter = 0;

  // Check for up-diagonal win
  for (int i = 0; i < m_size; i++) {
    if (m_area_vector[m_size - i - 1][i] == 'X') {
      ACounter++;
      BCounter = 0;
    }
    else if (m_area_vector[m_size - i - 1][i] == 'O') {
      ACounter = 0;
      BCounter++;
    }
    else { ACounter = 0; BCounter = 0; }
    if (ACounter == 3) {
      Gotoxy(0, 0);
      std::cout << "Player A wins";
      return false;
    }
    if (BCounter == 3) {
      Gotoxy(0, 0);
      std::cout << "Player B wins";
      return false;
    }

  }

  // Check is there free spaces left on table
  for (int i = 0; i < m_size; i++) {
    for (int j = 0; j < m_size; j++)
      if (m_area_vector[i][j] == '_') {
        // We found free space, so nothing more to do here
        return true;
      }
  }
  // We didn't find free space, so nobody won.
  Gotoxy(0, 0);
  std::cout << "It was a tie!";
  return false;

}

void GameClass::Move(int column, int line) {
  if (column < m_size * 4 && line < m_size * 4) {
    m_coord.X = column;
    m_coord.Y = line;
    SetConsoleCursorPosition(
      GetStdHandle(STD_OUTPUT_HANDLE),
      m_coord
    );
  }
}
void GameClass::Gotoxy(int column, int line) {
  m_coord.X = column;
  m_coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle(STD_OUTPUT_HANDLE),
    m_coord
  );
}

void GameClass::GetAreaSize() {
  std::cout << "Enter Area size";
  std::cin >> m_size;
  std::cout << "Area size will be " << m_size << "\n";
}

void GameClass::SetAreaSize(int i) {
  m_size = i;
}

void GameClass::InitializeArea() {
  int columnCounter = 0, rowCounter = 0;
  bool isLineRow = false;
  Gotoxy(0, 0);
  system("cls");

  std::cout << "Player A turn" << std::endl;

  for (int i = 0; i < m_size * 4 - 1; i++) {
    rowCounter++;
    if (rowCounter % 4 == 0) isLineRow = true;
    else isLineRow = false;
    for (int j = 0; j < m_size * 4 - 1; j++) {
      columnCounter++;
      if (!isLineRow) {
        if (columnCounter % 4 != 0) std::cout << " ";
        else std::cout << "|";
      }
      else {
        if (columnCounter % 4 != 0) std::cout << "-";
        else std::cout << "+";
      }
    }

    columnCounter++;
    std::cout << std::endl;
  }

  //Initialize AreaVector
  if (m_area_vector.empty()) {
    for (int i = 0; i <= m_size; i++) {
      std::vector<char> row;
      for (int j = 0; j <= m_size; j++) {
        row.push_back('_');
      }
      m_area_vector.push_back(row);
    }
  }
  else {
    for (int i = 0; i < m_size; i++) {
      for (int j = 0; j < m_size; j++) {
        m_area_vector[i][j] = '_';
      }
    }
  }
  // Reinitialize booleans
  InitializeBooleans();
}

void GameClass::InitializeBooleans() {
  m_isPlayerA = true; m_isGameOn = true; m_playerAWon = false; m_playerBWon = false;

}

COORD GameClass::GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
  CONSOLE_SCREEN_BUFFER_INFO cbsi;
  if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
  {
    return cbsi.dwCursorPosition;
  }
  else
  {
    // The function failed. Call GetLastError() for details.
    COORD invalid = { 0, 0 };
    return invalid;
  }
}