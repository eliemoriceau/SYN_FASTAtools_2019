/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_my_str_isnum
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_str_isnum, test_num)
{
    char *str = "2";
    int res = my_str_isnum(str);

    cr_assert_eq(res, 1);
}

Test(my_str_isnum, test_letter)
{
    char *str = "ka";
    int res = my_str_isnum(str);

    cr_assert_eq(res, 0);
}

Test(my_str_isnum, test_neg_num)
{
    char *str = "-2";
    int res = my_str_isnum(str);

    cr_assert_eq(res, 1);
}