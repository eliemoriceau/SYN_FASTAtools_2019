/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len_dest = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0' && i < nb) {
        dest[len_dest + i] = src[i];
        i++;
    }
    dest[len_dest + i + 1] = '\0';
    return (dest);
}