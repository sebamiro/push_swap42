/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:03:18 by smiro             #+#    #+#             */
/*   Updated: 2022/11/08 15:32:58 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

void	ft_check(int ac, char **av);

typedef struct 		t_int
{
	int				n;
	int				index;
	struct t_int	*prev;
	struct t_int	*next;
}					t_int;

void	ft_addback(t_int **lst, int value);

void	swap(t_int **lst, char c);

void	rotate(t_int **lst, char c);

void	rrotate(t_int **lst, char c);

void	push(t_int **a, t_int **b, char c);

void	ft_handle3(t_int **a, char c);

void	ft_handle5(t_int **a, t_int **b, int size);

void	ft_handle100(t_int **a, t_int **b, int size);

void	ft_handle500(t_int **a, t_int **b, int size);

void	scanchunk(t_int	**a, t_int **b, int min, int max);

int		ft_issort(t_int **lst);

int		ismin(int n, t_int **lst);

int		ismax(int n, t_int **lst);

int		lstlen(t_int **lst);

t_int	*initialize(int ac, char **av);

t_int	*ft_last(t_int **lst);


#endif
