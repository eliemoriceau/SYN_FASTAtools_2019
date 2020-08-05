/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** my_getline
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *my_getline(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);
    if (read == -1) {
        free(line);
        return (NULL);
    }
    return (line);
}