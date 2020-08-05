/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** Needleman–Wunsch
*/

#include "fasta.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void free_arrint(int **tab, int size)
{
    for (int i = 0; i <= size; i++)
        free(tab[i]);
    free(tab);
}

int **init_matrix_f(int len1, int len2)
{
    int **matrix_f = (int **)malloc(sizeof(int *) * (len1 + 1));

    for (int i = 0; i <= len1; i++) {
        matrix_f[i] = (int *)malloc(sizeof(int) * (len2 + 1));
        for (int j = 0; j < len2; j++) {
            matrix_f[i][j] = 0;
        }
    }
    matrix_f[0][0] = 0;
    for (int i = 1; i <= len1; i++) {
        matrix_f[i][0] = matrix_f[i - 1][0] + -1;
    }
    for (int i = 1; i <= len2; i++) {
        matrix_f[0][i] = matrix_f[0][i - 1] + -1;
    }
    return (matrix_f);
}

int max3(int x, int y, int z)
{
    if (x > y && x > z)
        return (x);
    else if (y > z && y > x)
        return (y);
    else
        return (z);
}

int needleman_wunsch(char *seq1, char *seq2)
{
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int **matrix_f = init_matrix_f(len1, len2);
    int res = 0;
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            s1 = matrix_f[i - 1][j - 1] + matrix_s(seq1[i - 1], seq2[j - 1]);
            s2 = matrix_f[i - 1][j] + -1;
            s3 = matrix_f[i][j - 1] + -1;
            matrix_f[i][j] = max3(s1, s2, s3);
        }
    }
    res = matrix_f[len1][len2];
    free_arrint(matrix_f, len1);
    return (res);
}
