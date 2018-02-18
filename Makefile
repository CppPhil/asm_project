all: main.o eprintf.o tests.o memchr_asm.o
	gcc -std=c99 -m64 -o application main.o eprintf.o tests.o memchr_asm.o
main.o: ./src/main.c
	gcc -std=c99 -m64 -c ./src/main.c
eprintf.o: ./src/eprintf.c
	gcc -std=c99 -m64 -c ./src/eprintf.c
tests.o: ./src/tests.c
	gcc -std=c99 -m64 -c ./src/tests.c	
memchr_asm.o: ./src/memchr_asm.s
	as -march=generic64 ./src/memchr_asm.s -o memchr_asm.o
clean: 
	rm ./*.o
	rm ./application
