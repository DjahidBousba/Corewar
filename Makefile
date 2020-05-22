##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

all: asm vm

asm:
	make -C ./Assembly

vm:
	make -C ./VirtualMachine

clean:
	make clean -C ./Assembly
	make clean -C ./VirtualMachine

fclean: clean
	make fclean -C ./Assembly
	make fclean -C ./VirtualMachine

re: fclean all

.PHONY: all clean fclean re
