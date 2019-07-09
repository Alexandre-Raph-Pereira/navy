/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** Unit Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototype.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(utils, usage_attempt_1)
{
    cr_assert(usage() == 0);
}

Test(error_attempt1, simple_string, .init = redirect_all_std)
{
    char *str = "salut";
    int result = 0;

    result = pos_error_char(str);
    cr_expect_eq(result, 84);
}

Test(error_attempt2, simple_string, .init = redirect_all_std)
{
    char *str = "2:C1:C2\n3:D4:F4\n4:B5:B8\n5:D7:H7\n";
    int result = 0;

    result = pos_error_char(str);
    cr_expect_eq(result, 0);
}

Test(error_attempt3, simple_string, .init = redirect_all_std)
{
    int pid = 0;
    int result = 0;

    result = connection_error(pid);
    cr_expect_eq(result, 84);
}

Test(error_attempt4, simple_string, .init = redirect_all_std)
{
    int e = 0;
    pos_t pos;
    int result = 0;
    char *str = "2:C1:C2\n3:D4:F4\n4:B5:B8\n5:D7:H7\n";

    result = size_boat_e(str, &e, &pos);
    cr_expect_eq(result, 0);
}

Test(error_attempt5, simple_string, .init = redirect_all_std)
{
    int result = 0;
    pos_t pos;

    result = init_error_pos(&pos);
    cr_expect_eq(result, 0);
}

Test(error_attempt6, simple_string, .init = redirect_all_std)
{
    int result = 0;
    char *str = "2:C1:C2";

    result = co_e(str);
    cr_expect_eq(result, 0);
}

Test(error_attempt7, simple_string, .init = redirect_all_std)
{
    int result = 0;
    char *str = "3:D4:F4";

    result = co_e(str);
    cr_expect_eq(result, 0);
}

Test(error_attempt8, simple_string, .init = redirect_all_std)
{
    int result = 0;
    char *str = "4:B5:B8";

    result = co_e(str);
    cr_expect_eq(result, 0);
}

Test(error_attempt9, simple_string, .init = redirect_all_std)
{
    int result = 0;
    char *str = "5:D7:H7";

    result = co_e(str);
    cr_expect_eq(result, 0);
}

Test(error_attempt10, simple_string, .init = redirect_all_std)
{
    int result = 0;
    char *str = "3:D7:H9";

    result = co_e(str);
    cr_expect_eq(result, 84);
}

Test(error_attempt11, simple_string, .init = redirect_all_std)
{
    int result = 0;
    char *str = "2:D7:H9";

    result = co_e(str);
    cr_expect_eq(result, 84);
}
