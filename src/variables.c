/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** variables.c
*/

#include "../include/my.h"

int try_to_add_var(store_t *store, char **tab)
{
    char **new_tab = my_str_to_word_array(tab[1], "=");

    if (!new_tab[1] || new_tab[2])
        return (84);
    add_alias(&store->variables, new_tab[0], new_tab[1]);
    return (0);
}

int my_own_set(node_t *env_list, char *buffer, store_t *store)
{
    char **tab = my_str_to_word_array(buffer, " \t");

    (void)env_list;
    if (!tab[1]) {
        for (alias_t *alias = store->variables; alias; alias = alias->next)
            printf("%s %s\n", alias->prev, alias->new);
        return (0);
    }
    if (!tab[2])
        return (try_to_add_var(store, tab));
    return (84);
}