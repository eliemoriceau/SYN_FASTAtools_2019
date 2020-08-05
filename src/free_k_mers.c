/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** free_k_mers
*/

#include "fasta.h"
#include <stdlib.h>

void free_k_mers(k_mer_t *link)
{
    if (link) {
        if (link->next)
            free_k_mers(link->next);
        free(link->mers);
        free(link);
    }
}