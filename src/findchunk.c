/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findchunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:21:12 by smiro             #+#    #+#             */
/*   Updated: 2022/11/08 20:53:24 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	setptr(t_int **front, t_int **back, t_int **a)
{
	if (a)
	{
		*front = *a;
		*back = ft_last(a);
	}
	else
	{
		*front = (*front)->next;
		*back = (*back)->prev;
	}
}

static void	pushchunk(t_int **a, t_int **b, int max)
{
	static int	n = 0;

	if (!n)
		n = max / 2;
	push(a, b, 'b');
	if ((*b)->index < max - n && (*b)->next)
		rotate(b, 'b');
}

static void	rotatechunk(t_int	**a, t_int **b, int max, int i)
{
	while (i > 0)
	{
		rotate(a, 'a');
		i--;
	}
	while (i < 0)
	{
		rrotate(a, 'a');
		i++;
	}
	pushchunk(a, b, max);
}

void	scanchunk(t_int	**a, t_int **b, int max)
{
	t_int	*front;
	t_int	*back;
	int		i;

	i = 0;
	setptr(&front, &back, a);
	while (lstlen(b) < max)
	{
		if (front->index < max || back->index < max)
		{
			if (front->index < max)
				rotatechunk(a, b, max, i);
			else if (front->next->index < max)
				rotatechunk(a, b, max, i + 1);
			else
				rotatechunk(a, b, max, -i - 1);
			i = 0;
			setptr(&front, &back, a);
		}
		else
		{
			i++;
			setptr(&front, &back, NULL);
		}
	}
}
