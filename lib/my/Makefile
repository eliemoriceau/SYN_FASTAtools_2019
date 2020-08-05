##
## EPITECH PROJECT, 2019
## PSU_my_printf_2019
## File description:
## Makefile lib
##

SRC 	=		src/my_putchar.c\
				src/my_putnbr.c\
				src/my_put_unsigned.c\
				src/my_strlen.c\
				src/my_putnbr_base.c\
				src/my_strcmp.c\
				src/my_strdump.c\
				src/my_strcpy.c\
				src/my_printf.c\
				src/my_putstr.c\
				src/my_char_isalpha.c\
				src/my_char_isnum.c\
				src/my_char_islower.c\
				src/my_char_isupper.c\
				src/my_show_word_array.c\
				src/my_strupcase.c\
				src/my_char_to_upper.c\
				src/my_word_to_array.c\
				src/my_realloc.c\
				src/my_strcat.c\
				src/my_strncat.c\
				src/my_str_isnum.c\
				src/my_getnbr.c


OBJ		=		$(SRC:%.c=%.o)

CFLAG 	= 		-W -Wshadow -Wextra -I./includes -g

LDFLAGS =

CC 		= 		gcc

NAME 	=		libmy.a

all		: 		$(NAME)

$(NAME)	:		$(OBJ)
				cp -f src/my.h ../../include
				ar rc -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
	  			$(RM) -f $(OBJ)

fclean	:		clean
				$(RM) -f $(NAME)

re		:		fclean all

dbg		:	CFLAGS += -g
dbg		:	re

.PHONY	: 		all fclean re clean
