/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct double_map
{
    char **my_map;
    char **enn_map;
    char *shot;
    int nb_hit_enn;
    int nb_hit;
} dbl_map;

typedef struct pos_boat
{
    char num;
    int f_l;
    int f_h;
    int l_l;
    int l_h;
} boat_t;

typedef struct position
{
    int p2;
    int p3;
    int p4;
    int p5;
} pos_t;

#endif /* !STRUCT_H_ */
