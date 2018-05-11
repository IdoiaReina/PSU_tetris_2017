##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=		gcc -g
RM	=		rm -f

SRC	=		src/main.c			\
			src/tetris_src.c		\
			src/check_tetrimino.c		\
			src/tetris_src2.c		\
			src/check_name.c		\
			src/file.c			\
			src/flags_manager.c		\
			src/debug.c			\
			src/display_help.c		\
			src/menu.c			\
			src/menu2.c			\
			src/tetris.c			\
			src/init_tetrimino.c		\
			src/state_tetris.c		\
			src/state_tetris1.c		\
			src/update_tetris1.c		\
			src/update_tetris2.c		\
			src/update_tetris3.c		\
			src/update_tetris4.c		\
			src/update_tetris5.c		\
			src/update_tetris6.c		\
			src/init_tetris.c		\
			src/flags_functions.c		\
			src/flags_functions2.c		\
			src/flags_functions3.c		\
			src/my_revstr.c			\
			src/printoc.c			\
			src/display_debug.c		\
			src/display_debug2.c		\

OBJ	=		$(SRC:.c=.o)

CFLAGS	=		-I./include
##CFLAGS	+=		-Wall -Wextra --coverage

LDFLAGS =		-lncurses

NAME	=		tetris

all:			$(NAME) clean

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
