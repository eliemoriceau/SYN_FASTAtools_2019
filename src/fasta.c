/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** fasta
*/

#include <string.h>
#include <stdlib.h>
#include "fasta.h"
#include "my.h"

void free_seq(seq_t *link)
{
    if (link) {
        if (link->next)
            free_seq(link->next);
        free(link->id);
        free(link->seq);
        free(link);
    }
}

void free_data(data_t *data)
{
    if (data->seq)
        free_seq(data->seq);
    free(data);
}

int fastatools(data_t *data)
{
    data->seq = set_data();

    switch (data->option) {
    case 1:
        return (dna(data));
    case 2:
        return (rna(data));
    case 3:
        return (reverse(data));
    case 4:
        return (k_mers(data));
    case 5:
        return (codon(data));
    case 6:
        return (amido_acids(data));
    case 7:
        return (alignment(data));
    default:
        return (84);
    }
}

int check_arg(int ac, char const **av)
{
    if (ac < 2 || ac > 3)
        return (84);
    if (strcmp(av[1], "-h") == 0) {
        usage();
        exit(0);
    }
    return (0);
}

int start(int ac, char const **av)
{
    data_t *data = init_data();
    int rtn = 84;

    if (check_arg(ac, av) == 84)
        return (rtn);
    data->option = my_getnbr(av[1]);
    if (data->option < 1 || data->option > 7) {
        free_data(data);
        return (rtn);
    }
    if (data->option == 4) {
        if (av[2] == NULL || !my_str_isnum(av[2])) {
            free_data(data);
            return (rtn);
        }
        data->k = my_getnbr(av[2]);
    }
    rtn = fastatools(data);
    return (rtn);
}
