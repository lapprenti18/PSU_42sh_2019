/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** alias.c
*/

#include "../include/my.h"

void add_alias(alias_t **alias, char *prev, char *new)
{
    alias_t *new_alias = malloc(sizeof(alias_t));
    alias_t *copy = *alias;

    new_alias->prev = my_strdup(prev);
    new_alias->new = my_strdup(new);
    new_alias->loop = false;
    new_alias->next = NULL;
    if (!copy) {
        *alias = new_alias;
        return;
    }
    while (copy->next)
        copy = copy->next;
    copy->next = new_alias;
}

int check_exist(store_t *store, char **tab, char *new)
{
    for (alias_t *alias = store->alias; alias; alias = alias->next)
        if (!my_strcmp(tab[1], alias->prev)) {
            alias->new = my_strdup(new);
            return (0);
        }
    add_alias(&store->alias, tab[1], new);
    return (0);
}

int my_alias(node_t *env_list, char *buffer, store_t *store)
{
    char **tab = my_str_to_word_array(buffer, " \t");
    char *new = NULL;

    (void)env_list;
    if (!my_strcmp(tab[0], "alias") && !tab[1]) {
        for (alias_t *alias = store->alias; alias; alias = alias->next)
            printf("%s %s\n", alias->prev, alias->new);
        return (0);
    }
    if (tab[0] && tab[1] && tab[2]) {
        for (int index = 2; tab[index]; index += 1) {
            new = my_strcat(new, tab[index]);
            if (tab[index + 1])
                new = my_strcat(new, " ");
        }
        return (check_exist(store, tab, new));
    }
    return (84);
}

void try_to_add_alias(char *line, store_t *store)
{
    char **tab = my_str_to_word_array(line, " \t");
    char *new = NULL;

    if (!my_strcmp(tab[0], "alias") && tab[1] && tab[2]) {
        for (int index = 2; tab[index]; index += 1) {
            new = my_strcat(new, tab[index]);
            if (tab[index + 1])
                new = my_strcat(new, " ");
        }
        add_alias(&store->alias, tab[1], new);
    } else if (tab[0] && tab[1] && !tab[2])
        add_alias(&store->variables, tab[0], tab[1]);
}

void get_list_from_file(store_t *store)
{
    int fd = open(".42shrc", O_RDONLY | O_CREAT, 0644);
    char *buffer = read_file(".42shrc");
    char **tab = my_str_to_word_array(buffer, "\n");

    store->alias = NULL;
    store->variables = NULL;
    if (!fd || !tab || !tab[0])
        return;
    for (int index = 0; tab[index]; index += 1)
        try_to_add_alias(tab[index], store);
    close(fd);
}