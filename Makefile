all: asm_test.o main.o
	gcc -std=c99 -m64 -o application asm_test.o main.o
main.o: ./src/main.c
	gcc -std=c99 -m64 -c ./src/main.c
asm_test.o: ./src/asm_test.s
	as -march=generic64 ./src/asm_test.s -o asm_test.o
clean: 
	rm application
	rm ./*.o
rebuild: clean all
