/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf
*/

#include <stdarg.h>
#include "my.h"

void check_flag_base(char flag, va_list print)
{
    switch (flag) {
    case 'o' :
        my_putnbr_base(va_arg(print, int), "01234567");
        break;
    case 'X' :
        my_putnbr_base(va_arg(print, int), "0123456789ABCDEF");
        break;
    case 'x' :
        my_putnbr_base(va_arg(print, int), "0123456789abcdef");
        break;
    default:
        my_putchar('%');
        my_putchar(flag);
        break;
    }
}

void check_flag_num(char flag, va_list print)
{
    switch (flag) {
    case 'd' :
        my_putnbr(va_arg(print, int));
        break;
    case 'i' :
        my_putnbr(va_arg(print, int));
        break;
    case 'u' :
        my_put_unsigned(va_arg(print, unsigned int));
        break;
    default:
        check_flag_base(flag, print);
        break;
    }
}

void check_flag(char flag, va_list print)
{
    switch (flag) {
    case 'c' :
        my_putchar(va_arg(print, int));
        break;
    case 's' :
        my_putstr(va_arg(print, char*));
        break;
    case '%' :
        my_putchar('%');
        break;
    default:
        check_flag_num(flag, print);
        break;
    }
}

int my_printf(const char *format, ...)
{
    int i = 0;
    char flag;
    va_list print;
    int index_arg = 0;

    va_start(print, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            flag = format[i];
            check_flag(flag, print);
        } else if (format[i - 1] != '%') {
            my_putchar(format[i]);
            i++;
        }else
            i++;
    }
    va_end(print);
}
