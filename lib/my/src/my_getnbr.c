/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int res = 0;
    int is_neg = 1;

    while (str[nb] == '-' || str[nb] == '+') {
        nb++;
    }
    if (nb && str[nb - 1] == '-')
        is_neg = -1;
    while (str[nb] >= '0' && str[nb] <= '9') {
        res *= 10;
        res += str[nb] - '0';
        nb++;
    }
    res *= is_neg;
    return (res);
}