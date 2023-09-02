Main: ./src/main.asm
	g++ ./src/compiler.cpp -o ./build/compiler
	nasm ./test/main.s -f elf64 -o ./build/main.o
	ld ./build/main.o -o ./build/main -O2
	rm ./build/main.o
