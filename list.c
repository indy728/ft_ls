/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:01:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/05/16 21:25:58 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char *check_path(char *str)
{
  int ret;
  char *tmp;

  if ((str[0] != '/' && str[1] != '/') && (str[0] != '.'))
  {
    tmp = ft_strjoin(ft_strdup("./"), str);
    ft_strdel(&str);
    str = ft_strdup(tmp);
    ft_strdel(&tmp);
  }
  if ((ret = stat_dir(str) == 0))
    return (str);
  tmp = ft_strdup("/");
  str = ft_strjoin(str, tmp);
  free(tmp);
  return (str);
}


static int list_read(t_posib *option, char **path, t_data **data, int i)
{
  int nb;
  char *bpath;

  if ((option->rec && i > 0) || option->nb_path > 1) //option->nb_path > 1
  {
    if (i > 0)
      ft_putendl(""); //mkr sure for i and putendl
    ft_putstr(*path);
    ft_putendl(":");
  }
  bpath = check_path(*path);
  nb = 0;
  if ((*data = read_directories(bpath, *path, option, &nb)) == NULL)
    return (0);
  print(data, option);
  return (1);
}

void recursive(t_data *elem, t_posib *option, char *path, int i)
{
  char *tmp, *tmp2;

  if (elem->left)
    recursive(elem->left, option, path, i);
  if ((option->a || elem->name[0] != '.')
  &&  ft_strcmp(elem->name, "..") != 0 &&
    ft_strcmp(elem->name, ".") != 0)
    {
      if (elem->mode[0] == 'd')
      {
        if (path[ft_strlen(path) - 1] == '/')
          tmp = ft_strdup(path);
        else
          tmp = ft_strjoin(path, "/");
        tmp2 = ft_strjoin(tmp, elem->name);
        ft_strdel(&tmp);
        list_recursive(option, tmp2, i + 1);
        ft_strdel(&tmp2);
      }
   }
   if(elem->right)
    recursive(elem->right, option, path, i);
}
int  list_recursive(t_posib *option, char *path, int i)
{
  t_data *data = NULL;
  t_data *elem;


  if (list_read(option, &path, &data, i) == 0)
    return (0);
  elem = data;
  if (option->rec && elem != NULL)
    recursive(elem, option, path, i);
  return(0);
}
//don't need t_data here?
void list(t_posib *option)
{
  int i;
  t_data *data;
  char *tmp = NULL;

  i = 0;
  data = NULL;
  while (i < option->nb_path)
  {
    if (option->path[i] != NULL)
    {
      tmp = ft_strdup(option->path[i]);
      list_recursive(option, tmp, i);
      free(tmp);
    }
    i++;
  }
}
