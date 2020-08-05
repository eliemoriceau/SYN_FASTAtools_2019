/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** my_strupcase
*/

#include "my.h"

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (my_char_islower(str[i])) {
            str[i] = my_char_to_upper(str[i]);
        }
        i++;
    }
    return (str);
}