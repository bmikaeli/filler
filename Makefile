# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/13 15:04:20 by bmikaeli          #+#    #+#              #
#    Updated: 2014/01/21 15:26:16 by bmikaeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	bmikaeli.filler
GCCW =	cc -Wall -Wextra -Werror

SRC =	main.c

OBJECT =	$(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECT)
	make -C libft/
	$(GCCW) -o $(NAME) $(LFLAGS) $(OBJECT) libft/libft.a

%.o: %.c
	$(GCCW) -c $^ $(IFLAGS) -o $@

clean:
	make clean -C libft/
	rm -f $(OBJECT)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all


