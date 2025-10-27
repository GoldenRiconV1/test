##
## EPITECH PROJECT, 2025
## G-PSU-100-LYN-1-1-myls-7
## File description:
## Makefile
##

SRC	=	main.c	\
		parser.c	\

OBJ	=	$(SRC:.c=.o)

# LDFLAGS += -lmy -L./lib/my

# CFLAGS += -I./include

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
