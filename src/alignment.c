/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** alignment
*/

#include "fasta.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



int nb_seq(seq_t *liste)
{
    seq_t *tmp = liste;
    int count = 0;

    while (tmp) {
        tmp = tmp->next;
        count++;
    }
    return (count);
}

int set_value_int(char c)
{
    char *arr = "AGCT";
    int i = 0;

    for (; arr[i]; i++) {
        if (c == arr[i])
            return (i);
    }
    return (i);
}

int matrix_s(char a, char b)
{
    int matrix_s[4][5] = {{1, -1, -1, -1, -1}, {-1, 1, -1, -1, -1}, \
{-1, -1, 1, -1, -1}, {-1, -1, -1, 1, -1}};
    int a_value = set_value_int(a);
    int b_value= set_value_int(b);

    return (matrix_s[a_value][b_value]);
}

int calc_alignment(char *seq1, char *seq2)
{
    int count = 0;
    int add = 0;

    for (int i = 0; seq1[i] && seq2[i]; i++) {
        add = matrix_s(seq1[i], seq2[i]);
        count += add;
    }
    return (count);
}

int alignment(data_t *data)
{
    int align = 0;

    if (nb_seq(data->seq) != 2)
        return (84);
    align = needleman_wunsch(data->seq->seq, data->seq->next->seq);
    printf("%i\n", align);
    free_data(data);
    return (0);
}