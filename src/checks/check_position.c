/*
** EPITECH PROJECT, 2019
** check_position.c
** File description:
** check_position
*/

#include "prototype.h"

int check_pos(int nb, dbl_map *map)
{
    int i = 0;
    int j = 0;
    int a = 0;

    while (a <= nb) {
        a++;
        j++;
        if (map->my_map[i][j] == '\0') {
            i++;
            j = 0;
        }
    }
    if (map->my_map[i][j] != '.') {
        map->my_map[i][j] = 'x';
        my_printf("%c%c: hit\n\n", map->my_map[0][j], map->my_map[i][0]);
        map->nb_hit++;
        return (1);
    }
    my_printf("%c%c: missed\n\n", map->my_map[0][j], map->my_map[i][0]);
    map->my_map[i][j] = 'o';
    return (2);
}
