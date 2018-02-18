#ifndef INCG_AP_BOOLALPHA_H
#define INCG_AP_BOOLALPHA_H

/*!
 * \def AP_BOOLALPHA(boolean_expr)
 * \brief Macro to turn a boolean expression into a "true"
 *        or "false" string.
**/
#define AP_BOOLALPHA(boolean_expr) \
    (&"false\0true"[(!!(boolean_expr)) * 6U])

#endif // INCG_AP_BOOLALPHA_H

