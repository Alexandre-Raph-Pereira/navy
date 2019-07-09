/*
** EPITECH PROJECT, 2019
** sleep.c
** File description:
** sleep
*/

#include "prototype.h"

void init_sleep(struct timespec *nano, struct timespec *t2)
{
    nano->tv_sec = 0;
    nano->tv_nsec = 50000000;
    t2->tv_sec = 0;
    t2->tv_nsec = 50000000;
}