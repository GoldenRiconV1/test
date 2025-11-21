##
## EPITECH PROJECT, 2025
## myls
## File description:
## Makefile
##

NAME = my_hunter
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
		src/objets/background.c	\
		src/objets/clock.c	\
		src/objets/duck.c	\
		src/objets/text.c	\
		src/objets/cursor.c	\
		src/objets/sound_music.c	\
		src/objets/btn.c	\
		src/utils/mini_printf.c	\
		src/utils/my_put_nbr.c	\
		src/utils/my_putchar.c	\
		src/utils/my_putstr.c	\
		src/utils/my_strcmp.c	\
		src/utils/my_revstr.c	\
		src/utils/unsigned_int_to_str.c	\
		src/utils/my_strlen.c	\
		src/utils/my_format_score.c	\
		src/utils/my_strcpy.c	\

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
