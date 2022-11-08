# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 21:28:18 by smiro             #+#    #+#              #
#    Updated: 2022/11/08 10:18:07 by smiro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

MKFL			=	Makefile

SRCS			=	src/ft_check.c src/operatins.c src/utils.c src/utils_sort.c src/handle3.c \
						src/findchunk.c src/handle100.c src/push_swap.c

Libft_DIR		=	includes/libft
Libft			=	$(Libft_DIR)/libft.a
Printf_DIR		=	includes/printf
Printf			=	$(Printf_DIR)/libftprintf.a

RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -I.

all: $(NAME)

#	@$(MAKE) -sC $(Libft_DIR)
#	@$(MAKE) -sC $(Printf_DIR)
#	@$(MAKE) $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) $(Libft) $(Printf) -o $(NAME)

clean:
	@$(MAKE) clean -sC $(Libft_DIR)
	@$(MAKE) clean -sC $(Printf_DIR)
	@echo "\nRemoved all \'.o\' files\n"

fclean:
	@$(MAKE) clean
	@$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)
	
.PHONY: all clean fclean re
