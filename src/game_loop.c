/*
** EPITECH PROJECT, 2019
** game_loop.c
** File description:
** game_loop
*/

#include "prototype.h"

int mid_game_verification(dbl_map *map)
{
    if (is_not_finish(map->enn_map) == 14) {
        return (1);
    }
    if (is_not_finish(map->my_map) == 14) {
        return (2);
    }
    return (0);
}

int player_1(dbl_map *map, int pid)
{
    int nb = 0;
    int result = 0;
    int ver = 0;

    nb = read_action(map);
    send_message(pid, nb, map);
    if (nb == 169)
        return (3);
    result = read_answer(pid, nb, map);
    modif_map(result, nb, map);
    ver = mid_game_verification(map);
    if (ver != 0) {
        disp_all(map);
        return (ver);
    }
    nb = receive_message(pid, map);
    if (nb == 169)
        return (3);
    send_answer(nb, pid, map);
    disp_all(map);
    return (0);
}

int player_2(dbl_map *map, int pid)
{
    int result = 0;
    int nb = 0;
    int ver = 0;

    nb = receive_message(pid, map);
    if (nb == 169)
        return (3);
    send_answer(nb, pid, map);
    ver = mid_game_verification(map);
    if (ver != 0) {
        disp_all(map);
        return (ver);
    }
    nb = read_action(map);
    send_message(pid, nb, map);
    if (nb == 169)
        return (3);
    result = read_answer(pid, nb, map);
    modif_map(result, nb, map);
    disp_all(map);
    return (0);
}

int game_loop(int play, int pid, dbl_map *map)
{
    int nb;

    if (play == 1) {
        if (is_not_finish(map->my_map) == 14)
            return (2);
        if (is_not_finish(map->enn_map) == 14)
            return (1);
        nb = player_1(map, pid);
        if (nb != 0)
            return (nb);
    }
    if (play == 0) {
        if (is_not_finish(map->my_map) == 14)
            return (2);
        if (is_not_finish(map->enn_map) == 14)
            return (1);
        nb = player_2(map, pid);
        if (nb != 0)
            return (nb);
    }
    return (0);
}
