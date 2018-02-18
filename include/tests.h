#ifndef INCG_AP_TESTS_H
#define INCG_AP_TESTS_H
#include "stringify.h" // AP_STRINGIFY
#include <stdbool.h> // bool
#include <stddef.h> // NULL

struct ap_test_result
{
    const char *failure_expression;
    const char *test_fun;
    const char *line;
};

#define AP_TEST_ASSERT(test) \
    do \
    { \
        struct ap_test_result ret = { NULL, NULL, NULL }; \
        ret.test_fun = __FUNCTION__; \
        ret.line = AP_STRINGIFY(__LINE__); \
        if (!(test)) \
        { \
            ret.failure_expression = AP_STRINGIFY(test); \
            return ret; \
        } \
    } while ((void)0, 0) 

#define AP_TEST_RUN(test) \
    do \
    { \
        struct ap_test_result ret = test(); \
        ++ap_tests_run; \
        if (ret.failure_expression != NULL) \
        { \
            return ret; \
        } \
    } while ((void)0, 0)

#define AP_TEST_CASE(identifier) \
    static struct ap_test_result \
    identifier(void) \
    { \

#define AP_TEST_CASE_END \
    struct ap_test_result test_result_thing = { NULL, NULL, NULL }; \
    return test_result_thing; \
}

extern int ap_tests_run;

bool ap_run_all_tests(void);

#endif // INCG_AP_TESTS_H

