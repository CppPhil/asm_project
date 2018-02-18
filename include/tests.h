#ifndef INCG_AP_TESTS_H
#define INCG_AP_TESTS_H
#include "stringify.h" // AP_STRINGIFY
#include <stdbool.h> // bool
#include <stddef.h> // NULL

/*!
 * \brief Struct used for the result of a test.
 * 
 * If failure_expression != NULL the test failed,
 * if the test failed failure_expression
 * will contain the text of the expression that was tested
 * and evaluated to false.
 * test_fun will contain the text of the identifier of the
 * associated test function.
 * line will be the line of the assertion.
**/
struct ap_test_result
{
    const char *failure_expression; /*!< The expression that made the test fail.
                                     *   NULL if the test was successful.
                                    **/
    const char *test_fun; /*!< the test function that this is the result of. */
    const char *line; /*!< The line of the assertion */
};

/*!
 * \def AP_TEST_ASSERT(test)
 * \brief macro that will test the expression passed in. To be used in test functions.
**/
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

/*!
 * \def AP_TEST_RUN(test)
 * \brief runs a test function; to be used in the function that will run all the tests.
**/
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

/*!
 * \def AP_TEST_CASE(identifier)
 * \brief macro to introduce a test case. 
 *        will declare a function called "identifier"
 *        place AP_TEST_ASSERT statements within the test case.
 *        A test case must end with AP_TEST_CASE_END
**/
#define AP_TEST_CASE(identifier) \
    static struct ap_test_result \
    identifier(void) \
    { \

/*!
 * \def AP_TEST_CASE_END
 * \brief the end of a test case
**/
#define AP_TEST_CASE_END \
    struct ap_test_result test_result_thing = { NULL, NULL, NULL }; \
    return test_result_thing; \
}

extern int ap_tests_run;

/*!
 * \brief function to be called from main to run the tests.
 *        will be the entry point for the test running stuff.
 * \return true if all tests were run successfully, false otherwise.
**/
bool ap_run_all_tests(void);

#endif // INCG_AP_TESTS_H
