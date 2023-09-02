#include "../headers/parser.hh"
#include "globals.cpp"
#include <cctype>
#include <cstdint>

using namespace std;

bool is_alpha(char c) { return std::isalpha(c) || c == '_'; }

void parse_code(string &code, Nodes &nodes) {
  std::string stack;

  for (size_t x = 0; x < code.length(); x++) {
    char current = code[x];
    char next = code[x + 1];

    if (current == SEMICOLON_STRING) {
      continue;
    }

    if (is_alpha(current)) {
      if (next == LEFT_PAREN_CHAR) {
        // Calling Function

        break;
      }

      stack.push_back(current);
    }
  }
}

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
