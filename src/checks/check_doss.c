/*
** EPITECH PROJECT, 2019
** check_doss.c
** File description:
** check_doss
*/

#include "prototype.h"

int check_doss(char *path)
{
    int fd = open(path, O_RDONLY);
    char *str;
    size_t s = 9;

    if (fd < 0)
        return (0);
    str = malloc(sizeof(char) * 10);
    if (str == NULL)
        return (84);
    if (read(fd, str, s) == -1) {
        close(fd);
        return (84);
    }
    if (close(fd) == -1)
        return (84);
    return (0);
}