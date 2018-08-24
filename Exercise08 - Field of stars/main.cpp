/// FILE NAME: main.cpp
/// PROJECT: Exercise08
/// AUTHOR: Mihkel Tiganik
/// CREATED: 11.06.2018
/// MODIFIED: 21.06.2018
///
/// DESCRIPTION: Create a field of stars in console. Field size is 50*30
///  chars. Number of stars varies between 50 and 150.
///  Example:
///          *       *   **  
///         *       *     **    *
///     * *     * *   *     *     *
///           *                 *
///       *       *         *       *
///     *     *                   
///                 *     *     *   *
///       *   *   *       **      *

#include <iostream>
#include <time.h> 

#include "functions08.h"

int main()
{
  int NumberOfStarts;

  // initialize random seed
  srand(time(NULL));

  // generate random number between 150 and 50
  NumberOfStarts = rand() % 100 + 50;

  FieldOfStars(NumberOfStarts);

  std::system("pause");
  return 0;
}


