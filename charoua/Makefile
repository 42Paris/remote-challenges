# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charoua <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/02 00:43:11 by charoua           #+#    #+#              #
#    Updated: 2020/06/02 00:43:17 by charoua          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	btsp

SRC	=	ft_putstr.c \
		btsp_charoua2.c \
		btsp_charoua.c

OBJ =	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@gcc -Wall -Werror -Wextra $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
