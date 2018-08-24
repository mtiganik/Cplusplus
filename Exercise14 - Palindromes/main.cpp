/// FILE NAME: main.cpp
/// PROJECT: Exercise14
/// AUTHOR: Mihkel Tiganik
/// CREATED: 14.06.2018
/// MODIFIED: 21.06.2018
///
/// DESCRIPTION:  Program asks user to enter a string.
///  After that it will display whether this string 
///  is palindrome or not

#include <iostream>
#include <vector>
#include <string>

#include "functions14.h"

int main(void)
{
  // some palindromes for testing
  std::vector<std::string> palindromes;
  palindromes.push_back("A but tuba");
  palindromes.push_back("A car, a man, a maraca");
  palindromes.push_back("A man, a plan, a canal: Panama");
  palindromes.push_back("This is not a palindrome");

  for (int i = 0; i < palindromes.size(); i++) {
  	if (IsPalindrome(palindromes[i])) {
      std::cout <<"Is palindrome \t"<< palindromes[i]  << std::endl;
  	}
  	else {
      std::cout<<"Not a palindrome \t" << palindromes[i]  << std::endl;
  	}
  }

  std::string _input = GetString();
  if (IsPalindrome(_input)) {
    std::cout << "This is a palindrome\n" << std::endl;
  }
  else {
    std::cout << "This is not a Palindrome\n" << std::endl;
  }

  std::system("pause");
  return 0;
}
