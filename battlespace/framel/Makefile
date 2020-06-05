# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framel <framel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/30 13:56:28 by framel            #+#    #+#              #
#    Updated: 2020/05/30 13:56:31 by framel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btsp

CC = gcc

CFLAG = -Wall -Wextra -Werror

SRC = btsp

SRC := $(addsuffix .c, $(SRC))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ)
	@echo "$(NAME) successfully compiled."

%.o: %.c
	$(CC) $(CFLAG) -o $@ -c $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
