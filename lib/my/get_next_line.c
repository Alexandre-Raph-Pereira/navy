/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "prototype.h"

char *copy_into_str(char *tmp, char *str)
{
    char *temp = malloc(sizeof(char) * (my_strlen(str) + READ_SIZE + 2));
    int i = 0;
    int j = 0;

    if (temp == NULL)
        return (NULL);
    while (str[j] != '\0') {
        temp[j] = str[j];
        j++;
    }
    while (tmp[i] != '\0' && tmp[i] != '\n' && i != READ_SIZE) {
        temp[j] = tmp[i];
        i++;
        j++;
    }
    temp[j] = '\0';
    return (temp);
}

char *copy_end_of_string(char *str, int *line)
{
    int i = 0;
    int u = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 2));

    if (tmp == NULL)
        return (NULL);
    *line = 0;
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    if (str[i] == '\n')
        i++;
    while (str[i] != '\0' ) {
        tmp[u] = str[i];
        if (str[i] == '\n')
            *line = 1;
        u++;
        i++;
    }
    tmp[u] = '\0';
    return (tmp);
}

char *read_function(char *str, char *tmp, int fd)
{
    free(tmp);
    tmp = malloc(sizeof(char) * (READ_SIZE + 2));
    if (read(fd, tmp, READ_SIZE) == 0 || tmp == NULL)
        return (str);
    tmp[READ_SIZE] = '\0';
    str = copy_into_str(tmp, str);
    return (str);
}

char *get_next_line(int fd)
{
    char *str = malloc(sizeof(char) * (READ_SIZE + 2));
    char *tmp = malloc(sizeof(char) * (READ_SIZE + 2));
    static char *str_2 = NULL;
    static int line = 0;

    if (str == NULL || tmp == NULL || fd < 0)
        return (NULL);
    str[0] = '\0';
    if (str_2 != NULL) {
        str = copy_into_str(str_2, str);
        if (line == 1) {
            str_2 = copy_end_of_string(str_2, &line);
            return (str);
        }
    }
    if (read(fd, tmp, READ_SIZE) == 0)
        return (NULL);
    tmp[READ_SIZE] = '\0';
    str = copy_into_str(tmp, str);
    while (my_strstr(tmp, "\n") == 0)
        str = read_function(str, tmp, fd);
    str_2 = copy_end_of_string(tmp, &line);
    return (str);
}
