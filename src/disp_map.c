/*
** EPITECH PROJECT, 2019
** disp_map.c
** File description:
** disp_map
*/

#include "prototype.h"

void disp_map(char **map)
{
    int i = 0;

    while (i < 10) {
        my_printf("%s\n", map[i]);
        i++;
    }
}

void disp_all(dbl_map *map)
{
    my_printf("my positions:\n");
    disp_map(map->my_map);
    my_printf("\n");
    my_printf("enemy’s positions:\n");
    disp_map(map->enn_map);
    my_printf("\n");
}
