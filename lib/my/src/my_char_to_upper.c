/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_char_to_upper
*/

#include "my.h"

char my_char_to_upper(char const c)
{
    if (my_char_islower(c))
        return ('A' - 'a' + c);
    return (c);
}