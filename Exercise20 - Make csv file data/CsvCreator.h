/// FILE NAME: CsvCreator.h
/// PROJECT: Exercise20
/// AUTHOR: Mihkel Tiganik
/// CREATED: 14.06.2018
/// MODIFIED 22.06.2018
///
/// DESCRIPTION:  Header file for CsvCreator

#ifndef EXERCISE20_CSVCREATOR_
#define EXERCISE20_CSVCREATOR_

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

class CsvCreator
{
  std::string m_fileName = "Example";
  char m_charArr[1000];
  std::string m_context;
  void SplitContextToVector();
  std::vector< std::vector<std::string> > m_arr;

  // trim from start (in place)
  static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
      return !isspace(ch) || ch == '"';
    }));
  }

  // trim from end (in place)
  static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
      return !isspace(ch) || ch == '"';
    }).base(), s.end());
  }
  // trim from both ends (in place)
  static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
  }

public:
  CsvCreator();
  ~CsvCreator();
  void GetUserInput();
  void WriteToFile();

};

#endif // !EXERCISE20_CSVCREATOR_