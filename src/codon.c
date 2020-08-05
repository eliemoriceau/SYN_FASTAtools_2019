/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** codon
*/

#include "fasta.h"
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int is_codon_end(char *codon)
{
    char end[3][4] = {"TAA", "TAG", "TGA"};

    for (int i = 0; i < 3; i++) {
        if (strncmp(codon, end[i], 3) == 0) {
            return (true);
        }
    }
    return (false);
}

k_mer_t *get_codon_seq(char *str, int size, k_mer_t *list)
{
    k_mer_t *new = malloc(sizeof(k_mer_t));
    k_mer_t *tmp = list;

    if (!new)
        return (NULL);
    new->mers = strndup(str, size);
    if (!new->mers)
        return (NULL);
    new->next = NULL;

    if (!list)
        list = new;
    else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
    return (list);
}

k_mer_t *set_codon(char *str, k_mer_t *list)
{
    for (int j = 3; str[j + 2]; j += 3) {
        if (is_codon_end(&str[j])) {
            list = get_codon_seq(str, j, list);
            return (list);
        }
    }
    return (list);
}

k_mer_t *search_codon(char *seq, k_mer_t *list)
{
    char *start = "ATG";
    int i = 0;

    for (; seq[i + 2]; i++) {
        if (strncmp(&seq[i], start, 3) == 0) {
            list = set_codon(&seq[i], list);
        }
    }
    return (list);
}

int codon(data_t *data)
{
    seq_t *tmp = data->seq;
    k_mer_t *list = NULL;
    char *rev = NULL;

    for (; tmp; tmp = tmp->next) {
        list = search_codon(tmp->seq, list);
        rev = reverse_dna(tmp->seq);
        list = search_codon(rev, list);
        free(rev);
    }
    bubblesort(list);
    print_k_mers(list);
    free_k_mers(list);
    free_data(data);
    return (0);
}