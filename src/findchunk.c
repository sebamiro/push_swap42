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

static int	findplace(t_int **lst, int num)
{
	t_int	*last;
	int		i;
	t_int	*temp;

	temp = *lst;
	last = ft_last(lst);
	i = 0;
	if (!temp || !temp->next
		|| (ismin(num, lst) && ismin(last->index, lst))
		|| (ismax(num, lst) && ismax((*lst)->index, lst))
		|| ((*lst)->index < num && last->index > num))
		return (i);
	while (temp->next)
	{
		i++;
		if ((ismax(temp->index, lst) && ismax(num, lst))
			|| (ismin(temp->index, lst) && ismin(num, lst))
			|| (temp->index > num && temp->next->index < num)
			|| (ismin(temp->index, lst) && ismax(temp->next->index, lst)
				&& (ismax(num, lst) || ismin(num, lst))))
			return (i);
		temp = temp->next;
	}
	return (i);
}

static void	pushchunk(t_int **a, t_int **b, int x)
{
	if (!*b || !x)
		push(a, b, 'b');
	else
	{
		while (x > 0 && x < lstlen(b))
		{
			if (x * 10 <= lstlen(b) * 5)
			{
				rotate(b, 'b');
				x--;
			}
			else
			{
				rrotate(b, 'b');
				x++;
			}
		}
		push(a, b, 'b');
	}
}

static void	rotatechunk(t_int	**a, t_int **b, t_int *num, int i)
{
	int	x;

	x = findplace(b, num->index);
	while (i > 0)
	{
		if (x * 10 <= lstlen(b) * 5 && x > 0)
		{
			rotate(a, 'r');
			rotate(b, 0);
			x--;
		}
		else
			rotate(a, 'a');
		i--;
	}
	while (i < 0)
	{
		if (x * 10 >= lstlen(b) * 5 && x < lstlen(b))
		{
			rrotate(a, 'r');
			rrotate(b, 0);
			x++;
		}
		else
			rrotate(a, 'a');
		i++;
	}
	pushchunk(a, b, x);
}

void	scanchunk(t_int	**a, t_int **b, int min, int max)
{
	t_int	*front;
	t_int	*back;
	int		i;

	i = 0;
	setptr(&front, &back, a);
	while (lstlen(b) < max)
	{
		if ((front->index >= min && front->index < max)
			|| (back->index >= min && back->index < max))
		{
			if (front->index >= min && front->index < max)
				rotatechunk(a, b, front, i);
			else
				rotatechunk(a, b, back, -i - 1);
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
