/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell_repeat.c
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

int exec_one_command(char *command, store_t *store, char **tab)
{
    pid_t pid = 0;
    char **exec_tab = my_list_to_tab(store->memory_env);
    char *str = get_good_env(store->memory_env);

    command = my_get_good_bin(str, command, 0);
    if (!command)
        return (84);
    pid = fork();
    if (pid == 0) {
        execve(command, tab, exec_tab);
        print_exec(command);
        exit(0);
    } else
        wait(&pid);
    return (0);
}

int my_own_repeat(node_t *env_list, char *buffer, store_t *store)
{
    char **arr = my_str_to_word_array(buffer, " \t");
    int nb = 0;
    int check = 0;

    (void)env_list;
    if (arr[1] == NULL || arr[2] == NULL) {
        printf("repeat: Too few arguments.\n");
        return (84);
    }
    if (my_str_isnum(arr[1]) == 0) {
        printf("repeat: Badly formed number.\n");
        return (84);
    }
    nb = my_getnbr(arr[1]);
    for (int i = 0; i < nb; i++)
        check = exec_one_command(arr[2], store, arr + 2) == 84 ? 84 : check;
    return (check);
}