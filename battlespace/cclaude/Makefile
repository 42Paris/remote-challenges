NAME = btsp

CC = clang

CFLAGS = -Wall -Wextra -Werror

HEADER = btsp.h

SRC = btsp.c check.c coeff.c map.c shield.c sink.c sunk.c tools.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n\033[0;33mCompiling..."
	$(CC) -o $(NAME) $(OBJ)
	@echo "\033[0m"

%.o: %.c
	@echo "\033[0;32mGenerating obj..."
	$(CC) -c $< $(CFLAGS)
	@echo "\033[0m"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
