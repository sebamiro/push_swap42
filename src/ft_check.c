/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:58:29 by smiro             #+#    #+#             */
/*   Updated: 2022/11/07 16:58:41 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int check_int(char *num)
{
  int i;

  i = 0;
  if (num[i] == '-' || num[i] == '+') 
    i++;
  if (!num[i]) 
    return (0);
  while (num[i]) 
  {
      if (!ft_isdigit(num[i]))
        return (0);
    i++;
  }
  return (1);
}

static int check_max(char *num)
{ 
  int len;

  len = ft_strlen(num);
  if (len > 11)
    return (0);
  if ((len == 11 && num[0] != '-') 
      || (len == 11 && ft_strncmp(num, "-2147483648",11) > 0)
      || (len == 10 && ft_strncmp(num, "2147483647",10) > 0))
    return (0);
  return (1);
}

static int check_dup(char **av ,int i, int size)
{
  int j;
  
  j = i + 1;
  while(j < size) 
  {
    if (!ft_strncmp(av[i], av[j], 11))
        return (0);
    j++;
  }
  return (1);
}

void	ft_check(int ac, char **av)
{
  int i;
     
  i = 1;
  while(i < ac) 
  {
    if (!check_int(av[i]) || !check_max(av[i]) || !check_dup(av, i, ac))
    {
      write(2,"Error\n",6);
      exit(1);
    }
    i++;
  }
}
