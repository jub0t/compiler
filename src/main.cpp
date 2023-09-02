#include "../headers/parser.hh"
#include "assemble.cpp"
#include "utils.cpp"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }

  const std::string file_name = argv[1];
  std::ifstream file(file_name);
  std::string code;

  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      code += line + "\n";
    }

    std::cout << "File Contents:\n" << code;

    Nodes nodes;

    Literals literals;
    Literal liter;
    liter.value = std::string("Greetings!");
    liter.type = Type::String;
    liter.key = randstr(4);

    Node node;
    node.ins = Keyword::PRINT;
    node.args.push_back(liter); // Push the literal into the args vector
    nodes.push_back(node);

    std::string assembly = assemble_nodes(nodes);
    std::cout << "\nGenerated Assembly:\n" << assembly;
  } else {
    std::cerr << "Unable to open the file: " << file_name << std::endl;
    return 1;
  }

  return 0;
}
