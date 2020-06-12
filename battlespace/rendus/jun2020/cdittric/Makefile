# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdittric <cdittric@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2029/06/02 19:54:00 by cdittric          #+#    #+#              #
#    Updated: 2029/06/02 19:54:00 by cdittric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btsp

INC = main.h

SRC = main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -O2 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) -rf $(OBJ)

fclean:
	$(RM) -rf $(OBJ)
	$(RM) -rf $(NAME)

re: fclean all
