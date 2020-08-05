/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_putnbr_base
*/

#include "my.h"
#include <stdlib.h>

int my_putnbr_base(int nb, char *base)
{
    int size_base = my_strlen(base);
    int i = 0;
    char str[size_base + 1];
    char *base_c = base;

    if (nb < 0){
        nb = nb * (-1);
        my_putchar('-');
    }
    while (nb != 0) {
        str[i] = base_c[nb % size_base];
        nb = nb / size_base;
        i++;
    }
    for (i -= 1; i >= 0; i--)
        my_putchar(str[i]);
    return (0);
}