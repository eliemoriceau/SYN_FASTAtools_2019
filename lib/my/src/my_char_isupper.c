/*
** EPITECH PROJECT, 2019
** my_isupper
** File description:
** characte is upper
*/

int my_char_isupper(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return (1);
    }
    return (0);
}