# https://misc.flogisoft.com/bash/tip_colors_and_formatting
_BOLD      =\e[1m
_DIM       =\e[2m
_UNDERLINE =\e[4m
_BLINK     =\e[5m
_REVERSE   =\e[7m
_HIDDEN    =\e[8m

# RESET list
_R          =\e[0m
_RBOLD      =\e[21m
_RDIM       =\e[22m
_RUNDERLINE =\e[24m
_RBLINK     =\e[25m
_RREVERSE   =\e[27m
_RHIDDEN    =\e[28m

# Colors
_RED      =\e[91m
_GREEN    =\e[92m
_YELLOW   =\e[93m
_BLUE     =\e[94m
_MAGENTA  =\e[35m
_CYAN     =\e[96m
_WHITE    =\e[97m

# Inverted, i.e. colored backgrounds
_IRED     =\e[101m
_IGREEN   =\e[102m
_IYELLOW  =\e[103m
_IBLUE    =\e[104m
_IMAGENTA =\e[45m
_ICYAN    =\e[106m
_IWHITE   =\e[107m

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/26 10:11:39 by juligonz          #+#    #+#              #
#    Updated: 2020/05/26 13:26:59 by juligonz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = btsp
DEBUG_EXEC = debug

LIB = ft

SRC_DIR = $(shell find ./srcs -type d)
INC_DIR = includes
OBJ_DIR = obj

LIB_DIR = $(shell find ./lib  -maxdepth 1 -type d)

SRC = main.c
#SRC+=

OBJ     = $(addprefix  $(OBJ_DIR)/,$(SRC:%.c=%.o))
vpath %.c $(SRC_DIR)

CC      = clang
CFLAGS  = -Wall -Wextra -Werror -g # -fsanitize=address  -fsanitize=undefined -fstack-protector  
IFLAGS  = -I./includes -I./lib/libft
LFLAGS  = $(foreach lib, $(LIB_DIR),-L$(lib))  $(foreach lib, $(LIB),-l$(lib))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(_GREEN)Compiling ...$(_END)"
	@$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) -o $@ $^
	@echo "$(_GREEN)Compiled !$(_END)"

debug: $(NAME)
	@echo "$(_BOLD)$(_GREEN)######## $(_RED)NOT IMPLEMENTED !$(_GREEN) ######$(_R)"
		
test: $(NAME)
	@echo "$(_BOLD)$(_GREEN)######## $(_RED)Testing !$(_GREEN) ######$(_R)"
	../battlespace $(MAP) btsp

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(_RED)Removed :$(_MAGENTA) $(OBJ_DIR)/$(_R)"

fclean: clean
	@rm -f $(NAME) $(DEBUG_EXEC)
	@echo "$(_RED)Removed : $(_MAGENTA)$(NAME), $(DEBUG_EXEC)$(_R)"

re_echo:
	@echo "$(_CYAN)Redoing $(_BOLD)ALLL $(_R)$(_CYAN)$(_DIM)the things $(_R)$(_BLINK)$(_BOLD)$(_YELLOW)...$(_R)\n"

re: re_echo fclean all

show:
	@echo "$(_CYAN)CC     :$(_RED)  $(CC)$(_END)"
	@echo "$(_CYAN)CFLAGS :$(_RED)  $(CFLAGS)$(_END)"
	@echo "$(_CYAN)IFLAGS :$(_RED)  $(IFLAGS)$(_END)"
	@echo "$(_CYAN)LFLAGS :$(_RED)  $(LFLAGS)$(_END)\n"
	@echo "$(_CYAN)SRC    :$(_RED)  $(SRC)$(_END)"
	@echo "$(_CYAN)OBJ    :$(_RED)  $(OBJ)$(_END)"


.PHONY: clean fclean re all bonus debug re_echo show
