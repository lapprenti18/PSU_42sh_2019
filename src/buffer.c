/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell_loop.c
*/

#include "../include/my.h"

char *bufferito(store_t *store, node_t *env_list)
{
    my_draw_prompt();
    return (my_getline(store->historique, env_list));
}