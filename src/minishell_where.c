/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell_where.c
*/

#include "../include/my.h"

char *isalias(char *cmd, store_t *store)
{
    for (alias_t *alias = store->alias; alias; alias = alias->next) {
        if (!my_strcmp(cmd, alias->prev))
            return (alias->new);
    }
    return (NULL);
}

char *isbuiltin(char *cmd)
{
    for (int i = 0; bin_tab[i].command; i++) {
        if (!my_strcmp(cmd, bin_tab[i].command))
            return ("ui");
    }
    return (NULL);
}

int my_own_where(node_t *env_list, char *buffer, store_t *store)
{
    char **arr = my_str_to_word_array(buffer, " \t");
    char *alias = NULL;
    int check = 0;

    (void)env_list;
    if (arr[1] == NULL) {
        printf("where: Too few arguments.\n");
        return (84);
    }
    for (int i = 1; arr[i]; i++) {
        if ((alias = isalias(arr[i], store)))
            printf("%s is aliased to %s\n", arr[i], alias);
        if ((alias = isbuiltin(arr[i])))
            printf("%s is a shell built-in\n", arr[i]);
        if ((alias = \
        my_get_good_bin(get_good_env(store->memory_env), arr[i], 1)))
            printf("%s\n", alias);
        check = alias == NULL ? 84 : check;
    }
    return (check);
}

int my_own_which_2(char **arr, store_t *store, int i)
{
    char *alias = NULL;
    int check = 0;

    if ((alias = isalias(arr[i], store)))
        printf("%s: \t aliased to %s\n", arr[i], alias);
    if (alias == NULL && (alias = isbuiltin(arr[i])))
        printf("%s: shell built-in command.\n", arr[i]);
    if (alias == NULL && (alias = \
    my_get_good_bin(get_good_env(store->memory_env), arr[i], 1)))
        printf("%s\n", alias);
    if (alias == NULL) {
        check = 84;
        printf("%s: Command not found.\n", arr[i]);
    }
    return (check);
}

int my_own_which(node_t *env_list, char *buffer, store_t *store)
{
    char **arr = my_str_to_word_array(buffer, " \t");
    int check = 0;

    (void)env_list;
    if (arr[1] == NULL) {
        printf("which: Too few arguments.\n");
        return (84);
    }
    for (int i = 1; arr[i]; i++)
        check = my_own_which_2(arr, store, i) == 84 ? 84 : check;
    return (check);
}