#include "../include/unused.h" // AP_UNUSED
#include "../include/boolalpha.h" // AP_BOOLALPHA
#include "../include/tests.h" // ap_run_all_tests
#include <stdbool.h> // bool
#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h> // printf

int main(int argc, char *argv[])
{
    AP_UNUSED(argc);
    AP_UNUSED(argv);
    
    const bool ret_val = ap_run_all_tests();
    
    printf("Test run result: %s\n", AP_BOOLALPHA(ret_val));

    return EXIT_SUCCESS;
}
