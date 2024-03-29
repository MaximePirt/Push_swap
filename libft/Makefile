# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 12:26:58 by mpierrot          #+#    #+#              #
#    Updated: 2024/03/29 21:38:43 by mpierrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRDIR = includes
SRC_FILES = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
			libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
			libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c \
			libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c \
			libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c \
			libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c \
			libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c \
			libft/ft_tolower.c libft/ft_toupper.c \
			libft/bonus/ft_lstadd_back.c libft/bonus/ft_lstadd_front.c libft/bonus/ft_lstclear.c \
			libft/bonus/ft_lstdelone.c libft/bonus/ft_lstiter.c libft/bonus/ft_lstlast.c \
			libft/bonus/ft_lstmap.c libft/bonus/ft_lstnew.c libft/bonus/ft_lstsize.c\
			GNL/get_next_line.c GNL/get_next_line_utils.c \
			ft_printf/ft_printf.c ft_printf/ft_putptrfunc.c ft_printf/ft_usefulfonc.c \

SRCDIR = libft GNL ft_printf
OBJ_D = objs
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_D)/%.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
AR = ar rcs
RM = rm -rf

DEFCOLOR = \033[0;39m
GREEN    = \033[1;92m
YELLOW   = \033[0;93m
PURPLE   = \033[0;95m
CYAN     = \033[0;96m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(AR) $@ $^
	@echo "$(GREEN)$(NAME) has been created successfully.$(DEFCOLOR)"

$(OBJ_D)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $< $(DEFCOLOR)"
	@$(CC) $(CFLAGS) -I $(HDRDIR) -c $< -o $@

clean:
	@$(RM) $(OBJ_D)

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)$(NAME) has been removed.$(DEFCOLOR)"

re: fclean all
	@echo "$(GREEN)Libft was remake successfully $(DEFCOLOR)"

.PHONY: all clean fclean re