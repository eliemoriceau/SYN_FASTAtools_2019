/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** task01
*/

#include "my.h"
#include <stdlib.h>

char *my_strdump(char const *src)
{
    char *str = malloc(sizeof(char) * my_strlen(src));
    my_strcpy(str, src);
    return (str);
}
