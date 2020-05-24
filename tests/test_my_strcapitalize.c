/*
** EPITECH PROJECT, 2019
** test_my_strcapitalize.c
** File description:
** test_my_str_capitalize.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

char my_strcapitalize2(char *str);
char *my_strcapitalize(char *str);

Test (my_strcapitalize1, should_print)
{
    char string[] = "hey, how are you? 42WORds forty-two; fifty+one";
    my_strcapitalize(string);
    cr_assert_str_eq(string, "Hey, How Are You? 42words Forty-Two; Fifty+One");
}

Test (my_strcapitalize, should_printe)
{
    char string[] = "je ne sais PaS quoi MetTre mAIs JE Le 10FAis";
    my_strcapitalize(string);
    cr_assert_str_eq(string, "Je Ne Sais Pas Quoi Mettre Mais Je Le 10fais");
}