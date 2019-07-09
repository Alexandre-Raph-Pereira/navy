/*
** EPITECH PROJECT, 2019
** read_action.c
** File description:
** read_action
*/

#include "prototype.h"

int check_str(char *str, dbl_map map, int *nb)
{
    int x = 0;
    int y = 0;

    if (str == NULL) {
        *nb = 169;
        return (169);
    }
    if (my_strlen(str) != 2)
        return (0);
    if ((str[0] > 'H' || str[0] < 'A') ||
        (str[1] > '8' || str[1] < '1'))
        return (0);
    x = (str[0] - 65) * 2 + 2;
    y = (str[1] - 48) + 1;
    if (map.enn_map[y][x] == 'o' || map.enn_map[y][x] == 'x')
        return (0);
    return (1);
}

int convert_position(char *str, dbl_map map)
{
    int x = str[0] - 65;
    int y = str[1] - 48 + 2;
    int nb = 0;

    nb = (y - 1) * 17 + x * 2 + 1;
    return (nb);
}

int read_action(dbl_map *map)
{
    int nb = 0;

    map->shot = NULL;
    while (nb == 0) {
        my_printf("attack: ");
        map->shot = get_next_line(0);
        if (check_str(map->shot, *map, &nb) == 0)
            my_printf("wrong position\n");
        else if (nb == 0)
            nb = convert_position(map->shot, *map);
    }
    return (nb);
}
