/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:46:13 by alcornea          #+#    #+#             */
/*   Updated: 2017/05/16 19:13:26 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void swap(char **s1, char **s2)
{
  char *tmp;

  tmp = ft_strdup(*s1);
  ft_strdel(s1);
  *s1 = ft_strdup(*s2);
  ft_strdel(s2);
  *s2 = ft_strdup(tmp);
  free(tmp);
}

void sort_path(char ***str, int size, char r)
{
  int i;
  int j;
  int value;

  i = 0;
  j = 0;
  size--;
  while (j <= size)
  {
    while (i <= size)
    {
      value = (r ? ft_strcmp((*str)[j], (*str)[i]) : ft_strcmp((*str)[i], (*str)[j]));
      if (value < 0)
        swap(&((*str)[j]), &((*str)[i]));
      i++;
    }
    j++;
    i = j;
  }
}
