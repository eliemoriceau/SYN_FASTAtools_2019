/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** test_word_to_array
*/

#include "my.h"
#include <criterion/criterion.h>

Test(my_word_to_array, test_space)
{
    char *str = "hello les amis";
    char **array = my_word_to_array(' ', str);

    cr_assert_str_eq(array[0], "hello");
    cr_assert_str_eq(array[1], "les");
    cr_assert_str_eq(array[2], "amis");
}