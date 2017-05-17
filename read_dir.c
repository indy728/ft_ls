/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:01:04 by alcornea          #+#    #+#             */
/*   Updated: 2017/05/16 21:42:51 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int stat_dir(char *path)
{
  struct stat str;

  if (stat(path, &str) == -1)
	{
		if (lstat(path, &str) == -1)
		{
			if (errno == ENOTDIR)
				return (0);
		}
	}
	if (S_ISDIR(str.st_mode))
		return (1);
	else if (S_ISLNK(str.st_mode))
		return (2);
	return (0);
}

t_data *read_directories(char *bpath, char *path, t_posib *option, int *nb)
{
  int tmp = 0;
  DIR *dir;
  t_data *data = NULL;
  t_data *new = NULL;
  struct dirent *dp;

  if ((dir = opendir(bpath)) == NULL)
  {
    if(errno == ENOENT || errno == ENOTDIR)
    {
      if (stat_dir(path) != 0)
      {
        ft_putendl(ft_strsub(path, 2, ft_strlen(path)));
        return (NULL);
      }
    }
    error(1, path);
    return (NULL);
  }
  while ((dp = readdir(dir)) != NULL)
  {
	if (!option->a && dp->d_name[0] == '.')///////////////
		continue ;///////////////
    if ((new = (t_data*)malloc(sizeof(t_data))) == NULL)
      exit(error(1, "read directories1"));
    init_elements(new);
    if ((new->name = ft_strdup(dp->d_name)) == NULL)
      exit(error(1, dp->d_name));
    if ((tmp = get_total(bpath, new, option)) == -1)
      continue;

    option->total += tmp;
    //insert_elem(&data, new, option);
    insert_elem(&data, new, option);
    (*nb)++;
  }
  if (dp == NULL && data == NULL)
    error(1, "read directories2");
  closedir(dir);
  return (data);

}
