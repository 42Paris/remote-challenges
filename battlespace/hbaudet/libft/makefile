# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 19:19:11 by hbaudet           #+#    #+#              #
#    Updated: 2020/01/14 21:22:18 by hbaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_bzero_printf.c ft_printf_convert_2.c ft_printf_convert_1.c \
			ft_putnbr_printf.c ft_printf.c ft_args.c ft_convert_hexa.c \
			ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isupper.c \
			ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strcmp.c \
			ft_strcpy.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strncpy.c \
			ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
			ft_toupper.c ft_zero.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
			ft_lstmap_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	libft.a

CC		=	gcc

RM		=	rm -f

CFLAGS 	=	-Wall -Wextra -Werror -IHeaders

%.o:		%.c
			$(CC) $(CFLAGS) -c  $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib ${NAME}

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			${RM} ${NAME}

re:			fclean all

o:			re
			${MAKE} clean

.PHONY:		all clean fclean re bonus o
