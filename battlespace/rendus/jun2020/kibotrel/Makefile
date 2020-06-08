# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/30 02:54:06 by kibotrel          #+#    #+#              #
#    Updated: 2020/06/01 20:25:33 by kibotrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- VARIABLES ---------------------------------#

# Executable

NAME			= btsp

# Color codes.

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

#--------------------------------- DIRECTORIES  -------------------------------#

# I/O Compilation.

SRCS_DIR		= srcs
OBJS_DIR		= objs

# Location of all header files used in the project.

INCS_DIR		:= incs

# All the subdirectories used in the project.

OBJS_SUBDIRS	:= core
OBJS_SUBDIRS	+= setup
OBJS_SUBDIRS	+= utils

#------------------------------------ FILES -----------------------------------#


# Used header at each compilation to check file integrity.

INCS			:= incs/structs.h
INCS			+= incs/core.h
INCS			+= incs/setup.h
INCS			+= incs/utils.h

# Source files.

SRCS			:= core/main.c
SRCS			+= core/ai.c
SRCS			+= core/communication.c
SRCS			+= setup/setup.c
SRCS			+= utils/ft_bzero.c
SRCS			+= utils/clear_2d_array.c
SRCS			+= utils/pick_random_cell.c
SRCS			+= utils/update_remaining_shots.c
SRCS			+= utils/ft_strcmp.c
SRCS			+= utils/area_2d.c
SRCS			+= utils/stack_index.c
SRCS			+= utils/secure_stack.c
SRCS			+= core/ai_2.c

#-------------------------------- MISCELANEOUS --------------------------------#

# Some tricks in order to get the makefile doing his job.

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
C_OBJS			= $(addprefix $(D_OBJS), $(OBJS))
C_INCS			= $(foreach include, $(INCS_DIR), -I$(include))
C_SUBDIRS		= $(foreach dir, $(OBJS_SUBDIRS), $(D_OBJS)$(dir))

#--------------------------------- COMPILATION --------------------------------#

# How files should be compiled.

CC				= gcc -Wall -Wextra -Werror
OBJS			= $(SRCS:.c=.o)

# Compilation flags.

CFLAGS			= $(C_INCS) # -Wall -Wextra -Werror

#------------------------------------ RULES -----------------------------------#

# Redefinition of the implicit compilation rule to prompt some informations.

$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Implicit make rule simply using dependancies to compile our project.

all: $(OBJS_DIR) $(C_SUBDIRS) $(NAME)

$(NAME): $(C_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Rules used to create folders if they aren't already existing.

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(C_SUBDIRS):
	@mkdir -p $(C_SUBDIRS)

# Deleting all .o files.

clean:
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(C_OBJS)

# Deleting all executables and libraries after cleaning up all .o files.

fclean: clean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(NAME)

# Re-compile everything.

re: fclean all

# Avoid unexpected behaviour when regular files get the same name
# as the following variables.

.PHONY: all clean fclean re
