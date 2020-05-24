/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** alias.c
*/

#include "../include/my.h"

char *fill(char *av)
{
    struct stat size_buff;
    int reslt = stat(av, &size_buff);
    char *buffer;
    int fd;

    if (reslt == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (size_buff.st_size + 1));
    fd = open(av, O_RDONLY);
    if (reslt == -1 || buffer == NULL || fd == -1)
        return (NULL);
    for (int i = 0; i < size_buff.st_size + 1; i += 1)
        buffer[i] = '\0';
    reslt = read(fd, buffer, size_buff.st_size + 1);
    if (fd == -1 || reslt == -1)
        return (NULL);
    close(fd);
    return (buffer);
}

void fill_history(historique_t *historique)
{
    FILE *fp;

    if (historique->cmd[0] == '\n')
        return;
    if ((fp = fopen(historique->where, "a")) == NULL)
        return;
    fprintf(fp, "%s\n", historique->cmd);
    fclose(fp);
}