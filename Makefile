CC      := gcc-5
AS      := as

CFLAGS  := -std=c99 -m64 -Werror -Wall -Wextra -Wlogical-op -Wjump-misses-init -Wshadow -Wformat=2
ASFLAGS := -march=generic64

all: main.o eprintf.o tests.o memchr_asm.o memset_asm.o memcpy_asm.o strlen_asm.o memfrob_asm.o memcmp_asm.o
	$(CC) $(CFLAGS) -o application main.o eprintf.o tests.o memchr_asm.o memset_asm.o memcpy_asm.o strlen_asm.o memfrob_asm.o memcmp_asm.o
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
memcpy_asm.o: ./src/memcpy_asm.s
	$(AS) $(ASFLAGS) ./src/memcpy_asm.s -o memcpy_asm.o
strlen_asm.o: ./src/strlen_asm.s
	$(AS) $(ASFLAGS) ./src/strlen_asm.s -o strlen_asm.o
memfrob_asm.o: ./src/memfrob_asm.s
	$(AS) $(ASFLAGS) ./src/memfrob_asm.s -o memfrob_asm.o
memcmp_asm.o: ./src/memcmp_asm.s
	$(AS) $(ASFLAGS) ./src/memcmp_asm.s -o memcmp_asm.o

.PHONY: clean
clean: 
	-rm ./*.o
	-rm ./application

.PHONY: rebuild
rebuild: clean all
