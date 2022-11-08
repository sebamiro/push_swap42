/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlelong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:23:03 by smiro             #+#    #+#             */
/*   Updated: 2022/11/08 10:23:15 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void  getmax(t_int **lst , int max)
{
  t_int *temp;
  int i;
  
  i = 0;
  temp = *lst;
  while (temp->index != max)
  {
      i++;
      temp = temp->next;
  }
  while(i * 10 <= lstlen(lst) * 5 && i > 0)
  {
    rotate(lst, 'b');
    i--;
  }
  while(i * 10 >= lstlen(lst) * 5 && i < lstlen(lst))
  {
    rrotate(lst, 'b');
    i++;
  }
}

void	ft_handle100(t_int **a, t_int **b, int size)
{
  int min;
  int max;
  int total;
  
  min = 0;
  max = 20;
  while (size > 0)
  {
    if (max >= total)
      max = total - 3;
    scanchunk(a , b, min, max);
    min += 20;
    max += 20;
    size -= 20;
  }
  getmax(b, total - 4);
  if (!ft_issort(a))
    ft_handle3(a, 'a');
  while (*b)
    push(b, a, 'a');
}

void	ft_handle500(t_int **a, t_int **b, int size)
{
  int min;
  int max;
  int total;
  
  min = 0;
  max = 50;
  while (size > 0)
  {
    if (max >= total)
      max = total - 3;
    scanchunk(a , b, min, max);
    min += 45;
    max += 45;
    size -= 45;
  }
  getmax(b, total - 4);
  if (!ft_issort(a))
    ft_handle3(a, 'a');
  while (*b)
    push(b, a, 'a');
}
