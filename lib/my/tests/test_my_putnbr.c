/*
** EPITECH PROJECT, 2019
** CPool_bistromatic_2019
** File description:
** test_my_putnbr
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_putnbr, dispalay1, .init=redirect_all_stdout)
{
    int nb = 1;

    my_putnbr(nb);
    cr_assert_stdout_eq_str("1");
}

Test(my_putnbr, dispalay9, .init=redirect_all_stdout)
{
    int nb = 9;

    my_putnbr(nb);
    cr_assert_stdout_eq_str("9");
}

Test(my_putnbr, dispalay12, .init=redirect_all_stdout)
{
    int nb = 12;

    my_putnbr(nb);
    cr_assert_stdout_eq_str("12");
}

Test(my_putnbr, dispalay100, .init=redirect_all_stdout)
{
    int nb = 100;

    my_putnbr(nb);
    cr_assert_stdout_eq_str("100");
}

Test(my_putnbr, dispalay2456, .init=redirect_all_stdout)
{
    int nb = 2456;

    my_putnbr(nb);
    cr_assert_stdout_eq_str("2456");
}

Test(my_putnbr, dispalay13907, .init=redirect_all_stdout)
{
    int nb = 13907;

    my_putnbr(nb);
    cr_assert_stdout_eq_str("13907");
}

Test(my_putnbr, dispalay0, .init=redirect_all_stdout)
{
    int nb = 0;

    my_putnbr(nb);
    cr_assert_stdout_eq_str("0");
}

Test(my_putnbr, dispalay4000000, .init=redirect_all_stdout)
{
    int nb = 4000000;

    my_putnbr(nb);
    cr_assert_stdout_eq_str("4000000");
}

Test(my_putnbr, dispalay000000, .init=redirect_all_stdout)
{
    int nb = 000000;

    my_putnbr(nb);
    cr_assert_stdout_eq_str("0");
}

Test(my_putnbr, dispalay_neg_89, .init=redirect_all_stdout)
{
    int nb = -89;

    my_putnbr(nb);
    cr_assert_stdout_eq_str("-89");
}