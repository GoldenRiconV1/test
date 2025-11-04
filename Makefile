##
## EPITECH PROJECT, 2025
## G-PSU-100-LYN-1-1-myls-7
## File description:
## Makefile
##

SRC	=	main.c	\
		parser.c	\
		args_manager.c \
		my_ls.c \
		utils/char_to_lower.c	\
		utils/create_result_array.c	\
		utils/dir_len.c	\
		utils/mini_printf.c	\
		utils/my_arraylen.c	\
		utils/free_memory.c	\
		utils/unsigned_int_to_str.c	\
		utils/my_put_nbr.c	\
		utils/my_putchar.c	\
		utils/my_putstr_err.c	\
		utils/my_putstr.c	\
		utils/my_revstr.c	\
		utils/my_strcat.c	\
		utils/my_strcmp.c	\
		utils/my_strcpy.c	\
		utils/my_strdup.c	\
		utils/my_strlen.c	\
		utils/nlink_t_to_str.c	\
		utils/off_t_to_str.c	\
		utils/print_array.c	\
		utils/put_default_data.c	\
		utils/structs_assignment.c	\
		utils/time_t_to_str.c	\
		handle/handle_basic_array.c	\
		handle/handle_file_args.c	\
		handle/handle_flags.c	\
		flags/basic.c	\
		flags/t.c	\
		flags/r_upcase.c	\

TEST_PATH = tests/test_my_ls.c	\

OBJ	=	$(SRC:.c=.o)

CC = epiclang
CFLAGS += -g3
NAME =	my_ls
MAIN_PATH = main.c

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(TESTNAME)

re: fclean all

.PHONY: all clean fclean re