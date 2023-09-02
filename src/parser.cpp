#include "parser.hh"
#include "globals.cpp"
#include <cstdint>

using namespace std;

void parse_code(string &code, Nodes &nodes) {}

void get_paren_indexes(ParenIndexes &indexes, std::string code) {
  for (size_t x = 0; x < code.length(); x++) {
    char currentChar = code[x];

    if (currentChar == LEFT_PAREN_CHAR) {
      indexes.push_back({x, ParenType::LEFT_PAREN});
    } else if (currentChar == RIGHT_PAREN_CHAR) {
      indexes.push_back({x, ParenType::RIGHT_PAREN});
    }
  }
}
