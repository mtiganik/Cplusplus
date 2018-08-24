/// FILE NAME: main.cpp
/// PROJECT: Exercise12
/// AUTHOR: Mihkel Tiganik
/// CREATED: 14.06.2018
/// MODIFIED: 21.06.2018
///
/// DESCRIPTION: Program suggest to play Tic Tac Toe Game. A field
///  for 3x3 Game should be drawn. User can control location for
///  insertion by arrows. Program should write a correct win message,
///  if one player would collect 3 symbols in line
///          |       |
///          |       |
///          |       |
///    - - - + - - - + - - -
///          |       |
///      X   |   O   |
///          |       |
///    - - - + - - - + - - -
///          |       |
///          |       |
///          |       |

#include "GameClass.h"

int main()
{
  GameClass game;
  game.StartGame();

  return 0;
}
