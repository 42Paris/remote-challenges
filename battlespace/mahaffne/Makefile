# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/02 18:39:18 by mahaffne          #+#    #+#              #
#    Updated: 2020/06/02 19:14:56 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	btsp

COMP			=	clang-9
FLAG			=	-Wall -Wextra -Werror

FILES_C			=   main.c
FILES_O			=	$(FILES_C:.c=.o)

all				:	$(NAME)

dev				:	debug $(NAME)


$(NAME)			:	$(FILES_O)
					@echo "\n Creating $(NAME)"
					@$(COMP) $(FLAG) $(FILES_O) -o $(NAME)
					@echo "ready !"


%.o				:	%.c
					@echo -e "\033[2K\c"
					@echo "\rCreating $@\c"
					@$(COMP) $(FLAG) -o $@ -c $<

clean			:
					@echo "Cleaned"
					@rm -f $(FILES_O)

fclean			:
					@echo "Fcleaned"
					@rm -f $(FILES_O)
					@echo "Removing $(NAME)"
					@rm -f $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
