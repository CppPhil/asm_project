CC      := gcc-5
AS      := as

CFLAGS  := -std=c99 -m64 -Wall
ASFLAGS := -march=generic64

all: main.o eprintf.o tests.o memchr_asm.o memset_asm.o
	$(CC) $(CFLAGS) -o application main.o eprintf.o tests.o memchr_asm.o memset_asm.o
main.o: ./src/main.c
	$(CC) $(CFLAGS) -c ./src/main.c
eprintf.o: ./src/eprintf.c
	$(CC) $(CFLAGS) -c ./src/eprintf.c
tests.o: ./src/tests.c
	$(CC) $(CFLAGS) -c ./src/tests.c	
memchr_asm.o: ./src/memchr_asm.s
	$(AS) $(ASFLAGS) ./src/memchr_asm.s -o memchr_asm.o
memset_asm.o: ./src/memset_asm.s
	$(AS) $(ASFLAGS) ./src/memset_asm.s -o memset_asm.o

.PHONY: clean
clean: 
	-rm ./*.o
	-rm ./application
.PHONY: rebuild

rebuild: clean all