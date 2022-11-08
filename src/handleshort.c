/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle3.o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:30:24 by smiro             #+#    #+#             */
/*   Updated: 2022/11/08 19:10:42 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort5(t_int **a)
{
	while (!ft_issort(a))
	{
		if (ismax((*a)->index, a) || ismax((*a)->next->index, a))
			rotate(a, 'a');
		else
			rrotate(a, 'a');
	}
}

void	ft_handle3(t_int **a, char c)
{
	t_int	*first;
	t_int	*last;

	first = *a;
	last = ft_last(a);
	if (ismax(last->index, a) || ismin(first->index, a)
		|| (ismax(first->index, a) && ismin(last->index, a)))
		swap(a, c);
	else if (ismax(first->next->index, a))
		rrotate(a, c);
	else
		rotate(a, c);
}

void	ft_handle5(t_int **a, t_int **b, int size)
{
	t_int	*mid;
	t_int	*last;

	while (size > 3)
	{
		push(a, b, 'b');
		size--;
	}
	while (!ft_issort(a))
		ft_handle3(a, 'a');
	while (*b)
	{
		last = ft_last(a);
		mid = (*a)->next;
		if ((ismax((*b)->index, a) && ismax(last->index, a))
			|| (ismin((*b)->index, a) && ismin((*a)->index, a))
			|| ((*b)->index < (*a)->index && (*b)->index > last->index))
			push(b, a, 'a');
		else if (!ismax((*b)->index, a)
				&& ((*b)->index > mid->index || (*b)->index > mid->next->index))
			rrotate(a, 'a');
		else
			rotate(a, 'a');
	}
	sort5(a);
}
