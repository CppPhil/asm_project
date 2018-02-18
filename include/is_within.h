#ifndef INCG_AP_IS_WITHIN_H
#define INCG_AP_IS_WITHIN_H

/*!
 * \def AP_IS_WITHIN(v, lower_bound, upper_bound)
 * \brief Expands to true if the expression 'v' is within the bounds delimited by
 *        'lower_bound' and 'upper_bound', otherwise expands to false.
**/
#define AP_IS_WITHIN(v, lower_bound, upper_bound) \
    (((v) >= (lower_bound)) && ((v) <= (upper_bound)))

#endif // INCG_AP_IS_WITHIN_H

