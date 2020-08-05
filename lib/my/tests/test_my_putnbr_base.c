/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put nbr_base
*/

# include <criterion/criterion.h>
# include <criterion/redirect.h>
# include "my.h"

void redirect_all_stdout(void);

Test(my_putnbr_base, test_octa, .init=redirect_all_stdout)
{
    int nb = 345;

    my_putnbr_base(nb, "01234567");

    cr_assert_stdout_eq_str("531");
}

Test(my_putnbr_base, num_nrg, .init=redirect_all_stdout)
{
    int nb = -345;

    my_putnbr_base(nb, "01234567");

    cr_assert_stdout_eq_str("-531");
}

Test(my_putnbr_base, test_bin, .init=redirect_all_stdout)
{
    int nb = 345;

    my_putnbr_base(nb, "01");

    cr_assert_stdout_eq_str("101011001");
}

Test(my_putnbr_base, test_hexa, .init=redirect_all_stdout)
{
    int nb = 3458;

    my_putnbr_base(nb, "0123456789abcdef");

    cr_assert_stdout_eq_str("d82");
}

Test(my_putnbr_base, test_hexa_upcase, .init=redirect_all_stdout)
{
    int nb = 3458;

    my_putnbr_base(nb, "0123456789ABCDEF");

    cr_assert_stdout_eq_str("D82");
}