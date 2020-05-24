/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** alias.c
*/

#include "../include/my.h"

void modif_histo(historique_t *historique)
{
    if (historique->history == NULL)
        return;
    if (historique->history_pos == (my_tab_lenght(historique->history))) {
        return;
    }
    if (historique->history_pos > my_tab_lenght(historique->history))
        historique->history_pos = my_tab_lenght(historique->history);
    if (my_tab_lenght(historique->history) == 1) {
        historique->cmd = str_cpy(historique->history[0]);
        historique->history_pos = my_tab_lenght(historique->history);
        return;
    }
    historique->cmd = str_cpy(historique->history[historique->history_pos]);
    historique->history_pos = my_tab_lenght(historique->history);
}

void modif_histo_two(historique_t *historique)
{
    if (!historique->history)
        return;
    if (historique->history_pos == (my_tab_lenght(historique->history) + 1)) {
        return;
    }
    historique->cmd = str_cpy(historique->history[historique->history_pos - 3]);
    historique->history_pos = my_tab_lenght(historique->history);
}