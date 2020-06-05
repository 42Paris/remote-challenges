NAME = btsp

SOURCES_DIR = ./srcs

INCLUDES_DIR = ./includes

G3 =  -g3 -fsanitize=address

COMPIL = gcc

FLAG = -Wall -Wextra -Werror

HEADER = -I $(INCLUDES_DIR)

LIBFT = libft/libft.a

SRCS_NAME = btsp.c init_grid.c random.c grid_utils.c chase.c destruction.c\
			print_read.c weight.c shield.c top_left_destruction.c top_right_destruction.c\
			top_destruction.c left_destruction.c right_destruction.c bottom_destruction.c\
			bottom_left_destruction.c bottom_right_destruction.c\

SRCS = $(addprefix $(SOURCES_DIR)/,$(SRCS_NAME))

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(COMPIL) $(FLAG) $(HEADER) $(OBJS) -L./libft -lft -o $(NAME)

$(LIBFT):
	@make -C ./libft re

%.o: %.c
	@$(COMPIL) $(FLAG) $(HEADER) -c $< -o $@

clean :	
	@make -C ./libft clean
	@rm -f $(OBJS)

fclean :	clean
		@make -C ./libft fclean
		@rm -f ./$(NAME)

re:		fclean all

.PHONY:		all clean fclean re
