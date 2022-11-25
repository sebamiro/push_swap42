/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:36:46 by smiro             #+#    #+#             */
/*   Updated: 2022/11/25 16:36:48 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_swap(t_int **a, t_int **b, char *action)
{
	if (!ft_strncmp(action, "pa\n", 5))
		push(b, a, 0);
	else if (!ft_strncmp(action, "pb\n", 5))
		push(a, b, 0);
	else if (!ft_strncmp(action, "sa\n", 5))
		swap(a, 0);
	else if (!ft_strncmp(action, "sb\n", 5))
		swap(b, 0);
	else
	{
		swap(b, 0);
		swap(a, 0);
	}
}

static void	rotate_r(t_int **a, t_int **b, char *action)
{
	if (!ft_strncmp(action, "ra\n", 5))
		rotate(a, 0);
	else if (!ft_strncmp(action, "rb\n", 5))
		rotate(b, 0);
	else if (!ft_strncmp(action, "rr\n", 5))
	{
		rotate(a, 0);
		rotate(b, 0);
	}
	else if (!ft_strncmp(action, "rra\n", 5))
		rrotate(a, 0);
	else if (!ft_strncmp(action, "rrb\n", 5))
		rrotate(b, 0);
	else
	{
		rrotate(a, 0);
		rrotate(b, 0);
	}
}

static void	ft_read(t_int **a, t_int **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (line[0] == 'r')
			rotate_r(a, b, line);
		else
			push_swap(a, b, line);
		line = get_next_line(0);
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
	b = NULL;
	ft_read(&a, &b);
	if (ft_issort(&a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit(0);
}
