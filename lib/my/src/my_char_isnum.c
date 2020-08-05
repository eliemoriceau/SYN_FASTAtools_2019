/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_char_isnum
*/

int my_char_isnum(char c)
{
    if (c >= '0' && c <= '9') {
        return (1);
    }
    return (0);
}