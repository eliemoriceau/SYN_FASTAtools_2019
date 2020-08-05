/*
** EPITECH PROJECT, 2019
** CPool_bistromatic_2019
** File description:
** test function my_putchar
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

Test(my_putchar, one_lowchar, .init=redirect_all_stdout)
{
    my_putchar('c');
    cr_assert_stdout_eq_str("c");
}

Test(my_putchar, one_upchar, .init=redirect_all_stdout)
{
    my_putchar('C');
    cr_assert_stdout_eq_str("C");
}

Test(my_putchar, one_numchar, .init=redirect_all_stdout)
{
    my_putchar('1');
    cr_assert_stdout_eq_str("1");
}