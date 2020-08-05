/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** test_my_strupcase
*/

#include "my.h"
#include <criterion/criterion.h>

Test(my_strcupcase, 1)
{
    char *str = "catCATGCC TADGACGAAGAGATGCTTTGAATGGRAATGAA";
    cr_assert_str_eq(my_strupcase(str), \
"CATCATGCC TADGACGAAGAGATGCTTTGAATGGRAATGAA");
}