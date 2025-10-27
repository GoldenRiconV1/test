##
## EPITECH PROJECT, 2025
## G-PSU-100-LYN-1-1-myls-7
## File description:
## Makefile
##

SRC	=	main.c	\
		parser.c	\
		utils/my_strcmp.c	\
		utils/my_strlen.c	\
		utils/my_strcpy.c	\
		utils/my_arraylen.c	\
		flags/handle_array.c	\
		flags/basic_ls.c	\

OBJ	=	$(SRC:.c=.o)

CC = epiclang
NAME =	my_ls

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(TESTNAME)

re: fclean all

.PHONY: all clean fclean re
