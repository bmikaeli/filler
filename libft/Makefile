#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 13:34:54 by bmikaeli          #+#    #+#              #
#    Updated: 2013/12/07 18:28:36 by bmikaeli         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_memcpy.c ft_strcmp.c ft_strncpy.c ft_memdel.c ft_strcpy.c \
	ft_strnequ.c ft_atoi.c ft_memmove.c	ft_strdel.c	ft_strnew.c \
	ft_bzero.c ft_memset.c	ft_strdup.c	ft_strnstr.c ft_isalnum.c \
	ft_putchar.c ft_strequ.c ft_strrchr.c ft_isalpha.c ft_putchar_fd.c \
	ft_striter.c ft_strstr.c ft_isascii.c ft_putendl_fd.c ft_striteri.c \
	ft_strsub.c ft_isdigit.c ft_putnbr.c ft_strjoin.c ft_strtrim.c \
	ft_isprint.c ft_putnbr_fd.c	ft_strlcat.c ft_tolower.c ft_itoa.c	\
	ft_putstr.c	ft_strlen.c	ft_toupper.c ft_memalloc.c	ft_putstr_fd.c	\
	ft_strmap.c	ft_memccpy.c ft_strcat.c ft_strmapi.c ft_memchr.c \
	ft_strchr.c	ft_strncat.c ft_memcmp.c ft_strclr.c ft_strncmp.c \
	ft_putendl.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	ft_lstadd.c ft_lstiter.c ft_lstmap.c get_next_line.c ft_printf_flags.c \
	ft_printf_put.c ft_printf_putnbr.c ft_printf.c


OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
		cc $(FLAGS) -c $(SRC) -I./includes/
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -rf

re: fclean all
