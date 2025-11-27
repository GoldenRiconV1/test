##
## EPITECH PROJECT, 2025
## MyRadar
## File description:
## Makefile
##

NAME = my_radar
CC = epiclang
CFLAGS = -Wall -Wextra -I include -g3
LDFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

SRC =	src/main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
