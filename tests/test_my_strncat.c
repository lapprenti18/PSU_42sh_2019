/*
** EPITECH PROJECT, 2019
** test_my_strncat.c
** File description:
** test_my_strncat.c
*/

#include <criterion/criterion.h>

char *my_strncat(char *dest, char const *src, int nb);

Test (my_strncat, should_print_un)
{
    char dest[] = "Techie";
    char src[] = "Delight";
    int nb = 4;
    my_strncat(dest, src, nb);
    cr_assert_str_eq(dest, "TechieDeli");
}