/// FILE NAME: Swapper.h
/// PROJECT: Exercise18
/// AUTHOR: Mihkel Tiganik
/// CREATED: 14.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Header file for Swapper

#ifndef EXERCISE18_SWAPPER_
#define EXERCISE18_SWAPPER_

#include <iostream>

class Swapper
{
  int m_sourceIndex = 0, m_length = 0, m_destinationIndex = 0;
  std::string m_inputFile;
  std::string m_outputFile;

  void CopyContext();
public:
  Swapper();
  ~Swapper();

  void GetInput();
  void GetInput(int sourceIndex, int length, int destinationIndex);
  void SetInputFile(std::string input);
  void SetOutputFile(std::string output);
  void DisplayOutput();

};

#endif // !EXERCISE18_SWAPPER_
