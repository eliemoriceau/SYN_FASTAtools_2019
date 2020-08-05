/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int nb = 0;
    while (str[nb] != '\0') {
        nb++;
    }
    return (nb);
}