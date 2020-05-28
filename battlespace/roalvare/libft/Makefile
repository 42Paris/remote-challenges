SRCS_MATH	= $(addprefix math/,	ft_abs.c \
									ft_max.c \
									ft_min.c)

SRCS_CONV	= $(addprefix conv/,	ft_atoi.c \
									ft_itoa.c \
									ft_tolower.c \
									ft_toupper.c \
									ft_hexa.c)

SRCS_PUT	= $(addprefix put/,		ft_putchar_fd.c \
									ft_putstr_fd.c \
									ft_putendl_fd.c \
									ft_putnbr_fd.c)

SRCS_MEM	= $(addprefix mem/,		ft_bzero.c \
									ft_calloc.c \
									ft_memcpy.c \
									ft_memchr.c \
									ft_memcmp.c \
									ft_memccpy.c \
									ft_memmove.c \
									ft_memset.c)

SRCS_IS		= $(addprefix is/,		ft_isalnum.c \
									ft_isalpha.c \
									ft_isascii.c \
									ft_isdigit.c \
									ft_isprint.c)

SRCS_STR	= $(addprefix str/,		ft_split.c \
									ft_strchr.c \
									ft_strdup.c \
									ft_strjoin.c \
									ft_strlcat.c \
									ft_strlcpy.c \
									ft_strlen.c \
									ft_strmapi.c \
									ft_strncmp.c \
									ft_strnstr.c \
									ft_strrchr.c \
									ft_strtrim.c \
									ft_substr.c)

SRCS_LIST	= $(addprefix list/,	ft_lstadd_back.c \
									ft_lstadd_front.c \
									ft_lstclear.c \
									ft_lstdelone.c \
									ft_lstiter.c \
									ft_lstlast.c \
									ft_lstmap.c \
									ft_lstnew.c \
									ft_lstsize.c \
									ft_lstprint.c)

SRCS_PRINT	= $(addprefix printf/,	ft_char.c \
									ft_content.c \
									ft_convert.c \
									ft_free.c \
									ft_getter.c \
									ft_has.c \
									ft_int.c \
									ft_list.c \
									ft_node.c \
									ft_printf.c \
									ft_setter.c)

SRCS_BTREE	= $(addprefix btree/,	ft_btree_apply.c \
									ft_btree_create_node.c \
									ft_btree_insert_data.c \
									ft_btree_print.c \
									ft_btree_search.c \
									ft_btree_level.c \
									ft_btree_size.c \
									ft_btree_clear.c \
									ft_btree_rotation.c \
									ft_btree_avl.c)


SRCS		=	${SRCS_LIST} \
				${SRCS_IS} \
				${SRCS_MEM} \
				${SRCS_PUT} \
				${SRCS_STR} \
				${SRCS_MATH} \
				${SRCS_CONV} \
				${SRCS_PRINT} \
				${SRCS_BTREE}

HEADER		= $(addprefix ${INCLUDES}/,	libft.h \
										ft_printf.h \
										btree.h)

INCLUDES 	= includes

NAME		= libft.a

CC			= clang

CFLAG		= -Wall -Wextra -Werror -g

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

all:		${NAME}

.c.o:
			${CC} ${CFLAG} -c -I ${INCLUDES} $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${HEADER}
			ar rc ${NAME} ${OBJS}

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
