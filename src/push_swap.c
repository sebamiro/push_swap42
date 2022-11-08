/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:59:10 by smiro             #+#    #+#             */
/*   Updated: 2022/11/08 21:11:26 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printlst(t_int **a)
{
	t_int *temp;

	temp = *a;
	while (temp)
	{
		ft_printf("n: %d index: %d\n", temp->n, temp->index);
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	t_int	*a;
	t_int	*b;

	if (ac == 1)
		return (0);
	ft_check(ac, av);
	a = initialize(ac, av);
	b = initialize(0, NULL);
	if (ac <= 4)
	{
		while (!ft_issort(&a))
			ft_handle3(&a, 'a');
	}
	else if (ac <= 6)
		ft_handle5(&a, &b, ac - 1);
	else if (ac <= 101)
		ft_handle100(&a, &b, ac - 1);
	else if (ac <= 501)
		ft_handle500(&a, &b, ac - 1);
	exit(1);
}
