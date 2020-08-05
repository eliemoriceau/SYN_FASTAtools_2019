/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** sort
*/

#include "fasta.h"
#include <unistd.h>
#include <string.h>

k_mer_t *bubblesort(k_mer_t *list)
{
    k_mer_t *begin = list;
    char *tmp = NULL;

    while (list->next) {
        if (strcmp(list->mers, list->next->mers) > 0) {
            tmp = list->mers;
            list->mers = list->next->mers;
            list->next->mers = tmp;
            list = begin;
        } else
            list = list->next;
    }
    list = begin;
    return (list);
}