/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** error gestion
*/

#include "prototype.h"

int glob_error(char *path, int pid)
{
    if (check_doss(path) == 84)
        return (84);
    if (pos_error(path) != 0)
        return (84);
    if (connection_error(pid) != 0)
        return (84);
    return (0);
}

int pos_error_char(char *buffer)
{
    int a = 0;

    while (buffer[a] != '\0') {
        if ((buffer[a] < 48 || buffer[a] > 57) &&
            (buffer[a] < 65 || buffer[a] > 90) &&
            buffer[a] != '\n' && buffer[a] != ':') {
            my_putstr2("\e[91m\e[1m[Error] Wrong inputs in file :/\e[0m\n");
            return (84);
        }
        a ++;
    }
    return (0);
}

int pos_error(char *path)
{
    int fd = open(path, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 32);
    char *str = NULL;

    if (fd == -1) {
        my_putstr2("\e[91m\e[1m[Error] Wrong file\e[0m\n");
        return (84);
    }
    str = get_next_line(fd);
    while (str != NULL) {
        buffer = my_strcat(buffer, str);
        buffer = my_strcat(buffer, "\n");
        str = get_next_line(fd);
    }
    buffer[my_strlen(buffer) - 1] = '\0';
    if (buff_error(buffer) != 0 || pos_error_char(buffer) != 0)
        return (84);
    return (0);
}

int connection_error(int pid)
{
    if (pid == 0) {
        my_putstr2("\e[91m\e[1m[Error] Wrong pid\e[0m\n");
        return (84);
    }
    return (0);
}
