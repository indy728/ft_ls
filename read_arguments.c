/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:53:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/05/16 19:09:45 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
// USE perror("{error message}")
int error(int nb, char *str)
{
	if (nb == 1)
	{
		ft_putstr_fd("ft_ls: ", 2);
		perror(str);
	}
	else if (nb == 2)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(str[0], 2);
		ft_putchar('\n');
		ft_putstr_fd("usage: ft_ls [-RSalrt] [file ...]", 2);
		ft_putendl("");
	}
	return (-1);
}

int check_str(char *str)
{
	int i;
	char *tmp;

	i = 0;
	tmp = "RSatlr";
	while (str[i])
	{
		if (ft_strchr(tmp, str[i]) == NULL)
			exit(error(2, &(str[i])));
		i++;
	}
	return (0);

}

int check_arg(t_posib option)
{
	int i;

	i = 0;
	while (i < option.nb_path)
	{
		if (option.path[i][0] == '\0')
		{
			errno = ENOENT;
			exit(error(1, "open"));
		}
		i++;
	}
	return (0);
}
//function that will concanate only charcaters and skip the dashes in argumets;
void	ft_strskipjoin(char **s1, char **s2)
{
	char *tmp;

	tmp = ft_strjoin(*s1, *s2);
	ft_strdel(s1);
	*s1 = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void  set_option(char *str, t_posib *option)
{
  int i;

  i = 0;
	check_str(str);
	check_arg(*option);
  while (str[i])
  {
    if (str[i] == 'R')
      option->rec = 1;
    if (str[i] == 'a')
      option->a = 1;
    if (str[i] == 'l')
      option->l = 1;
    if (str[i] == 'r')
      option->r = 1;
    if (str[i] == 't')
      option->t = 1;
		if (str[i] == 'S')
			option->s = 1;
    i++;
  }
}

char *get_rid_of_dash(char **av, int *ac)
{
  int i;
  int num;
  char *str;
  char *tmp;

  i = 1;
  num = (*ac);
  str = ft_strnew(*ac);
  while (i < num && av[i][0] == '-' && av[i][1] != '\0')
  {
    if (ft_strcmp(av[i], "--") != 0)
    {
      tmp = ft_strdup(&av[i][1]);
      ft_strskipjoin(&str, &tmp);
      free(tmp);
    }
    else
    {
      (*ac)--;
      break;
    }
    i++;
    (*ac)--;
  }
	(*ac)--;
  return (str);
}

char *get_argument(int ac, char **av, t_posib *option)
{
  int i;
  int j;
  int num; //arguments number
  char *str;

  num = ac;
  str = get_rid_of_dash(av, &ac); // str of all possible choices, ex:-r-l-a str = rla;
  if ((option->path = (char **)malloc(sizeof(char *) *
    	(((ac) == 0 ? 1 : ac) + 1))) == NULL)
			error(1, "get argument");
  if (ac < 1)
  {
		option->path[0] = NULL;
		option->path[0] = ft_strdup(".");
		option->path[1] = NULL;
		option->nb_path++; //nb_path = 1;
		return (str);
  }
  i = num - ac;
  j = 0;
  while (i < num)
  {
    option->path[j] = NULL;
    option->path[j] = ft_strdup(av[i]);
    j++;
    i++;
    option->nb_path++;
  }
  option->path[j] = NULL;
	printf("str: %s\n", str);
  return (str);
}
