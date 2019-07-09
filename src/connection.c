/*
** EPITECH PROJECT, 2019
** connection.c
** File description:
** connection.c
*/

#include "prototype.h"

int pid_recup(int nb)
{
    static int pid;

    if (nb != 0)
        pid = nb;
    return (pid);
}

void connected(int sig, siginfo_t *siginfo, void *context)
{
    my_printf("enemy connected\n\n");
    pid_recup(siginfo->si_pid);
}

void enn_connect(int sig, siginfo_t *siginfo, void *context)
{
    my_printf("successfully connected\n\n");
}

int connection(int *pid, int ac)
{
    struct sigaction connect;
    struct sigaction success;

    connect.sa_sigaction = &connected;
    connect.sa_flags = SA_SIGINFO;
    success.sa_sigaction = &enn_connect;
    success.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &connect, NULL);
    sigaction(SIGUSR2, &success, NULL);
    if (ac == 2) {
        my_printf("waiting for enemy connection...\n\n");
        pause();
        *pid = pid_recup(0);
        kill(*pid, SIGUSR2);
    }
    if (ac == 3) {
        if (kill(*pid, SIGUSR1) == -1)
            return (84);
        pause();
    }
    return (0);
}
