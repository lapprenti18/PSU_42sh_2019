#include <criterion/criterion.h>

int my_strncmp(const char *s1, const char *s2, int nb);

Test(my_strncmp, should_return_negative_value)
{
    char s1 = "azer";
    char s2 = "azerty";
    int nb = 5;
    int i = my_strncmp(s1, s2, nb);
    cr_assert_lt(i, 0);
}

Test(my_strncmp, should_return_0)
{
    char s1 = "azerty";
    char s2 = "azerty";
    int nb = 6;
    int i = my_strncmp(s1, s2, nb);
    cr_assert_eq(i, 0);
}

Test(my_strncmp, should_return_1)
{
    char s1 = "azertyuiop";
    char s2 = "azerty";
    int nb = 8;
    int i = my_strncmp(s1, s2, nb);
    cr_assert_gt(i, 0);
}