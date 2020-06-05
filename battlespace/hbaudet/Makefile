# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 18:03:34 by hbaudet           #+#    #+#              #
#    Updated: 2020/05/27 19:34:08 by hbaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	main.c

OBJS_DIR		=	objs_dir/

OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

PATHLIBFT		=	libft/

LIBFT			=	libft.a

NAME			=	btsp

CC				=	clang-9

RM				=	rm -f

CFLAGS 			=	-Wall -Wextra -Werror

LINK			=	-L$(PATHLIBFT) -lft

all:			$(LIBFT) $(NAME) 

$(OBJS_DIR)%.o:	%.c | $(OBJS_DIR)
				$(CC) $(CFLAGS) -c  $< -o $@

$(NAME):		$(OBJS_DIR) $(OBJS)
				$(CC) -o $(NAME) $(OBJS) $(LINK)

$(LIBFT):		
				$(MAKE) -C $(PATHLIBFT)

$(OBJS_DIR):	
				mkdir $(OBJS_DIR)
clean:		
				$(RM) -rf $(OBJS_DIR)
				$(MAKE) clean -C $(PATHLIBFT)
			
fclean:			clean
				$(RM) $(NAME)
				$(RM) $(PATHLIBFT)$(LIBFT)

re:				fclean all

.PHONY:			all clean fclean re bonus
