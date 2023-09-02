#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream file("test.hz");

  if (file.is_open()) {
    string line;
    while (std::getline(file, line)) {
      cout << line;
    }
  } else {
    cout << "Unable to open file";
  }
}
