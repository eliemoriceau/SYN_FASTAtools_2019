/*
** EPITECH PROJECT, 2019
** my_strcy.c
** File description:
** task01
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(src);

    while (i != len +1) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
