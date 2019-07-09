/*
** EPITECH PROJECT, 2019
** Navy SEALS !!!
** File description:
** the fucking main guy
*/

#include "prototype.h"

int loop(int nb, int pid, dbl_map map, int ac)
{
    int player = nb;
    int a = 0;

    disp_all(&map);
    while (a == 0) {
        a = game_loop(nb, pid, &map);
    }
    if (a == 1)
        my_printf("\e[32m\e[1mI won\e[0m\n");
    if (a == 2)
        my_printf("\e[95m\e[1mennemy won\e[0m\n");
    if (a == 3)
        a = 0;
    return (a);
}

int navy(int ac, char **argv)
{
    int pid = 0;
    char *path = NULL;
    dbl_map map;

    if (init(ac, &pid, &path, argv) == 84)
        return (84);
    if (glob_error(path, pid) != 0)
        return (84);
    if (init_pos(path, &map) == 84)
        return (84);
    my_printf("my_pid: %d\n", getpid());
    if (connection(&pid, ac) == 84)
        return (84);
    if (ac == 2)
        return (loop(1, pid, map, ac));
    else if (ac == 3)
        return (loop(0, pid, map, ac));
}

int main(int ac, char **argv)
{
    if (ac > 1 && my_str("-h", argv[1]) == 0) {
        usage();
        return (0);
    }
    if (ac != 2 && ac != 3 || argv[1][0] == '-' && argv[1][1] == '1') {
        my_putstr2("\e[91m\e[1mWrong Arguments :/\e[0m\n");
        return (84);
    }
    else
        return (navy(ac, argv));
}
