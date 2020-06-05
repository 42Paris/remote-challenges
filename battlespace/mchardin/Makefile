# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/23 10:00:28 by mchardin          #+#    #+#              #
#    Updated: 2020/06/02 17:04:03 by mchardin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PREFIX		=	./srcs/

INCLUDES	=	./includes/

INCLUDES_L	=	./libft/includes/

INCL_FILES	=	$(addprefix $(INCLUDES), btsp.h)

SRCS		=	$(addprefix $(PREFIX), \
								ft_btsp.c \
								ft_move.c \
								ft_find.c \
								ft_solve.c \
								ft_patterns.c \
								ft_line.c \
								ft_diagonal.c \
								ft_sunk.c \
								ft_utils.c \
				)

OBJS		=	${SRCS:.c=.o}

CC			=	clang-9

CFLAGS		=	-Werror -Wextra -Wall -I ${INCLUDES} -I ${INCLUDES_L}

NAME 		=	btsp

RM			=	rm -f

DIR_LIBFT	=	libft

LIBFT_FLAGS	=	-L./${DIR_LIBFT}/ -lft

all:		makelib
			${MAKE} ${NAME}

${NAME}:	${OBJS} ${INCL_FILES} ./${DIR_LIBFT}/libft.a
			${CC} ${CFLAGS} ${OBJS} ${LIBFT_FLAGS} -o ${NAME}

run:		all
			./$(NAME)

makelib:
			${MAKE} -C ${DIR_LIBFT}

clean:
			${RM} ${OBJS}
			${MAKE} -C ${DIR_LIBFT} clean

fclean:
			${RM} ${OBJS}
			${RM} ${NAME}
			${MAKE} -C ${DIR_LIBFT} fclean

re:			fclean all

.PHONY: 	all re run makelib clean fclean
