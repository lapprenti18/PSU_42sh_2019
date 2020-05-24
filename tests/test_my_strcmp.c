#include <criterion/criterion.h>

int my_strcmp(const char *s1, const char *s2);

Test(my_strcmp, should_return_minus_1)
{
    char s1 = "azerty";
    char s2 = "azertyuiop";
    int i = my_strcmp(s1, s2);
    cr_assert_lt(i, 0, "wrong value %d", i);
}

Test(my_strcmp, should_return_0)
{
    char s1[] = "azerty";
    char s2[] = "azerty";
    int i = my_strcmp(s1, s2);
    cr_assert_eq(i, 0);
}

Test(my_strcmp, should_return_1)
{
    char s1 = "azertyuiop";
    char s2 = "azerty";
    int i = my_strcmp(s1, s2);
    cr_assert_gt(i, 0);
}