/*
** EPITECH PROJECT, 2019
** init_map.c
** File description:
** init_map
*/

#include "prototype.h"

void file_first_line(dbl_map *map)
{
    int j = 0;
    int i = 2;
    char l = 'A';

    while (i < 17) {
        if (j == 0) {
            map->my_map[0][i] = l;
            map->enn_map[0][i] = l;
            l++;
            j = 1;
        }
        else if (j == 1) {
            map->my_map[0][i] = ' ';
            map->enn_map[0][i] = ' ';
            j = 0;
        }
        i++;
    }
}

void file_line(dbl_map *map, int j)
{
    int i = 2;
    int t = 0;

    while (i < 17) {
        if (t == 0) {
            map->my_map[j][i] = '.';
            map->enn_map[j][i] = '.';
            t = 1;
        }
        else if (t == 1) {
            map->my_map[j][i] = ' ';
            map->enn_map[j][i] = ' ';
            t = 0;
        }
        i++;
    }
    map->my_map[j][i] = '\0';
    map->enn_map[j][i] = '\0';
}

int file_rest_of_map(dbl_map *map)
{
    int j = 2;
    char l = '1';

    while (j < 10) {
        map->my_map[j] = malloc(sizeof(char) * 18);
        map->enn_map[j] = malloc(sizeof(char) * 18);
        if (map->my_map[j] == NULL || map->enn_map[j] == NULL)
            return (84);
        map->my_map[j][0] = l;
        map->my_map[j][1] = '|';
        map->enn_map[j][0] = l;
        map->enn_map[j][1] = '|';
        file_line(map, j);
        l++;
        j++;
    }
    return (0);
}

int init_first_second_line(dbl_map *map)
{
    map->my_map[0] = malloc(sizeof(char) * 18);
    map->enn_map[0] = malloc(sizeof(char) * 18);
    map->my_map[1] = malloc(sizeof(char) * 18);
    map->enn_map[1] = malloc(sizeof(char) * 18);
    if (map->enn_map[0] == NULL || map->my_map[0] == NULL ||
        map->enn_map[1] == NULL || map->my_map[1] == NULL)
        return (84);
    my_strcpy(map->my_map[0], " |");
    my_strcpy(map->enn_map[0], " |");
    my_strcpy(map->my_map[1], "-+");
    my_strcpy(map->enn_map[1], "-+");
    my_strcat(map->enn_map[1], "---------------");
    my_strcat(map->my_map[1], "---------------");
    map->my_map[0][17] = '\0';
    map->my_map[1][17] = '\0';
    map->enn_map[0][17] = '\0';
    map->enn_map[1][17] = '\0';
    file_first_line(map);
    return (0);
}

int init_map(char **pos, dbl_map *map)
{
    map->enn_map = malloc(sizeof(char *) * 10);
    map->my_map = malloc(sizeof(char *) * 10);
    map->nb_hit_enn = 0;
    map->nb_hit = 0;

    if (map->enn_map == NULL || map->my_map == NULL)
        return (84);
    if (init_first_second_line(map) == 84)
        return (84);
    if (file_rest_of_map(map) == 84)
        return (84);
    file_boat(pos, map);
    return (0);
}
