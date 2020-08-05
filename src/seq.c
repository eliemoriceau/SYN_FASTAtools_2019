/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** seq
*/

#include "fasta.h"
#include <unistd.h>
#include <stdlib.h>

seq_t *add_seq(seq_t *seq, seq_t *new)
{
    seq_t *tmp = seq;

    if (!tmp || !new)
        return (seq);
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
    return (seq);
}

seq_t *init_seq(void)
{
    seq_t *new = malloc(sizeof(seq_t));

    if (!new)
        return (NULL);
    new->id = "";
    new->seq = "";
    new->next = NULL;

    return (new);
}
