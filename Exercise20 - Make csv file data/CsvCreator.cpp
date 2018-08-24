/// FILE NAME: CsvCreator.cpp
/// PROJECT: Exercise20
/// AUTHOR: Mihkel Tiganik
/// CREATED: 14.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Definitions of CsvCreator methods

#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include "CsvCreator.h"


CsvCreator::CsvCreator()
{
}


CsvCreator::~CsvCreator()
{
}


void CsvCreator::SplitContextToVector()
{
  //remove whitespaces or "" marks from begginning
  m_context.erase(m_context.begin(), find_if(m_context.begin(),m_context.end(), [](int ch) {
    return !isspace(ch) || ch == '"';
  }));

  //remove whitespaces or "" marks from end
  m_context.erase(m_context.find_last_not_of("\" ") + 1);


  int counter = 0;
  std::vector<std::string> Column;

  for (unsigned int i = 0; i < m_context.length(); i++) {

    if (m_context[i] == '"') {
      counter = 0;
      do {
        i++;
        counter++;
      } while (m_context[i] != '"');
      Column.push_back(m_context.substr(i - counter, counter + 1));
      counter = 0;
      continue;
    }
    if (m_context[i] == ',') {
      Column.push_back(m_context.substr(i - counter, counter));
      counter = 0;
    }
    else if (m_context[i] == ';') {
      Column.push_back(m_context.substr(i - counter, counter));
      m_arr.push_back(Column);
      counter = 0;
      Column.clear();
    }
    else {
      counter++;
    }
  }
  std::cout << std::endl;

}


void CsvCreator::GetUserInput()
{
  char fileName[40];
  std::cout << "Enter new csv file name, with no csv prefix" << std::endl;
  std::cin.getline(fileName, sizeof(fileName), '\n');
  m_fileName = fileName;
  std::cout << "Enter context to file:" << std::endl;;
  std::cin.ignore(); //cin.ignore to clear buffer from other newlines
  std::cin.getline(m_charArr, sizeof(m_charArr), '\n');
  m_context = m_charArr;

}

void CsvCreator::WriteToFile()
{
  SplitContextToVector();

  std::ofstream fs;
  fs.open(m_fileName + ".csv");
  if (!fs) {
    std::cout << "Error, could not find file";
    abort();
  }
  for (unsigned int i = 0; i < m_arr.size(); i++) {
    for (unsigned int j = 0; j < m_arr[i].size(); j++) {

      // trim whitespaces from all new cells
      m_arr[i][j].erase(m_arr[i][j].begin(), std::find_if(m_arr[i][j].begin(), m_arr[i][j].end(), [](int ch) {
        return !isspace(ch);
      }));

      m_arr[i][j].erase(m_arr[i][j].find_last_not_of(" ") + 1);

      fs << m_arr[i][j];
      fs << ';';
    }
    fs << '\n';
  }

  fs.close();

  std::cout << "Check new file " << m_fileName << ".csv" << std::endl << "That was created to this project folder" << std::endl;

}
