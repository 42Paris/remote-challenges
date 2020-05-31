SRCS		= $(addprefix srcs/,	players.c \
									box.c \
									ft_army.c \
									ft_nation.c \
									ft_mercenaries.c \
									ft_aliens.c)

OBJS		= ${SRCS:.c=.o}

INCLUDES	= includes

INCLUDES_L	= libft/includes

DIR_LIBFT	= libft

NAME 		= btsp

CC			= clang

CFLAGS		= -g -Werror -Wextra -Wall -I ${INCLUDES_L} -I ${INCLUDES}

all:	makelib
	${MAKE} ${NAME}

${NAME}:	${OBJS} ./${DIR_LIBFT}/libft.a
	${CC} ${CFLAGS} ${OBJS} -L./${DIR_LIBFT}/ -lft -o ${NAME}

makelib:
	${MAKE} -C ${DIR_LIBFT}

clean:
	${RM} ${OBJS}
	${MAKE} -C ${DIR_LIBFT} clean

fclean:
	${RM} ${OBJS}
	${RM} ${NAME}
	${MAKE} -C ${DIR_LIBFT} fclean

re:	fclean all

test: all
	../a.out ../exemple.txt btsp

.PHONY: 	all re makelib clean fclean