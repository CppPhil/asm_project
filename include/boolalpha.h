#ifndef INCG_AP_BOOLALPHA_H
#define INCG_AP_BOOLALPHA_H

#define AP_BOOLALPHA(boolean_expr) \
    (&"false\0true"[(!!(boolean_expr)) * 6U])

#endif // INCG_AP_BOOLALPHA_H

