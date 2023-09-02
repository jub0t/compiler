#include "../headers/utils.hh"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

std::string randstr(int length) {
  const std::string charset =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  const int charsetLength = charset.length();
  std::string randomString;

  srand(static_cast<unsigned int>(time(nullptr)));

  for (int i = 0; i < length; ++i) {
    int randomIndex = rand() % charsetLength;
    randomString += charset[randomIndex];
  }

  return randomString;
}
