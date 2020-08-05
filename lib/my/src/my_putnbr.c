/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_putnbr
*/

#include "my.h"

void my_putnbr(int nb)
{
    int spe_nb = 0;

    if (nb == -2147483648) {
        spe_nb = 1;
        nb++;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10)
        my_putnbr(nb / 10);
    if (spe_nb)
        my_putchar(nb % 10 + 1 + '0');
    else
        my_putchar(nb % 10 + '0');
}