##
## EPITECH PROJECT, 2025
## G-PSU-100-LYN-1-1-myls-7
## File description:
## Makefile
##

SRC	=	main.c	\
		parser.c	\
		utils/char_to_lower.c	\
		utils/lexicographic_cmp.c	\
		utils/mini_printf.c	\
		utils/my_arraylen.c	\
		utils/my_put_nbr.c	\
		utils/my_putchar.c	\
		utils/my_putstr_err.c	\
		utils/my_putstr.c	\
		utils/my_strcmp.c	\
		utils/my_strcpy.c	\
		utils/my_strlen.c	\
		flags/handle_array.c	\
		flags/handle_flags.c	\
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
