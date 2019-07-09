/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** Usage file
*/

#include "prototype.h"

int usage(void)
{
    my_printf("\e[96m\e[1mUSAGE\n");
    my_printf("\t\t./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n");
    my_printf("\t\tfirst_player_pid: only for the 2nd player.");
    my_printf("pid of the first player.\n");
    my_printf("\t\tnavy_positions:  file representing the ");
    my_printf("positions of the ships.\e[0m\n");
    return (0);
}
