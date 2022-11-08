/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:32:32 by smiro             #+#    #+#             */
/*   Updated: 2022/11/08 17:56:57 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	lstlen(t_int **lst)
{
	int		i;
	t_int	*temp;

	temp = *lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	ft_issort(t_int **lst)
{
	t_int	*temp;

	temp = *lst;
	while (temp->next)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ismin(int n, t_int **lst)
{
	t_int	*temp;

	temp = *lst;
	while (temp)
	{
		if (n > temp->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ismax(int n, t_int **lst)
{
	t_int	*temp;

	temp = *lst;
	while (temp)
	{
		if (temp->index > n)
			return (0);
		temp = temp->next;
	}
	return (1);
}
