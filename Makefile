# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 15:03:26 by mpierrot          #+#    #+#              #
#    Updated: 2024/03/11 20:31:43 by mpierrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_F	= push_swap.c 
SRC_D	= srcs
OBJ_D = objs

OBJ_F = $(SRC_F:%.c=$(OBJ_D)/%.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ_F)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "Push_swap has been compiled successfully"

$(OBJ_D)/%.o: %.c
	@mkdir -p $(OBJ_D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) objs
	@echo "Object files cleaned !!"

fclean: clean
	@$(RM) $(NAME)
	@echo "Push_swap executable has been destroy"

re: fclean all

.PHONY: all clean fclean re