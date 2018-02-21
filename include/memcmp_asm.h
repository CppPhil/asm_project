#ifndef INCG_AP_MEMCMP_ASM_H
#define INCG_AP_MEMCMP_ASM_H
#include <stdint.h> // int32_t, uint64_t

/*!
 * \brief Compares the first count characters of the objects pointed to by 'lhs' and 'rhs'. 
 *        The comparison is done lexicographically.
 *        The sign of the result is the sign of the difference between the values of the 
 *        first pair of bytes (both interpreted as unsigned char) that differ in the objects 
 *        being compared.
 * \param lhs Pointer to the left hand side object to compare 
 * \param rhs Pointer to the right hand side object to compare
 * \param count number of bytes to examine 
 * \return Negative value if 'lhs' appears before 'rhs' in lexicographical order.
 *         Zero if 'lhs' and 'rhs' compare equal, or if 'count' is zero.
 *         Positive value if 'lhs' appears after 'rhs' in lexicographical order. 
 * \warning The behavior is undefined if access occurs beyond the end of either 
 *          object pointed to by 'lhs' and 'rhs'. The behavior is undefined if either
 *          'lhs' or 'rhs' is a null pointer. 
**/
int32_t memcmp_asm(const void *lhs, const void *rhs, uint64_t count);

#endif // INCG_AP_MEMCMP_ASM_H
