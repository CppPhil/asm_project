all: main.o memchr_asm.o
	gcc -std=c99 -m64 -o application memchr_asm.o main.o
main.o: ./src/main.c
	gcc -std=c99 -m64 -c ./src/main.c
memchr_asm.o: ./src/memchr_asm.s
	as -march=generic64 ./src/memchr_asm.s -o memchr_asm.o
clean: 
	rm ./*.o
	rm ./application
rebuild: clean all
