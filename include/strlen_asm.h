#ifndef INCG_AP_STRLEN_ASM_H
#define INCG_AP_STRLEN_ASM_H
#include <stdint.h> // uint64_t

/*!
 * \brief Returns the length of the given null-terminated byte string, 
 *        that is, the number of characters in a character array whose 
 *        first element is pointed to by 'str' up to and not including 
 *        the first null character.
 * \param str pointer to the null-terminated byte string to be examined 
 * \return The length of the null-terminated byte string 'str'.
 * \warning The behavior is undefined if 'str' is not a pointer to a 
 *          null-terminated byte string.
**/
uint64_t strlen_asm(const char *str);

#endif // INCG_AP_STRLEN_ASM_H
