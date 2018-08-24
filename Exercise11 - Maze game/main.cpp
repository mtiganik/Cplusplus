/// FILE NAME: main.cpp
/// PROJECT: Exercise11
/// AUTHOR: Mihkel Tiganik
/// CREATED: 13.06.2018
/// MODIFIED: 21.06.2018
///
/// DESCRIPTION: After program start, a field 20x20 should be displayed 
///  in the console. Where 'G' is a player, '.' is a empty cell, 'T' is 
///  a obstacle and 'X' is a exit. All obstacles are generated randomly
///  and their total number is 50. On the field there can be only one 
///  exit and its position is also generated randomly. User can control
///  a player ('G') with arrows on keyboard. If player enters a exit, then
///  he wins. If player enters obstacle, then loose.
///  Example of field:
///   .T...T..T..T.....T...
///   ..................G..
///   ...T.....TT.....T...T
///   T......T....TT....T.T
///   ...TT...TT.....T.T...
///   TT...TT...T.T.T.T...T
///   ..T..T...T...T....T..
///   T..TT....T...XT....T.
///   TT...T...T...T...T.TT

#include <iostream>

#include"functions11.h"

int main()
{
  initializeArea();
  game();

  std::system("pause");
  return 0;
}

