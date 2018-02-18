#ifndef INCG_AP_COUNT_OF_H
#define INCG_AP_COUNT_OF_H

/*!
 * \def AP_COUNT_OF(ary)
 * \brief Expands to the count of elements of the array 'ary'.
 * \note Do not use on pointers. In particular be aware of array to pointer decay.
**/
#define AP_COUNT_OF(ary) (sizeof((ary)) / sizeof(*(ary)))

#endif // INCG_AP_COUNT_OF_H

