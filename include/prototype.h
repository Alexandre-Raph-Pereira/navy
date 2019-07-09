/*
** EPITECH PROJECT, 2018
** prototype.h
** File description:
** HEADER
*/

#ifndef MY_PROTO_H
#define MY_PROTO_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include "my.h"
#include "my_printf.h"
#include "get_next_line.h"
#include "struct.h"

int game_loop(int play, int pid, dbl_map *map);
void disp_all(dbl_map *map);
int my_printf(char *str, ...);
int glob_error(char *path, int pid);
int pos_error(char *pathfile);
int connection_error(int pid);
int buff_error(char *buffer);
int init(int ac, int *pid, char **path, char **argv);
int init_map(char **pos, dbl_map *map);
int init_pos(char *path, dbl_map *map);
int connection(int *pid, int ac);
char *get_next_line(int fd);
void disp_map(char **map);
void file_boat(char **pos, dbl_map *map);
int read_action(dbl_map *map);
int receive_message(int pid, dbl_map *map);
int send_message(int pid, int nb, dbl_map *map);
int send_answer(int sig, int pid, dbl_map *map);
int check_pos(int nb, dbl_map *map);
int read_answer(int pid, int nb, dbl_map *map);
int is_not_finish(char **map);
void modif_map(int result, int nb, dbl_map *map);
int usage();
int check_doss(char *path);
int long_boat_e(char *str);
int pos_error_char(char *buffer);
int size_boat_e(char *buffer, int *e, pos_t *pos);
int dia_boat_e(char *buffer, int *e);
int buff_error(char *buffer);
int init_error_pos(pos_t *pos);
int co_e(char *bcp);
#endif /* ! MY_PROTO_H */
