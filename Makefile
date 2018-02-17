all: asm_test.o main.o
	gcc -std=c99 -m64 -o application asm_test.o main.o
main.o: main.c
	gcc -std=c99 -m64 -c main.c
asm_test.o: asm_test.s
	as -march=generic64 asm_test.s -o asm_test.o
clean: 
	rm application
	rm ./*.o
rebuild: clean all
