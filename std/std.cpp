#include "./std.hh"
#include <string>

std::string print_asm() {
  return R"(
print:
mov rdi, 1
mov rax, 1
syscall
ret
)";
}
