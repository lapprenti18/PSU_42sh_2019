/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** alias.c
*/

#include "../include/my.h"

void up_curent(historique_t *historique)
{
    historique->cursor_pos = my_strlen(historique->\
    history[historique->history_pos - 1]);
    write(1, "\r", 1);
    for (int temp = 0; temp < 127; temp += 1)
        write(1, " ", 1);
}

void up_histo(historique_t *historique)
{
    historique->cursor_pos = my_strlen\
    (historique->history[historique->history_pos - 1]);
    write(1, "\r", 1);
    for (int temp = 0; temp < 127; temp += 1)
        write(1, " ", 1);
}