/*
** EPITECH PROJECT, 2019
** my_compute_power_rec_test
** File description:
** yo
*/

#include "my.h"
#include <criterion/criterion.h>

Test(check_valid_command, should_return_1)
{
    int res = 0;
    char *tab[] = {"/bin/ls", "yo", NULL};

    res = my_tab_lenght(tab);
    cr_assert_eq(res, 2);
}

Test(check_valid_command, should_return_2)
{
    int res = 0;
    char *tab[] = {NULL};

    res = my_tab_lenght(tab);
    cr_assert_eq(res, 0);
}

Test(check_valid_command, should_return_3)
{
    char *res;
    char *tab = "test";

    res = str_cpy(tab);
    cr_assert_str_eq(res, "test");
}

Test(check_valid_command, should_return_4)
{
    char *res;
    char *tab = NULL;
    int a = 0;

    res = str_cpy(tab);
    if (!res)
        a = 1;
    cr_assert_eq(a, 1);
}

Test(check_valid_command, should_return_5)
{
    char *res;
    char *tab = "test";
    char a = 'a';

    res = my_strcat_str_c(tab, a);
    cr_assert_str_eq(res, "testa");
}
