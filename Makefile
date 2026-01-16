FILES = srcs/main.c	\
	srcs/algo.c	\
	srcs/push.c	\
	srcs/rotate.c	\
	srcs/rrotate.c	\
	srcs/stack_cmd.c\
	srcs/swap.c	\
	
	
OBJETS = $(FILES:.c=.o)

CFLAGS = -Wall -Werror -Wextra -Iincludes -Ilibft -g3

CC = cc

NAME = push_swap

LIB_PATH = libft/libft.a

FT_PRINTF_PATH = libft/ft_printf/libftprintf.a

all: $(NAME)


$(NAME): $(OBJETS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJETS) $(LIB_PATH) $(FT_PRINTF_PATH) -o $(NAME)

clean:
	make clean -C libft
	rm -rf $(OBJETS)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
