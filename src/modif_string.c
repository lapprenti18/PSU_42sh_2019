/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** modif_string.c
*/

#include "../include/my.h"

char *change_buffer(char *buffer, store_t *store)
{
    char **tab = my_str_to_word_array(buffer, "\n \t");
    char *new_buffer = NULL;

    if (!tab || !tab[0])
        return (NULL);
    for (int index = 0; tab[index]; index += 1) {
        for (alias_t *alias = store->alias; alias; alias = alias->next)
            if (!my_strcmp(tab[index], alias->prev))
                tab[index] = my_strdup(alias->new);
        new_buffer = my_strcat(new_buffer, tab[index]);
        new_buffer = my_strcat(new_buffer, " ");
    }
    return (new_buffer);
}