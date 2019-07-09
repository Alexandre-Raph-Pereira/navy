/*
** EPITECH PROJECT, 2019
** send_message.c
** File description:
** send_message
*/

#include "prototype.h"

int counter(int nb, int is_zero)
{
    static int pid = 0;
    static int pid2 = 0;

    if (is_zero > 0){
        pid = pid + nb;
        return (pid);
    }
    if (is_zero == 0) {
        pid = 0;
        return (pid);
    }
    if (is_zero == -1) {
        pid2 = pid2 + nb;
        return (pid2);
    }
    if (is_zero == -2) {
        pid2 = 0;
        return (pid2);
    }
    return (pid);
}

void counting(int sig, siginfo_t *siginfo, void *context)
{
    counter(1, 1);
}

void counting2(int sig, siginfo_t *siginfo, void *context)
{
    counter(1, -1);
}

int send_message(int pid, int nb, dbl_map *map)
{
    int a = 0;

    usleep(10000);
    while (a != nb) {
        kill(pid, SIGUSR1);
        usleep(5000);
        a++;
    }
    usleep(10000);
    kill(pid, SIGUSR2);
    counter(0, 0);
    counter(0, -2);
    return (0);
}

int receive_message(int pid, dbl_map *map)
{
    int nb = 0;
    int a = 0;
    struct sigaction is_touch;
    struct sigaction end;

    my_printf("waiting for enemy's attack...\n");
    sigemptyset(&is_touch.sa_mask);
    sigemptyset(&end.sa_mask);
    is_touch.sa_sigaction = &counting;
    is_touch.sa_flags = SA_SIGINFO;
    end.sa_sigaction = &counting2;
    end.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &is_touch, NULL);
    sigaction(SIGUSR2, &end, NULL);
    while (counter(0, -1) == 0)
        pause();
    nb = counter(0, 1);
    counter(0, 0);
    counter(0, -2);
    return (nb);
}
