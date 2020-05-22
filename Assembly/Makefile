##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## test
##

SRC =   $(wildcard src/*.c) \
        $(wildcard ressources/*.c) \
        $(wildcard ../Op/*.c)

CFLAGS  =  -g3 -W -Wall -Wextra -Werror

NAME    =   asm

all: $(NAME)

$(NAME): $(SRC)
	cp libgnl.txt libgnl.a
	gcc $(CFLAGS) -o $(NAME) $(SRC) -L. -lgnl

clean:
	rm -f *.c~
	rm -f \#*\#
	rm -f *.o
	rm -f *.a
	rm -f vgcore*

fclean: clean
	rm -f $(NAME)

re:     fclean all
