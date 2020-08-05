/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** usage
*/

#include <stdio.h>

void usage(void)
{
    printf("USAGE\n\
\t./FASTAtools option\n\
DESCRIPTION\n\
\toption 1: read FASTA from the standard input, write the DNA sequences to \
the standard output\n\
\toption 2: read FASTA from the standard input, write the RNA sequences to \
the standard output\n\
\toption 3: read FASTA from the standard input, write the reverse complement \
to the standard output\n\
\toption 4: read FASTA from the standard input, write the k-mer list to the \
standard output\n\
\toption 5: read FASTA from the standard input, write the coding sequences \
list to the standard output\n\
\toption 6: read FASTA from the standard input, write the amino acids list \
to the standard output\n\
\toption 7: read FASTA from the standard input containing exactly 2 squences, \
align them and write the result to the standard output\n\
\tk: size of the k-mers for option 4\n");
}
