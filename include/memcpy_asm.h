#ifndef INCG_AP_MEMCPY_ASM_H
#define INCG_AP_MEMCPY_ASM_H
#include <stdint.h> // uint64_t

void *memcpy_asm(
    void * restrict dest, 
    const void * restrict src, 
    uint64_t count);
#endif // INCG_AP_MEMCPY_ASM_H
