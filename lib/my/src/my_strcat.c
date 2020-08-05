/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_strcat
*/

#include "my.h"
#include <stdlib.h>
#include <string.h>

char *my_strcat(char *dest, char *src)
{
    int len = strlen(dest);
    int tmp = 0;
    char *res = malloc(sizeof(char) * (len + strlen(src) + 1));

    for (int i = 0; i < len; i++)
        res[i] = dest[i];
    free(dest);
    while (src[tmp] != '\0') {
        res[len] = src[tmp];
        len++;
        tmp++;
    }
    res[len] = '\0';
    dest = strdup(res);
    free(res);
    return (dest);
}
