/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** dna
*/

#include "fasta.h"
#include <stdio.h>

int dna(data_t *data)
{
    seq_t *tmp = data->seq;

    for (; tmp; tmp = tmp->next)
        printf("%s%s\n", tmp->id, tmp->seq);

    free_data(data);
    return (0);
}