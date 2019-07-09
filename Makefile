##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## My_Sokoban
##

SRC =   src/main.c					\
		src/answer.c				\
		src/checks/check_doss.c		\
		src/checks/check_position.c	\
		src/connection.c			\
		src/disp_map.c				\
		src/errors/error.c			\
		src/errors/error2.c			\
		src/errors/error3.c			\
		src/file_boat.c				\
		src/game_loop.c				\
		src/inits/init_stats.c		\
		src/inits/init_map.c		\
		src/modif_map.c				\
		src/read_action.c			\
		src/send_message.c			\
		src/sleep.c					\
		src/usage.c					\

SRCC =	tests/test_lib.c		\
		tests/test_project.c	\
		src/answer.c				\
		src/checks/check_doss.c		\
		src/checks/check_position.c	\
		src/connection.c			\
		src/disp_map.c				\
		src/errors/error.c			\
		src/errors/error2.c			\
		src/errors/error3.c			\
		src/file_boat.c				\
		src/game_loop.c				\
		src/inits/init_stats.c		\
		src/inits/init_map.c		\
		src/modif_map.c				\
		src/read_action.c			\
		src/send_message.c			\
		src/sleep.c					\
		src/usage.c					\

OBJ =	$(SRC:.c=.o)

OBJC =	$(SRCC:.c=.o)

NAME =	navy

LIB = -L./lib/my -lmy

CRIT = --coverage -lcriterion

WALL = -Wall -Wextra -Werror

CFLAGS  = -I./include/ -L./lib/my/ -lmy

FLAG_T  =       --coverage -lcriterion

CRITERION = unit_tests

VALGRIND = -g3

all:	$(NAME)

$(NAME):	$(OBJ)
			make -C ./lib/my
			gcc -o $(NAME) $(OBJ) $(CFLAGS)
			rm -f $(OBJ)
			rm -f ../lib/my/libmy.a
			rm -f lib/my/libmy.a

exe:		$(NAME)
			clear
			./$(NAME) $(ARGUMENTS)

valgrind:	$(OBJ)
			make -C ./lib/my
			gcc -o $(NAME) $(OBJ) $(LIB) $(CUR) $(VALGRIND)
			rm -f $(OBJ)
			valgrind ./$(NAME) $(ARGUMENTS)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my

fclean:	clean
		rm -f $(NAME)
		rm -f ../lib/my/libmy.a
		rm -f lib/my/libmy.a
		make fclean -C ./lib/my

re: fclean all

error:		$(NAME)
			clear
			./$(NAME) wpos

tests_run:	$(OBJC)
			make -C ./lib/my
			gcc -o $(CRITERION) $(SRCC) $(CFLAGS) $(LIB) $(FLAG_T)
			./$(CRITERION)

tclean:	fclean
		rm -f $(CRITERION)
		rm -f *gcno
		rm -f *gcda
