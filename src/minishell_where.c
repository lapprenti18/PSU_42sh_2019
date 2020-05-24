/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell_where.c
*/

#include "../include/my.h"

char *my_bin(char *env, char *buffer, int i)
{
    char *result = NULL;
    char **tab = my_str_to_word_array(buffer, " \t\n");
    static int place = 0;

    if (i == 0) {
        place = 0;
        return (NULL);
    }
    if (access(tab[0], X_OK) == 0 && !place++)
        return (tab[0]);
    result = my_special_str_dup(env, tab[0]);
    while (env[place++]) {
        if (env[place] == ':')
            result = my_special_str_dup(&env[place + 1], tab[0]);
        if (result && access(result, X_OK) == 0)
            return (result);
    }
    if (place == 0)
        return (NULL);
    return ("ret");
}

int my_own_where2(char **arr, store_t *store)
{
    int check = 0;
    char *alias = NULL;

    for (int i = 1; arr[i]; i++) {
        if ((alias = isalias(arr[i], store)))
            printf("%s is aliased to %s\n", arr[i], alias);
        if ((alias = isbuiltin(arr[i])))
            printf("%s is a shell built-in\n", arr[i]);
        while ((alias = my_bin(get_good_env(store->memory_env), arr[i], 1))) {
            if (!my_strcmp(alias, "ret"))
                break;
            printf("%s\n", alias);
        }
        my_bin(get_good_env(store->memory_env), arr[i], 0);
        check = alias == NULL ? 84 : check;
    }
    return (check);
}

int my_own_where(node_t *env_list, char *buffer, store_t *store)
{
    char **arr = my_str_to_word_array(buffer, " \t");

    (void)env_list;
    if (arr[1] == NULL) {
        printf("where: Too few arguments.\n");
        return (84);
    }
    return (my_own_where2(arr, store));
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