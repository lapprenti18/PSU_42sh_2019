/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** modif_string.c
*/

#include "../include/my.h"

int avoid_loop(char **str, alias_t *alias, int check)
{
    if (!my_strcmp(alias->new, alias->prev))
        return (0);
    if (!my_strcmp(*str, alias->prev)) {
        if (alias->loop == true) {
            printf("Alias loop.\n");
            return (-1);
        }
        alias->loop = true;
        *str = my_strdup(alias->new);
        check += 1;
    }
    return (check);
}

int check_alias(char **new_buffer, char **tab, store_t *store)
{
    int check = 0;

    for (alias_t *alias = store->alias; alias; alias = alias->next) {
        check = avoid_loop(&tab[0], alias, check);
        if (check == -1)
            return (-1);
    }
    for (int index = 0; tab[index]; index += 1) {
        *new_buffer = my_strcat(*new_buffer, tab[index]);
        *new_buffer = my_strcat(*new_buffer, " ");
    }
    return (check);
}

char *check_for_var(char *str, store_t *store)
{
    if (str[0] != '$')
        return (str);
    for (alias_t *var = store->variables; var; var = var->next)
        if (!my_strcmp(&str[1], var->prev))
            return (my_strdup(var->new));
    printf("%s: Undefined variable.\n", &str[1]);
    return (str);
}

char *check_var(char *buffer, store_t *store)
{
    char **tab = my_str_to_word_array(buffer, "\t ");
    char *new_buffer = NULL;

    for (int i = 0; tab[i]; i += 1) {
        tab[i] = check_for_var(tab[i], store);
        new_buffer = my_strcat(new_buffer, tab[i]);
        new_buffer = my_strcat(new_buffer, " ");
    }
    return (new_buffer);
}

char *change_buffer(char *buffer, store_t *store)
{
    char **tab = my_str_to_word_array(buffer, "\n \t");
    char *new_buffer = NULL;
    int check = 0;

    if (!tab || !tab[0])
        return (NULL);
    check = check_alias(&new_buffer, tab, store);
    if (check)
        return (change_buffer(new_buffer, store));
    new_buffer = check_var(new_buffer, store);
    for (alias_t *alias = store->alias; alias; alias = alias->next)
        alias->loop = false;
    if (check == -1)
        return (NULL);
    return (new_buffer);
}