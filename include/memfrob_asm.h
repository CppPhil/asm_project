#ifndef INCG_AP_MEMFROB_H
#define INCG_AP_MEMFROB_H
#include <stdint.h> // uint64_t

/*!
 * \brief The memfrob_asm() function encrypts the first 'n' bytes of 
 *        the memory area 's' by exclusive-ORing each character 
 *        with the number 42. The effect can be reversed by using
 *        memfrob_asm() on the encrypted memory area.
 * \param s Pointer to the memory area to frobnicate.
 * \param n The size of the memory area pointed to by 's' in bytes.
 * \return The memfrob_asm() function returns a pointer to the encrypted memory area. 
 * \note Note that this function is not a proper encryption routine 
 *       as the XOR constant is fixed, and is only suitable for hiding strings. 
**/
void *memfrob_asm(void *s, uint64_t n);
#endif // INCG_AP_MEMFROB_H
