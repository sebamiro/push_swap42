/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlelong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:23:03 by smiro             #+#    #+#             */
/*   Updated: 2022/11/08 21:02:46 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_previous(t_int **a, t_int **b, int num)
{
	if ((*b)->index == num - 1)
		push(b, a, 'a');
	else
	{
		push(b, a, 'a');
		rotate(a, 'a');
	}
}

static void	sort_a(t_int **a)
{
	if ((*a)->next->index == (*a)->index - 1)
		swap(a, 'a');
	if ((ft_last(a))->index < (*a)->index)
		rrotate(a, 'a');
}

static void	getmax(t_int **a, t_int **b)
{
	t_int	*temp;
	int		i;

	i = 0;
	temp = *b;
	while (!ismax(temp->index, b) && ++i)
		temp = temp->next;
	while (i * 10 <= lstlen(b) * 5 && i > 0)
	{
		if ((*b)->index == temp->index - 1 || (*b)->index == temp->index - 2)
			push_previous(a, b, temp->index);
		else
			rotate(b, 'b');
		i--;
	}
	while (i * 10 >= lstlen(b) * 5 && i < lstlen(b))
	{
		if ((*b)->index == temp->index - 1 || (*b)->index == temp->index - 2)
		{
			push_previous(a, b, temp->index);
			i--;
		}
		rrotate(b, 'b');
		i++;
	}
}

void	ft_handle100(t_int **a, t_int **b, int size)
{
	int	max;
	int	total;

	max = 20;
	total = size;
	while (size > 0)
	{
		if (max >= total)
			max = total - 3;
		scanchunk(a, b, max);
		max += 20;
		size -= 20;
	}
	while (!ft_issort(a))
		ft_handle3(a, 'a');
	while (*b)
	{
		getmax(a, b);
		push(b, a, 'a');
		sort_a(a);
	}
}

void	ft_handle500(t_int **a, t_int **b, int size)
{
	int	max;
	int	total;

	max = 62;
	total = size;
	while (size > 0)
	{
		if (max >= total)
			max = total - 3;
		scanchunk(a, b, max);
		max += 62;
		size -= 62;
	}
	while (!ft_issort(a))
		ft_handle3(a, 'a');
	while (*b)
	{
		getmax(a, b);
		push(b, a, 'a');
		sort_a(a);
	}
}
