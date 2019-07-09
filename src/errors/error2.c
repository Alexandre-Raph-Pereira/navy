/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** second file for error gestion
*/

#include "prototype.h"

int size_boat_e(char *buffer, int *e, pos_t *pos)
{
    int r = 0;

    while (buffer[r]) {
        if (buffer[r] != '2' && buffer[r] != '3' && buffer[r] != '4' &&
            buffer[r] != '5')
            e ++;
        if (buffer[r] == '2')
            pos->p2 ++;
        if (buffer[r] == '3')
            pos->p3 ++;
        if (buffer[r] == '4')
            pos->p4 ++;
        if (buffer[r] == '5')
            pos->p5 ++;
        r += 8;
    }
    return (0);
}

int dia_boat_e(char *buffer, int *e)
{
    int r = 0;

    if (buffer[2] != buffer[5] && buffer[3] != buffer[6])
        (*e) ++;
    if (buffer[10] != buffer[13] && buffer[11] != buffer[14])
        (*e) ++;
    if (buffer[18] != buffer[21] && buffer[19] != buffer[22])
        (*e) ++;
    if (buffer[26] != buffer[29] && buffer[27] != buffer[30])
        (*e) ++;
    if (long_boat_e(buffer) != 0)
        return (84);
    return (0);
}

int init_error_pos(pos_t *pos)
{
    pos->p2 = 0;
    pos->p3 = 0;
    pos->p4 = 0;
    pos->p5 = 0;
    return (0);
}

int buff_error(char *buffer)
{
    int e = 0;
    int r = 0;
    pos_t pos;

    init_error_pos(&pos);
    size_boat_e(buffer, &e, &pos);
    if (dia_boat_e(buffer, &e) != 0)
        return (84);
    if (pos.p2 != 1 || pos.p3 != 1 || pos.p4 != 1 || pos.p5 != 1)
        e ++;
    if (e > 0) {
        my_putstr2("\e[91m\e[1m[Error] Wrong inputs in file :/\e[0m\n");
        return (84);
    }
}
