# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 21:28:18 by smiro             #+#    #+#              #
#    Updated: 2022/11/10 09:56:52 by smiro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

MKFL			=	Makefile

SRCS			=	src/ft_check.c src/operations.c src/utils.c src/utils_sort.c src/handleshort.c \
						src/findchunk.c src/handlelong.c src/push_swap.c

BONUS_SRCS		=	src/checker.c src/ft_check.c src/utils.c src/utils_sort.c src/operations.c

Libft_DIR		=	includes/libft
Libft			=	$(Libft_DIR)/libft.a
Printf_DIR		=	includes/printf
Printf			=	$(Printf_DIR)/libftprintf.a

RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -I includes/

all:
	@$(MAKE) -sC $(Libft_DIR)
	@$(MAKE) -sC $(Printf_DIR)
	@$(MAKE) $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) $(Libft) $(Printf) -o $(NAME)

bonus: $(SRCS)
	@$(MAKE) -sC $(Libft_DIR)
	@$(MAKE) -sC $(Printf_DIR)
	@$(CC) $(CFLAGS) $(BONUS_SRCS) $(Libft) $(Printf) -o checker

clean:
	@$(MAKE) clean -sC $(Libft_DIR)
	@$(MAKE) clean -sC $(Printf_DIR)
	@echo "Removed all \'.o\' files\n"

fclean:
	@$(MAKE) clean
	@$(RM) $(NAME) checker

re:
	@$(MAKE) fclean
	@$(MAKE)
	
.PHONY: all clean fclean re
