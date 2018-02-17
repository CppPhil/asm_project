#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include "../include/memchr_asm.h"

int32_t multiply_x64(int32_t a, int32_t b);

int main(void)
{
    const int32_t res = multiply_x64(INT32_C(5), INT32_C(3));
    printf("%" PRId32 "\n", res);
    
    char a[] = "text";
    
    const char *p = (const char *)memchr_asm(a, 'x', sizeof(a));
    if (p != NULL) {
        printf("%c\n", *p);
    }

    return EXIT_SUCCESS;
}

