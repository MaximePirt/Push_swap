# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 15:03:26 by mpierrot          #+#    #+#              #
#    Updated: 2024/03/15 17:03:36 by mpierrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_F	= push_swap.c move.c ft_atol.c libft/libft.a ft_lstdupcheck.c \

SRC_D	= srcs
OBJ_D = objs

OBJ_F = $(SRC_F:%.c=$(OBJ_D)/%.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs
NAME = push_swap
CLIB = libft/Makefile

DEFCOLOR	= \033[0;39m
CYAN		= \033[1;96m
PURPLE		= \033[0;95m
YELLOW		= \033[0;93m
RED			= \033[0;91m




all: $(NAME)

$(NAME): $(OBJ_F) libft/libft.a
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(CYAN)Push_swap has been compiled successfully$(DEFCOLOR)"

$(OBJ_D)/%.o: %.c
	@mkdir -p $(OBJ_D)
	@echo "$(YELLOW)Compiling $<$(DEFCOLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

libft/libft.a: $(CLIB)
	@$(MAKE) -s -C $(dir $(CLIB)) -f $(notdir $(CLIB))

clean:
	@$(MAKE) -s -C $(dir $(CLIB)) -f $(notdir $(CLIB)) clean
	@$(RM) objs 
	@echo "$(PURPLE)Push_Swap object files cleaned !!$(DEFCOLOR)"

fclean: clean
	@$(MAKE) -s -C $(dir $(CLIB)) -f $(notdir $(CLIB)) fclean
	@$(RM) $(NAME)
	@echo "$(RED)Push_swap executable has been destroy$(DEFCOLOR)"

re: fclean all

.PHONY: all clean fclean re