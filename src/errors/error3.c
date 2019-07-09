/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** Error Gestion file Three
*/

#include "prototype.h"

int short_e(char *bcp)
{
    int a = bcp[5] - bcp[2];
    int b = my_getnbr(bcp);
    int c = bcp[6] - bcp[3];
    int d = -1 * a;
    int e = -1 * c;

    if (a < 0)
        a = d;
    if (c < 0)
        c = e;
    if (a + 1 < b && c + 1 < b) {
        my_putstr2("\e[91m\e[1m[Error] Too short boat cheater !!!! >:(\e[0m\n");
        return (84);
    }
    return (0);
}

int type_e(char *bcp)
{
    if (bcp[2] < 65 || bcp[2] > 72) {
        my_putstr2("\e[91m\e[1m[Error] Too long boat cheater !!!! >:(\e[0m\n");
        return (84);
    }
    if (bcp[3] < 48 || bcp[3] > 56) {
        my_putstr2("\e[91m\e[1m[Error] Too long boat cheater !!!! >:(\e[0m\n");
        return (84);
    }
    if (bcp[5] < 65 || bcp[5] > 72) {
        my_putstr2("\e[91m\e[1m[Error] Too long boat cheater !!!! >:(\e[0m\n");
        return (84);
    }
    if (bcp[6] < 48 || bcp[6] > 56) {
        my_putstr2("\e[91m\e[1m[Error] Too long boat cheater !!!! >:(\e[0m\n");
        return (84);
    }
    return (0);
}

int co_e(char *bcp)
{
    int a = bcp[5] - bcp[2];
    int b = my_getnbr(bcp);
    int c = bcp[6] - bcp[3];
    int d = -1 * a;
    int e = -1 * c;

    if (a >= b || c >= b) {
        my_putstr2("\e[91m\e[1m[Error] Too long boat cheater !!!! >:(\e[0m\n");
        return (84);
    }
    if (d >= b || e >= b) {
        my_putstr2("\e[91m\e[1m[Error] Too long boat cheater !!!! >:(\e[0m\n");
        return (84);
    }
    return (0);
}

int cuter(char *str)
{
    int r = 0;
    int a = 0;
    char *bcp = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str[r]) {
        while (str[r] != '\n' && str[r] != '\0') {
            bcp[a] = str[r];
            a ++;
            r ++;
        }
        if (co_e(bcp) != 0 || type_e(bcp) != 0 || short_e(bcp) != 0)
            return (84);
        a = 0;
        r ++;
    }
    return (0);
}

int long_boat_e(char *str)
{
    int c = 0;

    while (str[c]) {
        if (str[c] == '9') {
            my_putstr2("\e[91m\e[1m[Error] Too long boat cheater >:(\e[0m\n");
            return (84);
        }
        c ++;
    }
    if (cuter(str) != 0)
        return (84);
    return (0);
}
