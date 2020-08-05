##
## EPITECH PROJECT, 2019
## makefile test
## File description:
## makefile for test lib
##

SRC 	=		test_my_putchar.c\
				test_my_putstr.c\
				test_my_putnbr.c\
				test_my_printf.c\
				test_my_putnbr_base.c\
				test_my_put_unsigned.c\
				test_my_word_to_array.c\
				test_my_str_isnum.c\
				test_my_strupcase.c\
				../src/my_putchar.c\
				../src/my_putnbr.c\
				../src/my_putstr.c\
				../src/my_printf.c\
				../src/my_put_unsigned.c\
				../src/my_putnbr_base.c\
				../src/my_strlen.c\
				../src/my_word_to_array.c\
				../src/my_str_isnum.c\
				../src/my_strupcase.c\


CFLAGS	=		-W -Wextra -Wshadow -I../src/ -g

LDFLAGS	=		-lcriterion --coverage -L../ -lmy

NAME	=		unit_tests

CC		=		gcc

all		:		$(NAME)

$(NAME)	:		$(SRC)
				$(CC) -o $(NAME) $(SRC) $(LDFLAGS) $(CFLAGS)


clean	:
				rm -f $(OBJ)
				rm -f *.gcda
				rm -f *.gcno

fclean	:		clean
				rm -f $(NAME)

re		:		fclean all
				./unit_tests || gcovr

.PHONY	:		all clea fclean re