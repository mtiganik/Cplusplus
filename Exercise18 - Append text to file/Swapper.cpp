/// FILE NAME: Swapper.cpp
/// PROJECT: Exercise18
/// AUTHOR: Mihkel Tiganik
/// CREATED: 22.06.2018
///
/// DESCRIPTION:  Definitions for class Swapper

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Swapper.h"

Swapper::Swapper()
{
}


Swapper::~Swapper()
{
}


void Swapper::CopyContext()
{
  std::vector<std::string> Arr;
  std::string line;
  std::ifstream file;
  file.open(m_inputFile);
  if (!file) {
    std::cerr << "Error: could not open file " << m_inputFile << std::endl;
    abort();
  }
  while (getline(file, line)) {
    Arr.push_back(line);
  }
  file.close();
  std::ofstream file2;
  file2.open(m_outputFile);
  if (!file2) {
    std::cerr << "Error: could not open file " << m_outputFile << std::endl;
    abort();
  }
  for (int i = 0; i < Arr.size(); i++) {
    file2 << Arr[i] << std::endl;
  }
  file2.close();

}


void Swapper::GetInput()
{
  std::cout << "Enter source index:" << std::endl;
  std::cin >> m_sourceIndex;
  std::cout << "Enter length of characters to be copied:" << std::endl;
  std::cin >> m_length;
  std::cout << "Enter destination index: " << std::endl;
  std::cin >> m_destinationIndex;

}

void Swapper::GetInput(int sourceIndex, int length, int destinationIndex)
{
  m_sourceIndex = sourceIndex;
  m_length = length;
  m_destinationIndex = destinationIndex;

}

void Swapper::SetInputFile(std::string input)
{
  m_inputFile = input;
}

void Swapper::SetOutputFile(std::string output)
{
  m_outputFile = output;
}

void Swapper::DisplayOutput()
{
  CopyContext(); // copies context from input file to output
  std::string copyString;
  std::string fileContent, line;
  std::ifstream ifile;
  ifile.open(m_outputFile, std::ios::app | std::ios::in);
  while (getline(ifile, line)) {
    fileContent += line;
    fileContent += "\n";
  }
  ifile.close();

  copyString = fileContent.substr(m_sourceIndex, m_length);
  fileContent.insert(m_destinationIndex, copyString);

  std::ofstream ofile;
  ofile.open(m_outputFile);
  ofile << fileContent;
  ofile.close();

  std::ifstream ifile2;
  ifile2.open(m_outputFile);
  while (getline(ifile2, line)) {
    std::cout << line << std::endl;
  }

}
