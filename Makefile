##
## EPITECH PROJECT, 2025
## G-PSU-100-LYN-1-1-mysudo-39
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/parser.c	\
		src/auth.c	\
		src/utils/init.c	\
		src/utils/free_prog.c	\
		src/utils/fill_buf_from_file.c	\
		src/utils/get_uid_gid.c	\
		src/utils/free_struct_s.c	\
		src/utils/file_parser.c	\

OBJ	=	$(SRC:.c=.o)

CC = epiclang
CFLAGS += -g3
NAME =	my_sudo

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re