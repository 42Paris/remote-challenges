NAME = btsp

SRC = srcs/btsp.c \

FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME):
	@echo "Compilation..."
	@(gcc $(FLAGS) $(SRC) -o $(NAME))
	@(echo "Compilation terminée")

fclean:	
	@echo "Fclean"
	@(rm -rf $(NAME))

re:	fclean all

.PHONY:	all clean fclean re
