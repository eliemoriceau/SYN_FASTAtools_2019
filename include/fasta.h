/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** fasta
*/

#ifndef FASTA_H_
#define FASTA_H_

typedef struct seq_s {
    char *id;
    char *seq;
    struct seq_s *next;
} seq_t;

typedef struct data_s {
    int option;
    int k;
    seq_t *seq;
} data_t;

typedef struct k_mers_s {
    char *mers;
    struct k_mers_s *next;
} k_mer_t;



seq_t *add_seq(seq_t *seq, seq_t *new);
seq_t *init_seq(void);
data_t *init_data(void);
int start(int ac, char const **av);
data_t *init_data(void);
void usage(void);
char *my_getline(void);
void free_seq(seq_t *seq);
int check_arg(int ac, char const **av);
void free_k_mers(k_mer_t *link);
void free_seq(seq_t *seq);
void free_data(data_t *data);

/* Data */
seq_t *get_data(char *line);
seq_t *set_data(void);
int is_valid_char(char c);
char *format_seq(char *str);

/* DNA */
int dna(data_t *data);

/* RNA */
int rna(data_t *data);
void print_rna(char *str);

/* Reverse */
char dna_complement(char c);
int reverse(data_t *data);
char *reverse_dna(char *seq);
void print_reverse(char *str);

/* k_mers */
int k_mers(data_t *data);
void print_k_mers(k_mer_t *list);
k_mer_t *get_l_mers(char *str, k_mer_t *list, int k);
k_mer_t *set_k_mers(char *str, int k, k_mer_t *list);
k_mer_t *add_mers(k_mer_t *list, k_mer_t *new);
k_mer_t *bubblesort(k_mer_t *list);

/* Codon */
int codon(data_t *data);
k_mer_t *search_codon(char *seq, k_mer_t *list);
int is_codon_end(char *codon);
k_mer_t *get_codon_seq(char *str, int size, k_mer_t *list);
k_mer_t *set_codon(char *str, k_mer_t *list);

/* Amido_acids */
int amido_acids(data_t *data);
char get_letter_acid(char *codon);
k_mer_t *get_acids(char *seq, k_mer_t *list);

/* Alignement */
int nb_seq(seq_t *liste);
int alignment(data_t *data);
int calc_alignment(char *seq1, char *seq2);
int matrix_s(char a, char b);
int set_value_int(char c);

int needleman_wunsch(char *seq1, char *seq2);

#endif /* !FASTA_H_ */
