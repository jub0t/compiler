Main: ./src
	g++ ./src/main.cpp -o ./build/compiler
	g++ ./std/std.cpp -S -o ./build/std.s

	nasm ./test/main.s -f elf64 -o ./build/main.o
	gcc ./build/std.s -o ./build/std.o
	
	ld ./build/main.o -o ./build/main -O2

	rm ./build/main.o
