Main: ./src
	nasm ./test/main.s -f elf64 -o ./build/main.o	
	ld ./build/main.o -o ./build/main -O2

	g++ ./src/main.cpp -o ./build/compiler
	rm ./build/main.o
