#include "./std.hh"
#include <string>

extern "C" void print(std::string v) { printf("%s", v.c_str()); }
