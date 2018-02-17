#ifndef INCG_AP_MEMCHR_ASM_H
#define INCG_AP_MEMCHR_ASM_H
#include <stdint.h> // int32_t, uint64_t

void *memchr_asm(const void *ptr, int32_t ch, uint64_t count);

#endif // INCG_AP_MEMCHR_ASM_H

