/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** initialisation file
*/

#include "prototype.h"

int init_path(int ac, char **path, char **argv)
{
    if (ac == 2) {
        *path = malloc(sizeof(char) * (my_strlen(argv[1]) + 1));
        if (*path == NULL)
            return (84);
        *path = my_strcpy(*path, argv[1]);
    }
    if (ac == 3) {
        *path = malloc(sizeof(char) * (my_strlen(argv[2]) + 1));
        if (*path == NULL)
            return (84);
        *path = my_strcpy(*path, argv[2]);
    }
    return (0);
}

int init_pid(int ac, int *pid, char **argv)
{
    if (ac == 2)
        (*pid) = getpid();
    if (ac == 3)
        (*pid) = my_getnbr(argv[1]);
    return (0);
}

int init_pos(char *path, dbl_map *map)
{
    char **pos = malloc(sizeof(char *) * 4);
    int fd = open(path, O_RDONLY);

    if (pos == NULL || fd == -1)
        return (84);
    for (int i = 0; i < 4; i ++)
        pos[i] = get_next_line(fd);
    if (init_map(pos, map) == 84)
        return (84);
    return (0);
}

int init(int ac, int *pid, char **path, char **argv)
{
    if (init_path(ac, path, argv) == 84)
        return (84);
    init_pid(ac, pid, argv);
    return (0);
}
