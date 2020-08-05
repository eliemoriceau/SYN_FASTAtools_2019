/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** word_to_array
*/

#include "my.h"
#include <stdlib.h>

char *my_strdump(char const *src);
int my_char_isalpha(char c);



char **my_word_to_array(char separator, char *str)
{
    char *buffer = malloc(sizeof(char) * my_strlen(str));
    char **array = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i_buffer = 0;
    int i_array =0;

    for (int i_str = 0; str[i_str] != '\0'; i_str++) {
        if (str[i_str] == separator) {
            buffer[i_buffer] = '\0';
            array[i_array] = my_strdump(buffer);
            i_buffer = 0;
            i_array++;
        } else {
            buffer[i_buffer] = str[i_str];
            i_buffer++;
        }
    }
    buffer[i_buffer] = '\0';
    array[i_array] = my_strdump(buffer);
    array[i_array + 1] = NULL;
    free(buffer);
    return (array);
}