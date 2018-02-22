#ifndef INCG_AP_MEMCPY_ASM_H
#define INCG_AP_MEMCPY_ASM_H
#include <stdint.h> // uint64_t

/*!
 * \brief Copies count characters from the object pointed to by 'src' to 
 *        the object pointed to by 'dest'. Both objects are interpreted as 
 *        arrays of unsigned char.
 * \param dest pointer to the object to copy to 
 * \param src pointer to the object to copy from 
 * \param count number of bytes to copy
 * \return Returns a copy of dest
 * \warning The behavior is undefined if access occurs beyond the end 
 *          of the 'dest' array. If the objects overlap (which is a violation
 *          of the restrict contract), the behavior is undefined. 
 *          The behavior is undefined if either 'dest' or 'src' is a null pointer.
**/
void *memcpy_asm(
    void * restrict dest, 
    const void * restrict src, 
    uint64_t count);
#endif // INCG_AP_MEMCPY_ASM_H
