/// FILE NAME: main.cpp
/// PROJECT: Exercise08
/// AUTHOR: Mihkel Tiganik
/// CREATED: 11.06.2018
/// MODIFIED: 21.06.2018
///
/// DESCRIPTION: Program asks user to enter a integer. After that 
///   this integer would be draw with asterisks(*).
///   Example for integer 42:
///         *       * * *    
///       * *     *       *  
///     *   *             *  
///   *     *             *  
///   *     *           *    
///   * * * *         *      
///         *       *        
///         *     * * * * *  

#include <iostream>

#include "functions09.h"

int main()
{
  printInteger(getInteger());

  std::system("pause");
  return 0;
}


