/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** amino_acids
*/

#include "fasta.h"
#include "my.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char get_letter_acid(char *codon)
{
    char codon_list[64][3] = {"GCT", "GCC", "GCA", "GCG", "TGT", "TGC", "GAT", \
"GAC", "GAA", "GAG", "TTT", "TTC", "GGT", "GGC", "GGA", "GGG", "CAT", \
"CAC", "ATT", "ATC", "ATA", "AAA", "AAG", "TTA", "TTG", "CTT", "CTC", \
"CTA", "CTG", "ATG", "AAT", "AAC", "CCT", "CCC", "CCA", "CCG", "CAA", \
"CAG", "AGA", "AGG", "CGT", "CGC", "CGA", "CGG", "TCT", "TCC", "TCA", \
"TCG", "AGT", "AGC", "ACT", "ACC", "ACA", "ACG", "GTT", "GTC", "GTA", \
"GTG", "TGG", "TAT", "TAC", "TAA", "TAG", "TGA"};
    char *acids = "AAAACCDDEEFFGGGGHHIIIKKLLLLLLMNNPPPPQQRRRRRRSSSSSSTTTTVVVVWY\
YOOO";
    for (int i = 0; i < 65; i++) {
        if (strncmp(codon, codon_list[i], 3) == 0)
            return (acids[i]);
    }
    return ('X');
}

k_mer_t *get_acids(char *seq, k_mer_t *list)
{
    int size = my_strlen(seq) / 3;
    char *acid = malloc(sizeof(char) * (size + 1));
    k_mer_t *new = malloc(sizeof(k_mer_t));
    int j = 0;

    if (!acid || !new)
        return (NULL);
    for (int i = 0; seq[i]; i += 3, j++) {
        acid[j] = get_letter_acid(&seq[i]);
    }
    acid[j] = '\0';
    new->mers = strdup(acid);
    new->next = NULL;
    free(acid);
    if (!list) {
        list = new;
        return (list);
    }
    list = add_mers(list, new);
    return (list);
}

int amido_acids(data_t *data)
{
    k_mer_t *codon_seq = NULL;
    seq_t *tmp = data->seq;
    k_mer_t *acids = NULL;
    char *rev;

    for (; tmp; tmp = tmp->next) {
        codon_seq = search_codon(tmp->seq, codon_seq);
        rev = reverse_dna(tmp->seq);
        codon_seq = search_codon(rev, codon_seq);
        free(rev);
    }
    for (; codon_seq; codon_seq = codon_seq->next) {
        acids = get_acids(codon_seq->mers, acids);
    }
    bubblesort(acids);
    print_k_mers(acids);
    free_k_mers(codon_seq);
    free_k_mers(acids);
    free_data(data);
    return (0);
}