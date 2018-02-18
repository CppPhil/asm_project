#include <stdio.h>
#include <stdlib.h>
#include "../include/memchr_asm.h"

int main(void)
{
    char a[] = "text";
    
    const char *p = (const char *)memchr_asm(a, 'x', sizeof(a));
    if (p != NULL) {
        printf("%c\n", *p);
    }

    return EXIT_SUCCESS;
}

