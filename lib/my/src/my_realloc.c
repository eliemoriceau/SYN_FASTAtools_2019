/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_realloc
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char *my_realloc(char *str, int size)
{
    char *str_realloc = NULL;
    int i;

    if (str == NULL || size < 1) {
        return (NULL);
    }
    str_realloc = malloc(sizeof(char) * (size + 1));
    if (!str_realloc) {
        return (NULL);
    }
    for (i = 0; i <= size && str[i] != '\0'; i++) {
        str_realloc[i] = str[i];
    }
    str_realloc[i] = '\0';
    free(str);
    return (str_realloc);
}