/*
** EPITECH PROJECT, 2019
** answer.c
** File description:
** answer
*/

#include "prototype.h"

int count_answer(int nb, int is_zero)
{
    static int pid = 0;
    static int pid2 = 0;

    if (is_zero > 0) {
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

void counting_answer(int sig, siginfo_t *siginfo, void *context)
{
    count_answer(1, 1);
}

void counting2_answer(int sig, siginfo_t *siginfo, void *context)
{
    count_answer(1, -1);
}

int read_answer(int pid, int nb, dbl_map *map)
{
    int a = 0;
    int result = 0;
    struct sigaction is_touch;
    struct sigaction end;

    sigemptyset(&is_touch.sa_mask);
    sigemptyset(&end.sa_mask);
    is_touch.sa_sigaction = &counting_answer;
    is_touch.sa_flags = SA_SIGINFO;
    end.sa_sigaction = &counting2_answer;
    end.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &is_touch, NULL);
    sigaction(SIGUSR2, &end, NULL);
    while (count_answer(0, -1) == 0)
        pause();
    result = count_answer(0, 1);
    a = count_answer(0, 0);
    count_answer(0, -2);
    return (result);
}

int send_answer(int sig, int pid, dbl_map *map)
{
    int nb = check_pos(sig, map);
    int a = 0;

    usleep(10000);
    while (a != nb) {
        kill(pid, SIGUSR1);
        usleep(10000);
        a++;
    }
    usleep(10000);
    kill(pid, SIGUSR2);
    nb = count_answer(0, 0);
    count_answer(0, -2);
    return (nb);
}
