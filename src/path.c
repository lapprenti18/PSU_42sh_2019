/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** alias.c
*/

#include "../include/my.h"

char *path(node_t *env_list)
{
    node_t *cpy = env_list;

    while (cpy->next) {
        if (my_strcmp(cpy->name, "HOME") == 0) {
            return (cpy->value);
        }
        cpy = cpy->next;
    }
    return (NULL);
}

char *path_to_history(node_t *env_list)
{
    return (fill(my_strcat(my_strcat(path(env_list), "/"), ".42sh_history")));
}