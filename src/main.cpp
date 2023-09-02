#include "../headers/parser.hh"
#include "assemble.cpp"
#include "utils.cpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cout << "Usage: " << argv[0] << " <input_file> <outout_path>"
              << std::endl;
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

    ofstream outfile;
    outfile.open("./build/temp.s");

    if (outfile.is_open()) {
      outfile << assembly;
      outfile.close();
    }

    const char *out_bin = argv[2];
    const char *build_cmd = "nasm -f elf64 ./build/temp.s -o ./build/temp.o";

    int result = std::system(build_cmd);
    if (result == 0) {
      cout << "Obejct File Created";
    } else {
      cout << "Object File Creation Failed!";
    }

    std::string comp_cmd = ("ld ./build/temp.o -o " + std::string(out_bin));
    int compres = std::system(comp_cmd.c_str());
    if (compres == 0) {
      cout << "Successfully Compiled Binary";
    }

  } else {
    std::cerr << "Unable to open the file: " << file_name << std::endl;
    return 1;
  }

  return 0;
}
