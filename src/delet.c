/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** alias.c
*/

#include "../include/my.h"

char *delete_key(historique_t *historique)
{
    char *result = malloc(sizeof(char) * my_strlen(historique->cmd));

    my_memsete(result, 0, my_strlen(historique->cmd));
    int rep;
    for (rep = 0; rep < historique->cursor_pos - 1; rep += 1)
        result[rep] = historique->cmd[rep];
    rep += 1;
    for (; rep < my_strlen(historique->cmd); rep += 1)
        result[rep - 1] = historique->cmd[rep];
    historique->cursor_pos -= 1;
    return (result);
}

void delete(historique_t *historique, int lenght)
{
    if (lenght == 0 || historique->cursor_pos == 0) {
        write(1, "\a", 1);
        return;
    }
    if (lenght == historique->cursor_pos) {
        write(1, "\b \b", 3);
        historique->cmd[my_strlen(historique->cmd) - 1] = '\0';
        historique->cursor_pos -= 1;
        return;
    }
    write(1, "\r", 1);
    for (int a = 0; a < 127; a += 1)
        write(1, " ", 1);
    write(1, "\r", 1);
    my_draw_prompt();
    historique->cmd = delete_key(historique);
    write(1, historique->cmd, my_strlen(historique->cmd));
    for (int temp = 0; temp < my_strlen(historique->cmd\
    ) - historique->cursor_pos; temp += 1)
        write(1, "\033[1D", 4);
}