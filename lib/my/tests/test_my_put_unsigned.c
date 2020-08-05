/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** test_put_unsigned
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_stdout(void);

Test(my_put_unsigned, big_num, .init=redirect_all_stdout)
{
    unsigned int num = 12341556;

    my_put_unsigned(num);
    cr_assert_stdout_eq_str("12341556");
}

Test(my_put_unsigned, big_num_two, .init=redirect_all_stdout)
{
    unsigned int num = 984473672;

    my_put_unsigned(num);
    cr_assert_stdout_eq_str("984473672");
}