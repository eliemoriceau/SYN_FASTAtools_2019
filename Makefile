##
## EPITECH PROJECT, 2019
## tetris
## File description:
## Makefile
##

NAME		=	FASTAtools

SRC			=	src/data.c\
				src/dna.c\
				src/fasta.c\
				src/seq.c\
				src/usage.c\
				src/rna.c\
				src/reverse.c\
				src/k_mers.c\
				src/sort.c\
				src/codon.c\
				src/my_getline.c\
				src/amino_acids.c\
				src/alignment.c\
				src/free_k_mers.c\
				src/needleman_wunsch.c\

test_NAME	=	unit_tests

MAIN 		=	src/main.c

test_SRC	=	$(SRC)							\
				tests/test_init_data.c\
				tests/test_nb_saq.c\
				tests/test_option_1.c\
				tests/test_seq.c\
				tests/test_start.c\
				tests/test_matrix_f.c\
				tests/test_set_value_int.c\
				tests/test_dna_complement.c\
				tests/test_reverse_dna.c\
				tests/test_rna.c\
				tests/test_usage.c\
				tests/test_sort.c\
				tests/test_add_kmers.c\
				tests/test_get_l_mers.c\
				tests/test_codon.c\
				tests/test_amino_acid.c\
				tests/test_data.c\
				tests/test_fasta.c\
				tests/test_alignment.c\
				tests/test_k_mers.c\

OBJ			=	$(SRC:%.c=%.o) $(MAIN:%.c=%.o)

test_OBJ	=	$(test_SRC:%.c=%.o)

INCLUDE		=	-I include

CFLAGS		=	-W -Wall -Wshadow -Wextra $(INCLUDE)

LDFLAGS		=	$(LIB) -L./lib/my -lmy

test_LDFLAGS= 	-lcriterion -lgcov --coverage $(LDFLAGS)

CC			=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) -C lib/my
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			@$(MAKE) -C lib/my clean
			$(RM) $(OBJ)
			$(RM) -f $(test_OBJ)
			$(RM) *.gcda
			$(RM) *.gcno
			$(RM) vgcore.*

fclean:		clean
			@$(MAKE) -C lib/my fclean
			@$(RM) $(NAME)

re:			fclean all
			$(MAKE) -C lib/my re

tests_run:		CFLAGS += -g
tests_run:		$(test_OBJ)
				$(MAKE) -C lib/my
				$(CC) -o $(test_NAME) $(test_SRC) $(test_LDFLAGS) $(CFLAGS)
				./unit_tests

coverage:		clean tests_run
				gcovr -e tests/

branch	:		clean tests_run
				gcovr -e tests/ --branch

dbg		:	CFLAGS += -g
dbg		:	re
			$(MAKE) -C lib/my dbg

.PHONY: all clean fclean re