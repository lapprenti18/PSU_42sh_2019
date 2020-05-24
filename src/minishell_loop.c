/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell_loop.c
*/

#include "../include/my.h"

const my_binaries_t bin_tab[13] =
{
    {"cd", my_own_cd},
    {"setenv", my_own_setenv},
    {"unsetenv", my_own_unsetenv},
    {"env", my_own_env},
    {"exit", my_own_exit},
    {"alias", my_alias},
    {"where", my_own_where},
    {"which", my_own_which},
    {"set", my_own_set},
    {"repeat", my_own_repeat},
    {"foreach", my_own_foreach},
    {"history", my_own_history},
    {NULL, NULL}
};

int good_return(char save, int ret, int temp, buffer_t *buff)
{
    if (temp) {
        save = buff->buffer[temp];
        buff->buffer[temp] = '\r';
        if (ret == 3 || ret == 9 || ret == 10)
            buff->buffer[temp - 1] = '\r';
    }
    if (save == '|')
        return (5);
    if (save == '<')
        return (4);
    if (save == '>')
        return (ret == 3) ? 3 : 2;
    return (0);
}

int lasts_checks(buffer_t *buff, int ret, int position)
{
    int temp = 0;
    char save = 0;

    for (position = 0; buff->buffer[position]; position += 1) {
        if (check_for_redirect(buff->buffer[position])) {
            temp = position;
            ret = 0;
        }
        if (buff->buffer[position] == '>' && \
        (position > 0 && buff->buffer[position - 1] == '>'))
            ret = 3;
    }
    return (good_return(save, ret, temp, buff));
}

void my_draw_prompt(void)
{
    static char *str = NULL;
    size_t size = 4096;

    if (!str)
        str = malloc(sizeof(char) * 4096);
    if (getcwd(str, size))
        my_printf("[%s]", str);
    my_printf("$ ");
}

int check_own(char *buffer, node_t *env_list, int fds[2], store_t *store)
{
    for (int i = 0; bin_tab[i].command != NULL; i += 1) {
        if (my_strcmp(bin_tab[i].command, buffer) == 0) {
            dup2(fds[0], 0);
            dup2(fds[1], 1);
            env_list->ret_value = (bin_tab[i].ptr(env_list, \
            buffer, store) == 84) ? -1 : 0;
            return (1);
        }
    }
    return (0);
}

int minishell_loop(node_t *env_list, store_t *store)
{
    char *buffer = NULL;
    size_t size = 0;
    tree_t *my_tree = NULL;
    buffer_t buff;

    store->historique = malloc(sizeof(historique_t));
    do {
        free_tree(my_tree);
        my_tree = NULL;
        if (isatty(0) > 0) {
            buffer = bufferito(store, env_list);
        } else
            if (getline(&buffer, &size, stdin) == -1)
                return (my_tty());
        if (!buffer)
            continue;
        buff.buffer = buffer;
        buffer = NULL;
        my_tree = my_binary_tree(&buff, my_tree);
    } while (parse_tree(my_tree, env_list, store));
    return (free_list(env_list));
}