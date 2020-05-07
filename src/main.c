/*
** EPITECH PROJECT, 2019
** PSU_my_exec_2019
** File description:
** main.c
*/

#include "../include/my.h"

char **my_tab_special(char **tab)
{
    char **tabdup = NULL;
    char *cat = NULL;

    for (int current = 0; tab[current]; current += 1) {
        cat = my_strcat(cat, tab[current]);
        cat = my_strcat(cat, " ");
    }
    tabdup = my_str_to_word_array(cat, " ");
    if (cat)
        free (cat);
    return (tabdup);
}

void sigint_handler(int sig_num)
{
    signal(SIGINT, sigint_handler);
    my_printf("\n");
    my_draw_prompt();
    if (sig_num == 0)
        return;
}

void my_memset(char *buffer, int size, char c)
{
    for (int cursor = 0; cursor < size; cursor += 1)
        buffer[cursor] = c;
}

int main(int ac, char *av[], char **env)
{
    store_t store;

    store.alias = get_list_from_file();
    store.memory_env = my_env_to_list(NULL, env);
    store.env_list = my_env_to_list(NULL, env);
    signal(SIGINT, sigint_handler);
    if (!av[0] || ac != 1)
        return (84);
    return (minishell_loop(store.env_list, &store));
}