#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_putnbr_base(int nbr, const char *base);
int displaynbr_base(const int nbr, const int len, const char *base);

Test (my_putnbrbase, should_print)
{
    cr_redirect_stdout();
    my_putnbr_base(0, "0123456789");
    cr_assert_stdout_eq(0);
}

Test (my_putnbrbase, should_printtwo)
{
    cr_redirect_stdout();
    my_putnbr_base(1, "0123456789");
    cr_assert_stdout_eq(1);
}

Test (my_putnbrbase, should_printthree)
{
    cr_redirect_stdout();
    my_putnbr_base(12, "0123456789");
    cr_assert_stdout_eq(12);
}

Test (my_putnbrbase, should_printfour)
{
    cr_redirect_stdout();
    my_putnbr_base(8, "abcdefghij");
    cr_assert_stdout_eq('h');
}

Test (my_putnbrbase, should_printfive)
{
    cr_redirect_stdout();
    my_putnbr_base(-1, "0123456789");
    cr_assert_stdout_eq(-9);
}