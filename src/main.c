/*
** EPITECH PROJECT, 2019
** PSU_my_exec_2019
** File description:
** main.c
*/

#include "../include/my.h"

int main(int ac, char *av[], char **env)
{
    store_t store;

    get_list_from_file(&store);
    store.memory_env = my_env_to_list(NULL, env);
    store.env_list = my_env_to_list(NULL, env);
    signal(SIGINT, sigint_handler);
    if (!av[0] || ac != 1)
        return (84);
    return (minishell_loop(store.env_list, &store));
}