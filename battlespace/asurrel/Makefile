# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theorder <theorder@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/01 14:30:43 by theorder          #+#    #+#              #
#    Updated: 2020/06/02 15:44:46 by theorder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	btsp

COMP			=	clang
FLAG			=	-Wall -Wextra -Werror

# Sources paths
FILES_C			=   btsp.c
FILES_O			=	$(FILES_C:.c=.o)

# Rules

all				:	$(NAME)

dev				:	debug $(NAME)


$(NAME)			:	$(FILES_O)
					@echo "\nAssemblage et création de l'exécutable $(NAME)"
					@$(COMP) $(FLAG) $(FILES_O) -o $(NAME)
					@echo "Terminé"


%.o				:	%.c
					@echo -e "\033[2K\c"
					@echo "\rCréation de l'objet $@\c"
					@$(COMP) $(FLAG) -o $@ -c $<

clean			:
					@echo "Nettoyage des objets"
					@rm -f $(FILES_O)

fclean			:
					@echo "Nettoyage des objets"
					@rm -f $(FILES_O)
					@echo "Nettoyage de l'exécutable $(NAME)"
					@rm -f $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
