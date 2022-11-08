/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:29:26 by smiro             #+#    #+#             */
/*   Updated: 2022/11/08 10:32:24 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int ft_index(int num , t_int **lst)
{
  t_int *temp;
  int i;

  i = 0;
  temp = *lst;  
  while (temp)
  {
    if (temp->n < num)
      i++;
    temp = temp->next;
  }
  return (i);
}

static void  putindex(t_int **lst)
{
  t_int *temp;
  
  temp = *lst;
  while (temp)
  {
    temp->index = ft_index(temp->n, lst);
    temp = temp->next;
  }
}


void	ft_addback(t_int **lst, int value)
{
  t_int *temp;
  t_int *last;
  
  temp = (t_int *)malloc(sizeof(t_int));
  if (!temp) 
    exit(3);
  temp->n = value;
  temp->index = 0;
  temp->next = NULL;
  last = ft_last(lst);
  last->next = temp;
  temp->prev = last;
}

t_int *initialize(int ac, char **av)
{
  t_int *temp;
  int i;
  
  if (!av)
    return (NULL);
  i = 2;
  temp = (t_int *)malloc(sizeof(t_int));
  if (!temp)
      exit(1);
  temp->next = NULL;
  temp->prev = NULL;
  temp->n = ft_atoi(av[1]);
  temp->index = 0;
  while (i < ac)
  {
    ft_addback(&temp, ft_atoi(av[i]));
    i++;
  }
  putindex(&temp);
  return (temp);
}
