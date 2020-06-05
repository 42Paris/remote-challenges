#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 14:58:05 by juligonz          #+#    #+#              #
#    Updated: 2020/01/31 15:45:57 by juligonz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRCS =	srcs/ft_printf.c 				\
		srcs/ft_dprintf.c				\
		srcs/ft_sprintf.c				\
		srcs/ft_asprintf.c				\
		srcs/ft_strdup_cat.c			\
		srcs/cast_len_modifier.c		\
		srcs/read_flags.c				\
		srcs/parse.c					\
		srcs/double_utils.c				\
		srcs/double_utils_2.c			\
		srcs/double_validation.c		\
		srcs/write_buffer.c				\
		../ft_strncpy.c					\
		../ft_strlen.c					\
		../ft_isdigit.c					\
		../ft_memset.c					\
		srcs/put/put_dec.c				\
		srcs/put/put_hex.c				\
		srcs/put/put_oct.c				\
		srcs/put/put_ptr.c				\
		srcs/put/put_double.c			\
		srcs/put/put_e.c				\
		srcs/put/put_g.c				\
		srcs/convs/conv_c.c				\
		srcs/convs/conv_s.c				\
		srcs/convs/conv_p.c				\
		srcs/convs/conv_d.c				\
		srcs/convs/conv_i.c				\
		srcs/convs/conv_u.c				\
		srcs/convs/conv_x_lowcase.c		\
		srcs/convs/conv_x_upcase.c		\
		srcs/convs/conv_n.c				\
		srcs/convs/conv_f.c				\
		srcs/convs/conv_g.c				\
		srcs/convs/conv_e.c				\
		srcs/convs/conv_o.c				\
		srcs/convs/conv_mod.c			\

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I./includes -I../

all: $(NAME) $(NAME_BONUS)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	$(info Compiled $(NAME))

clean:
	@rm -f $(OBJ)
	$(info .o removed !)

fclean: clean
	@rm -f $(NAME)
	$(info lib removed !)

bonus: $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus