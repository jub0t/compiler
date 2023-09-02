#ifndef PARSER
#define PARSER

#include <cstdint>
#include <string>
#include <variant>
#include <vector>

using PolyVal = std::variant<int, bool, std::string>;

enum Type {
  String,
  Int,
  Bool,
};

enum Keyword {
  PRINT,
  DEFINE,
};

enum ParenType {
  LEFT_PAREN,
  RIGHT_PAREN,
};

struct Literal {
  Type type;
  PolyVal value;
  std::string key;
};

using Literals = std::vector<Literal>;

struct Paren {
  ParenType type;
  uint8_t index;
};

template <typename T> using IndexVector = std::vector<T>;
using ParenIndexes = IndexVector<Paren>;

struct Node {
  Keyword ins;
  Literals args;
};

using Nodes = std::vector<Node>;

void parse_code(std::string &code, Nodes &nodes);
void get_paren_indexes(ParenIndexes indexes, std::string &code);

#endif
