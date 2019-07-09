/*
** EPITECH PROJECT, 2019
** Minishell 2
** File description:
** Unit Test for project
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototype.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(lib_attempt1, simple_string, .init = redirect_all_std)
{
    char *str = "salut";
    int result = 0;

    result = my_strlen(str);
    cr_expect_eq(result, 5);
}

Test(lib_attempt2, simple_string, .init = redirect_all_std)
{
    char *str = "salut\0 ca va ?";
    int result = 0;

    result = my_strlen(str);
    cr_expect_eq(result, 5);
}

Test(lib_attempt3, simple_string, .init = redirect_all_std)
{
    char *str = "42";
    int result = 0;

    result = my_getnbr(str);
    cr_expect_eq(result, 42);
}

Test(lib_attempt4, simple_string, .init = redirect_all_std)
{
    char *str = "42salutlama";
    int result = 0;

    result = my_getnbr(str);
    cr_expect_eq(result, 42);
}

Test(lib_attempt5, simple_string, .init = redirect_all_std)
{
    char *str = "salutlama42";
    int result = 0;

    result = my_getnbr(str);
    cr_expect_eq(result, 0);
}

Test(lib_attempt6, simple_string, .init = redirect_all_std)
{
    char *str = "lama";
    char *str2 = "lama";
    int result = 0;

    result = my_str(str, str2);
    cr_expect_eq(result, 0);
}

Test(lib_attempt7, simple_string, .init = redirect_all_std)
{
    char *str = "lama";
    char *str2 = "lamascotte";
    int result = 0;

    result = my_str(str, str2);
    cr_expect_eq(result, 0);
}

Test(lib_attempt8, simple_string, .init = redirect_all_std)
{
    char *str = "lama";
    char *str2 = "lamascotte";
    int result = 0;

    result = my_str(str2, str);
    cr_expect_eq(result, 1);
}

Test(asserts, string)
{
    cr_assert_str_empty("");
    cr_assert_str_not_empty("foo");
    cr_assert_str_eq("hello", "hello");
    cr_assert_str_neq("hello", "olleh");
    cr_assert_str_gt("hello", "hell");
    cr_assert_str_geq("hello", "hell");
    cr_assert_str_geq("hello", "hello");
    cr_assert_str_lt("hell", "hello");
    cr_assert_str_leq("hell", "hello");
    cr_assert_str_leq("hello", "hello");
}
