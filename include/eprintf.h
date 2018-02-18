#ifndef INCG_AP_EPRINTF_H
#define INCG_AP_EPRINTF_H

/*!
 * \brief Prints in a printf-style manner to stderr.
 * \param fmt The printf-style format string.
 * \return The number of characters written if successful 
 *         or negative value if an error occurred.
**/
int ap_eprintf(const char *fmt, ...);

#endif // INCG_AP_EPRINTF_H

