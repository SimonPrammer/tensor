#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdio.h>
#include <assert.h>

// Function to run a test
#define RUN_TEST(test_func) \
    do { \
        printf("Running %s...\n", #test_func); \
        if (test_func()) { \
            printf("\033[92m✅ %s passed\033[0m\n", #test_func); \
        } else { \
            printf("\033[91m❌ %s failed\033[0m\n", #test_func); \
        } \
    } while (0)

// Utility function to print an error message
#define ASSERT_TRUE(expr) \
    do { \
        if (!(expr)) { \
            printf("\033[91mAssertion failed: %s, function %s, file %s, line %d.\033[0m\n", \
                   #expr, __FUNCTION__, __FILE__, __LINE__); \
            return 0; \
        } \
    } while (0)

#endif // TEST_FRAMEWORK_H