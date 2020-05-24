/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell_loop.c
*/

#include "../include/my.h"

int my_own_history(node_t *env_list, char *buffer, store_t *store)
{
    if (!store->historique->history)
        return (0);
    for (int temp = 0; store->historique->history[temp]; temp += 1) {
        printf("%s\n", store->historique->history[temp]);
    }
    return (0);
}