all: asm_test.o main.o memchr_asm.o
	gcc -std=c99 -m64 -o application asm_test.o memchr_asm.o main.o
main.o: ./src/main.c
	gcc -std=c99 -m64 -c ./src/main.c
asm_test.o: ./src/asm_test.s
	as -march=generic64 ./src/asm_test.s -o asm_test.o
memchr_asm.o: ./src/memchr_asm.s
	as -march=generic64 ./src/memchr_asm.s -o memchr_asm.o
clean: 
	rm ./*.o
	rm ./application
rebuild: clean all
