/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** alias.c
*/

#include "../include/my.h"

void init_stat(historique_t *historique, char *open_history, node_t *env_list)
{
    historique->key_pressed = 0;
    historique->cursor_pos = 0;
    historique->dir = 0;
    historique->history_pos = 0;
    historique->cmd = NULL;
    historique->where = my_strcat(my_strcat(path(env_list), "/")\
    , ".42sh_history");
    if (open_history) {
        historique->history = my_str_to_word_array(open_history, "\n");
        historique->history_pos = my_tab_lenght(historique->history);
    } else {
        historique->history_pos = 0;
        historique->history = NULL;
    }
}

void changemode(int dir)
{
    static struct termios oldt;
    static struct termios newt;

    if (dir == 1) {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    }
    else
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

int kbhit(void)
{
    struct timeval tv;
    fd_set rdfs;

    tv.tv_sec = 0;
    tv.tv_usec = 0;

    FD_ZERO(&rdfs);
    FD_SET (STDIN_FILENO, &rdfs);

    select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
    return (FD_ISSET(STDIN_FILENO, &rdfs));
}

void check_key(historique_t *historique, char *open_history)
{
    modif_histo(historique);
    if (historique->key_pressed == DELETE)
        delete(historique, my_strlen(historique->cmd));
    else {
        if (historique->key_pressed != '\n') {
            historique->cmd = add_letter(historique);
        }else {
            if (historique->cmd)
                fill_history(historique);
            write(1, "\n", 1);
            historique->cursor_pos = 0;
            historique->history_pos += 1;
            historique->history = my_str_to_word_array(open_history, "\n");
        }
    }
}

char *my_getline(historique_t *historique, node_t *env_list)
{
    char *open_history = path_to_history(env_list);

    init_stat(historique, open_history, env_list);
    changemode(1);
    while (historique->key_pressed != '\n') {
        while (!kbhit());
        control_c(historique);
        historique->key_pressed = getchar();
        if (historique->key_pressed == 4) {
            remove(historique->where);
            changemode(0);
            exit (0);
        }
        if (historique->key_pressed == 27)
            check_key_dir(historique);
        else if (historique->boool == 0)
            check_key(historique, open_history);
    }
    changemode(0);
    modif_histo_two(historique);
    return (return_getline(historique));
}