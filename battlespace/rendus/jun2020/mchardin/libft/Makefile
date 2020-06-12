# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/23 10:00:49 by mchardin          #+#    #+#              #
#    Updated: 2020/06/02 12:24:22 by mchardin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PREF_CONV	= ./conv/

PREF_GNL	= ./gnl/

PREF_IS		= ./is/

PREF_LST	= ./lst/

PREF_MEM	= ./mem/

PREF_PRINTF	= ./printf/

PREF_PUT	= ./put/

PREF_STR	= ./str/

PREF_INCL	= ./includes/

INCL_FILES	= $(addprefix ${PREF_INCL}, ft_printf.h get_next_line.h libft_structs.h libft.h new_lib.h)

SRCS_CONV	= $(addprefix ${PREF_CONV}, ft_atoi.c ft_tolower.c ft_toupper.c ft_itoa.c)

SRCS_GNL	= $(addprefix ${PREF_GNL}, get_next_line.c get_next_line_utils.c)

SRCS_IS		= $(addprefix ${PREF_IS}, ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isprint.c ft_isdigit.c ft_iswhitespace.c)

SRCS_LST	= $(addprefix ${PREF_LST}, ft_lstdelone.c ft_lstadd_back.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstadd_front.c)

SRCS_MEM	= $(addprefix ${PREF_MEM}, ft_freez.c ft_memccpy.c ft_bzero.c ft_memchr.c ft_calloc.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c)

SRCS_PRINTF	= $(addprefix ${PREF_PRINTF}, ft_fprintf.c ft_printf.c ft_printf_addflags.c ft_printf_utils.c ft_printf_nb_format.c ft_printf_conversion.c ft_printf_print.c)

SRCS_PUT	= $(addprefix ${PREF_PUT}, ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c)

SRCS_STR	= $(addprefix ${PREF_STR}, ft_strs_add_end.c ft_strndup.c ft_strs_cpy.c ft_strslen.c ft_free_strs.c ft_strs_plus_one.c ft_strdup_nosp.c ft_strncmp.c ft_split.c ft_strnstr.c ft_strchr.c ft_strrchr.c ft_strdup.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_strlcat.c ft_strlcpy.c ft_strmapi.c ft_strlen.c)

ALL_SRCS	= $(SRCS_CONV) $(SRCS_GNL) $(SRCS_IS) $(SRCS_LST) $(SRCS_MEM) $(SRCS_PRINTF) $(SRCS_PUT) $(SRCS_STR)

OBJS		= ${ALL_SRCS:.c=.o}

NAME		= libft.a

CC			= clang-9

CFLAGS		= -Wall -Wextra -Werror -I ${PREF_INCL}

RM			= rm -f

AR			= ar rc

$(NAME):	${OBJS} ${INCL_FILES}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
