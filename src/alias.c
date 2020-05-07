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
    new_alias->next = NULL;
    if (!copy) {
        *alias = new_alias;
        return;
    }
    while (copy->next)
        copy = copy->next;
    copy->next = new_alias;
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
            new = my_strcat(new, " ");
        }
        add_alias(&store->alias, tab[1], new);
        return (0);
    }
    return (84);
}

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 1000);
    int bytes = 0;

    if (!fd)
        return (NULL);
    memset(buffer, 0, 1000);
    bytes = read(fd, buffer, 999);
    if (!bytes)
        return (NULL);
    return (buffer);
}

void try_to_add_alias(char *line, alias_t **alias)
{
    char **tab = my_str_to_word_array(line, " \t");
    char *new = NULL;

    if (!my_strcmp(tab[0], "alias") && tab[1] && tab[2]) {
        for (int index = 2; tab[index]; index += 1) {
            new = my_strcat(new, tab[index]);
            new = my_strcat(new, " ");
        }
        add_alias(alias, tab[1], new);
    }
}

alias_t *get_list_from_file(void)
{
    alias_t *alias = NULL;
    int fd = open(".42shrc", O_RDONLY | O_CREAT, 0644);
    char *buffer = read_file(".42shrc");
    char **tab = my_str_to_word_array(buffer, "\n");

    if (!fd || !tab || !tab[0])
        return (NULL);
    for (int index = 0; tab[index]; index += 1)
        try_to_add_alias(tab[index], &alias);
    close(fd);
    return (alias);
}