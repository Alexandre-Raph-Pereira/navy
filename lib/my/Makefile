##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

DOS	=	my_printf.c			\
		my_strcat.c			\
		my_base.c			\
		my_base2.c			\
		my_base3.c			\
		my_putstr.c			\
		my_strstr.c			\
		my_put_nbr.c		\
		my_revstr.c			\
		my_putchar.c		\
		my_strlen.c 		\
		my_strcpy.c 		\
		my_getnbr.c			\
		my_putstr2.c 		\
		my_str.c	\
		my_str_isalpha.c 	\
		get_next_line.c 	\

NAME	=	libmy.a

HEADERS = 	my.h

CFLAGS  =       -I./../../include/ -g3

all:		$(NAME)

$(NAME):	$(NAME)
			gcc -c $(DOS) $(CFLAGS)
			ar rc $(NAME) *.o
			rm -f *.o

clean:
		rm -f *.o

fclean:		clean
		rm -f $(NAME)

re:		fclean all
