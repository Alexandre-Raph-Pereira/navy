/*
** EPITECH PROJECT, 2019
** file_boat.c
** File description:
** file_boat.c
*/

#include "prototype.h"

void place_boat(dbl_map *map, boat_t boat, int d, int l)
{
    int j = boat.f_h + 1;
    int i = (boat.f_l * 2) + 2;
    int lengh = boat.num - 48;

    if (boat.f_h == boat.l_h) {
        while (l < (lengh * 2)) {
            map->my_map[j][i] = boat.num;
            i = i + d;
            l = l + 2;
        }
    }
    if (boat.f_l == boat.l_l) {
        while (l < lengh) {
            map->my_map[j][i] = boat.num;
            j = j + d;
            l++;
        }
    }
}

int calc_dep(boat_t boat)
{
    int d = 0;

    if (boat.f_h == boat.l_h) {
        if (boat.f_l > boat.l_l)
            d = -2;
        else if (boat.f_l < boat.l_l)
            d = 2;
    }
    if (boat.f_l == boat.l_l) {
        if (boat.f_h > boat.l_h)
            d = -1;
        else if (boat.f_h < boat.l_h)
            d = 1;
    }
    return (d);
}

void file_boat(char **pos, dbl_map *map)
{
    int j = 0;
    int d = 0;
    int l = 0;
    boat_t boat;

    while (j < 4) {
        boat.num = pos[j][0];
        boat.f_l = pos[j][2] - 65;
        boat.f_h = pos[j][3] - 48;
        boat.l_l = pos[j][5] - 65;
        boat.l_h = pos[j][6] - 48;
        d = calc_dep(boat);
        place_boat(map, boat, d, l);
        j++;
    }
}