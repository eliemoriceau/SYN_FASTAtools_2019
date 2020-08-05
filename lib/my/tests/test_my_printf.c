/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** test_my_printf
*/

# include <criterion/criterion.h>
# include <criterion/redirect.h>
# include "my.h"

void redirect_all_stdout(void);

Test(my_printf, simple_string, .init=redirect_all_stdout)
{
    my_printf(" hello world ");
    cr_assert_stdout_eq_str(" hello world ");
}

Test(my_printf, simple_str, .init=redirect_all_stdout)
{
    char *str = "world";

    my_printf(" hello %s", str);
    cr_assert_stdout_eq_str(" hello world");
}

Test(my_printf, nbr, .init=redirect_all_stdout)
{
    int nbr = 12;

    my_printf("%i", nbr);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, simple_nbr_str, .init=redirect_all_stdout)
{
    int nbr = 12;
    char *str = "world";

    my_printf(" hello %i %s", nbr, str);
    cr_assert_stdout_eq_str(" hello 12 world");
}

Test(my_printf, simple_nbr_HEXA, .init=redirect_all_stdout)
{
    int nbr = 12;

    my_printf(" %x ", nbr);
    cr_assert_stdout_eq_str(" c ");
}

Test(my_printf, simple_nbr_hexa, .init=redirect_all_stdout)
{
    int nbr = 12;

    my_printf(" %X ", nbr);
    cr_assert_stdout_eq_str(" C ");
}

Test(my_printf, simple_nbr_octa, .init=redirect_all_stdout)
{
    int nbr = 12;

    my_printf(" %o ", nbr);
    cr_assert_stdout_eq_str(" 14 ");
}

Test(my_printf, simple_double_modulo, .init=redirect_all_stdout)
{
    int nbr = 12;

    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, simple_four_modulo, .init=redirect_all_stdout)
{
    int nbr = 12;

    my_printf("%%%%");
    cr_assert_stdout_eq_str("%%");
}

Test(my_printf, born_inf_d_i, .init=redirect_all_stdout)
{
    int nbr = -2147483648;

    my_printf("%d", nbr);
    cr_assert_stdout_eq_str("-2147483648");
}

Test(my_printf, space_beetwen_flag_modulo, .init=redirect_all_stdout)
{
    int nbr = -2147483648;

    my_printf("%   d", nbr);
    cr_assert_stdout_eq_str("-2147483648");
}

Test(my_printf, born_sup_d_i, .init=redirect_all_stdout)
{
    int nbr = 2147483647;

    my_printf("%d", nbr);
    cr_assert_stdout_eq_str("2147483647");
}

Test(my_printf, string_num, .init=redirect_all_stdout)
{
    int nbr = 2147483647;
    char *str = "hello";

    my_printf("%s%d", str, nbr);
    cr_assert_stdout_eq_str("hello2147483647");
}

Test(my_printf, string_num2, .init=redirect_all_stdout)
{
    int nbr = 2147483647;
    char *str = "hello";

    my_printf("%s%34", str, nbr);
    cr_assert_stdout_eq_str("hello");
}