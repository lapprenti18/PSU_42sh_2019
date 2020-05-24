/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** alias.c
*/

#include "../include/my.h"

void add_lett(historique_t *historique)
{
    write(1, &historique->key_pressed, 1);
    historique->cursor_pos += 1;
}

void write_cursur(historique_t *historique, char *result)
{
    write(1, "\r", 1);
    my_draw_prompt();
    write(1, result, my_strlen(result));
    for (int rep = 0; rep < my_strlen(result) - historique\
    ->cursor_pos; rep += 1)
        write(1, "\033[1D", 4);
}

char *add_letter(historique_t *historique)
{
    char *result = NULL;
    int temp;

    if (historique->cursor_pos == my_strlen(historique->cmd)) {
        add_lett(historique);
        return (my_strcat_str_c(historique->cmd\
        , (char)historique->key_pressed));
    } else {
        if (!historique->cmd)
            historique->cursor_pos = 0;
        result = malloc(sizeof(char) * (my_strlen(historique->cmd) + 4));
        my_memsete(result, '\0', my_strlen(historique->cmd) + 3);
        for (temp = 0; temp < historique->cursor_pos; temp += 1)
            result[temp] = historique->cmd[temp];
        result[temp] = historique->key_pressed;
        for (; temp < my_strlen(historique->cmd); temp += 1)
            result[temp + 1] = historique->cmd[temp];
        historique->cursor_pos += 1;
        write_cursur(historique, result);
    }
    return (result);
}