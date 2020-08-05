/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** k_mers
*/

#include "fasta.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

k_mer_t *add_mers(k_mer_t *list, k_mer_t *new)
{
    k_mer_t *tmp = list;

    if (!new)
        return (list);
    if (!list) {
        list = new;
        return (list);
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
    return (list);
}

k_mer_t *get_l_mers(char *str, k_mer_t *list, int k)
{
    k_mer_t *new = malloc(sizeof(k_mer_t));
    k_mer_t *tmp = NULL;
    int exist = 0;

    if (!new)
        return (NULL);
    new->mers = strndup(str, k);
    new->next = NULL;
    if (!list) {
        list = new;
        return (list);
    }
    for (tmp = list; tmp != NULL; tmp = tmp->next) {
        if (strncmp(tmp->mers, str, k) == 0)
            exist = 1;
    }
    if (!exist) {
        add_mers(list, new);
    } else
        free_k_mers(new);
    return (list);
}

k_mer_t *set_k_mers(char *str, int k, k_mer_t *list)
{
    int n = my_strlen(str);

    for (int i = 0; i <= n - k; i++) {
        char *tmp = malloc(sizeof(char) * k);
        if (!tmp)
            return (NULL);
        list = get_l_mers(&str[i], list, k);
        free(tmp);
    }
    return (list);
}

void print_k_mers(k_mer_t *list)
{
    k_mer_t *tmp = list;

    for (; tmp; tmp = tmp->next) {
        printf("%s\n", tmp->mers);
    }
}

int k_mers(data_t *data)
{
    seq_t *tmp = data->seq;
    k_mer_t *list = NULL;

    for (; tmp; tmp = tmp->next) {
        list = set_k_mers(tmp->seq, data->k, list);
    }
    list = bubblesort(list);
    print_k_mers(list);
    free_data(data);
    free_k_mers(list);
    return (0);
}