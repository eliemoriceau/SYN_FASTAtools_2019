/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** test_my_putstr
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

Test(my_putstr, char_alpha, .init=redirect_all_stdout)
{
    char *str = "azertyuiopqsdfghjklmwxcvbn";

    my_putstr(str);
    cr_assert_stdout_eq_str(str);
}

Test(my_putstr, dispalay_digit, .init=redirect_all_stdout)
{
    char *str = "1234567890";

    my_putstr(str);
    cr_assert_stdout_eq_str(str);
}

Test(my_putstr, dispalay_special_cases, .init=redirect_all_stdout)
{
    char *str = "&#\\@*";

    my_putstr(str);
    cr_assert_stdout_eq_str(str);
}