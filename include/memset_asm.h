#ifndef INCG_AP_MEMSET_ASM_H
#define INCG_AP_MEMSET_ASM_H
#include <stdint.h> // int32_t, uint64_t

/*!
 * \brief Copies the value 'ch' (after conversion to unsigned char as if by (unsigned char)ch) 
 *        into each of the first 'count' characters of the object pointed to by 'dest'.
 * \param dest pointer to the object to fill
 * \param ch fill byte
 * \param count number of bytes to fill
 * \return a copy of 'dest'.
 * \warning The behavior is undefined if access occurs beyond the end of the 'dest' array. 
 *          The behavior is undefined if 'dest' is a null pointer.
**/
void *memset_asm(void *dest, int32_t ch, uint64_t count);

#endif // INCG_AP_MEMSET_ASM_H
