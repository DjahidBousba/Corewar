##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## test
##

SRC	=	./src/*.c \
		./ressources/*.c \
		../OP/op.c \
		./graphique/*.c

CFLAGS 	= 	-g3 -Werror -Wextra -W

NAME	=	corewar

all: $(NAME)

$(NAME): $(SRC)
	gcc $(CFLAGS) -o $(NAME) $(SRC) -lcurses -lncurses
clean:
	rm -f *.c~
	rm -f \#*\#
	rm -f *.o
	rm -f vgcore*

fclean: clean
	rm -f $(NAME)

re:     fclean all
