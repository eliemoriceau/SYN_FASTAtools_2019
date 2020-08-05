/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_putnbr
*/

#include "my.h"

void my_put_unsigned(unsigned int nb)
{
    if (nb <= 9)
        my_putchar(nb + '0');
    if (nb >= 10) {
        my_put_unsigned(nb / 10);
        my_putchar((nb % 10) + '0');
    }
}