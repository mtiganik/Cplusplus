/// FILE NAME: main.cpp
/// PROJECT: Exercise16
/// AUTHOR: Mihkel Tiganik
/// CREATED: 15.06.2018
/// MODIFIED: 22.06.2018
///
/// DESCRIPTION: Program gets a txt file as argument. After that
///  it will display a number of uppercase, lowercase, digits
///  and other characters

#include <iostream>
#include <fstream>
#include <string>

int main()
{
  std::string filename = "Exercise16.txt";
  int upperCase = 0, lowerCase = 0, digits = 0, notAlphaNum = 0, others = 0;
  std::ifstream fin(filename.c_str());
  if (!fin) {
    std::cerr << "Error. Could not open file for I/O" << std::endl;
    abort();
  }
  char ch;
  while (fin.get(ch)) {
    if (isupper(ch)) upperCase++;
    else if (islower(ch)) lowerCase++;
    else if (isdigit(ch)) digits++;
    else if (!isalnum(ch)) notAlphaNum++;
    else others++; // this other should be 0 in the end!
  }
  fin.close();

  std::cout << "from file: '" << filename << "' compiler found: " << std::endl;
  std::cout << upperCase << " uppercase letters, " << std::endl;
  std::cout << lowerCase << " lowercase letters, " << std::endl;
  std::cout << digits << " digits," << std::endl;
  std::cout << notAlphaNum << " other characters" << std::endl;
  std::cout << others << std::endl; // if last line is 0, then that is good!
  std::system("pause");
  return 0;
}
