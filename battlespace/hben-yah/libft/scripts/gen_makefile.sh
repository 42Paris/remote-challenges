#!/bin/sh
echo "# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: \c" > Makefile

date "+%Y/%m/%d %H:%M:%S" | tr -d '\n' >> Makefile

echo " by hben-yah          #+#    #+#              #
#    Updated: \c" >> Makefile

date "+%Y/%m/%d %H:%M:%S" | tr -d '\n' >> Makefile

echo " by hben-yah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

COMP			=	clang
FLAG			=	-Wall -Wextra -Werror
FLAGDEV         =   -g3

# Sources paths
FILES_C			=   \\" >> Makefile
(cd srcs; find . -name '*.c' | sed -e '$ ! s/$/ \\/' | sed -e 's/^\.\//					/' >> ../Makefile)
echo "FILES_O			=	\$(FILES_C:.c=.o)
FILES_H			=	\\" >> Makefile
(cd includes; find . -name '*.h' | sed -e '$ ! s/$/ \\/' | sed -e 's/^\.\//					/' >> ../Makefile)
echo "
# Directories
SRCS_SD			= 	\\" >> Makefile
(cd srcs; find . ! -path . -type d | sed -e '$ ! s/$/ \\/' | sed -e 's/^\.\//					/' >> ../Makefile)

echo "SRCS_D			=	./srcs/
OBJS_D			=   ./objs/
INCL_D 			=	./includes/

# Paths
SRCS			= 	\$(addprefix \$(SRCS_D), \$(FILES_C))
OBJS			=	\$(addprefix \$(OBJS_D), \$(FILES_O))
INCL			=	\$(addprefix \$(INCL_D), \$(FILES_H))

" >> Makefile

echo "

# Rules

all				:	\$(NAME)

dev				:	debug \$(NAME)

\$(NAME)			:	\$(OBJS)
					@echo \"\\\nAssemblage et création de la librairie \$(NAME)\"
					@ar rc \$(NAME) \$(OBJS)
					@ranlib \$(NAME)
					@echo \"Libft terminée\"

\$(OBJS_D)%.o	:	\$(SRCS_D)%.c \$(INCL)
					@echo -e \"\\\033[2K\\\c\"
					@echo \"\\\rCréation de l'objet \$@\\\c\"
					@mkdir -p \$(addprefix \$(OBJS_D), \$(SRCS_SD))
					@\$(COMP) \$(FLAG) -I \$(INCL_D) -o \$@ -c \$<

clean			:
					@echo \"Nettoyage des objets ./libft/objs/\"
					@rm -rf \$(OBJS_D)

fclean			:	clean
					@echo \"Nettoyage de la librairie \$(NAME)\"
					@rm -f \$(NAME)

re				:	fclean all

debug			:	force
					@\$(eval FLAG = \$(FLAG) \$(FLAGDEV))

force			:
					@true

.PHONY			:	all clean fclean re force debug dev" >> Makefile