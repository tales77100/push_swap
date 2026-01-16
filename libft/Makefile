# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsantini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 10:02:20 by jsantini          #+#    #+#              #
#    Updated: 2025/11/13 13:19:35 by jsantini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c \
	ft_isalnum.c \
	ft_isdigit.c \
	ft_memcmp.c \
	ft_memset.c \
	ft_strlcat.c \
	ft_strncmp.c \
	ft_tolower.c \
	ft_bzero.c \
	ft_isalpha.c \
	ft_isprint.c \
	ft_memcpy.c \
	ft_strchr.c \
	ft_strlcpy.c \
	ft_strnstr.c \
	ft_toupper.c \
	ft_calloc.c \
	ft_isascii.c \
	ft_memchr.c \
	ft_memmove.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_strrchr.c \
	ft_strjoin.c \
	ft_substr.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_freeall.c

FILES_BONUS =	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c 
	
OBJETS = $(SRCS:.c=.o)

OBJETS_BONUS = $(FILES_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

NAME = libft.a

all: make_printf $(NAME)

$(NAME): $(OBJETS) bonus
	ar -csr $(NAME) $(OBJETS)

make_printf:
	make -C ft_printf

bonus: $(OBJETS_BONUS)
	ar -csr $(NAME) $(OBJETS_BONUS)

clean:
	make clean -C ft_printf
	rm -rf $(OBJETS) $(OBJETS_BONUS)

fclean: clean
	make fclean -C ft_printf
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
