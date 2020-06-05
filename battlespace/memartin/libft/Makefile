# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 15:26:01 by memartin          #+#    #+#              #
#    Updated: 2020/04/19 15:22:14 by memartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_joinfree.c\
      ft_ltoa.c\
      ft_printf.c\
      ft_printf_add.c\
      ft_printf_buffer.c\
      ft_printf_c.c\
      ft_printf_conv.c\
      ft_printf_di.c\
      ft_printf_flags.c\
      ft_printf_parse.c\
      ft_printf_oux.c\
      ft_printf_p.c\
      ft_printf_majd.c\
      ft_printf_majo.c\
      ft_printf_maju.c\
      ft_printf_majc.c\
      ft_printf_majs.c\
      ft_printf_s.c\
      ft_utoa_base.c\
      ft_strjoin.c\
      ft_strdel.c\
      ft_intmaxsize.c\
      ft_strnew.c\
      ft_putchar.c\
      ft_strdup.c\
      ft_strlen.c\
      ft_isdigit.c\
      ft_atoi.c\
      ft_strchr.c\
      ft_strcat.c\
      ft_strcpy.c\
      ft_isspace.c\
      ft_memset.c\
      ft_printf_modulo.c\
      ft_putendl.c\
      ft_putstr.c\
      ft_printf_unicode.c\
      ft_printf_utils.c\
      get_next_line.c\
      ft_strcmp.c\
      ft_intsize.c\
      ft_substr.c\
	ft_strallocset.c\
	ft_bzero.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re: fclean all
