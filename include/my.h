/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#define ERROR 84
#define SUCSESS 0
#define TRUE 1
#define FALSE 0

int my_printf(const char *format, ...);
void my_putchar(char c);
void my_putstr(char const *str);
void my_put_unsigned(unsigned int nb);
void my_putnbr(int nb);
int my_putnbr_base(int nb, char *base);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strdump(char const *src);
char *my_strcpy(char *dest, char const *src);
int my_show_word_array(char * const *tab);
int my_char_isupper(char c);
int my_char_islower(char c);
int my_isalpha(char c);
int my_char_isnum(char c);
char **my_word_to_array(char separator, char *str);
char my_char_to_upper(char const c);
char *my_strupcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_realloc(char *str, int size);
char *my_strcat(char *dest, char *src);
int my_str_isnum(char const *str);
int my_getnbr(char const *str);

#endif /* !MY_H_ */
