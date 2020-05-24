/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** alias.c
*/

#include "../include/my.h"

int my_tab_lenght(char **tab)
{
    int lenght = 0;

    if (!tab)
        return (0);
    for (; tab[lenght]; lenght += 1);
    return (lenght);
}

char *str_cpy(char *str_two)
{
    char *str = NULL;

    if (my_strlen(str_two) == 0)
        return (NULL);
    str = malloc(sizeof(char) * (my_strlen(str_two) + 4));
    for (int rep = 0; rep < my_strlen(str_two) + 3; rep += 1)
        str[rep] = '\0';

    for (int temp = 0; str_two[temp]; temp += 1)
        str[temp] = str_two[temp];
    return (str);
}

char *my_strcat_str_c(char *word, char c)
{
    char *result;
    int temp;

    if (!word) {
        result = malloc(sizeof(char) * (2));
        result[0] = c;
        result[1] = '\0';
    } else {
        result = malloc(sizeof(char) * (my_strlen(word) + 2));
        for (temp = 0; word[temp]; temp += 1)
            result[temp] = word[temp];
        result[temp] = c;
        result[temp + 1] = '\0';
    }
    return (result);
}

void my_memsete(char *word, char c, int temp)
{
    for (int rep = 0; rep < temp; rep += 1)
        word[rep] = c;
}