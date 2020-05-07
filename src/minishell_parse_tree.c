/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** minishell_parse_tree.c
*/

#include "../include/my.h"

void change_fd(tree_t *tree, node_t *env_list, store_t *store, int check[2])
{
    if (!check[1]) {
        tree->left->pipefds[0] = check[0];
        tree->left->pipefds[1] = tree->pipefds[1];
    } else {
        tree->left->pipefds[0] = tree->pipefds[0];
        tree->left->pipefds[1] = check[0];
    }
    parse_tree(tree->left, env_list, store);
    close(check[0]);
}

void exec_redirect_left(tree_t *tree, node_t *env_list, store_t *store)
{
    char **tab = NULL;
    int fd = 0;
    int check[2];

    if (tree && (!tree->left || !tree->right)) {
        my_printf("Missing name for redirect.\n");
        return;
    }
    tab = my_str_to_word_array(tree->right->command, " ");
    fd = open(tab[0], O_RDONLY);
    if (fd >= 0) {
        check[0] = fd;
        check[1] = 0;
        change_fd(tree, env_list, store, check);
    } else
        my_printf("%s: No such file or directory.\n", tab[0]);
}

void exec_double(tree_t *tree, node_t *env_list, store_t *store)
{
    parse_tree(tree->left, env_list, store);
    parse_tree(tree->right, env_list, store);
}

void exec_double_redirect_right(tree_t *tree, node_t *env_list, store_t *store)
{
    char **tab = NULL;
    int fd = 0;
    int check[2];

    if (tree && (!tree->left || !tree->right)) {
        my_printf("Missing name for redirect.\n");
        return;
    }
    tab = my_str_to_word_array(tree->right->command, " ");
    fd = open(tab[0], O_WRONLY | O_CREAT | O_APPEND, 0664);
    check[0] = fd;
    check[1] = 1;
    change_fd(tree, env_list, store, check);
}

void exec_redirect_right(tree_t *tree, node_t *env_list, store_t *store)
{
    char **tab = NULL;
    int fd = 0;
    int check[2];

    if (tree && (!tree->left || !tree->right)) {
        my_printf("Missing name for redirect.\n");
        return;
    }
    tab = my_str_to_word_array(tree->right->command, " ");
    fd = open(tab[0], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    check[0] = fd;
    check[1] = 1;
    change_fd(tree, env_list, store, check);
}