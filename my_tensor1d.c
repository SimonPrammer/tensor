#include "test_framework.h"

// ----------------------------------------------------------------------
// utils

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int ceil_div(int a, int b)
{
    // integer division that rounds up...ceil
    return (a + b - 1) / b;
}

// ----------------------------------------------------------------------
// memory allocation

// Test function for the add function
int run_tests()
{
    ASSERT_TRUE(min(2, 3) == 2);
    ASSERT_TRUE(max(-1, 1) == 1);
    ASSERT_TRUE(ceil_div(3, 2) == 2);
    ASSERT_TRUE(ceil_div(6, 2) == 3);
    ASSERT_TRUE(ceil_div(3, 6) == 1);
    return 1; // Return 1 if all assertions pass
}

// ----------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    RUN_TEST(run_tests);

    return 0;
}