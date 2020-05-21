/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** variables.c
*/

#include "../include/my.h"

int my_variables(node_t *env_list, char *buffer, store_t *store)
{
    char **tab = my_str_to_word_array(buffer, " \t");

    (void)env_list;
    if (!my_strcmp(tab[0], "set") && !tab[1]) {

    }
}