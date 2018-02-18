#include "../include/tests.h"
#include "../include/count_of.h" // AP_COUNT_OF
#include "../include/eprintf.h" // ap_eprintf
#include "../include/memchr_asm.h" // memchr_asm
#include <stdbool.h> // bool
#include <stddef.h> // size_t, NULL

typedef struct ap_test_result (*ap_test_function)(void);

int ap_tests_run = 0;

AP_TEST_CASE(memchr_asm_test)
    const char ary[] = "Text";    
    const char *p = (const char *)memchr_asm(ary, 'x', sizeof(ary));
    AP_TEST_ASSERT(p != NULL);
    AP_TEST_ASSERT(*p == 'x');
    
    p = (const char *)memchr_asm(ary, '?', sizeof(ary));
    AP_TEST_ASSERT(p == NULL);
    
    const char ary2[] = "";
    p = (const char *)memchr_asm(ary2, ' ', sizeof(ary2));
    AP_TEST_ASSERT(p == NULL);
    
    p = (const char *)memchr_asm(ary2, '\0', sizeof(ary2));
    AP_TEST_ASSERT(p != NULL);
    AP_TEST_ASSERT(*p == '\0');   
AP_TEST_CASE_END

static ap_test_function test_functions[] = {
    &memchr_asm_test
};

static struct ap_test_result all_tests(void)
{
    for (size_t i = 0U; i < AP_COUNT_OF(test_functions); ++i) {
        AP_TEST_RUN(test_functions[i]);
    }

    struct ap_test_result return_value = { NULL, NULL };
    return return_value;
}

bool ap_run_all_tests(void)
{
    struct ap_test_result result = all_tests();
    
    if (result.failure_expression != NULL) {
        ap_eprintf(
            "!!!TEST FAILED!!! Test: \"%s\""
            " expression: \"%s\" was false\n"
            "line: %s\n",
            result.test_fun,
            result.failure_expression,
            result.line);
    } else {
        ap_eprintf("ALL TESTS PASSED\n");
    }
    
    ap_eprintf("Tests run: %d\n", ap_tests_run);
    
    return result.failure_expression == NULL;
}

