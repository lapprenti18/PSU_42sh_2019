/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** alias.c
*/

#include "../include/my.h"

void right(historique_t *historique)
{
    modif_histo(historique);
    if (historique->cursor_pos >= my_strlen(historique->cmd)) {
        write(1, "\a", 1);
        historique->boool++;
        return;
    }
    historique->cursor_pos += 1;
    historique->boool++;
    write(1, "\033[1C", 4);
}

void left(historique_t *historique)
{
    modif_histo(historique);
    if (historique->cursor_pos == 0) {
        write(1, "\a", 1);
        historique->boool++;
        return;
    }
    historique->cursor_pos -= 1;
    historique->boool++;
    write(1, "\033[1D", 4);
}

void down(historique_t *historique, int a)
{
    if (historique->history_pos < a && my_tab_lenght\
    (historique->history) != 0) {
        down_histo(historique);
    }
    else if (historique->history_pos == a && my_tab_lenght\
    (historique->history) != 0) {
        down_current(historique);
    } else
        write(1, "\a", 1);
}

void up(historique_t *historique, int a)
{
    if (historique->history_pos > 0 && my_tab_lenght\
    (historique->history) != 0) {
        if (historique->history_pos == a) {
            up_curent(historique);
        } else {
            up_histo(historique);
        }
        write(1, "\r", 1);
        my_draw_prompt();
        write(1, historique->history[historique->history_pos - 1], my_strlen\
        (historique->history[historique->history_pos - 1]));
        historique->history_pos -= 1;
    } else
        write(1, "\a", 1);
}

void check_key_dir(historique_t *historique)
{
    int a = my_tab_lenght(historique->history);

    historique->key_pressed = getchar();
    if (historique->key_pressed == 91) {
        historique->key_pressed = getchar();
        if (historique->key_pressed == UP) {
            up(historique, a);
            historique->boool++;
        }
        if (historique->key_pressed == DOWN) {
            down(historique, a);
            historique->boool++;
        }
        if (historique->key_pressed == LEFT)
            left(historique);
        if (historique->key_pressed == RIGHT)
            right(historique);
    }
}