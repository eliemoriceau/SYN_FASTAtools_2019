/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** data
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "fasta.h"
#include "my.h"

data_t *init_data(void)
{
    data_t *data = malloc(sizeof(data_t));

    if (!data)
        return (NULL);
    data->option = 0;
    data->seq = NULL;

    return (data);
}

int is_valid_char(char c)
{
    if (c == 'A' || c == 'T' || c == 'G' || c == 'C' || c == 'N')
        return (1);
    else
        return (0);
}

char *format_seq(char *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    if (!res)
        return (NULL);
    str = my_strupcase(str);
    for (int j = 0; str[j]; j++) {
        if (is_valid_char(str[j])) {
            res[i] = str[j];
            i++;
        }
    }
    res[i] = '\0';
    free(str);
    return (res);
}

seq_t *get_data(char *line)
{
    seq_t *new = malloc(sizeof(seq_t));

    if (!new)
        return (NULL);
    new->id = line;
    new->seq = strdup("");
    if (!new->seq)
        return (NULL);
    line= my_getline();
    while (line != NULL && line[0] != '>') {
        new->seq = my_strcat(new->seq, line);
        free(line);
        line = my_getline();
    }
    new->seq = format_seq(new->seq);
    if (line == NULL)
        new->next = NULL;
    else
        new->next = get_data(line);
    return (new);
}

seq_t *set_data(void)
{
    seq_t *seq = NULL;
    char *line = my_getline();

    seq = get_data(line);
    return (seq);
}
