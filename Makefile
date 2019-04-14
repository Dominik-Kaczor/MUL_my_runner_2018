##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my_hunter
##

SRC	=	src/main.c	\
		src/my_putstr.c	\
		src/my_putchar.c	\
		src/tools_runner.c	\
		src/display_runner.c	\
		src/movment.c	\
		src/creation_runner.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) -lcsfml-window -lcsfml-graphics	\
		-lcsfml-system -lcsfml-audio

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
