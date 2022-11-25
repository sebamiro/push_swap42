/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:04:38 by smiro             #+#    #+#             */
/*   Updated: 2022/11/08 18:15:12 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_int	*ft_last(t_int **lst)
{
	t_int	*temp;

	temp = *lst;
	if (!temp)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	swap(t_int **lst, char c)
{
	t_int	*first;
	t_int	*second;

	if (!*lst || !(*lst)->next)
		return ;
	first = *lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	*lst = second;
	if (c)
		ft_printf("s%c\n", c);
}

void	rotate(t_int **lst, char c)
{
	t_int	*first;
	t_int	*last;

	first = *lst;
	last = ft_last(&first);
	*lst = first->next;
	(*lst)->prev = NULL;
	last->next = first;
	first->next = NULL;
	first->prev = last;
	if (c)
		ft_printf("r%c\n", c);
}

void	rrotate(t_int **lst, char c)
{
	t_int	*first;
	t_int	*last;

	first = *lst;
	last = ft_last(&first);
	last->prev->next = NULL;
	first->prev = last;
	*lst = last;
	(*lst)->prev = NULL;
	(*lst)->next = first;
	if (c)
		ft_printf("rr%c\n", c);
}

void	push(t_int **a, t_int **b, char c)
{
	t_int	*temp;

	temp = *a;
	*a = temp->next;
	if (*a)
		(*a)->prev = NULL;
	temp->next = *b;
	if (*b)
		(*b)->prev = temp;
	*b = temp;
	if (c)
		ft_printf("p%c\n", c);
}
