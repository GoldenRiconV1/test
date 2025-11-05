##
## EPITECH PROJECT, 2025
## G-CPE-110-LYN-1-1-settingup-6
## File description:
## Makefile
##

SRC	=	main.c	\
		parser.c	\
		generate_map.c	\
		utils/my_strlen.c	\
		utils/read_map.c	\
		utils/print_map.c	\
		utils/my_getnbr.c	\
		utils/my_strdup.c	\
		max_square_size.c	\

OBJ	=	$(SRC:.c=.o)

CC = epiclang
CFLAGS += -g3
NAME =	setting_up

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(TESTNAME)

re: fclean all

.PHONY: all clean fclean re