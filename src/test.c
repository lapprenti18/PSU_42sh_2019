/*
** EPITECH PROJECT, 2019
** PSU_my_exec_2019
** File description:
** main.c
*/

#include "../include/my.h"

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 1000);
    int bytes = 0;

    if (!fd)
        return (NULL);
    my_memsete(buffer, '\0', 1000);
    bytes = read(fd, buffer, 999);
    if (!bytes)
        return (NULL);
    return (buffer);
}

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
    my_printf("^C\n");
    my_draw_prompt();
    ctr_c = 1;
    if (sig_num == 0)
        return;
}

void my_memset(char *buffer, int size, char c)
{
    for (int cursor = 0; cursor < size; cursor += 1)
        buffer[cursor] = c;
}