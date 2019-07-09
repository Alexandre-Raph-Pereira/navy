/*
** EPITECH PROJECT, 2019
** modif_map.c
** File description:
** modif_map
*/

#include "prototype.h"

int is_not_finish(char **map)
{
    int i = 2;
    int j = 2;
    int nb_x = 0;

    while (j < 10) {
        if (map[j][i] == '\0') {
            j++;
            i = 2;
        }
        if (j < 10 && map[j][i] == 'x')
            nb_x++;
        i++;
    }
    return (nb_x);
}

void modif_map(int result, int nb, dbl_map *map)
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
    if (result == 1) {
        map->enn_map[i][j] = 'x';
        map->nb_hit_enn++;
        my_printf("%s: hit\n\n", map->shot);
    }
    else if (result == 2) {
        map->enn_map[i][j] = 'o';
        my_printf("%s: missed\n\n", map->shot);
    }
}
