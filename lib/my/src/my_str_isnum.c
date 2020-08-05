/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** str_isnum
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_char_isnum(str[i])) {
            i++;
        } else {
            return (0);
        }
    }
    return (1);
}