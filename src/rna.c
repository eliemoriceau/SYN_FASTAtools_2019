/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** rna
*/

#include "fasta.h"
#include "my.h"

void print_rna(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == 'T')
            my_putchar('U');
        else
            my_putchar(str[i]);
    }
    my_putchar('\n');
}

int rna(data_t *data)
{
    seq_t *tmp = data->seq;

    for (; tmp; tmp = tmp->next) {
        my_putstr(tmp->id);
        print_rna(tmp->seq);
    }
    free_data(data);
    return (0);
}