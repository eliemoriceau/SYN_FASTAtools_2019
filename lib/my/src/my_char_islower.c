/*
** EPITECH PROJECT, 2019
** my_islower
** File description:
** characte is lower
*/

int my_char_islower(char c)
{
    if (c >= 'a' && c <= 'z') {
        return (1);
    }
    return (0);
}