/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** exec_tree.c
*/

#include "../include/my.h"

static sep_t sep_tab[7] =
{
    {";", exec_double},
    {"|", execute_pipe},
    {">", exec_redirect_right},
    {"<", exec_redirect_left},
    {">>", exec_double_redirect_right},
    {"&&", exec_double_and},
    {"||", exec_double_pipe}
};

void close_and_dup(int new_fds[2], int fds[2], node_t *env_list, pid_t pid)
{
    env_list->ret_value = pid;
    close(fds[1]);
    dup2(new_fds[0], 0);
    dup2(new_fds[1], 1);
}

void exec_simple(char *command, char **tab, int fds[2], store_t *store)
{
    pid_t pid = 0;
    char **exec_tab = my_list_to_tab(store->memory_env);
    char *str = get_good_env(store->memory_env);
    int new_fds[2] = {dup(0), dup(1)};

    command = my_get_good_bin(str, command, 0);
    if (!command)
        return;
    pid = fork();
    if (pid == 0) {
        dup2(fds[0], 0);
        dup2(fds[1], 1);
        execve(command, tab, exec_tab);
        print_exec(command);
        close(fds[0]);
        close(fds[1]);
        exit(0);
    } else
        wait(&pid);
    close_and_dup(new_fds, fds, store->env_list, pid);
    simple_ending(str, exec_tab, tab, pid);
}

void execute_pipe(tree_t *tree, node_t *env_list, store_t *store)
{
    pid_t pid;
    int new_fd[2];

    if (tree && (!tree->left || !tree->right))
        return (little_print());
    tree->left->pipefds[0] = tree->pipefds[0];
    tree->right->pipefds[1] = tree->pipefds[1];
    pipe(new_fd);
    tree->left->pipefds[1] = new_fd[1];
    tree->right->pipefds[0] = new_fd[0];
    pid = fork();
    if (pid == 0) {
        close(new_fd[0]);
        parse_tree(tree->left, env_list, store);
        close(new_fd[1]);
        exit(0);
    }
    close(new_fd[1]);
    parse_tree(tree->right, env_list, store);
    wait(&pid);
}

int parse_tree(tree_t *tree, node_t *env_list, store_t *store)
{
    char **tab = NULL;
    int index = 0;

    if (!tree)
        return (1);
    while (index < 7) {
        if (!my_strcmp(sep_tab[index].sep, tree->command)) {
            sep_tab[index].ptr(tree, env_list, store);
            return (1);
        }
        index += 1;
    }
    tree->command = change_buffer(tree->command, store);
    tab = my_str_to_word_array(tree->command, " \t\n");
    if (check_own(tree->command, env_list, tree->pipefds, store) \
    || !tree->command)
        return (1);
    exec_simple(tree->command, tab, tree->pipefds, store);
    return (1);
}