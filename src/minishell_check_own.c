/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** minishell_check_own.c
*/

#include "../include/my.h"

int my_check_sep(char *buffer)
{
    for (int position = 0; buffer[position]; position += 1) {
        if (buffer[position] == '|' || buffer[position] == ';' || \
        buffer[position] == '<' || buffer[position] == '>' || \
        buffer[position] == '&')
            return (1);
    }
    return (0);
}

tree_t *obtain_good_tree(buffer_t *buff, int cursor, tree_t *my_tree)
{
    if (!my_check_sep(buff->buffer) || !my_tree) {
        my_tree = insert(my_tree, buff->buffer, cursor);
        return (my_tree);
    }
    if (cursor == 1)
        my_tree->right = my_binary_tree(buff, my_tree->right);
    if (cursor == 0)
        my_tree->left = my_binary_tree(buff, my_tree->left);
    return (my_tree);
}

int check_for_pipe(buffer_t *buff)
{
    int position = 0;
    int temp = 0;

    for (position = 0; buff->buffer[position]; position += 1) {
        if (buff->buffer[position] == '|')
            temp = position;
    }
    if (temp) {
        buff->buffer[temp] = '\r';
        return (5);
    }
    return (0);
}

int check_for_double(buffer_t *buff, int position, int temp)
{
    for (position = 0; buff->buffer[position]; position += 1) {
        if (buff->buffer[position] == '|' && \
        (position > 0 && buff->buffer[position - 1] == '|'))
            temp = position;
    }
    if (temp) {
        buff->buffer[temp] = '\r';
        buff->buffer[temp - 1] = '\r';
        return (7);
    }
    for (position = 0; buff->buffer[position]; position += 1) {
        if (buff->buffer[position] == '&' && \
        (position > 0 && buff->buffer[position - 1] == '&'))
            temp = position;
    }
    if (temp) {
        buff->buffer[temp] = '\r';
        buff->buffer[temp - 1] = '\r';
        return (6);
    }
    return (lasts_checks(buff, 0, 0));
}

int my_change_buffer(buffer_t *buff)
{
    int position = 0;
    int temp = 0;

    for (; buff->buffer[position]; position += 1) {
        if (buff->buffer[position] == ';')
            temp = position;
    }
    if (temp) {
        buff->buffer[temp] = '\r';
        return (1);
    }
    return (check_for_double(buff, 0, 0));
}