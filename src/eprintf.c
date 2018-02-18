#include "../include/eprintf.h"
#include <stdarg.h> // va_list, va_start, va_end
#include <stdio.h> // vfprintf

int ap_eprintf(const char *fmt, ...)
{
    va_list arg;
    
    va_start(arg, fmt);
    const int ret_val = vfprintf(stderr, fmt, arg);
    va_end(arg);
    
    return ret_val;
}

