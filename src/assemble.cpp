#include "../headers/assemble.hh"
#include "../headers/parser.hh"
#include "../headers/utils.hh"
#include <cstdio>
#include <cstring>
#include <string>

std::string assemble_nodes(Nodes &nodes) {
  std::string data;
  std::string text;

  for (size_t i = 0; i < nodes.size(); i++) {
    auto node = nodes[i];
    char dline[128];
    char tline[128];

    switch (node.ins) {
    case Keyword::PRINT: {
      PolyVal value = node.args.at(0).value;
      std::string strval = std::get<std::string>(value);
      std::string varname = randstr(4);

      sprintf(dline, "%s: db \"%s\"\n", varname.c_str(), strval.c_str());
      data += dline; // Append the formatted line to the 'data' string

      sprintf(tline, "mov rdi, %s\nmov rdx, %ld\ncall print", varname.c_str(),
              strlen(strval.c_str()));
      text += tline; // Append the formatted line to the 'data' string

      break; // Don't forget to break
    }

    case Keyword::DEFINE: {
      // Handle DEFINE case here
      break; // Don't forget to break
    }
    }
  }

  return "section .data\n" + data + "\n\nsection .text\n" + text;
}
