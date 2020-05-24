/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** alias.c
*/

#include "../include/my.h"

void control_c(historique_t *historique)
{
    if (ctr_c == 1) {
        historique->cmd = NULL;
        ctr_c = 0;
        historique->cursor_pos = 0;
        historique->history_pos = my_tab_lenght(historique->history) + 1;
    }
    historique->boool = 0;
}

char *return_getline(historique_t *historique)
{
    if (historique->cmd == NULL)
        return ("\n\0");
    return (historique->cmd);
}