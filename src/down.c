/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** alias.c
*/

#include "../include/my.h"

void down_histo(historique_t *historique)
{
    write(1, "\r", 1);
    for (int temp = 0; temp < 127; temp += 1)
        write(1, " ", 1);
    write(1, "\r", 1);
    my_draw_prompt();
    historique->history_pos += 1;
    historique->cursor_pos = (my_strlen(historique->history\
    [historique->history_pos - 1]));
    write(1, historique->history[historique->history_pos], my_strlen\
    (historique->history[historique->history_pos]));
}

void down_current(historique_t *historique)
{
    historique->dir = 1;
    write(1, "\r", 1);
    for (int temp = 0; temp < 127; temp += 1)
        write(1, " ", 1);
    write(1, "\r", 1);
    my_draw_prompt();
    historique->history_pos += 1;
    historique->cursor_pos = (my_strlen(historique->cmd) - 1);
    write(1, historique->cmd, my_strlen(historique->cmd));
}