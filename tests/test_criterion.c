/*
** EPITECH PROJECT, 2019
** my_compute_power_rec_test
** File description:
** yo
*/

#include "my.h"
#include <criterion/criterion.h>


Test(check_valid_command, should_return_6)
{
    char *res;
    char *tab = NULL;
    char a = 'a';

    res = my_strcat_str_c(tab, a);
    cr_assert_str_eq(res, "a");
}

Test(check_valid_command, should_return_7)
{
    int res = 0;
    char *tab = NULL;

    res = my_strlen(tab);
    cr_assert_eq(res, 0);
}

Test(check_valid_command, should_return_8)
{
    int res = 0;
    char *tab = "a";

    res = my_strlen(tab);
    cr_assert_eq(res, 1);
}