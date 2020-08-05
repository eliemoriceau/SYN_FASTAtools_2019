/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** reverse
*/

#include "fasta.h"
#include "my.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char dna_complement(char c)
{
    switch (c) {
    case 'A':
        return ('T');
    case 'T':
        return ('A');
    case 'G':
        return ('C');
    case 'C':
        return ('G');
    default:
        return (c);
    }
}

char *reverse_dna(char *seq)
{
    char *revert = malloc(sizeof(char) * (strlen(seq) + 1));
    int i = 0;

    if (!revert)
        return (NULL);
    for (int j = strlen(seq) - 1; j >= 0; i++, j--) {
        revert[i] = dna_complement(seq[j]);
    }
    revert[i] = '\0';
    return (revert);
}

void print_reverse(char *str)
{
    char *reverse = reverse_dna(str);
    printf("%s\n", reverse);
    free(reverse);
}

int reverse(data_t *data)
{
    seq_t *tmp = data->seq;

    for (; tmp; tmp = tmp->next) {
        printf("%s", tmp->id);
        print_reverse(tmp->seq);
    }
    free_data(data);
    return (0);
}