##
## EPITECH PROJECT, 2025
## myls
## File description:
## Makefile
##

NAME = MoneyRush
CC = epiclang
CFLAGS = -Wall -Wextra -I include -g3
LDFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

SRC =	src/create.c	\
		src/destroy.c	\
		src/events.c	\
		src/game.c	\
		src/main.c	\
		src/init.c	\
		src/menu/handle_play.c	\
		src/menu/check_click_btn.c	\
		src/menu/start.c	\
		src/menu/loose.c	\
		src/menu/pause.c	\
		src/menu/handle_menu.c	\
		src/sprite_texture/background.c	\
		src/sprite_texture/clock.c	\
		src/sprite_texture/duck.c	\
		src/sprite_texture/btn.c
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
