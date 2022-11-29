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
BNUS			=	.bonus

MKFL			=	Makefile

PUSH			=	src/push_swap.c $(SRCS)
SRCS			=	src/ft_check.c src/operations.c src/utils.c src/utils_sort.c src/handleshort.c \
						src/findchunk.c src/handlelong.c 

OBJS			=	$(PUSH:.c=.o)

CHECK			=	src/checker_bonus.c $(SRCS)

BONUS_OBJS		=	$(CHECK:.c=.o)

Libft_DIR		=	includes/libft
Libft			=	$(Libft_DIR)/libft.a
Printf_DIR		=	includes/printf
Printf			=	$(Printf_DIR)/libftprintf.a

RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -I includes/

%.o: %.c includes/push_swap.h $(MKFL)
	@$(CC) $(CFLAGS) -c $< -o $@

all:
	@$(MAKE) libs
	@$(MAKE) $(NAME)

libs:
	@$(MAKE) -sC $(Libft_DIR)
	@$(MAKE) -sC $(Printf_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(Libft) $(Printf) -o $(NAME)

bonus:
	@$(MAKE) $(BNUS)

$(BNUS): $(BONUS_OBJS)
	@touch $@
	@$(MAKE) libs
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(Libft) $(Printf) -o checker

clean:
	@$(MAKE) clean -sC $(Libft_DIR)
	@$(MAKE) clean -sC $(Printf_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "Removed all \'.o\' files\n"

fclean:
	@$(MAKE) clean
	@$(RM) $(NAME) checker

re:
	@$(MAKE) fclean
	@$(MAKE)
	
.PHONY: all clean fclean re bonus
