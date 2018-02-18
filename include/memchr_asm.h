#ifndef INCG_AP_MEMCHR_ASM_H
#define INCG_AP_MEMCHR_ASM_H
#include <stdint.h> // int32_t, uint64_t

/*!
 * \brief Finds the first occurrence of 'ch' 
 *        (after conversion to unsigned char as if by (unsigned char)ch) 
 *        in the initial 'count' characters (each interpreted as unsigned char) 
 *        of the object pointed to by 'ptr'. 
 * \param ptr pointer to the object to be examined 
 * \param ch character to search for 
 * \param count maximum number of characters to examine 
 * \return Pointer to the location of the character, or NULL if no such character is found. 
 * \warning The behavior is undefined if access occurs beyond the end of the array searched. 
 *          The behavior is undefined if 'ptr' is a null pointer. 
**/
void *memchr_asm(const void *ptr, int32_t ch, uint64_t count);

#endif // INCG_AP_MEMCHR_ASM_H

