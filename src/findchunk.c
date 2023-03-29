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
	int		i;

	i = 0;
	front = *a;
	while (lstlen(b) < max)
	{
		if (front->index < max)
		{
			if (front->index < max)
				rotatechunk(a, b, max, i);
			i = 0;
			front = *a;
		}
		else
		{
			i++;
			front = front->next;
		}
	}
}
