#ifndef INCG_AP_STRINGIFY_H
#define INCG_AP_STRINGIFY_H

/*!
 * \def AP_STRINGIFY_DETAIL(x)
 * \brief Implementation macro of 'AP_STRINGIFY(x)'.
 * \see AP_STRINGIFY(x)
**/
#define AP_STRINGIFY_DETAIL(x) #x

/*!
 * \def AP_STRINGIFY(x)
 * \brief Macro that turns a sequence of tokens 'x' into a string literal.
**/
#define AP_STRINGIFY(x) AP_STRINGIFY_DETAIL(x)

#endif // INCG_AP_STRINGIFY_H

