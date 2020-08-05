/*
** EPITECH PROJECT, 2019
** my_isalpha
** File description:
** char is alpha caractere
*/

int my_char_isupper(char c);
int my_char_islower(char c);

int my_char_isalpha(char c)
{
    if (my_char_islower(c) || my_char_isupper(c)) {
        return (1);
    }
    return (0);
}