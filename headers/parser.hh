#ifndef PARSER
#define PARSER

#include <cstdint>
#include <string>
#include <variant>
#include <vector>

using PolyVal = std::variant<int, bool, std::string>;

enum ParenType {
  LEFT_PAREN,
  RIGHT_PAREN,
};

struct Paren {
  ParenType type;
  uint8_t index;
};

template <typename T> using IndexVector = std::vector<T>;
using ParenIndexes = IndexVector<Paren>;

enum Instruction {
  PRINT,
  DEFINE,
};

typedef struct Constant {
  std::string Key;
  PolyVal Value;
} Constant;

typedef struct Node {
  Instruction Ins;
  std::vector<Constant> Values;
} InsNode;

using Nodes = std::vector<Node>;

void parse_code(std::string &code, Nodes &nodes);
void get_paren_indexes(ParenIndexes indexes, std::string &code);

#endif
